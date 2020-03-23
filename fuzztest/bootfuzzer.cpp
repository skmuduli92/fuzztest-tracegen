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

struct FSMWriteTamperer : public ITamperer {
    virtual void tamper(Voc8051_tb* top);
};

void FSMWriteTamperer::tamper(Voc8051_tb* top)
{
    const int BUF_SIZE = 16;
    for(unsigned i=0; i < BUF_SIZE; i++) {
        top->oc8051_tb__DOT__fsm_writer_i__DOT__buf_addr[i] = 0;
        top->oc8051_tb__DOT__fsm_writer_i__DOT__buf_data[i] = 0;
        top->oc8051_tb__DOT__fsm_writer_i__DOT__buf_delay[i] = 0;
    }
    for(unsigned i=0; i < BUF_SIZE; i++) {
        uint16_t addr, delay;
        int data;
        if (scanf("%hx", &addr) != 1)  { break; }
        if (scanf("%u",  &data) != 1)  { break; }
        if (scanf("%hu", &delay) != 1) { break; }
        printf("%hx -> %u @ %hu\n", addr, data, delay);
        top->oc8051_tb__DOT__fsm_writer_i__DOT__buf_addr[i] = addr;
        top->oc8051_tb__DOT__fsm_writer_i__DOT__buf_data[i] = data;
        top->oc8051_tb__DOT__fsm_writer_i__DOT__buf_delay[i] = delay;
    }
}

int main() {
    // create top module
    std::unique_ptr<Voc8051_tb> top = std::make_unique<Voc8051_tb>();

    // afl init
    afl_init(&fid, &oldss);

    // filenames
    std::string romfile("../rom/secureboot.dat");
    std::string imgfile("../rom/prog.hex");

    // first run.
    run(top.get(), NoTamper, romfile, imgfile);

    // second trace.
    FSMWriteTamperer tamper;
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
