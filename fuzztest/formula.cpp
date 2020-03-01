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
    out << "(eq ";
    for (auto arg : args) {
      arg->display(out);
      out << " ";
    }
    out << ")";
  }

  bool Equal::eval(uint32_t cycle, const TraceList& traces)
  {
    // eval not well-defined when multiple traces are available.
    assert (traces.size() > 0);
    ValueType v0 = std::dynamic_pointer_cast<Term>(args[0])->value(cycle, 0, traces);
    for (unsigned i=1; i != traces.size(); i++) {
      if (std::dynamic_pointer_cast<Term>(args[i])->value(cycle, i, traces) != v0) {
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
}
