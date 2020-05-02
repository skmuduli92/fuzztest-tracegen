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

using namespace HyperPLTL;

// required for afl
static int fid = 0;
static std::stringstream oldss;

static ITamperer NoTamper;

unsigned trid = 0;

int main(int argc, char *argv[]) {

  std::vector<std::string> propstrlist;
  std::vector<PHyperProp> proplist;

  if (argc < 2) {
    std::cerr << "usage : ./check <propfile>\n";
    exit(1);
  }

  // openfile
  std::fstream fs(argv[1], std::ios::in);
  PVarMap varmap = std::make_shared<VarMap>();

  std::string propstr;
  while (std::getline(fs, propstr)) {
    std::cout << "parsing formula : " << propstr << " : ";
    proplist.push_back(parse_formula(propstr, varmap));
    std::cout << " OK" << std::endl;
  }

  // for (auto formula : proplist) {
  //   formula->display(std::cout);
  //   std::cout << std::endl;
  // }

  // write logic to record traces of SoC using libprop trace API

  // get the list of signal names
  std::vector<std::string> varlist = varmap->getVarList();

  std::cout << "list of varmap formula : " << std::endl;
  for (auto si : varlist) std::cout << si << std::endl;

  // create the vector with

  Voc8051_Simulator sim(2, 0, varlist.size());
  // filenames
  std::string romfile("../rom/aes_test.dat");
  std::string imgfile;

  // create traceinfo to be used for updating variable corrspondign to a trace
  for (auto varname : varlist) {
    // add all int vars
    unsigned trindex = varmap->getVarIndex(varname);
    std::cout << "trindex : " << trindex << std::endl;
    sim.addVar(varname, trindex, trindex, Voc8051_Simulator::VarInfo::TERM, 0);
  }

  std::vector<std::string> signals({"aes_reg_start", "ack_aes", "aes_xram_ack", "aes_reg_state", "aes_reg_state_next",
                                    "aes_byte_counter", "aes_reg_oplen", "aes_data_out_mux", "good_value",
                                    "operated_bytes_count", "operated_bytes_count_next", "block_counter",
                                    "block_counter_next", "more_blocks", "last_byte_acked"});

  const unsigned int aes_tg = 0;

  FILE *insource = NULL;
  if (argc == 3) {
    std::cout << "reading input from file : " << argv[2] << std::endl;
    insource = fopen(argv[2], "rb");
  } else
    insource = stdin;

  std::shared_ptr<TraceGenerator> tg = std::make_shared<TraceGenerator>(aes_tg, insource);
  tg->addVars(signals);

  // afl init
  afl_init(&fid, &oldss);
  sim.run(NoTamper, romfile, imgfile, tg);

  if (insource != stdin) fclose(insource);

  return 0;
}
