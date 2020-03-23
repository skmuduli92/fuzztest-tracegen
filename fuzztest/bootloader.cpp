#include <iostream>
#include <verilated.h>
#include "secureboot.h"
#include "Voc8051_tb.h"
#include "Voc8051_tb__Syms.h"

#include <memory>
#include <string>

// required for afl
// static int fid = 0;

int main() {
    // create top module
    std::unique_ptr<Voc8051_tb> top = std::make_unique<Voc8051_tb>();

    // afl init

    // std::stringstream oldss;
    // afl_init(&fid, &oldss);

    // filenames
    std::string romfile("../rom/secureboot.dat");
    std::string imgfile("../rom/prog.hex");
    run(top.get(), romfile, imgfile);

    // push coverage
    /*
    std::vector<uint32_t> coverageBins(
        opcode_tracker.size() + pc_tracker.size());
    std::copy(opcode_tracker.begin(), opcode_tracker.end(),
              coverageBins.begin());
    std::copy(pc_tracker.begin(), pc_tracker.end(),
              coverageBins.begin() + opcode_tracker.size());
    afl_copy(coverageBins.data(), coverageBins.size());
    */

    return 0;
}
