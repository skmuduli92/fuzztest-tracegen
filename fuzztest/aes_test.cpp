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
  Voc8051_Simulator sim(2, 1, 0);

  // filenames
  std::string romfile("../rom/aes_test.dat");
  std::string imgfile;

  std::vector<std::string> signals({"aes_reg_start", "ack_aes", "aes_xram_ack", "aes_reg_state", "aes_reg_state_next",
                                    "aes_byte_counter", "aes_reg_oplen", "aes_data_out_mux", "good_value",
                                    "operated_bytes_count", "operated_bytes_count_next", "block_counter",
                                    "block_counter_next", "more_blocks", "last_byte_acked"});

  const unsigned int aes_tg = 0;

  std::shared_ptr<TraceGenerator> tg = std::make_shared<TraceGenerator>(aes_tg, stdin);
  tg->addVars(signals);

  // OpcodeTamperer tamper(379 /* base addr */, 24 /* size */);
  // // afl init
  // afl_init(&fid, &oldss);
  //
  // sim.run(tamper, romfile, imgfile, tg);
  //
  // // push coverage
  // sim.copy_coverage();

  DIR* pDIR;

  std::string dirpath = "/home/sujit/Tools/fuzztest-tracegen/fuzztest/aes-out/queue/";
  struct dirent* entry;
  if (pDIR = opendir(dirpath.c_str())) {
    while (entry = readdir(pDIR)) {
      if (trid == 100) break;
      if ((entry->d_name[0] != '.') && strcmp(entry->d_name, "..") != 0) {

        std::cout << entry->d_name << "\n";
        // sim.run(tamper, romfile, imgfile, tg);

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
