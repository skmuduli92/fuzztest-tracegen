#include "formula.h"
#include "trace.h"
#include <gtest/gtest.h>

using namespace HyperPLTL;
using namespace std;


PHyperProp propertyOnceOperator() {
    PVarMap varmap(new VarMap());
    unsigned xIndex = varmap->addVar("x");
    unsigned yIndex = varmap->addVar("y");
    PTerm x(new TermVar(varmap, xIndex));
    PTerm y(new TermVar(varmap, yIndex));

    PHyperProp eqX(new Equal(varmap, x));
    PHyperProp eqY(new Equal(varmap, y));
    PHyperProp andEqXEqY(new And(varmap, eqX, eqY));
    // (O (And (eqX, eqY)))
    PHyperProp property(new Once(varmap, andEqXEqY));
    return property;
}

TEST(PropertyLIbTest, ValidTraceOnceOperator) {
  PHyperProp property = propertyOnceOperator();

  PTrace trace1(new Trace(2));
  PTrace trace2(new Trace(2));
  TraceList tracelist({trace1, trace2});

  bool result = false;
  unsigned traceLength = rand() % 20 + 20;

  size_t cycle = 0;
  for(; cycle < traceLength; ++cycle) {
    unsigned xvalue = rand() % 100;
    // setting 'x' var value
    trace1->updateTermValue(0, cycle, xvalue);
    xvalue = (xvalue == 50) ? 51 : (100 - xvalue);	
    trace2->updateTermValue(0, cycle, xvalue);
    // setting 'y' var value

    unsigned yvalue = rand() % 100;
    trace1->updateTermValue(1, cycle, yvalue);
    yvalue = (yvalue == 50) ? 51 : (100 - yvalue);
    trace2->updateTermValue(1, cycle, yvalue);
    result = property->eval(cycle, tracelist);
  }

  trace1->updateTermValue(0, cycle, 10);
  trace2->updateTermValue(0, cycle, 10);
  trace1->updateTermValue(1, cycle, 11);
  trace2->updateTermValue(1, cycle, 11);
  result = property->eval(cycle, tracelist);
  cycle = cycle + 1;
  
  traceLength = rand() % 20 + 20 + cycle;
  for(; cycle < traceLength; ++cycle) {
      unsigned xvalue = rand() % 100;
      // setting 'x' var value
      trace1->updateTermValue(0, cycle, xvalue);
      xvalue = (xvalue == 50) ? 51 : (100 - xvalue);	
      trace2->updateTermValue(0, cycle, xvalue);
      // setting 'y' var value

      unsigned yvalue = rand() % 100;
      trace1->updateTermValue(1, cycle, yvalue);
      yvalue = (yvalue == 50) ? 51 : (100 - yvalue);
      trace2->updateTermValue(1, cycle, yvalue);
      result = property->eval(cycle, tracelist);
  }

  EXPECT_TRUE(result);
}

TEST(PropertyLIbTest, InvalidTraceOnceOperator) {
  PHyperProp property = propertyOnceOperator();

  PTrace trace1(new Trace(2));
  PTrace trace2(new Trace(2));
  TraceList tracelist({trace1, trace2});

  bool result = false;
  unsigned traceLength = rand() % 20 + 20;

  size_t cycle = 0;
  for(; cycle < traceLength; ++cycle) {
    unsigned xvalue = rand() % 100;
    // setting 'x' var value
    trace1->updateTermValue(0, cycle, xvalue);
    xvalue = (xvalue == 50) ? 51 : (100 - xvalue);
    trace2->updateTermValue(0, cycle, xvalue);
    // setting 'y' var value

    unsigned yvalue = rand() % 100;
    trace1->updateTermValue(1, cycle, yvalue);
    trace2->updateTermValue(1, cycle, yvalue);
    result = property->eval(cycle, tracelist);
  }
  
  traceLength = rand() % 20 + 20 + cycle;
  for(; cycle < traceLength; ++cycle) {
      unsigned xvalue = rand() % 100;
      // setting 'x' var value
      trace1->updateTermValue(0, cycle, xvalue);
      trace2->updateTermValue(0, cycle, xvalue);
      // setting 'y' var value

      unsigned yvalue = rand() % 100;
      trace1->updateTermValue(1, cycle, yvalue);
      yvalue = (yvalue == 50) ? 51 : (100 - yvalue);
      trace2->updateTermValue(1, cycle, yvalue);
      result = property->eval(cycle, tracelist);
  }

  EXPECT_TRUE(result);
}
