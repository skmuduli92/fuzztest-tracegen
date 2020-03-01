#include "formula.h"

namespace HyperPLTL {
  std::ostream& operator<<(std::ostream& out, const Formula& t)
  {
    t.display(out);
    return out;
  }

  // ---------------------------------------------------------------------- //
  //                               class True                               //
  // ---------------------------------------------------------------------- //
  void True::display(std::ostream& out) const {
    out << "true";
  }

  bool True::eval(uint32_t cycle, const TraceList& traces) {
    return true;
  }

  // ---------------------------------------------------------------------- //
  //                           class Variable                               //
  // ---------------------------------------------------------------------- //
  void Variable::display(std::ostream& out) const
  {
    out << var_map->getName(index);
  }

  ValueType Variable::value(uint32_t cycle, unsigned trace, const TraceList& traces)
  {
    // eval not well-defined when multiple traces are available.
    assert (traces.size() > trace);
    return traces[trace]->valueAt(index, cycle);
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
    ValueType v0 = std::dynamic_pointer_cast<Term>(
                        args[0])->value(cycle, 0, traces);
    for (unsigned i=1; i != traces.size(); i++) {
      if (std::dynamic_pointer_cast<Term>(
                  args[i])->value(cycle, i, traces) != v0) 
      {
        return false;
      }
    }
    return true;
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
    PProposition f = std::dynamic_pointer_cast<Proposition>(args[0]);
    return (past = past && f->eval(cycle, traces));
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
    auto p = dynamic_pointer_cast<Proposition>(args[0]);
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
    bool r = true;
    for (auto arg : args) {
      PProposition p = std::dynamic_pointer_cast<Proposition>(arg);
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

  bool Or ::eval(uint32_t cycle, const TraceList& traces)
  {
    bool r = false;
    for (auto arg : args) {
      PProposition p = std::dynamic_pointer_cast<Proposition>(arg);
      r = r || p->eval(cycle, traces);
    }
    return r;
  }

  // ---------------------------------------------------------------------- //
  //                        class Implies                                  //
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
    PProposition p1 = std::dynamic_pointer_cast<Proposition>(args[0]);
    PProposition p2 = std::dynamic_pointer_cast<Proposition>(args[1]);
    return (!p1->eval(cycle, traces) || p2->eval(cycle, traces));
  }
}
