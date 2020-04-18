#include <verilated.h>
#include <algorithm>
#include <array>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <sstream>
#include "Voc8051_tb.h"
#include "Voc8051_tb__Syms.h"

#include "afl.h"
#include "coverage.h"
#include "secureboot.h"

#include "formula.h"
#include "trace.h"

// Clock cycle counter.
vluint64_t main_time = 0;

// Returns current clock cycle number.
double sc_time_stamp() { return main_time; }
void reset_time_stamp() { main_time = 0; }

const int Voc8051_Simulator::DEBUG_REG_ADDR = 0xEFFC;
const int Voc8051_Simulator::DEBUG_REG_DATA = 0xEFFE;

// Helper to monitor the ports.
void Voc8051_Simulator::monitor_ports() {
  static int p0, p1, p2, p3;
  if (p0 != top->oc8051_tb__DOT__p0_out || p1 != top->oc8051_tb__DOT__p1_out ||
      p2 != top->oc8051_tb__DOT__p2_out || p3 != top->oc8051_tb__DOT__p3_out) {
    std::cout << "monitor_ports @ " << std::setw(8) << std::dec << main_time << ": "
              << std::hex << std::setw(2) << p0 << "/" << std::hex << std::setw(2) << p1
              << "/" << std::hex << std::setw(2) << p2 << "/" << std::hex << std::setw(2)
              << p3 << std::endl;

    p0 = top->oc8051_tb__DOT__p0_out;
    p1 = top->oc8051_tb__DOT__p1_out;
    p2 = top->oc8051_tb__DOT__p2_out;
    p3 = top->oc8051_tb__DOT__p3_out;
  }
}

// Helper to monitor writes to the debug registers.
void Voc8051_Simulator::monitor_debug_registers() {
  auto ackw = top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__ackw;
  uint32_t addr = top->oc8051_tb__DOT__oc8051_xiommu1__DOT__addr_out;

  if (ackw && addr == DEBUG_REG_DATA + 1) {
    uint16_t lo_data = top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff
                           [DEBUG_REG_DATA];
    uint16_t hi_data = top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff
                           [DEBUG_REG_DATA + 1];
    uint16_t this_data = lo_data | (hi_data << 8);

    uint16_t lo_addr = top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff
                           [DEBUG_REG_ADDR];
    uint16_t hi_addr = top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff
                           [DEBUG_REG_ADDR + 1];
    uint16_t this_addr = lo_addr | (hi_addr << 8);

    // std::cout << "set @ " << std::dec << main_time << ": " << std::dec << this_addr
    //           << " -> " << std::dec << this_data << std::endl;
    setVar(trace, this_addr, main_time, this_data);
  } else {
    traces[trace]->extendToCycle(main_time);
  }
}

// simulates delay number of cycles. Set delay < 0 to simulate
// indefinetely.
int Voc8051_Simulator::simulate(std::shared_ptr<TraceGen>& tg, long delay) {
  long cnt = 0;
  int clk = 0;

  for (cnt = 0; cnt < delay || delay < 0; cnt++, main_time++) {
    // check if verilog code is finished
    if (Verilated::gotFinish()) {
      break;
    }

    TraceGenerator::tracegen_aes(top, tg);
    // set clock and simulate.
    top->oc8051_tb__DOT__clk = clk;
    top->eval();
    monitor_ports();
    monitor_debug_registers();
    // coverage.
    if (clk == 0) {
      // track signals on rising clock
      uint32_t opcode = top->oc8051_tb__DOT__oc8051_top_1__DOT__op1_d;
      tracker.track(0, opcode);
      auto pc = top->oc8051_tb__DOT__oc8051_top_1__DOT__pc;
      tracker.track(1, pc);
      if (top->oc8051_tb__DOT__oc8051_xiommu1__DOT__stb_out &&
          top->oc8051_tb__DOT__oc8051_xiommu1__DOT__ack_in) {
        unsigned addr = top->oc8051_tb__DOT__oc8051_xiommu1__DOT__proc_addr;
        unsigned data = 0;
        if (top->oc8051_tb__DOT__oc8051_xiommu1__DOT__wr_out) {
          data = top->oc8051_tb__DOT__oc8051_xiommu1__DOT__proc_data_in;
        }
        tracker.track(2, addr | (opcode << 16) | (data << 24));
      }
    }

    // toggle clock.
    if (clk == 1) {
      clk = 0;
    } else {
      clk = 1;
    }
  }
  return cnt;
}

