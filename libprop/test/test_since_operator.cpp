#include "formula.h"
#include "trace.h"
#include <gtest/gtest.h>

using namespace HyperPLTL;
using namespace std;


PHyperProp propertySinceOperator() {
  std::string formula("(S (EQ x) (EQ y))");
  auto prop = parse_formula(formula);
  prop->display(std::cout);
  return prop;
}

TEST(PropertyLibTest, ValidTraceSinceOperator) {
  PHyperProp property = propertySinceOperator();

  PTrace trace1(new Trace(2));
  PTrace trace2(new Trace(2));
  TraceList tracelist({trace1, trace2});

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
