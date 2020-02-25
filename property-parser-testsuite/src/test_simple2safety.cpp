#include <memory>
#include "property_parser.h"
#include "probmodel.h"

#include <gtest/gtest.h>


TEST(PropertyParserTest, ValidTrace2safety) {

    num_lit = 1;
    tr_lit.clear();
    tr_lit.emplace_back("x");

    Formula *formula = parse("(G (IMPLIES (GEQ (1.x) (10)) (GEQ (2.x) (10))))");

    const unsigned traceLength = 100;
    long* trace1 = new long[traceLength];
    long* trace2 = new long[traceLength];

    ProbModel pm;
    bool result = false;
    for (unsigned idx = 0; idx < traceLength; ++idx) {
        if (pm.probM(20)) {
            trace1[idx] = trace2[idx] = 11;
        }
        else {
            trace1[idx] = trace2[idx] = 0;
        }
	result = formula->eval(&trace1[idx], &trace2[idx]);
    }

    EXPECT_TRUE(result);

    if(HasFailure()) {
        printTraces(formula, trace1, trace2, traceLength);
    }
    
    free(trace1);
    free(trace2);
}

TEST(PropertyParserTest, InvalidTrace2safety) {

    num_lit = 1;
    tr_lit.clear();
    tr_lit.emplace_back("x");

    Formula *formula = parse("(G (IMPLIES (GEQ (1.x) (10)) (GEQ (2.x) (10))))");

    const unsigned traceLength = 100;
    long* trace1 = new long[traceLength];
    long* trace2 = new long[traceLength];

    ProbModel pm;
    bool result = true;
    for (unsigned idx = 0; idx < traceLength; ++idx) {
        if (pm.probM(20)) {
            trace1[idx] = 11;
            trace2[idx] = 0;
        }
        else {
            trace1[idx] = trace2[idx] = 0;
        }
	result = formula->eval(&trace1[idx], &trace2[idx]);
    }

    EXPECT_FALSE(result);

    if(HasFailure()) {
        printTraces(formula, trace1, trace2, traceLength);
    }

    
    free(trace1);
    free(trace2);
}
