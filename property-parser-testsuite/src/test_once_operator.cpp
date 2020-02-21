#include <memory>
#include "property_parser.h"
#include "probmodel.h"

#include <gtest/gtest.h>


TEST(PropertyParserTest, ValidTraceOnceOperator) {

    num_lit = 1;
    tr_lit.emplace_back("x");

    Formula *formula = parse("(O (AND (GEQ (1.x) (10)) (GEQ (2.x) (10))))");

    const unsigned traceLength = 100;
    std::unique_ptr<long[]> trace1 = std::make_unique<long[]>(traceLength);
    std::unique_ptr<long[]> trace2 = std::make_unique<long[]>(traceLength);

    ProbModel pm;
    for (unsigned idx = 0; idx < traceLength; ++idx) {
        if (pm.probM(20)) {
            trace1[idx] = 11;
            trace2[idx] = 0;
        }
        else {
            trace1[idx] = 0;
            trace2[idx] = 11;
        }
    }

    EXPECT_TRUE(formula->eval(trace1.get(), trace2.get()));
    if (HasFailure())
        printTraces(trace1, trace2, traceLength);

}

TEST(PropertyParserTest, InvalidTraceOnceOperator) {

    num_lit = 1;
    tr_lit.emplace_back("x");

    Formula *formula = parse("(O (AND (GEQ (1.x) (10)) (GEQ (2.x) (10))))");

    const unsigned traceLength = 100;
    std::unique_ptr<long[]> trace1 = std::make_unique<long[]>(traceLength);
    std::unique_ptr<long[]> trace2 = std::make_unique<long[]>(traceLength);

    ProbModel pm;
    for (unsigned idx = 0; idx < traceLength; ++idx) {
        if (pm.probM(20)) {
            trace1[idx] = 11;
            trace2[idx] = 0;
        }
        else {
            trace1[idx] = trace2[idx] = 0;
        }
    }

    EXPECT_FALSE(formula->eval(trace1.get(), trace2.get()));
    if (HasFailure())
        printTraces(trace1, trace2, traceLength);

}
