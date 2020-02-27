#include <memory>
#include "property_parser.h"

#include <gtest/gtest.h>


TEST(PropertyParserTest, ValidTraceYOperator) {

    num_lit = 1;
    tr_lit.clear();
    tr_lit.emplace_back("x");

    Formula *formula = parse("(Y (AND (EQL (1.x) (10)) (EQL (2.x) (10))))");

    const unsigned traceLength = 10;
    long* trace1 = new long[traceLength];
    long* trace2 = new long[traceLength];

    bool result = false;
    for (unsigned idx = 0; idx < traceLength - 2; ++idx) {
        trace1[idx] = trace2[idx] = 0;
        result = formula->eval(&trace1[idx], &trace2[idx]);
    }

    trace1[traceLength - 1] = trace2[traceLength - 1] = 10;
    result = formula->eval(&trace1[traceLength - 1], &trace2[traceLength - 1]);

    trace1[traceLength - 1] = trace2[traceLength - 1] = 0;
    result = formula->eval(&trace1[traceLength - 1], &trace2[traceLength - 1]);


    EXPECT_TRUE(result);

    if(HasFailure())
        printTraces(formula, trace1, trace2, traceLength);

    delete [] (trace1);
    delete [] (trace2);
}

TEST(PropertyParserTest, InvalidTraceYOperator) {

    num_lit = 1;
    tr_lit.clear();
    tr_lit.emplace_back("x");

    Formula *formula = parse("(Y (AND (EQL (1.x) (10)) (EQL (2.x) (10))))");

    const unsigned traceLength = 10;
    long* trace1 = new long[traceLength];
    long* trace2 = new long[traceLength];

    bool result = false;
    for (unsigned idx = 0; idx < traceLength; ++idx) {
        trace1[idx] = trace2[idx] = 0;
        result = formula->eval(&trace1[idx], &trace2[idx]);
    }

    EXPECT_FALSE(result);

    if(HasFailure()) {
        printTraces(formula, trace1, trace2, traceLength);
    }

    delete [] (trace1);
    delete [] (trace2);
}
