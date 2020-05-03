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

#include "formula_util.h"

using namespace HyperPLTL;

// required for afl
static int fid = 0;
static std::stringstream oldss;

static ITamperer NoTamper;

bool isparent = true;
unsigned trid = 0;

std::vector<unsigned> violated;
std::vector<unsigned> traceidlist;

int main(int argc, char *argv[]) {

  std::vector<std::string> propstrlist;
  std::vector<PHyperProp> proplist;

  if (argc < 2) {
    std::cerr << "usage : ./check <propfile>\n";
    exit(1);
  }

  // these signal names are nothing but the varnames in the formula
  std::vector<std::string> signals({"aes_reg_start", "ack_aes", "aes_xram_ack", "aes_reg_state", "aes_reg_state_next",
                                    "aes_byte_counter", "aes_reg_oplen", "aes_data_out_mux", "good_value",
                                    "operated_bytes_count", "operated_bytes_count_next", "block_counter",
                                    "block_counter_next", "more_blocks", "last_byte_acked"});

  // openfile
  std::fstream fs(argv[1], std::ios::in);
  PVarMap varmap = std::make_shared<VarMap>();

  Voc8051_Simulator sim(2, 0, signals.size());
  std::cout << "numvars (signals size) : " << signals.size() << std::endl;

  for (auto varname : signals) {
    unsigned varid = varmap->addIntVar(varname);
    std::cout << "varname : " << varname << ", varid : " << varid << std::endl;
    sim.addVar(varname, varid, varid, Voc8051_Simulator::VarInfo::TERM, 0);
  }

  std::string propstr;
  while (std::getline(fs, propstr)) {
    std::cout << "parsing formula : " << propstr << " : ";
    proplist.push_back(parse_formula(propstr, varmap));
    std::cout << "[DONE]" << std::endl;
  }

  // filenames
  std::string romfile("../rom/aes_test.dat");
  std::string imgfile;

  const unsigned int aes_tg = 0;

  // simulate verilator, input is provided from STDIN of from Binary File Stream
  FILE *insource = NULL;
  if (argc == 3) {
    std::cout << "reading input from file : " << argv[2] << std::endl;
    insource = fopen(argv[2], "rb");
  } else
    insource = stdin;

  std::shared_ptr<TraceGenerator> tg = std::make_shared<TraceGenerator>(aes_tg, insource);
  // tg->addVars(signals);

  afl_init(&fid, &oldss);

  sim.run(NoTamper, romfile, imgfile, tg);
  // afl init
  sim.nextTrace();

  // second trace.
  std::cout << "simulating next trace : " << sim.getcurrTrace() << std::endl;
  OpcodeTamperer tamper(379 /* base addr */, 24 /* size */);
  sim.run(tamper, romfile, imgfile, tg);

  // check formula proplist
  TraceList traces = sim.tracelist();

  // validate formula
  for (size_t propid = 0; propid < proplist.size(); ++propid) {
    bool result = evaluateTraces(proplist[propid], traces);
    std::cout << "formula : ";
    proplist[propid]->display(std::cout);
    if (result)
      std::cout << " [SATISFIED]\n";
    else {
      violated.push_back(propid);
      std::cout << " [FAILED]\n";
    }
  }

  sim.copy_coverage();

  if (isparent) {
    std::ofstream res("result.txt");
    res << "violated property indices : " << std::endl;
    for (int i : violated) res << i << std::endl;
  }

  if (insource != stdin) fclose(insource);
  return 0;
}
