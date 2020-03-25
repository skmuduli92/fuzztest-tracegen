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
    Voc8051_Simulator sim(0, 0);

    // afl init
    afl_init(&fid, &oldss);

    // filenames
    std::string romfile("../rom/secureboot.dat");
    std::string imgfile("../rom/prog.hex");

    // first run.
    sim.run(NoTamper, romfile, imgfile);

    // second trace.
    FSMWriteTamperer tamper;
    Verilated::reset_verilator();
    reset_time_stamp();
    sim.run(tamper, romfile, imgfile);

    // push coverage
    sim.copy_coverage();

    return 0;
}
