#ifndef __FORMULA_H_DEFINED__
#define __FORMULA_H_DEFINED__

#include <iostream>
#include <vector>
#include <memory>
#include <map>
#include <string>
#include "trace.h"

namespace HyperPLTL {
  class VarMap;
  class Formula;
  class Proposition;
  class Term;

  typedef std::shared_ptr<VarMap> PVarMap;
  typedef std::shared_ptr<Formula> PFormula;
  typedef std::shared_ptr<Proposition> PProposition;
  typedef std::shared_ptr<Term> PTerm;

  class VarMap {
    std::vector<std::string> names;
    std::map<std::string, unsigned> indices;

  public:
    const std::string& getName(unsigned i) const {
      assert(i < names.size());
      return names[i];
    }

    int getIndex(const std::string& name) const {
      auto pos = indices.find(name);
      assert (pos != indices.end());
      return pos->second;
    }

    unsigned addVar(const std::string& name) {
      unsigned idx = names.size();
      names.push_back(name);
      indices[name] = idx;
      return idx;
    }
  };

  class Formula {
  protected:
    PVarMap var_map;
    std::vector<PFormula> args;
    // constructor.
    Formula(PVarMap m) : var_map(m) {}
  public:

    // write this formula to the screen.
    virtual void display(std::ostream& out) const = 0;

  };

  class Term : public Formula {
  protected:
    Term(PVarMap m) : Formula(m) {}
  public:
    virtual ValueType value(uint32_t cycle, unsigned trace, const TraceList& traces) = 0;
  };

  class Proposition : public Formula {
  protected:
    Proposition(PVarMap m) : Formula(m) {}
  public:
    // evaluate the formula at this time index.
    virtual bool eval(uint32_t cycle, const TraceList& traces) = 0;
  };

  /** Write formula. the output stream (delegates to display). */
  std::ostream& operator<<(std::ostream& out, const Formula& t);

  /** Formula true. */
  class True : public Proposition {
  public:
    True(PVarMap m) : Proposition(m) {}

    virtual void display(std::ostream& out) const;
    virtual bool eval(uint32_t cycle, const TraceList& traces);
  };

  /** Formula var(name): this is an integer valued variable. */
  class Variable : public Term {
    unsigned index;
  public:
    Variable(PVarMap m, unsigned i)
      : Term(m)
      , index(i) 
    {}

    virtual void display(std::ostream& out) const;
    virtual ValueType value(uint32_t cycle, unsigned trace, const TraceList& traces);
  };

  /** Predicate =(v_1,v_2,v_n). */
  class Equal : public Proposition {
  public:
    Equal(PVarMap m, const std::vector<PTerm>& terms) 
      : Proposition(m)
    {
      std::copy(terms.begin(), terms.end(), std::back_inserter(args));
    }
    virtual void display(std::ostream& out) const;
    virtual bool eval(uint32_t cycle, const TraceList& traces);
  };

  /** Formula G(phi). */
  class Always : public Proposition {
    bool past;
  public:
    Always(PVarMap m, PProposition f) 
      : Proposition(m)
      , past(true)
    {
      args.push_back(f);
    }
    
    virtual void display(std::ostream& out) const;
    virtual bool eval(uint32_t cycle, const TraceList& traces);
  };

  /** Formula !a */
  class Not : public Proposition {
  public:
    Not(PVarMap m, PProposition f)
      : Proposition(m)
    {
      args.push_back(f);
    }
    virtual void display(std::ostream& out) const;
    virtual bool eval(uint32_t cycle, const TraceList& traces);
  };

  /** Formula a /\ b */
  class And : public Proposition {
  public:
    And(PVarMap m, PProposition a, PProposition b)
      : Proposition(m)
    {
      args.push_back(a);
      args.push_back(b);
    }
    And(PVarMap m, std::vector<PProposition> props)
      : Proposition(m)
    {
      std::copy(props.begin(), props.end(), std::back_inserter(args));
    }
    virtual void display(std::ostream& out) const;
    virtual bool eval(uint32_t cycle, const TraceList& traces);
  };

  /** Formula a \/ b */
  class Or : public Proposition {
  public:
    Or(PVarMap m, PProposition a, PProposition b)
      : Proposition(m)
    {
      args.push_back(a);
      args.push_back(b);
    }
    Or(PVarMap m, std::vector<PProposition> props)
      : Proposition(m)
    {
      std::copy(props.begin(), props.end(), std::back_inserter(args));
    }
    virtual void display(std::ostream& out) const;
    virtual bool eval(uint32_t cycle, const TraceList& traces);
  };

  /** Formula a => b */
  class Implies : public Proposition {
  public:
    Implies(PVarMap m, PProposition a, PProposition b)
      : Proposition(m)
    {
      args.push_back(a);
      args.push_back(b);
    }
    virtual void display(std::ostream& out) const;
    virtual bool eval(uint32_t cycle, const TraceList& traces);
  };
}

#endif
