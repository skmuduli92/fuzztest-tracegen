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

  #ifdef SIMULATE_TRACES
    if(argc < 2) {
        std::cerr << "ERROR : Provide the path for the test inputs\n";
        exit(1);
    }

  #endif

  // filenames
  std::string romfile("../rom/memwr.dat");
  std::string imgfile;

  std::vector<std::string> signals({"memwr_start_op",
                                    "memwr_reg_state",
                                    "mem_reg_rd_addr",
                                    "mem_reg_wr_addr",
                                    "memwr_reg_bytes_written",
                                    "memwr_reg_bytes_read",
                                    "memwr_reg_bytes_read_next",
                                    "memwr_reg_bytes_written_next",
                                    "memwr_reg_len",
                                    "memwr_wren",
                                    "memwr_state_next",
                                    "memwr_xram_ack",
                                    "memwr_xram_stb",
                                    "ack_memwr",
                                    "stb_memwr",
                                    "fsm_writer_finished",
                                    "fsm_writer_ptr",
                                    "fsm_writer_delay",
                                    "procarbiter_arbiter_state",
                                    "procarbiter_arbit_hold",
                                    "procarbiter_arbiter_state_next",
                                    "procarbiter_arbit_winner",
                                    "procarbiter_arbit_holder_next",
                                    "memarbiter_arbiter_state",
                                    "memarbiter_arbit_holder",
                                    "memarbiter_arbiter_state_next",
                                    "memarbiter_arbit_winner",
                                    "memarbiter_arbit_holder_next",
                                    "xram_ackw",
                                    "xram_ackr",
                                    "xram_cnt"});

  const unsigned int wr_tg = 4;
  std::shared_ptr<TraceGenerator> tg = std::make_shared<TraceGenerator>(wr_tg, stdin);
  tg->addVars(signals);


  #ifdef SIMULATE_TRACES

    std::cout << "SIMULATING TRACES...\n";

    DIR* pDIR;
    std::string dirpath = std::string(argv[1]);
    struct dirent* entry;

    if (pDIR = opendir(dirpath.c_str())) {

      while (entry = readdir(pDIR)) {

        if (trid == 100) {
            std::cout << "Finished trace generation (processing upto 100 test cases)\n";
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
