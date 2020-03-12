#include "formula.h"

namespace HyperPLTL {
    
  std::ostream& operator<<(std::ostream& out, const Formula& t)
  {
    t.display(out);
    return out;
  }

  //////////////////////////////////////////////
  // VarMap class member function definitions //
  //////////////////////////////////////////////

  const std::string& VarMap::getVarName(unsigned i) const {
    assert(i < varNames.size());
    return varNames[i];
  }

  int VarMap::getVarIndex(const std::string& name) const {
    auto pos = varIndices.find(name);
    assert (pos != varIndices.end());
    return pos->second;
  }

  unsigned  VarMap::addVar(const std::string& name) {
    unsigned idx = varNames.size();
    varNames.push_back(name);
    varIndices[name] = idx;
    return idx;
  }

  const std::string&  VarMap::getPropName(unsigned i) const {
    assert(i < propNames.size());
    return propNames[i];
  }

  int  VarMap::getPropIndex(const std::string& name) const {
    auto pos = propIndices.find(name);
    assert (pos != propIndices.end());
    return pos->second;
  }

  unsigned  VarMap::addProp(const std::string& name) {
    unsigned idx = propNames.size();
    propNames.push_back(name);
    propIndices[name] = idx;
    return idx;
  }

  // ---------------------------------------------------------------------- //
  //                               class True                               //
  // ---------------------------------------------------------------------- //
  void True::display(std::ostream& out) const {
    out << "true";
  }

  bool True::propValue(uint32_t cycle, unsigned trace, const TraceList& traces) {
    return true;
  }

  // ---------------------------------------------------------------------- //
  //                            class TermVar                               //
  // ---------------------------------------------------------------------- //
  void TermVar::display(std::ostream& out) const
  {
    out << var_map->getVarName(index);
  }

  ValueType TermVar::termValue(uint32_t cycle, unsigned trace, const TraceList& traces)
  {
    assert (traces.size() > trace);
    return traces[trace]->termValueAt(index, cycle);
  }

  // ---------------------------------------------------------------------- //
  //                            class PropVar                               //
  // ---------------------------------------------------------------------- //
  void PropVar::display(std::ostream& out) const
  {
    out << var_map->getPropName(index);
  }

  bool PropVar::propValue(uint32_t cycle, unsigned trace, const TraceList& traces)
  {
    // eval not well-defined when multiple traces are available.
    assert(trace < traces.size());
    return traces[trace]->propValueAt(index, cycle);
  }

  // ---------------------------------------------------------------------- //
  //                             class Equal                                //
  // ---------------------------------------------------------------------- //
  void Equal::display(std::ostream& out) const
  {
    out << "(eq";
    for (auto arg : args) {
      out << " ";
      arg->display(out);
    }
    out << ")";
  }

  bool Equal::eval(uint32_t cycle, const TraceList& traces)
  {
    // eval not well-defined when multiple traces are available.
    assert (traces.size() > 0);
    PTerm arg = std::dynamic_pointer_cast<Term>(args[0]);
    ValueType v0 = arg->termValue(cycle, 0, traces);
    
    for (unsigned i = 1; i != traces.size(); i++) {
      if (arg->termValue(cycle, i, traces) != v0)
          return false;
    }
    return true;
  }

  // ---------------------------------------------------------------------- //
  //                          class TraceSelect                             //
  // ---------------------------------------------------------------------- //
  void TraceSelect::display(std::ostream& out) const
  {
    out << "(trace-select " << trace << " ";
    args[0]->display(out);
    out << ")";
  }

  bool TraceSelect::eval(uint32_t cycle, const TraceList& traces)
  {
    auto p = std::dynamic_pointer_cast<TraceProp>(args[0]);
    return p->propValue(cycle, trace, traces);
  }

  // ---------------------------------------------------------------------- //
  //                              class Not                                 //
  // ---------------------------------------------------------------------- //
  void Not::display(std::ostream& out) const
  {
    out << "(not ";
    args[0]->display(out);
    out << ")";
  }

  bool Not::eval(uint32_t cycle, const TraceList& traces)
  {
    using namespace std;
    auto p = dynamic_pointer_cast<HyperProp>(args[0]);
    return !p->eval(cycle, traces);
  }

