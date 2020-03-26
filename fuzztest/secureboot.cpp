#include <verilated.h>
#include <iterator>
#include <iostream>
#include <iomanip>
#include "Voc8051_tb.h"
#include "Voc8051_tb__Syms.h"
#include <array>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <cstdlib>
#include <memory>
#include <sstream>
#include <map>

#include "secureboot.h"
#include "coverage.h"
#include "afl.h"

#include "trace.h"
#include "formula.h"

// Clock cycle counter.
vluint64_t main_time = 0;

// Returns current clock cycle number.
double sc_time_stamp() { return main_time; }
void reset_time_stamp() { main_time = 0; }

const int Voc8051_Simulator::DEBUG_REG_ADDR = 0xEFFC;
const int Voc8051_Simulator::DEBUG_REG_DATA = 0xEFFE; 

// Helper to monitor the ports.
void Voc8051_Simulator::monitor_ports() 
{
  static int p0, p1, p2, p3;
  if (p0 != top->oc8051_tb__DOT__p0_out ||
      p1 != top->oc8051_tb__DOT__p1_out ||
      p2 != top->oc8051_tb__DOT__p2_out ||
      p3 != top->oc8051_tb__DOT__p3_out )
  {
    std::cout << "monitor_ports @ " << std::setw(8) 
      << std::dec << main_time << ": " 
      << std::hex << std::setw(2) << p0
      << "/" << std::hex << std::setw(2) << p1
      << "/" << std::hex << std::setw(2) << p2
      << "/" << std::hex << std::setw(2) << p3
      << std::endl;
    p0 = top->oc8051_tb__DOT__p0_out;
    p1 = top->oc8051_tb__DOT__p1_out;
    p2 = top->oc8051_tb__DOT__p2_out;
    p3 = top->oc8051_tb__DOT__p3_out;
  }
}

// Helper to monitor writes to the debug registers.
void Voc8051_Simulator::monitor_debug_registers()
{
  auto ackw = top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__ackw;
  uint32_t addr = top->oc8051_tb__DOT__oc8051_xiommu1__DOT__addr_out;

  if (ackw && addr == DEBUG_REG_DATA+1) {
    uint16_t lo_data = top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[DEBUG_REG_DATA];
    uint16_t hi_data = top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[DEBUG_REG_DATA+1];
    uint16_t this_data = lo_data | (hi_data << 8);

    uint16_t lo_addr = top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[DEBUG_REG_ADDR];
    uint16_t hi_addr = top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[DEBUG_REG_ADDR+1];
    uint16_t this_addr = lo_addr | (hi_addr << 8);

    std::cout << "set @ " << std::dec << main_time << ": " 
              << std::dec << this_addr << " -> " 
              << std::dec << this_data << std::endl;
    setVar(trace, this_addr, main_time, this_data);
  }
}


// simulates delay number of cycles. Set delay < 0 to simulate
// indefinetely.
int Voc8051_Simulator::simulate(long delay) 
{
  long cnt = 0;
  int clk = 0;
  for(cnt = 0; cnt < delay || delay < 0; cnt++, main_time++) {
    // check if verilog code is finished
    if(Verilated::gotFinish()) { break; }

    // set clock and simulate.
    top->oc8051_tb__DOT__clk = clk;
    top->eval();
    monitor_ports();
    monitor_debug_registers();

    // coverage.
    if (clk == 0) {
      // track signals on rising clock
      opcode_tracker.track(top->oc8051_tb__DOT__oc8051_top_1__DOT__op1_d);
      pc_tracker.track(top->oc8051_tb__DOT__oc8051_top_1__DOT__pc);
    }
    // trace builder.

    // toggle clock.
    if (clk == 1) { clk = 0; }
    else { clk = 1; }
  }
  return cnt;
}

// reset uc
void Voc8051_Simulator::reset_uc()
{
  top->oc8051_tb__DOT__rst = 1;
  top->oc8051_tb__DOT__p0_in = 0x00;
  top->oc8051_tb__DOT__p1_in = 0x00;
  top->oc8051_tb__DOT__p2_in = 0xff;
  if(simulate(20) != 20) {
    fprintf(stderr, "ERROR: Reset failed.\n");
    exit(1);
  }
  top->oc8051_tb__DOT__rst = 0;
}

// load into ROM
void Voc8051_Simulator::load_program(const std::string& romfile)
{
  const int CXROM_BUF_SIZE = 65536;
  std::ifstream infile;
  infile.open(romfile);
  int value_cnt,a,b;
  infile >> value_cnt;
  // read in value_cnt entries.
  for (int i = 0; i < value_cnt; i++) {
    infile >> b >> a;
    top->oc8051_tb__DOT__oc8051_cxrom1__DOT__buff[b] = (unsigned int)a;
  }
  // fill in the rest with zeros.
  for (;value_cnt < CXROM_BUF_SIZE; value_cnt++) {
    top->oc8051_tb__DOT__oc8051_cxrom1__DOT__buff[value_cnt] = 0U;
  }
  infile.close();
  return;
}

// load IMG.
void Voc8051_Simulator::load_boot_image(const std::string& imgfile)
{
  if (imgfile.size() == 0) return;

  std::ifstream infile;
  infile.open(imgfile);
  const int XRAM_BASE = 0x3000;
  for (int i=0; !infile.eof(); i++){
    int b;
    infile >> std::hex >> b;
    top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[XRAM_BASE+i] = (unsigned int)b;
  }

  infile.close();
  return;
}

// run program.
void Voc8051_Simulator::run(
    ITamperer& tamperer,
    const std::string& romfile, const std::string& imgfile)
{
  reset_uc();
  load_program(romfile);
  load_boot_image(imgfile);
  tamperer.tamper(top.get());
  simulate(2621440);
  std::cout << "finished @ " << std::dec << main_time << std::endl;
}

void Voc8051_Simulator::copy_coverage()
{
  std::vector<uint32_t> coverageBins(
      opcode_tracker.size() + pc_tracker.size());
  std::copy(opcode_tracker.begin(), opcode_tracker.end(),
      coverageBins.begin());
  std::copy(pc_tracker.begin(), pc_tracker.end(),
      coverageBins.begin() + opcode_tracker.size());
  afl_copy(coverageBins.data(), coverageBins.size());
}

// Default tamperer
ITamperer NoTamper;
// Default tamper function.
void ITamperer::tamper(Voc8051_tb* top) 
{
  (void) top;
  // do nothing.
}
