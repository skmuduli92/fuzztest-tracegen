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
  std::string romfile("../rom/page_table_test.dat");
  std::string imgfile;

  std::vector<std::string> signals({"read_succeed",   "write_succeed", "wr_addr",       "rd_addr",      "ack_w",
                                    "ack_r",          "ia_addr_reg",   "pc_ia_reg",     "ia_reg_next",  "pt_in_wr_range",
                                    "pt_in_rd_range", "pt_wr_reg_use", "pt_rd_reg_use", "ia_rwn_reg",   "illegal_src",
                                    "illegal_wr",     "illegal_rd",    "accesser",      "ia_src_next",  "wr_enabled_0",
                                    "wr_enabled_1",   "wr_enabled_2",  "rd_enabled_0",  "rd_enabled_1", "rd_enabled_2"});

  const unsigned int page_table_tg = 2;
  std::shared_ptr<TraceGenerator> tg = std::make_shared<TraceGenerator>(page_table_tg, stdin);
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

  std::string dirpath = "/home/sujit/Tools/fuzztest-tracegen/fuzztest/pt-out/queue/";
  struct dirent* entry;
  if (pDIR = opendir(dirpath.c_str())) {

    while (trid < 200 && (entry = readdir(pDIR))) {
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
