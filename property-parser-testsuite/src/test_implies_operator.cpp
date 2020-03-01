#include <memory>
#include <stdlib.h>
#include "property_parser.h"
#include "probmodel.h"

#include <gtest/gtest.h>

TEST(PropertyParserTest, ValidTraceImpliesVacuous) {

    num_lit = 1;
    tr_lit.clear();
    tr_lit.emplace_back("x");

    Formula *formula = parse("(G (IMPLIES (EQL (1.x) (1)) (EQL (2.x) (2))))");

    // creating test with 1.x always zero making (1.x == 1) always false
    // hence, the formula always holds

    long tr1[] = {0};
    long tr2[] = {1};
    bool result = false;

    for(unsigned idx = 0; idx < 10; ++idx) {
      result = formula->eval(tr1, tr2);
    }

    EXPECT_TRUE(result);    
}

TEST(PropertyParserTest, ValidTraceImpliesOperator) {

    num_lit = 1;
    tr_lit.clear();
    tr_lit.emplace_back("x");

    Formula *formula = parse("(G (IMPLIES (EQL (1.x) (1)) (EQL (2.x) (2))))");

    // testing if the property evaluates to true on a valie trace

    long tr[] = {1, 2};
    bool result = false;

    const int traceLength = 100;
    ProbModel pm;

    for (int idx; idx < traceLength; ++idx) {
	if (pm.probM(20)) {
	    // trace 1:  1....
	    // trace 2:  2....
	    result = formula->eval(&tr[0], &tr[1]);
	}
	else {
	    // trace 1:  2....
	    // trace 2:  2....
	    unsigned rand_idx = rand() % 2;
	    result = formula->eval(&tr[1], &tr[rand_idx]);
	}
    }

    EXPECT_TRUE(result);
}

TEST(PropertyParserTest, InvalidTraceImpliesOperator) {

    num_lit = 1;
    tr_lit.clear();
    tr_lit.emplace_back("x");

    Formula *formula = parse("(G (IMPLIES (EQL (1.x) (1)) (EQL (2.x) (2))))");
    
    long tr[] = {1, 2};
    bool result = true;
    const int traceLength = 100;
    ProbModel pm;
    
    for (int idx; idx < traceLength; ++idx) {

	if (pm.probM(20)) {
	    // trace 1:  1....
	    // trace 2:  1....
	    result = formula->eval(&tr[0], &tr[0]);
	}
	else {
	    unsigned rand_idx = rand() % 2;
	    result = formula->eval(&tr[1], &tr[rand_idx]);
	}
    }

    EXPECT_FALSE(result);
}
