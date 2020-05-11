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

#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <fstream>
#include <iostream>

// required for afl
static int fid = 0;
static std::stringstream oldss;

static ITamperer NoTamper;

unsigned trid = 0;

int main(int argc, char* argv[]) {
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
  std::shared_ptr<TraceGenerator> tg = std::make_shared<TraceGenerator>(aes_tg, stdin);
  tg->addVars(signals);


  #ifdef SIMULATE_TRACES

    std::cout << "SIMULATING TRACES...\n";

    DIR* pDIR;
    std::string dirpath = std::string(argv[1]);
    struct dirent* entry;

    if (pDIR = opendir(dirpath.c_str())) {

      while (entry = readdir(pDIR)) {

        if (trid == 100) {
            std::cout << "Finished trace generation (processed only 100 test cases)\n";
            break;
        }

        if ((entry->d_name[0] != '.') && strcmp(entry->d_name, "..") != 0) {
          std::cout << entry->d_name << "\n";
          std::string filepath = dirpath + std::string(entry->d_name);
          tg->insource = fopen(filepath.c_str(), "rb");
          sim.run(NoTamper, romfile, imgfile, tg);
          fclose(tg->insource);
          sim.nextTrace();
          std::cout << "Simulating next trace : " << trid++ << std::endl;
        }
      }
      closedir(pDIR);
    } else {
      std::cout << "NOT able to open directroy" << std::endl;
    }

  #else
    OpcodeTamperer tamper(379 /* base addr */, 24 /* size */);
    // afl init
    afl_init(&fid, &oldss);

    sim.run(tamper, romfile, imgfile, tg);

    // push coverage
    sim.copy_coverage();

  #endif

  return 0;
}
