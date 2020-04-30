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

int main() {
  // create top module
  Voc8051_Simulator sim(2, 1, 5);

  // filenames
  std::string romfile("../rom/sha_pycomp.dat");
  std::string imgfile;

  std::vector<std::string> signals({"sha_reg_len", "byte_counter", "byte_counter_next", "sha_reg_state", "sha_state_next",
                                    "byte_counter_next_rw", "ready_flag", "reg_bytes_read", "bytes_read_next",
                                    "block_counter", "block_counter_next", "sha_reg_rd_addr", "sha_reg_wr_addr",
                                    "sha_more_blocks", "sha_core_init", "sha_core_next", "sha_core_ready_r", "good_value"});

  const unsigned int sha_tg = 1;
  // FILE* fsource = fopen("/home/sujit/Tools/fuzztest-tracegen/fuzztest/afl-in/sha_test/in1.bin", "rb");
  std::shared_ptr<TraceGenerator> tg = std::make_shared<TraceGenerator>(sha_tg, stdin);
  tg->addVars(signals);

  DIR* pDIR;

  std::string dirpath = "/home/sujit/Tools/fuzztest-tracegen/fuzztest/sha-out/queue/";
  struct dirent* entry;
  if (pDIR = opendir(dirpath.c_str())) {
    while (entry = readdir(pDIR)) {
      if (trid > 100) break;
      if ((entry->d_name[0] != '.') && strcmp(entry->d_name, "..") != 0) {

        std::cout << entry->d_name << "\n";
        std::string filepath = dirpath + std::string(entry->d_name);
        tg->insource = fopen(filepath.c_str(), "rb");
        sim.run(NoTamper, romfile, imgfile, tg);
        fclose(tg->insource);
        sim.nextTrace();
        std::cout << "SIMULATING nextTrace : " << trid++ << std::endl;
      }
    }
    closedir(pDIR);
  } else {
    std::cout << "NOT able to open directroy" << std::endl;
  }

  return 0;
}
