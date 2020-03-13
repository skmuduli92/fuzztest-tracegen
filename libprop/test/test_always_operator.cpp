#include "formula.h"
#include "trace.h"
#include <gtest/gtest.h>

using namespace HyperPLTL;
using namespace std;


PHyperProp property1AlwaysOperator() {
  PVarMap varmap(new VarMap());
  unsigned xIndex = varmap->addVar("x");
  PTerm x(new TermVar(varmap, xIndex));

  PHyperProp eqX(new Equal(varmap, x));
  PHyperProp property(new Always(varmap, eqX));
  return property;
}

PHyperProp property2AlwaysOperator() {
  PVarMap varmap(new VarMap());
  unsigned xIndex = varmap->addVar("x");
  unsigned yIndex = varmap->addVar("y");
  PTerm x(new TermVar(varmap, xIndex));
  PTerm y(new TermVar(varmap, yIndex));

  PHyperProp eqX(new Equal(varmap, x));
  PHyperProp eqY(new Equal(varmap, y));
  PHyperProp eqX_OR_eqY(new Or(varmap, eqX, eqY));
  // (G (Or (eqX, eqY)))
  PHyperProp property(new Always(varmap, eqX_OR_eqY));
  return property;
}

TEST(PropertyLibTest, ValidTraceAlwaysOperator_Test1) {
  PHyperProp property = property1AlwaysOperator();

  PTrace trace1(new Trace(1));
  PTrace trace2(new Trace(1));
  TraceList tracelist({trace1, trace2});

  bool result = false;
  unsigned traceLength = rand() % 20 + 20;

  // tr1.x is always equal to tr2.x
  unsigned xvalue = 0;
  for (size_t cycle = 0; cycle < traceLength; ++cycle) {
    xvalue = rand() % std::numeric_limits<unsigned>::max();
    trace1->updateTermValue(0, cycle, xvalue);
    trace2->updateTermValue(0, cycle, xvalue);
    result = property->eval(cycle, tracelist);
  }
  
  EXPECT_TRUE(result);
}

TEST(PropertyLibTest, InvalidTraceAlwaysOperator_Test1) {
  PHyperProp property = property1AlwaysOperator();

  PTrace trace1(new Trace(1));
  PTrace trace2(new Trace(1));
  TraceList tracelist({trace1, trace2});

  bool result = false;
  unsigned traceLength = rand() % 20 + 20;
  size_t cycle = 0;
    
  // tr1.x is always equal to tr2.x
  unsigned xvalue = 0;
  for (; cycle < traceLength; ++cycle) {
    xvalue = rand() % std::numeric_limits<unsigned>::max();
    trace1->updateTermValue(0, cycle, xvalue);
    trace2->updateTermValue(0, cycle, xvalue);
    result = property->eval(cycle, tracelist);
  }

  trace1->updateTermValue(0, cycle, xvalue);
  trace2->updateTermValue(0, cycle, !xvalue);
  result = property->eval(cycle, tracelist);
  
  EXPECT_FALSE(result);
}

TEST(PropertyLibTest, ValidTraceAlwaysOperator_Test2) {

  // (G (Or (eqX, eqY)))
  PHyperProp property = property2AlwaysOperator();

  PTrace trace1(new Trace(2));
  PTrace trace2(new Trace(2));
  TraceList tracelist({trace1, trace2});

  bool result = false;
  unsigned traceLength = rand() % 20 + 20;

  // tr1.x is always equal to tr2.x
  for (size_t cycle = 0; cycle < traceLength; ++cycle) {
    unsigned xvalue = rand() % std::numeric_limits<unsigned>::max();
    unsigned yvalue = rand() % std::numeric_limits<unsigned>::max();
    
    if(cycle % 3 == 0) {
      trace1->updateTermValue(0, cycle, xvalue);
      trace2->updateTermValue(0, cycle, xvalue);
      trace1->updateTermValue(1, cycle, yvalue);
      trace2->updateTermValue(1, cycle, yvalue);
    }
    else if(cycle % 3 == 1) {
      trace1->updateTermValue(0, cycle, xvalue);
      trace2->updateTermValue(0, cycle, !xvalue);
      trace1->updateTermValue(1, cycle, yvalue);
      trace2->updateTermValue(1, cycle, yvalue);
    }
    else {
      trace1->updateTermValue(0, cycle, xvalue);
      trace2->updateTermValue(0, cycle, xvalue);
      trace1->updateTermValue(1, cycle, yvalue);
      trace2->updateTermValue(1, cycle, !yvalue);
    }

    result = property->eval(cycle, tracelist);
  }
  
  EXPECT_TRUE(result);
}


TEST(PropertyLibTest, InvalidTraceAlwaysOperator_Test2) {

  // (G (Or (eqX, eqY)))
  PHyperProp property = property2AlwaysOperator();

  PTrace trace1(new Trace(2));
  PTrace trace2(new Trace(2));
  TraceList tracelist({trace1, trace2});

  bool result = false;
  unsigned traceLength = rand() % 20 + 20;

  for (size_t cycle = 0; cycle < traceLength; ++cycle) {
    unsigned xvalue = rand() % std::numeric_limits<unsigned>::max();
    unsigned yvalue = rand() % std::numeric_limits<unsigned>::max();
    
    if(cycle % 3 == 0) {
      trace1->updateTermValue(0, cycle, xvalue);
      trace2->updateTermValue(0, cycle, xvalue);
      trace1->updateTermValue(1, cycle, yvalue);
      trace2->updateTermValue(1, cycle, yvalue);
    }
    else if(cycle % 3 == 1) {
      trace1->updateTermValue(0, cycle, xvalue);
      trace2->updateTermValue(0, cycle, !xvalue);
      trace1->updateTermValue(1, cycle, yvalue);
      trace2->updateTermValue(1, cycle, yvalue);
    }
    else {
      // violating state
      trace1->updateTermValue(0, cycle, xvalue);
      trace2->updateTermValue(0, cycle, !xvalue);
      trace1->updateTermValue(1, cycle, yvalue);
      trace2->updateTermValue(1, cycle, !yvalue);
    }

    result = property->eval(cycle, tracelist);
  }
  
  EXPECT_FALSE(result);
}
