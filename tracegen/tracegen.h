#ifndef __TRACEGEN_H__
#define __TRACEGEN_H__

#include <algorithm>
#include <cassert>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <random>
#include <string>
#include <vector>

/// Utility to handle trace file generation
/// TODO : improve the overall design and make it more useful :P

#define RESET_TIME 20

enum class VarType { BOOL_VAL, INT_VAL };

class TraceGen {
 protected:
  std::vector<std::ofstream> int_facts;

  // std::map<std::string, unsigned> var2idMap;
  std::vector<std::string> filenames;
  std::vector<std::string> varnames;

  std::vector<std::string> intvars;
  std::vector<std::string> boolvars;

  std::map<std::string, unsigned> intvar2id;
  std::map<std::string, unsigned> boolvar2id;

 public:
  TraceGen() {}

  // void addBoolVars(std::vector<std::string> const& bvs) {
  //   boolvars = bvs;
  //   for (std::string const& var : boolvars) {
  //     boolvar2id[var] = false_facts.size();
  //     false_facts.push_back(std::ofstream(genFileName(var, false)));
  //     true_facts.push_back(std::ofstream(genFileName(var, true)));
  //   }
  // }

  void addIntVars(std::vector<std::string> const& ivs) {
    intvars = ivs;
    for (std::string const& var : intvars) {
      intvar2id[var] = int_facts.size();
      int_facts.push_back(std::ofstream(genFileName(var)));
    }
  }

  void closeall() {
    // for (std::ofstream& fs : false_facts) fs.close();
    // for (std::ofstream& fs : true_facts) fs.close();
    for (std::ofstream& fs : int_facts) fs.close();
  }

  // inline size_t getTraceLen() { return TraceLen; }

  unsigned getVarIndex(std::string const& varname) {
    auto it = std::find(varnames.begin(), varnames.end(), varname);
    assert(it != varnames.end());
    return (it - varnames.begin());
  }

  std::string genFileName(std::string const& varname, bool fact) {
    std::string fname = varname + "_";

    if (fact)
      fname += "true.facts";
    else
      fname += "false.facts";

    filenames.push_back(fname);
    return fname;
  }

  std::string genFileName(std::string const& varname) {
    std::string fname = varname + ".facts";
    filenames.push_back(fname);
    return fname;
  }

  inline unsigned getRandUInt() { return rand() % std::numeric_limits<unsigned>::max(); }

  unsigned getRandUInt(unsigned exclNum) {
    unsigned threshold = 10;
    unsigned newRandUInt = 0;

    while (threshold--) {
      newRandUInt = getRandUInt();
      if (exclNum != newRandUInt) break;
    }
    assert(threshold);
    return newRandUInt;
  }

  void recordIntSignal(std::string const& sname, uint32_t traceId, uint64_t time,
                       int64_t value);
  /// destrcutor shall close all opened ofstreams
  ~TraceGen() { closeall(); }
};

#endif
