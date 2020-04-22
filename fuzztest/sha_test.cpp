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
  std::string romfile("../rom/sha_pycomp.dat");
  std::string imgfile;

  std::vector<std::string> signals({"sha_reg_len", "byte_counter", "byte_counter_next",
                                    "sha_reg_state", "sha_state_next", "byte_counter_next_rw",
                                    "ready_flag", "reg_bytes_read", "bytes_read_next",
                                    "block_counter", "block_counter_next", "sha_reg_rd_addr",
                                    "sha_reg_wr_addr", "sha_more_blocks", "sha_core_init",
                                    "sha_core_next", "sha_core_ready_r", "good_value"});

  const unsigned int sha_tg = 1;
  std::shared_ptr<TraceGenerator> tg = std::make_shared<TraceGenerator>(sha_tg);
  tg->addVars(signals);

  afl_init(&fid, &oldss);

  // first run.
  sim.run(NoTamper, romfile, imgfile, tg);

  // push coverage
  sim.copy_coverage();

  return 0;
}
