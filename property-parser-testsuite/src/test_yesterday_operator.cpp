#include <memory>
#include "property_parser.h"

#include <gtest/gtest.h>


TEST(PropertyParserTest, ValidTraceEqlarray) {

    num_lit = 1;
    tr_lit.clear();
    tr_lit.emplace_back("x");

    Formula *formula = parse("(Y (AND (EQL (1.x) (10)) (EQL (2.x) (10))))");

    const unsigned traceLength = 10;
    std::unique_ptr<long[]> trace1 = std::make_unique<long[]>(traceLength);
    std::unique_ptr<long[]> trace2 = std::make_unique<long[]>(traceLength);

    trace1[traceLength - 1] = trace2[traceLength - 1] = 10;

    EXPECT_TRUE(formula->eval(trace1.get(), trace2.get()));
    if(HasFailure())
        printTraces(formula, trace1, trace2, traceLength);
}

TEST(PropertyParserTest, InvalidTraceEqlarray) {

    num_lit = 1;
    tr_lit.clear();
    tr_lit.emplace_back("x");

    Formula *formula = parse("(Y (AND (EQL (1.x) (10)) (EQL (2.x) (10))))");

    const unsigned traceLength = 10;
    std::unique_ptr<long[]> trace1 = std::make_unique<long[]>(traceLength);
    std::unique_ptr<long[]> trace2 = std::make_unique<long[]>(traceLength);

    for (unsigned i = 0; i < traceLength; ++i) {
        trace1[i] = trace2[i] = 0;
    }

    bool result = formula->eval(trace1.get(), trace2.get());
    std::cout << "result : " << result << std::endl;

    EXPECT_FALSE(result);
    if(HasFailure()) {
        printTraces(formula, trace1, trace2, traceLength);
    }

}
