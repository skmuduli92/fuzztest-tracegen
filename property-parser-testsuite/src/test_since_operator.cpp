#include <memory>
#include "property_parser.h"

#include <gtest/gtest.h>

// TODO: test for Since (S) operator


TEST(PropertyParserTest, ValidTraceOnceOperator_1Literal) {

  num_lit = 1;
  tr_lit.clear();
  tr_lit.emplace_back("x");

  bool result = false;

  Formula* formula = parse("(S (GEQ (1.x) (2.x)) (EQL (1.x) (2.x)))");

  const unsigned traceLength = 100;
  const long tr[] = {1, 2, 3};

  const long* trace1 = NULL;
  const long* trace2 = NULL;
  
  // valid trace example :
  // 2.2.2.2.2.3.3.2.2.3.2.3..
  // 1.1.3.2.2.1.2.1.2.1.2.3..

  for (unsigned idx = 0; idx < traceLength; ++idx) {
    if (idx < (traceLength/2)) {
      // 1.x < 2.x
      int randidx = rand() % 3;
      randidx = randidx == 1? 2 : randidx;
      trace1 = &tr[1];
      trace2 = &tr[randidx];
    }
    else if(idx == (traceLength / 2)) {
      // making 1.x == 2.x
      trace1 = trace2 = &tr[1];
    }
    else {
      // 1.x >= 2.x
      int randidx = rand() % 3;
      trace2 = &tr[randidx];    
      randidx = (randidx == 0) ? 1 : randidx;
      trace1 = &tr[randidx];
    }

    result = formula->eval(trace1, trace2);
    // std::cout << "tr1 : " << *trace1 << "    tr2 : " << *trace2 << std::endl;
  }
  
  EXPECT_TRUE(result);
}

TEST(PropertyParserTest, InvalidTrace1OnceOperator_1Literal) {

  num_lit = 1;
  tr_lit.clear();
  tr_lit.emplace_back("x");

  bool result = true;

  Formula* formula = parse("(S (GEQ (1.x) (2.x)) (EQL (1.x) (2.x)))");

  const unsigned traceLength = 100;
  const long tr[] = {1, 2, 3};

  const long* trace1 = NULL;
  const long* trace2 = NULL;
  
  // valid trace example :
  // 2.2.2.2.2.3.3.2.2.3.2.3..
  // 1.1.3.2.2.1.2.1.2.1.2.3..

  for (unsigned idx = 0; idx < traceLength; ++idx) {
    int randidx = rand() % 2;
    trace1 = &tr[randidx];
    trace2 = &tr[1 - randidx];
    result = formula->eval(trace1, trace2);
    // std::cout << "tr1 : " << *trace1 << "    tr2 : " << *trace2 << std::endl;
  }
  
  EXPECT_FALSE(result);
}
