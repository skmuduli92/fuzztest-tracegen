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
  Voc8051_Simulator sim(2, 1, 0);

  // filenames
  std::string romfile("../rom/aes_test.dat");
  std::string imgfile;

  std::vector<std::string> signals(
      {"decoder_state",         "decoder_wr",           "decoder_alu_op",
       "decoder_wr_sfr",        "decoder_ram_wr_sel",   "decoder_rd_sel",
       "decoder_state_dec",     "decoder_op",           "decoder_ram_rd_sel_r",
       "mem_intrfc_rd_addr_r",  "mem_intrfc_dack_ir",   "mem_intrfc_ddat_ir",
       "mem_intrfc_rn_r",       "mem_intrfc_ri_r",      "mem_intrfc_imm_r",
       "mem_intrfc_imm2_r",     "mem_intrfc_int_ack_t", "mem_intrfc_int_vec_buff",
       "mem_intrfc_op2_buff",   "mem_intrfc_op3_buff",  "mem_intrfc_op1_o",
       "mem_intrfc_op2_o",      "mem_intrfc_op3_o",     "mem_intrfc_istb_t",
       "mem_intrfc_imem_wait",  "mem_intrfc_dmem_wait", "mem_intrfc_op_length",
       "mem_intrfc_op_pos",     "mem_intrfc_inc_pc",    "mem_intrfc_pc_wr_r",
       "mem_intrfc_pc_wr_r2",   "mem_intrfc_cdata",     "mem_intrfc_cdone",
       "mem_intrfc_pcs_source", "mem_intrfc_pcs_cy"});

  const unsigned int aes_tg = 5;
  std::shared_ptr<TraceGenerator> tg = std::make_shared<TraceGenerator>(aes_tg);
  tg->addVars(signals);

  // afl init
  afl_init(&fid, &oldss);
  sim.run(NoTamper, romfile, imgfile, tg);

  // push coverage
  sim.copy_coverage();

  return 0;
}
