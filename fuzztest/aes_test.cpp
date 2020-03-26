#include <iostream>
#include <verilated.h>
#include "secureboot.h"
#include "Voc8051_tb.h"
#include "Voc8051_tb__Syms.h"

#include <memory>
#include <string>

#include "formula.h"
#include "trace.h"
#include "parse_util.h"

// required for afl
static int fid = 0;
static std::stringstream oldss;

struct NopTamperer : public ITamperer {
  virtual void tamper(Voc8051_tb* top);
};

void NopTamperer::tamper(Voc8051_tb* top)
{
  const int BUF_SIZE = 24;
  const int BASE_ADDR = 379;
  for(unsigned i=0; i < BUF_SIZE; i++) {
    int data;
    if (scanf("%u",  &data) != 1)  { break; }
    top->oc8051_tb__DOT__oc8051_cxrom1__DOT__buff[i + BASE_ADDR] = data;
  }
}

int main() {
  // create top module
  Voc8051_Simulator sim(1, 0);
  auto f = HyperPLTL::parse_formula(std::string("(IMPLIES (O good.1) (O good.0))"));
  const int GOOD_DEBUG_ID = 0x12;
  auto traceIdx = f->getPropId(std::string("good"));
  sim.addVar(std::string("good"), traceIdx, GOOD_DEBUG_ID, Voc8051_Simulator::VarInfo::PROPOSITION, 0); 

  // afl init
  afl_init(&fid, &oldss);

  // filenames
  std::string romfile("../rom/aes_test.dat");
  std::string imgfile;

  // first run.
  sim.run(NoTamper, romfile, imgfile);

  // second trace.
  NopTamperer tamper;
  Verilated::reset_verilator();
  reset_time_stamp();
  sim.run(tamper, romfile, imgfile);

  // push coverage
  sim.copy_coverage();

  return 0;
}
