#include <memory>
#include "property_parser.h"

#include <gtest/gtest.h>


TEST(PropertyParserTest, ValidTraceEqlarray) {

    num_lit = 1;
    tr_lit.clear();
    tr_lit.emplace_back("x");

    Formula *formula = parse("(G (EQLARRAY (0) (9)))");

    const unsigned traceLength = 10;
    long* trace1 = new long[traceLength];
    long* trace2 = new long[traceLength];


    for (unsigned i = 0; i < traceLength; ++i) {
        trace1[i] = trace2[i] = 0;
    }

    EXPECT_TRUE(formula->eval(trace1, trace2));

    if(HasFailure())
        printTraces(formula, trace1, trace2, traceLength);

   
    delete(trace1);
    delete(trace2); 
}

TEST(PropertyParserTest, InvalidTraceEqlarray) {

    num_lit = 1;
    tr_lit.clear();
    tr_lit.emplace_back("x");

    Formula *formula = parse("(G (EQLARRAY (0) (9)))");

    const unsigned traceLength = 10;
    long* trace1 = new long[traceLength];
    long* trace2 = new long[traceLength];


    for (unsigned i = 0; i < traceLength; ++i) {
        trace1[i] = trace2[i] = 0;
    }

    trace2[traceLength - 1] = 10;

    EXPECT_FALSE(formula->eval(trace1, trace2));

    if(HasFailure())
        printTraces(formula, trace1, trace2, traceLength);

    delete(trace1);
    delete(trace2);
}
