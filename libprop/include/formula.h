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
  class TraceProp;
  class HyperProp;
  class Term;

  typedef std::shared_ptr<VarMap> PVarMap;
  typedef std::shared_ptr<Formula> PFormula;
  typedef std::shared_ptr<TraceProp> PTraceProp;
  typedef std::shared_ptr<HyperProp> PHyperProp;
  typedef std::shared_ptr<Term> PTerm;

  class VarMap {
    std::vector<std::string> varNames;
    std::map<std::string, unsigned> varIndices;
    std::vector<std::string> propNames;
    std::map<std::string, unsigned> propIndices;

  public:

    unsigned addProp(const std::string& name);
    unsigned addVar(const std::string& name);
    const std::string& getPropName(unsigned i) const;
    int getPropIndex(const std::string& name) const;
    const std::string& getVarName(unsigned i) const;
    int getVarIndex(const std::string& name) const;
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

  // integer-sorted terms.
  class Term : public Formula {
  protected:
    Term(PVarMap m) : Formula(m) {}
  public:
    virtual ValueType termValue(uint32_t cycle, unsigned trace, const TraceList& traces) = 0;
  };

  // trace propositions (booleans).
  class TraceProp : public Formula {
  protected:
    TraceProp(PVarMap m) : Formula(m) {}
  public:
    // evaluate the proposition in a particular trace.
    virtual bool propValue(uint32_t cycle, unsigned trace, const TraceList& traces) = 0;
  };

  // hyper-propositions (defined over multiple traces).
  class HyperProp : public Formula {
  protected:
    HyperProp(PVarMap m) : Formula(m) {}
  public:
    // evaluate the formula at this time index.
    virtual bool eval(uint32_t cycle, const TraceList& traces) = 0;
  };

  /** Formula TermVar(name): this is an integer valued variable. */
  class TermVar : public Term {
    unsigned index;
  public:
    TermVar(PVarMap m, unsigned i)
      : Term(m)
      , index(i) 
    {}

    virtual void display(std::ostream& out) const;
    virtual ValueType termValue(uint32_t cycle, unsigned trace, const TraceList& traces);
  };

  /** Formula PropVar(name): this is a boolean variable. */
  class PropVar : public TraceProp {
    unsigned index;
  public:
    PropVar(PVarMap m, unsigned i)
      : TraceProp(m)
      , index(i)
    {}

    virtual void display(std::ostream& out) const;
    virtual bool propValue(uint32_t cycle, unsigned trace, const TraceList& traces);
  };

  /** Formula true. */
  class True : public TraceProp {
  public:
    True(PVarMap m) : TraceProp(m) {}

    virtual void display(std::ostream& out) const;
    virtual bool propValue(uint32_t cycle, unsigned trace, const TraceList& traces);
  };


  
  /** Predicate (eq v_1,v_2,...,v_n). */
  class Equal : public HyperProp {
  public:
    Equal(PVarMap m, PTerm term) 
      : HyperProp(m)
    {
      args.push_back(term);
    }
    virtual void display(std::ostream& out) const;
    virtual bool eval(uint32_t cycle, const TraceList& traces);
  };

  /** TraceSelect. */
  class TraceSelect : public HyperProp {
    unsigned trace;
  public:
    TraceSelect(PVarMap m, unsigned tr, PTraceProp p)
      : HyperProp(m)
      , trace(tr)
    {
      args.push_back(p);
    }
    virtual void display(std::ostream& out) const;
    virtual bool eval(uint32_t cycle, const TraceList& traces);
  };

  /** Formula !a */
  class Not : public HyperProp {
  public:
    Not(PVarMap m, PHyperProp f)
      : HyperProp(m)
    {
      args.push_back(f);
    }
    virtual void display(std::ostream& out) const;
    virtual bool eval(uint32_t cycle, const TraceList& traces);
  };

  /** Formula a /\ b */
  class And : public HyperProp {
  public:
    And(PVarMap m, PHyperProp a, PHyperProp b)
      : HyperProp(m)
    {
      args.push_back(a);
      args.push_back(b);
    }
    And(PVarMap m, std::vector<PHyperProp> props)
      : HyperProp(m)
    {
      std::copy(props.begin(), props.end(), std::back_inserter(args));
    }
    virtual void display(std::ostream& out) const;
    virtual bool eval(uint32_t cycle, const TraceList& traces);
  };

  /** Formula a \/ b */
  class Or : public HyperProp {
  public:
    Or(PVarMap m, PHyperProp a, PHyperProp b)
      : HyperProp(m)
    {
      args.push_back(a);
      args.push_back(b);
    }
    Or(PVarMap m, std::vector<PHyperProp> props)
      : HyperProp(m)
    {
      std::copy(props.begin(), props.end(), std::back_inserter(args));
    }
    virtual void display(std::ostream& out) const;
    virtual bool eval(uint32_t cycle, const TraceList& traces);
  };

  /** Formula a => b */
  class Implies : public HyperProp {
  public:
    Implies(PVarMap m, PHyperProp a, PHyperProp b)
      : HyperProp(m)
    {
      args.push_back(a);
      args.push_back(b);
    }
    virtual void display(std::ostream& out) const;
    virtual bool eval(uint32_t cycle, const TraceList& traces);
  };

  
  /** Formula G(phi). */
  class Always : public HyperProp {
    bool past;
  public:
    Always(PVarMap m, PHyperProp f) 
      : HyperProp(m)
      , past(true)
    {
      args.push_back(f);
    }
    
    virtual void display(std::ostream& out) const;
    virtual bool eval(uint32_t cycle, const TraceList& traces);
  };


  class Yesterday : public HyperProp {
      bool present;
  public:
      Yesterday(PVarMap m, PHyperProp f)
	  : HyperProp(m)
	  , present(false)
      {
        args.push_back(f);
      }

      virtual void display(std::ostream& out) const;
      virtual bool eval(uint32_t cycle, const TraceList& traces);
  };

  class Once : public HyperProp {
      bool valid;
    public:
      Once(PVarMap m, PHyperProp f)
	  : HyperProp(m), valid(false)
	  {
	      args.push_back(f);
	  }

      virtual void display(std::ostream& out) const;
      virtual bool eval(uint32_t cycle, const TraceList& traces);
  };

}

#endif
