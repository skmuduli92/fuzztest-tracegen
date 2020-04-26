#include <verilated.h>
#include <iostream>

#include <memory>
#include <string>

#include "Voc8051_tb.h"
#include "Voc8051_tb__Syms.h"

#include "formula.h"
#include "parse_util.h"
#include "secureboot.h"
#include "tamper.h"
#include "trace.h"

// required for afl
static int fid = 0;
static std::stringstream oldss;

static ITamperer NoTamper;

unsigned trid = 0;

int main() {
  // create top module
  Voc8051_Simulator sim(2, 1, 5);

  // filenames
  std::string romfile("../rom/exp_test.dat");
  std::string imgfile;

  std::vector<std::string> signals({"exp_reg_state", "wren", "start_op", "byte_counter",
                                    "byte_counter_next", "exp_reg_state_next", "exp_reg_opaddr",
                                    "modexp_state", "modexp_ei", "modex_state_next", "square_state",
                                    "square_state_next", "mul_state", "mul_state_next"});

  // NOTE : this experiment is only claling modexp module for testing

  const unsigned int rsa_tg = 3;
  std::shared_ptr<TraceGenerator> tg = std::make_shared<TraceGenerator>(rsa_tg);
  tg->addVars(signals);

  afl_init(&fid, &oldss);

  // first run.
  sim.run(NoTamper, romfile, imgfile, tg);

  // push coverage
  sim.copy_coverage();

  return 0;
}
