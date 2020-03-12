#include "formula.h"
#include "trace.h"
#include <gtest/gtest.h>

using namespace HyperPLTL;
using namespace std;

PHyperProp propertyNotOperator() {
  PVarMap varmap(new VarMap());
  unsigned xIndex = varmap->addVar("x");
  PTerm x(new TermVar(varmap, xIndex));
  PHyperProp eqX(new Equal(varmap, x));
  PHyperProp notEqX(new Not(varmap, eqX));
  PHyperProp property(new Always(varmap, notEqX));
  return property;
}

TEST(PropertyLibTest, ValidTraceNotOperator) {
  PHyperProp property = propertyNotOperator();
  property->display(std::cout); std::cout << std::endl;

  PTrace trace1(new Trace(1));
  PTrace trace2(new Trace(1));
  TraceList tracelist({trace1, trace2});

  bool result = false;
  unsigned traceLength = rand() % 20 + 20;

  for(size_t cycle = 0; cycle < traceLength; ++cycle) {
    unsigned xvalue = rand() % 100;
    // setting 'x' var value
    trace1->updateTermValue(0, cycle, xvalue);
    trace2->updateTermValue(0, cycle, !xvalue);
    result = property->eval(cycle, tracelist);
  }

  EXPECT_TRUE(result);
}

TEST(PropertyLibTest, InvalidTraceNotOperator) {
  PHyperProp property = propertyNotOperator();
  property->display(std::cout); std::cout << std::endl;

  PTrace trace1(new Trace(1));
  PTrace trace2(new Trace(1));
  TraceList tracelist({trace1, trace2});

  bool result = true;
  unsigned traceLength = rand() % 20 + 20;

  for(size_t cycle = 0; cycle < traceLength; ++cycle) {
    unsigned xvalue = rand() % std::numeric_limits<unsigned>::max();
    // setting 'x' var value
    trace1->updateTermValue(0, cycle, xvalue);
    if(rand() % 2)  trace2->updateTermValue(0, cycle, !xvalue);
    else  trace2->updateTermValue(0, cycle, xvalue);  
    result = property->eval(cycle, tracelist);
  }
  
  EXPECT_FALSE(result);
}
