#ifndef _SECUREBOOT_H_DEFINED_
#define _SECUREBOOT_H_DEFINED_

#include <verilated.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include "Voc8051_tb.h"
#include "Voc8051_tb__Syms.h"
#include "afl.h"
#include "coverage.h"

#include "formula.h"
#include "tamper.h"
#include "trace.h"

#define NUM_TRACES 300

extern unsigned trid;

class TraceGenerator;

extern vluint64_t main_time;

double sc_time_stamp();
void reset_time_stamp();

class Voc8051_Simulator {
  static const int DEBUG_REG_ADDR;
  static const int DEBUG_REG_DATA;

 protected:
  // member vars
  std::shared_ptr<Voc8051_tb> top;
  ValueTracker tracker;

  // run for some number of steps.
  int simulate(std::shared_ptr<TraceGenerator>& tg, long delay);
  void monitor_ports();
  void monitor_debug_registers();

  TraceList traces;

 public:
  // Information about a particular variable.
  struct VarInfo {
    std::string name;
    unsigned traceIndex;
    unsigned debugIndex;
    enum Type { PROPOSITION, TERM } type;
    // Constructor.
    VarInfo(const std::string& n, unsigned trcIdx, unsigned dbgIdx, Type t)
        : name(n), traceIndex(trcIdx), debugIndex(dbgIdx), type(t) {}
  };

 protected:
  typedef std::shared_ptr<VarInfo> PVarInfo;
  // Map from variables to VarInfo objects.
  std::map<std::string, PVarInfo> varNames;
  // Map from debug indices to  VarInfo objects.
  std::map<unsigned, PVarInfo> varIndices;
  // current trace
  unsigned trace;

 public:
  // constructor.
  Voc8051_Simulator(unsigned numTraces, unsigned numProps, unsigned numVars)
      : top(std::make_shared<Voc8051_tb>()), tracker(65536), trace(0) {
    tracker.add(21841, 8);
    tracker.add(21841, 16);
    tracker.add(21841, 32);

    for (unsigned i = 0; i != numTraces; i++) {
      traces.push_back(PTrace(new Trace(numProps, numVars)));
    }
  }

  // public interface methods.

  void addVar(const std::string& name, unsigned traceIndex, unsigned debugIndex, VarInfo::Type t, uint64_t init) {
    PVarInfo varInfo(new VarInfo(name, traceIndex, debugIndex, t));
    varNames.insert(std::make_pair(name, varInfo));
    varIndices.insert(std::make_pair(debugIndex, varInfo));
    for (unsigned i = 0; i != traces.size(); i++) {
      setVar(i, debugIndex, 0, init);
    }
  }

  void setVar(unsigned t, unsigned dbgIndex, uint32_t time, uint64_t value) {
    auto pos = varIndices.find(dbgIndex);
    assert(pos != varIndices.end());
    PVarInfo inf = pos->second;
    if (inf->type == VarInfo::PROPOSITION) {
      traces[t]->updatePropValue(inf->traceIndex, time, value != 0);
    } else {
      traces[t]->updateTermValue(inf->traceIndex, time, value);
    }
  }

  /** Inline function to be called before the tampering begins. */
  void nextTrace() {
    Verilated::reset_verilator();
    reset_time_stamp();
    trace++;
    assert(trace < traces.size());
  }

  void reset_uc(std::shared_ptr<TraceGenerator>& tg);
  void load_program(const std::string& romfile);
  void load_boot_image(const std::string& imgfile);

  void run(ITamperer& tamper, const std::string& romfile, const std::string& imgfile, std::shared_ptr<TraceGenerator>& tg);

  void copy_coverage();

  /** Function that evaluates whether the property is true or not. */
  bool evaluate(HyperPLTL::PHyperProp f);
};

class TraceGenerator {

  std::vector<std::ofstream> int_facts;
  std::map<std::string, unsigned> intvar2id;
  std::vector<std::string> filenames;

  uint32_t addr_store;

  void tracegen_aes(std::shared_ptr<Voc8051_tb> top);           // id = 0
  void tracegen_sha(std::shared_ptr<Voc8051_tb> top);           // id = 1
  void tracegen_page_table(std::shared_ptr<Voc8051_tb> top);    // id = 2
  void tracegen_rsa(std::shared_ptr<Voc8051_tb> top);           // id = 3
  void tracegen_exp(std::shared_ptr<Voc8051_tb> top);           // id = 4
  void tracegen_meminterface(std::shared_ptr<Voc8051_tb> top);  // id = 5

 public:
  static const int DEBUG_REG_ADDR;
  static const int DEBUG_REG_DATA;
  static const int MAX_TRACES;
  static const uint32_t RESET_TIME;
  //  static uint32_t trid;

  // based on this ID one of the functions will be called
  unsigned tracegenID;

  TraceGenerator(unsigned id) : tracegenID(id), addr_store(0) {}

  void tracegen_main(std::shared_ptr<Voc8051_tb> top);

  void recordSignal(std::string const& sname, uint32_t traceId, uint64_t time, int64_t value);

  void randomizeData(std::shared_ptr<Voc8051_tb> top);
  void randomizeData_page_table(std::shared_ptr<Voc8051_tb> top);
  void randomizeData_aes(std::shared_ptr<Voc8051_tb> top);
  void randomizeData_sha(std::shared_ptr<Voc8051_tb> top);
  void randomizeData_rsa(std::shared_ptr<Voc8051_tb> top);
  void randomizeData_exp(std::shared_ptr<Voc8051_tb> top);
  void randomizeData_wr(std::shared_ptr<Voc8051_tb> top);
  void tracegen_wr(std::shared_ptr<Voc8051_tb> top);
  //  void tracegen_rsa(std::shared_ptr<Voc8051_tb> top);

  void addVars(std::vector<std::string> const& intvars);

  std::string genFileName(std::string const& varname);

  std::string genFileName(std::string const& varname, bool fact);

  void closeall() {
    for (std::ofstream& fs : int_facts) fs.close();
  }
};

#endif
