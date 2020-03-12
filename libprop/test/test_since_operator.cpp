#include "formula.h"
#include "trace.h"
#include <gtest/gtest.h>

using namespace HyperPLTL;
using namespace std;


PHyperProp propertySinceOperator() {
  PVarMap varmap(new VarMap());
  unsigned xIndex = varmap->addVar("x");
  unsigned yIndex = varmap->addVar("y");
  PTerm x(new TermVar(varmap, xIndex));
  PTerm y(new TermVar(varmap, yIndex));

  PHyperProp eqX(new Equal(varmap, x));
  PHyperProp eqY(new Equal(varmap, y));

  // eqY SINCE eqX    
  PHyperProp eqYSINCEeqX(new Since(varmap, eqY, eqX));
  return eqYSINCEeqX;
}

TEST(PropertyLibTest, ValidTraceSinceOperator) {
  PHyperProp property = propertySinceOperator();

  PTrace trace1(new Trace(2));
  PTrace trace2(new Trace(2));
  TraceList tracelist({trace1, trace2});

  property->display(std::cout); std::cout << std::endl;
  bool result = false;

  size_t cycle = 0;
  unsigned xvalue = 0;
  unsigned yvalue = 0;
  unsigned traceLength = rand() % 20 + 20;
  
  for(; cycle < traceLength; ++cycle) {
    xvalue = rand() % 100;
    // setting 'x' var value
    trace1->updateTermValue(0, cycle, xvalue);
    trace2->updateTermValue(0, cycle, !xvalue);

    // setting 'y' var value
    trace1->updateTermValue(1, cycle, rand() % 100);
    trace2->updateTermValue(1, cycle, rand() % 100);

    result = property->eval(cycle, tracelist);
  }

  xvalue = rand() % 100;
  // setting 'x' var value
  trace1->updateTermValue(0, cycle, xvalue);
  trace2->updateTermValue(0, cycle, xvalue);
  // setting 'y' var value
  trace1->updateTermValue(1, cycle, rand() % 100);
  trace2->updateTermValue(1, cycle, rand() % 100);

  result = property->eval(cycle, tracelist);
  cycle = cycle + 1;

  for(traceLength = rand() % 20 + 20 + cycle; cycle < traceLength; ++cycle) {
    // setting 'x' var value
    trace1->updateTermValue(0, cycle, rand() % 100);
    trace2->updateTermValue(0, cycle, rand() % 100);

    // setting 'y' var value
    yvalue = rand() % 100;
    trace1->updateTermValue(1, cycle, yvalue);
    trace2->updateTermValue(1, cycle, yvalue);

    result = property->eval(cycle, tracelist);
  }
 
  EXPECT_TRUE(result);
}

TEST(PropertyLibTest, InvalidTraceSinceOperator_Test1) {

  // eqX never becomes true, hence SINCE(eqY, eqX) should fail.
  PHyperProp property = propertySinceOperator();

  PTrace trace1(new Trace(2));
  PTrace trace2(new Trace(2));
  TraceList tracelist({trace1, trace2});

  property->display(std::cout); std::cout << std::endl;
  bool result = false;

  size_t cycle = 0;
  unsigned xvalue = 0;
  unsigned traceLength = rand() % 20 + 20;
  
  for(; cycle < traceLength; ++cycle) {
    xvalue = rand() % 100;
    // setting 'x' var value
    trace1->updateTermValue(0, cycle, xvalue);
    trace2->updateTermValue(0, cycle, !xvalue);
    // setting 'y' var value
    trace1->updateTermValue(1, cycle, rand() % 100);
    trace2->updateTermValue(1, cycle, rand() % 100);

    result = property->eval(cycle, tracelist);
  }
 
  EXPECT_FALSE(result);  
}

TEST(PropertyLibTest, InvalidTraceSinceOperator_Test2) {

  // eqX is always true but eqY never becomes true
  PHyperProp property = propertySinceOperator();

  PTrace trace1(new Trace(2));
  PTrace trace2(new Trace(2));
  TraceList tracelist({trace1, trace2});

  property->display(std::cout); std::cout << std::endl;
  bool result = false;

  size_t cycle = 0;
  unsigned xvalue = 0;
  unsigned yvalue = 0;
  unsigned traceLength = rand() % 20 + 20;
  
  for(; cycle < traceLength; ++cycle) {
    xvalue = rand() % 100;
    // setting 'x' var value
    trace1->updateTermValue(0, cycle, xvalue);
    trace2->updateTermValue(0, cycle, xvalue);
    // setting 'y' var value
    yvalue = rand() % 100;
    trace1->updateTermValue(1, cycle, yvalue);
    trace2->updateTermValue(1, cycle, !yvalue);

    result = property->eval(cycle, tracelist);
  }
 
  EXPECT_FALSE(result);  
}
