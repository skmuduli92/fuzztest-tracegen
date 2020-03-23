#ifndef _SECUREBOOT_H_DEFINED_
#define _SECUREBOOT_H_DEFINED_

#include <verilated.h>
#include <iostream>
#include "Voc8051_tb.h"
#include "Voc8051_tb__Syms.h"
#include "coverage.h"
#include "afl.h"

extern ValueTracker opcode_tracker;
extern ValueTracker pc_tracker;

double sc_time_stamp();
void reset_time_stamp();

int simulate(long delay, Voc8051_tb *top);
void reset_uc(Voc8051_tb* top);
void load_program(Voc8051_tb *top, const std::string& romfile);
void load_boot_image(Voc8051_tb* top, const std::string& imgfile);
void no_tamper(void);

// interface for tampering.
struct ITamperer {
    virtual void tamper(Voc8051_tb* top);
};
// default tamperer.
extern ITamperer NoTamper;

// run function.
void run(Voc8051_tb* top, ITamperer& tamper, const std::string& romfile, const std::string& imgfile);

#endif
