#ifndef __FORMULA_H_DEFINED__
#define __FORMULA_H_DEFINED__

#include <iostream>
#include <vector>
#include <memory>
#include <map>
#include <string>
#include "trace.h"

namespace HyperPLTL {
  class VarMap {
    std::vector<std::string> names;
    std::map<std::string, unsigned> indices;

    const std::string& getName(unsigned i) const {
      assert(i < names.size());
      return names[i];
    }

    const std::string& getIndex(const std::string& name) const {
      auto pos = indices.find(name);
      assert (pos != indices.end());
      return pos->second;
    }
  };

  class Formula{
  public:
    std::vector<std::shared_ptr<Formula>> args;

    // write this formula to the screen.
    virtual void display(std::ostream& out) const = 0;
    // evaluate the formula at this time index.
    virtual bool eval(uint32_t cycle, const TraceList& traces) = 0;

  };

  /** Write formula. the output stream (delegates to display). */
  std::ostream& operator<<(std::ostream& out, const Formula& t);

  /** Formula true. */
  class True : public Formula {
  public:
    True() {}

    virtual void display(std::ostream& out) const;
    virtual bool eval(uint32_t cycle, const TraceList& traces);
  };

  /** Formula var(name). */
  class Variable : public Formula {
    std::string name;
  public:
    Variable(const char* n) :  name(n) {}
    Variable(const std::string& n) : name(n) {}
  };
}

#endif
