#include <memory>
#include <stdlib.h>
#include "property_parser.h"

#include <gtest/gtest.h>

TEST(PropertyParserTest, ValidTraceIMPLIESVacuous) {

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
