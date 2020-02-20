//
// Created by sujit on 20/02/20.
//

#include <memory>
#include "property_parser.h"
#include "prob-models/ProbModel.h"

#include <gtest/gtest.h>


TEST(PropertyParserTest, ValidTracePastOperator) {

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
        printTraces(trace1.get(), trace2.get(), traceLength);

    // TODO: print traces on failure
}
