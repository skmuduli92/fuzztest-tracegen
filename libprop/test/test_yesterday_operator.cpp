
#include "formula.h"
#include "trace.h"
#include <gtest/gtest.h>

using namespace HyperPLTL;
using namespace std;


PHyperProp propertyYOperator() {
  // TODO: add new method to get varmap size
  PVarMap varmap(new VarMap());
  unsigned xIndex = varmap->addVar("x");
  unsigned yIndex = varmap->addVar("y");
  PTerm x(new TermVar(varmap, xIndex));
  PTerm y(new TermVar(varmap, yIndex));

  PHyperProp eqX(new Equal(varmap, x));
  PHyperProp eqY(new Equal(varmap, y));
  PHyperProp YesterdayEqX(new Yesterday(varmap, eqX));
  // (Y (eq x)) => (eq y)
  PHyperProp property(new Implies(varmap, YesterdayEqX, eqY));

  return property;
}

TEST(PropertyLibTest, ValidTraceYOperator) {

  PHyperProp property = propertyYOperator();

  PTrace trace1(new Trace(2));
  PTrace trace2(new Trace(2));
  TraceList tracelist({trace1, trace2});

  size_t cycle = 0;
  bool result = true;

  trace1->updateTermValue(0, cycle, 20);
  trace2->updateTermValue(0, cycle, 20);
  trace1->updateTermValue(1, cycle, rand() % 10);
  trace2->updateTermValue(1, cycle, rand() % 10);

  result = property->eval(cycle, tracelist);
  cycle = cycle + 1;

  trace1->updateTermValue(0, cycle, 20);
  trace2->updateTermValue(0, cycle, 21);
  trace1->updateTermValue(1, cycle, 10);
  trace2->updateTermValue(1, cycle, 10);

  result = property->eval(cycle, tracelist);

  // FIXME : remove this after fixing yesterday computation logic
  // eval is returning value from previous cycle

  EXPECT_TRUE(result);
}

TEST(PropertyLibTest, InvalidTraceYOperator) {
  PHyperProp property = propertyYOperator();

  PTrace trace1(new Trace(2));
  PTrace trace2(new Trace(2));
  TraceList tracelist({trace1, trace2});

  size_t cycle = 0;
  bool result = true;

  unsigned traceLength = rand() % 20 + 20;

  for ( ; cycle < traceLength; ++cycle) {
    trace1->updateTermValue(0, cycle, rand() % 100);
    trace2->updateTermValue(0, cycle, rand() % 100);
    trace1->updateTermValue(1, cycle, rand() % 100);
    trace2->updateTermValue(1, cycle, rand() % 100);
    result = property->eval(cycle, tracelist);
  }

  trace1->updateTermValue(0, cycle, 20);
  trace2->updateTermValue(0, cycle, 20);
  trace1->updateTermValue(1, cycle, 10);
  trace2->updateTermValue(1, cycle, 10);

  result = property->eval(cycle, tracelist);
  cycle = cycle + 1;

  trace1->updateTermValue(0, cycle, 20);
  trace2->updateTermValue(0, cycle, 21);
  trace1->updateTermValue(1, cycle, 10);
  trace2->updateTermValue(1, cycle, 11);

  result = property->eval(cycle, tracelist);
  cycle = cycle + 1;


  // FIXME : remove this after fixing yesterday computation logic
  // eval is returning value from previous cycle
  EXPECT_FALSE(result);
}


TEST(PropertyLibTest, InvalidTraceYeqXNeverTrue) {
  // check the property evaluation value when (Y (eq x) is never true

  PHyperProp property = propertyYOperator();

  PTrace trace1(new Trace(2));
  PTrace trace2(new Trace(2));
  TraceList tracelist({trace1, trace2});

  bool result = false;
  unsigned traceLength = rand() % 20 + 20;

  for(size_t cycle = 0; cycle < traceLength; ++cycle) {
    unsigned xvalue = rand() % 100;
    // setting 'x' var value
    trace1->updateTermValue(0, cycle, xvalue);
    xvalue = (xvalue == 50) ? 51 : (100 - xvalue);
    trace2->updateTermValue(0, cycle, xvalue);
    // setting 'y' var value
    trace1->updateTermValue(1, cycle, rand() % 100);
    trace2->updateTermValue(1, cycle, rand() % 100);
    result = property->eval(cycle, tracelist);
  }

  EXPECT_TRUE(result);
}
