#include "formula.h"

namespace HyperPLTL {
  std::ostream& operator<<(std::ostream& out, const Formula& t)
  {
    t.display(out);
    return out;
  }

  void True::display(std::ostream& out) const {
    out << "true";
  }

  void True::eval(uint32_t cycle, const TraceList& traces) {
    return true;
  }
}
