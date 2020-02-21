#include <memory>
#include "property_parser.h"

#include <gtest/gtest.h>


TEST(PropertyParserTest, ValidTraceEqlarray) {

    num_lit = 1;
    tr_lit.clear();
    tr_lit.emplace_back("x");


    const unsigned traceLength = 10;
    Formula *formula = parse("(G (EQLARRAY (0) (9)))");

    std::unique_ptr<long[]> trace1 = std::make_unique<long[]>(traceLength);
    std::unique_ptr<long[]> trace2 = std::make_unique<long[]>(traceLength);

    for (unsigned i = 0; i < traceLength; ++i) {
        trace1[i] = trace2[i] = 0;
    }

    EXPECT_TRUE(formula->eval(trace1.get(), trace2.get()));

    if(HasFailure())
        printTraces(formula, trace1, trace2, traceLength);

}

// TEST(PropertyParserTest, InvalidTraceEqlarray) {

//     // TODO : write test for eqlarray operator

//     EXPECT_TRUE(true);
// }