  // ---------------------------------------------------------------------- //
  //                              class And                                 //
  // ---------------------------------------------------------------------- //
  void And::display(std::ostream& out) const
  {
    out << "(and ";
    for (auto arg : args) {
      out << " ";
      arg->display(out);
    }
    out << ")";
  }

  bool And::eval(uint32_t cycle, const TraceList& traces)
  {
    using namespace std;
    bool r = true;
    for (auto arg : args) {
      auto p = dynamic_pointer_cast<HyperProp>(arg);
      r = r && p->eval(cycle, traces);
    }
    return r;
  }

  // ---------------------------------------------------------------------- //
  //                              class Or                                  //
  // ---------------------------------------------------------------------- //
  void Or ::display(std::ostream& out) const
  {
    out << "(or ";
    for (auto arg : args) {
      out << " ";
      arg->display(out);
    }
    out << ")";
  }

  bool Or::eval(uint32_t cycle, const TraceList& traces)
  {
    bool r = false;
    for (auto arg : args) {
      auto p = std::dynamic_pointer_cast<HyperProp>(arg);
      r = r || p->eval(cycle, traces);
    }
    return r;
  }

  // ---------------------------------------------------------------------- //
  //                        class Implies                                   //
  // ---------------------------------------------------------------------- //
  void Implies ::display(std::ostream& out) const
  {
    out << "(=> ";
    for (auto arg : args) {
      out << " ";
      arg->display(out);
    }
    out << ")";
  }

  bool Implies ::eval(uint32_t cycle, const TraceList& traces)
  {
    auto p1 = std::dynamic_pointer_cast<HyperProp>(args[0]);
    auto p2 = std::dynamic_pointer_cast<HyperProp>(args[1]);
    return (!p1->eval(cycle, traces)) || p2->eval(cycle, traces);
  }

  
  // ---------------------------------------------------------------------- //
  //                            class Always                                //
  // ---------------------------------------------------------------------- //

  void Always::display(std::ostream& out) const
  {
    out << "(G ";
    args[0]->display(out);
    out << ")";
  }

  bool Always::eval(uint32_t cycle, const TraceList& traces)
  {
    auto f = std::dynamic_pointer_cast<HyperProp>(args[0]);
    past = past && f->eval(cycle, traces);
    return past;
  }
  
  // ---------------------------------------------------------------------- //
  //                        class Yesterday                                 //
  // ---------------------------------------------------------------------- //

  void Yesterday::display(std::ostream& out) const {
    out << "(Y ";
    args[0]->display(out);
    out << ")";
  }

  bool Yesterday::eval(uint32_t cycle, const TraceList& traces) {

    // FIXME : need to fix yesterday computation logic or trace compression
    // mechanism, the evaluation seems to be returning past values

    auto f = std::dynamic_pointer_cast<HyperProp>(args[0]);
    bool past = present;
    present = f->eval(cycle, traces);
    return past;
  }

  // ---------------------------------------------------------------------- //
  //                        class once                                      //
  // ---------------------------------------------------------------------- //

  void Once::display(std::ostream& out) const {
    out << "(O ";
    args[0]->display(out);
    out << ")";
  }

  bool Once::eval(uint32_t cycle, const TraceList& traces) {
    auto f = std::dynamic_pointer_cast<HyperProp>(args[0]);
    valid = valid || f->eval(cycle, traces);
    return valid;
  }

  // ---------------------------------------------------------------------- //
  //                        class since                                     //
  // ---------------------------------------------------------------------- //

  void Since::display(std::ostream& out) const {
    out << "(S ";
    args[0]->display(out);
    args[1]->display(out);
    out << ")";
  }

  bool Since::eval(uint32_t cycle, const TraceList& traces) {
    // S(f1, f2)
    auto f1 = std::dynamic_pointer_cast<HyperProp>(args[0]);
    auto f2 = std::dynamic_pointer_cast<HyperProp>(args[1]);

    if (validF2 == false) {
      validF2 = f2->eval(cycle, traces);
    } else {
      // if f2 has become true once, need to check if f1 is true there onwards
      if(f1->eval(cycle, traces)) return true;
      else return false;
    }

    return false;
  }
  
}