// reset uc
void Voc8051_Simulator::reset_uc(std::shared_ptr<TraceGen>& tg) {
  top->oc8051_tb__DOT__rst = 1;
  top->oc8051_tb__DOT__p0_in = 0x00;
  top->oc8051_tb__DOT__p1_in = 0x00;
  top->oc8051_tb__DOT__p2_in = 0xff;
  if (simulate(tg, 20) != 20) {
    fprintf(stderr, "ERROR: Reset failed.\n");
    exit(1);
  }

  const int dataloc = 0xE000;

  std::cout << "trace id : " << TraceGenerator::trid << std::endl;

  for (size_t idx = 0; idx < 16; ++idx) {
    top->oc8051_tb__DOT__oc8051_cxrom1__DOT__buff[dataloc + idx] =
        (unsigned int)(rand() % 256);
  }
  top->oc8051_tb__DOT__rst = 0;
}

// load into ROM
void Voc8051_Simulator::load_program(const std::string& romfile) {
  const int CXROM_BUF_SIZE = 65536;
  std::ifstream infile;
  infile.open(romfile);
  int value_cnt, a, b;
  infile >> value_cnt;

  // read in value_cnt entries.

  std::cout << "loading AES program into memory : " << romfile << std::endl;
  for (int i = 0; i < value_cnt; i++) {
    infile >> b >> a;
    top->oc8051_tb__DOT__oc8051_cxrom1__DOT__buff[b] = (unsigned int)a;
  }
  // fill in the rest with zeros.
  for (; value_cnt < CXROM_BUF_SIZE; value_cnt++) {
    top->oc8051_tb__DOT__oc8051_cxrom1__DOT__buff[value_cnt] = 0U;
  }
  infile.close();
  return;
}

// load IMG.
void Voc8051_Simulator::load_boot_image(const std::string& imgfile) {

  if (imgfile.size() == 0) return;

  std::ifstream infile;
  infile.open(imgfile);
  const int XRAM_BASE = 0x3000;
  for (int i = 0; !infile.eof(); i++) {
    int b;
    infile >> std::hex >> b;
    top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[XRAM_BASE + i] =
        (unsigned int)b;
  }

  infile.close();
  return;
}

void Voc8051_Simulator::print_aes_metadata() {

  std::cout << "aes_reg_oplen : " << std::dec
            << (uint32_t)
                   top->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__aes_reg_oplen
            << std::hex << std::endl;

  // printing keyvalue
  std::cout << "printing keyvalues : " << std::endl;
  for (size_t idx = 0; idx < 4; ++idx) {
    std::cout
        << (uint32_t)
               top->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__aes_reg_key0[idx]
        << std::endl;
  }
}

void Voc8051_Simulator::randomizeData() {

  // randomize aes data length
  unsigned aes_reg_len = rand() % 128;
  top->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__aes_reg_oplen = aes_reg_len;

  // randomly generate keys
  for (size_t idx = 0; idx < 4; ++idx) {
    top->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__aes_reg_key0[idx] =
        rand() % std::numeric_limits<unsigned>::max();
  }
}

// run program.
void Voc8051_Simulator::run(ITamperer& tamperer, const std::string& romfile,
                            const std::string& imgfile, std::shared_ptr<TraceGen>& tg) {

  srand(time(NULL));
  reset_uc(tg);
  load_program(romfile);

  randomizeData();

  load_boot_image(imgfile);
  tamperer.tamper(top.get());
  simulate(tg, 2621440);
  std::cout << "finished @ " << std::dec << main_time << std::endl;
}

void Voc8051_Simulator::copy_coverage() {
#ifdef DEBUG_COVERAGE
  for (auto p = tracker.begin(); p != tracker.end(); p++) {
    std::cout << "bin: " << (int)*p << std::endl;
  }
#endif
  afl_copy(tracker.data(), tracker.size());
}

bool Voc8051_Simulator::evaluate(HyperPLTL::PHyperProp f) {
  unsigned len = traces[0]->length();
  for (unsigned i = 1; i < traces.size(); i++) {
    if (len > traces[i]->length()) {
      len = traces[i]->length();
    }
  }
  assert(len > 0);
  bool result;
  for (unsigned i = 0; i != len; i++) {
    result = f->eval(i, traces);
  }
  return result;
}

// Default tamperer
ITamperer NoTamper;
