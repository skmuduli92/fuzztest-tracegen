#ifndef _SECUREBOOT_H_DEFINED_
#define _SECUREBOOT_H_DEFINED_

#include <verilated.h>
#include <iostream>
#include "Voc8051_tb.h"
#include "Voc8051_tb__Syms.h"
#include "coverage.h"
#include "afl.h"

#include "trace.h"
#include "formula.h"

// addresses of the "fake" register used to update debug values.

extern ValueTracker opcode_tracker;
extern ValueTracker pc_tracker;

double sc_time_stamp();
void reset_time_stamp();

// interface for tampering.
struct ITamperer {
    virtual void tamper(Voc8051_tb* top);
};
// default tamperer.
extern ITamperer NoTamper;

class Voc8051_Simulator {
  static const int DEBUG_REG_ADDR;
  static const int DEBUG_REG_DATA; 
 protected:
  // member vars
  std::unique_ptr<Voc8051_tb> top;
  ValueTracker opcode_tracker;
  ValueTracker pc_tracker;

  // run for some number of steps.
  int simulate(long delay);
  void monitor_ports();

  Trace t1, t2;
 public:
  // constructor.
  Voc8051_Simulator(unsigned numProps, unsigned numVars)
      : top(std::make_unique<Voc8051_tb>())
      , opcode_tracker(16381, 8)
      , pc_tracker(32771, 16)
      , t1(numProps, numVars)
      , t2(numProps, numVars)
  {
  }

  // public interface.
  void reset_uc();
  void load_program(const std::string& romfile);
  void load_boot_image(const std::string& imgfile);
  void run(ITamperer& tamper, const std::string& romfile, const std::string& imgfile);
  void copy_coverage();
};



// run function.

#endif
