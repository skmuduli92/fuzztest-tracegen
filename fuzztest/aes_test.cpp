#include <verilated.h>
#include <iostream>
#include "Voc8051_tb.h"
#include "Voc8051_tb__Syms.h"
#include "secureboot.h"

#include "tamper.h"

#include <cstdlib>
#include <memory>
#include <string>
#include "formula.h"
#include "parse_util.h"
#include "trace.h"
#include "tracerecord.h"

// required for afl
static int fid = 0;
static std::stringstream oldss;

static ITamperer NoTamper;

int main() {
  // create top module
  Voc8051_Simulator sim(2, 1, 0);
  // parse the property
  HyperPLTL::PVarMap varmap(new HyperPLTL::VarMap());
  auto traceIdx = varmap->addPropVar(std::string("good"));
  auto f =
      HyperPLTL::parse_formula(std::string("(IMPLIES (O good.1) (O good.0))"), varmap);

  const int GOOD_DEBUG_ID = 0x12;
  sim.addVar(std::string("good"), traceIdx, GOOD_DEBUG_ID,
             Voc8051_Simulator::VarInfo::PROPOSITION, 0);

  // filenames
  std::string romfile("../rom/aes_test.dat");
  std::string imgfile;

  std::vector<std::string> signals(
      {"aes_reg_start", "ack_aes", "aes_xram_ack", "aes_reg_state", "aes_reg_state_next",
       "aes_byte_counter", "aes_reg_oplen", "aes_data_out_mux", "good_value",
       "operated_bytes_count", "operated_bytes_count_next", "block_counter",
       "block_counter_next"});

  std::shared_ptr<TraceGen> tg = std::make_shared<TraceGen>();
  tg->addIntVars(signals);

  // afl init
  afl_init(&fid, &oldss);

  // first run.
  //  int callres = std::system("sh genfw.sh");

fork();

  sim.run(NoTamper, romfile, imgfile, tg);

  // second trace.
  // OpcodeTamperer tamper(379 /* base addr */, 24 /* size */);
  sim.nextTrace();
  // sim.run(tamper, romfile, imgfile);

  // assert(sim.evaluate(f));

  // push coverage
  sim.copy_coverage();

  return 0;
}
