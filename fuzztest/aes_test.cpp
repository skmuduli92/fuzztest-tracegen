#include <iostream>
#include <verilated.h>
#include "secureboot.h"
#include "Voc8051_tb.h"
#include "Voc8051_tb__Syms.h"

#include <memory>
#include <string>

// required for afl
static int fid = 0;
static std::stringstream oldss;

struct NopTamperer : public ITamperer {
    virtual void tamper(Voc8051_tb* top);
};

void NopTamperer::tamper(Voc8051_tb* top)
{
    const int BUF_SIZE = 24;
    const int BASE_ADDR = 379;
    for(unsigned i=0; i < BUF_SIZE; i++) {
        int data;
        if (scanf("%u",  &data) != 1)  { break; }
        top->oc8051_tb__DOT__oc8051_cxrom1__DOT__buff[i + BASE_ADDR] = data;
    }
}

int main() {
    // create top module
    std::unique_ptr<Voc8051_tb> top = std::make_unique<Voc8051_tb>();

    // afl init
    afl_init(&fid, &oldss);

    // filenames
    std::string romfile("../rom/aes_test.dat");
    std::string imgfile;

    // first run.
    run(top.get(), NoTamper, romfile, imgfile);

    // second trace.
    NopTamperer tamper;
    Verilated::reset_verilator();
    reset_time_stamp();
    run(top.get(), tamper, romfile, imgfile);

    // push coverage
    std::vector<uint32_t> coverageBins(
        opcode_tracker.size() + pc_tracker.size());
    std::copy(opcode_tracker.begin(), opcode_tracker.end(),
              coverageBins.begin());
    std::copy(pc_tracker.begin(), pc_tracker.end(),
              coverageBins.begin() + opcode_tracker.size());
    afl_copy(coverageBins.data(), coverageBins.size());

    return 0;
}
