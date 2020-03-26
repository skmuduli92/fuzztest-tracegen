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

  Trace t0, t1;

  // Information about a particular variable.
  struct VarInfo {
      std::string name;
      unsigned traceIndex;
      unsigned debugIndex;
      enum Type { PROPOSITION, TERM } type;
      // Constructor.
      VarInfo(const std::string& n,
              unsigned trcIdx, unsigned dbgIdx,
              Type t)
       : name(n)
       , traceIndex(trcIdx)
       , debugIndex(dbgIdx)
       , type(t)
      {
      }
  };
  typedef std::shared_ptr<VarInfo> PVarInfo;
  // Map from variables to VarInfo objects.
  std::map<std::string, PVarInfo> varNames;
  // Map from debug indices to  VarInfo objects.
  std::map<unsigned, PVarInfo> varIndices;
  // current trace
  unsigned trace;
 public:
  // constructor.
  Voc8051_Simulator(unsigned numProps, unsigned numVars)
      : top(std::make_unique<Voc8051_tb>())
      , opcode_tracker(16381, 8)
      , pc_tracker(32771, 16)
      , t0(numProps, numVars)
      , t1(numProps, numVars)
      , trace(0)
  {
  }

  // public interface methods.

  void addVar(const std::string& name, unsigned traceIndex, unsigned debugIndex, VarInfo::Type t, uint64_t init) 
  {
    PVarInfo varInfo(
      new VarInfo(name, traceIndex, debugIndex, t));
    varNames.insert(std::make_pair(name, varInfo));
    varIndices.insert(std::make_pair(debugIndex, varInfo));
    setVar(0, debugIndex, 0, init);
    setVar(1, debugIndex, 0, init);
  }

  void setVar(unsigned trace, unsigned dbgIndex, uint32_t time, uint64_t value)
  {
    auto pos = varIndices.find(dbgIndex);
    assert (pos != varIndices.end());
    PVarInfo inf = pos->second;
    Trace& t(trace == 0 ? t0 : t1);
    if (inf->type == VarInfo::PROPOSITION) {
      t.updatePropValue(inf->traceIndex, time, value != 0);
    } else {
      t.updateTermValue(inf->traceIndex, time, value);
    }
  }

  void reset_uc();
  void load_program(const std::string& romfile);
  void load_boot_image(const std::string& imgfile);
  void run(ITamperer& tamper, const std::string& romfile, const std::string& imgfile);
  void copy_coverage();
};



// run function.

#endif
