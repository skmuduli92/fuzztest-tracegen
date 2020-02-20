
#include <memory>
#include "property_parser.h"
#include "prob-models/ProbModel.h"

#include <gtest/gtest.h>


TEST(PropertyParserTest, ValidTrace) {

    num_lit = 1;
    tr_lit.emplace_back("x");

    Formula *formula = parse("(G (IMPLIES (GEQ (1.x) (10)) (GEQ (2.x) (10))))");

    const unsigned traceLength = 300;
    std::unique_ptr<long[]> trace1{new long[traceLength]};
    std::unique_ptr<long[]> trace2{new long[traceLength]};

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

    EXPECT_TRUE(formula->eval(trace1.get(), trace2.get()));
    
    if(HasFailure()) {
        std::cout << "Trace-1 : ";
        for (unsigned idx = 0; idx < traceLength; ++idx) {
            std::cout << trace1[idx] << ", ";
        }
        std::cout << "\n";
        std::cout << "Trace-2 : ";
        for (unsigned idx = 0; idx < traceLength; ++idx) {
            std::cout << trace2[idx] << ", ";
        }
        std::cout << "\n\n";
    }
}

TEST(PropertyParserTest, InValidTrace) {

    num_lit = 1;
    tr_lit.emplace_back("x");

    Formula *formula = parse("(G (IMPLIES (GEQ (1.x) (10)) (GEQ (2.x) (10))))");

    const unsigned traceLength = 300;
    std::unique_ptr<long[]> trace1{new long[traceLength]};
    std::unique_ptr<long[]> trace2{new long[traceLength]};

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

    if(HasFailure()) {
        std::cout << "Trace-1 : ";
        for (unsigned idx = 0; idx < traceLength; ++idx) {
            std::cout << trace1[idx] << ", ";
        }
        std::cout << "\n";
        std::cout << "Trace-2 : ";
        for (unsigned idx = 0; idx < traceLength; ++idx) {
            std::cout << trace2[idx] << ", ";
        }
        std::cout << "\n\n";
    }
}