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
  std::string romfile("../rom/rsa_test.dat");
  std::string imgfile;

  std::vector<std::string> signals;

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
