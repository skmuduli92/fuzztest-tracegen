#include <memory>
#include "property_parser.h"
#include "probmodel.h"

#include <gtest/gtest.h>


// TODO : write tests for relational operators (LEQ, GEQ, GREATER, LESS)

TEST(PropertyParserTest, ValidTraceLEQ) {

    num_lit = 1;
    tr_lit.clear();
    tr_lit.emplace_back("x");
    
    Formula *formula = parse("(O (LEQ (1.x) (2.x)))");
    bool result = false;
    const long tr[] = {1, 2};

    ProbModel pm;

    for (unsigned idx = 0; idx < 100; ++idx) {

        if(pm.probM(20))
            result = formula->eval(&tr[0], &tr[1]);
        else
            result = formula->eval(&tr[pm.probM(50)], &tr[pm.probM(50)]);
    }
    
    EXPECT_TRUE(result);
}


TEST(PropertyParserTest, ValidTraceLEQ_2Literals) {

    num_lit = 2;
    tr_lit.clear();
    tr_lit.emplace_back("x");
    tr_lit.emplace_back("y");
    
    Formula *formula = parse("(O (AND (LEQ (1.x) (2.x)) (GEQ (1.y) (2.y))))");
    bool result = false;
    const long tr[] = {1, 2};

    ProbModel pm;
    const unsigned validIdx = 20;

    for(unsigned idx = 0; idx < 100; ++idx) {
        if (idx == validIdx) {
            result = formula->eval(&tr[0], &tr[1]);
            result = formula->eval(&tr[1], &tr[0]);
        }
        else {
            result = formula->eval(&tr[pm.probM(50)], &tr[pm.probM(50)]);
            result = formula->eval(&tr[pm.probM(50)], &tr[pm.probM(50)]);
        }
    }
        
    EXPECT_TRUE(result);
}


TEST(PropertyParserTest, InvalidTraceLEQ) {

    num_lit = 1;
    tr_lit.clear();
    tr_lit.emplace_back("x");
    
    Formula *formula = parse("(O (LEQ (1.x) (2.x)))");
    bool result = false;
    const long tr[] = {1, 2};

    ProbModel pm;

    for (unsigned idx = 0; idx < 100; ++idx) {

        if(pm.probM(20)) {
            result = formula->eval(&tr[1], &tr[0]);
        }
        else {
            int randIdx = rand() % 2;
            result = formula->eval(&tr[randIdx], &tr[randIdx]);
        }
    }

    EXPECT_FALSE(result);
}

TEST(PropertyParserTest, InvalidTraceLEQ_2Literals) {

    num_lit = 2;
    tr_lit.clear();
    tr_lit.emplace_back("x");
    tr_lit.emplace_back("y");
    
    Formula *formula = parse("(O (AND (LEQ (1.x) (2.x)) (GEQ (1.y) (2.y))))");
    bool result = true;
    const long tr[] = {1, 2};
    ProbModel pm;

    // FIXME : check how to use the API for two_literals
    // tests may be failing due to wrong usage of the API
    for(unsigned idx = 0; idx < 100; ++idx) {
        result = formula->eval(&tr[1], &tr[0]);
        result = formula->eval(&tr[1], &tr[1]);
    }

    EXPECT_FALSE(result);
}



/////////////////////////////////
// Test cases for EQ operator //
/////////////////////////////////

TEST(PropertyParserTest, ValidTraceEQ) {}

TEST(PropertyParserTest, ValidTraceEQ_2Literals) {}

TEST(PropertyParserTest, InvalidTraceEQ) {}

TEST(PropertyParserTest, InvalidTraceEQ_2Literals) {}


/////////////////////////////////
// Test cases for GEQ operator //
/////////////////////////////////

TEST(PropertyParserTest, ValidTraceGEQ) {}

TEST(PropertyParserTest, ValidTraceGEQ_2Literals) {}

TEST(PropertyParserTest, InvalidTraceGEQ) {}

TEST(PropertyParserTest, InvalidTraceGEQ_2Literals) {}


////////////////////////////////////
// Test cases for LESSER operator //
////////////////////////////////////

TEST(PropertyParserTest, ValidTraceLESSER) {}

TEST(PropertyParserTest, ValidTraceLESSER_2Literals) {}

TEST(PropertyParserTest, InvalidTraceLESSER) {}

TEST(PropertyParserTest, InvalidTraceLESSER_2Literals) {}

