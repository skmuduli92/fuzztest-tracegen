#include <memory>
#include "property_parser.h"
#include "probmodel.h"

#include <gtest/gtest.h>


TEST(PropertyParserTest, ValidTraceOnceOperator) {

    num_lit = 1;
    tr_lit.clear();
    tr_lit.emplace_back("p");

    Formula *formula = parse("(O (AND (GEQ (1.p) (10)) (GEQ (2.p) (10))))");

    const unsigned traceLength = 100;

    long* trace1 = new long[traceLength];
    long* trace2 = new long[traceLength];
    
    ProbModel pm;
    bool result = false;
    for (unsigned idx = 0; idx < traceLength; ++idx) {
        if (pm.probM(10)) {
            trace1[idx] = 11;
        }
        else {
            trace1[idx] = 0;
        }
	trace2[idx] = 11;
	result = formula->eval(&(trace1[idx]), &(trace2[idx]));
    }

    EXPECT_TRUE(result);

    if (HasFailure())
        printTraces(formula, trace1, trace2, traceLength);

    delete(trace1);
    delete(trace2);
}

TEST(PropertyParserTest, InvalidTraceOnceOperator) {

    num_lit = 1;
    tr_lit.clear();
    tr_lit.emplace_back("p");

    Formula *formula = parse("(O (AND (GEQ (1.p) (10)) (GEQ (2.p) (10))))");

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

    if (HasFailure())
        printTraces(formula, trace1, trace2, traceLength);

    delete(trace1);
    delete(trace2);
}
