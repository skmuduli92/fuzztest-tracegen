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

#define DEBUG_REG_ADDR 0xEFFE
#define DEBUG_REG_DATA 0xEFFF

// Coverage trackers.
ValueTracker opcode_tracker(16381 /* closest prime to 16384 */, 8);
ValueTracker pc_tracker(32771 /* closest prime to 32768 */, 16);
// Clock cycle counter.
vluint64_t main_time = 0;

// Returns current clock cycle number.
double sc_time_stamp() { return main_time; }
void reset_time_stamp() { main_time = 0; }

// Helper to monitor the ports.
void monitor_ports(Voc8051_tb* top) {
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

// simulates delay number of cycles. Set delay < 0 to simulate
// indefinetely.
int simulate(long delay, Voc8051_tb *top) {
    long cnt = 0;
    int clk = 0;
    for(cnt = 0; cnt < delay || delay < 0; cnt++, main_time++) {
        // check if verilog code is finished
        if(Verilated::gotFinish()) { break; }

        // set clock and simulate.
        top->oc8051_tb__DOT__clk = clk;
        top->eval();
        monitor_ports(top);
        
        // coverage.
        if (clk == 0) {
            // track signals on rising clock
            opcode_tracker.track(top->oc8051_tb__DOT__oc8051_top_1__DOT__op1_d);
            pc_tracker.track(top->oc8051_tb__DOT__oc8051_top_1__DOT__pc);
        }

        // toggle clock.
        if (clk == 1) { clk = 0; }
        else { clk = 1; }
    }
    return cnt;
}

// reset uc
void reset_uc(Voc8051_tb* top)
{
    top->oc8051_tb__DOT__rst = 1;
    top->oc8051_tb__DOT__p0_in = 0x00;
    top->oc8051_tb__DOT__p1_in = 0x00;
    top->oc8051_tb__DOT__p2_in = 0xff;
    if(simulate(20, top) != 20) {
        fprintf(stderr, "ERROR: Reset failed.\n");
        exit(1);
    }
    top->oc8051_tb__DOT__rst = 0;
}

// load into ROM
void load_program(Voc8051_tb *top, const std::string& romfile){
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
void load_boot_image(Voc8051_tb* top, const std::string& imgfile){
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
void run(
    Voc8051_tb* top, ITamperer& tamperer,
    const std::string& romfile, const std::string& imgfile)
{
    reset_uc(top);
    load_program(top, romfile);
    load_boot_image(top, imgfile);
    tamperer.tamper(top);
    simulate(2621440,top);
    std::cout << "finished @ " << std::dec << main_time << std::endl;
}

// Default tamperer
ITamperer NoTamper;
// Default tamper function.
void ITamperer::tamper(Voc8051_tb* top) 
{
    (void) top;
    // do nothing.
}
