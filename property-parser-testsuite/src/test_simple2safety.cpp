#include <memory>
#include <stdlib.h>
#include "property_parser.h"
#include "probmodel.h"

#include <gtest/gtest.h>


TEST(PropertyParserTest, ValidTrace2safety) {

    num_lit = 1;
    tr_lit.clear();
    tr_lit.emplace_back("x");

    Formula *formula = parse("(G (IMPLIES (GEQ (1.x) (10)) (GEQ (2.x) (10))))");

    const unsigned traceLength = 100;
    long* trace1 = new long[traceLength];
    long* trace2 = new long[traceLength];

    ProbModel pm;
    bool result = false;
    for (unsigned idx = 0; idx < traceLength; ++idx) {
        if (pm.probM(20)) {
            trace1[idx] = trace2[idx] = 11;
        }
        else {
            trace1[idx] = trace2[idx] = 0;
        }
	result = formula->eval(&trace1[idx], &trace2[idx]);
    }

    EXPECT_TRUE(result);
    if(HasFailure()) {
        printTraces(formula, trace1, trace2, traceLength);
    }
    
    delete [] (trace1);
    delete [] (trace2);
}

TEST(PropertyParserTest, InvalidTrace2safety) {

    num_lit = 1;
    tr_lit.clear();
    tr_lit.emplace_back("x");

    Formula *formula = parse("(G (IMPLIES (GEQ (1.x) (10)) (GEQ (2.x) (10))))");

    const unsigned traceLength = 100;
    long * trace1 = new long[traceLength];
    long * trace2 = new long[traceLength];

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

    if(HasFailure()) {
        printTraces(formula, trace1, trace2, traceLength);
    }

    
    delete [] (trace1);
    delete [] (trace2);
}

TEST(PropertyParserTest, InvalidTraceObsDetGoodOut) {

    num_lit = 2;
    tr_lit.clear();
    tr_lit.emplace_back("x");
    tr_lit.emplace_back("y");

    Formula *formula = parse("(IMPLIES (EQL (1.x) (2.x)) (G (EQL (1.y) (2.y))))");

    const unsigned traceLength = 100;
    long* trace1 = new long[2];
    long* trace2 = new long[2];

    ProbModel pm;
    bool result = true;
    bool ante;
    bool good = true;
    bool violationIndex = rand() % traceLength;
    // DEBUG:
    // printf("good=%d; violationIndex=%d\n", (int) good, violationIndex);
    const int INDEX_X = 1, INDEX_Y = 0;
    for (unsigned idx = 0; idx < traceLength; ++idx) {
        if (idx == 0) {
            ante = pm.probM(50);
            if (ante) {
                trace1[INDEX_X] = trace2[INDEX_X] = rand() % 100;
            } else {
                trace1[INDEX_X] = rand() % 100;
                trace2[INDEX_X] = trace1[INDEX_X] + (rand() % 5) + 1;
            }
        }
        if (good && ante) {
            trace1[INDEX_Y] = trace2[INDEX_Y] = rand() % 100;
        } else {
            if (idx == violationIndex) {
                trace1[INDEX_Y] = rand() % 100;
                trace2[INDEX_Y] = trace1[INDEX_Y] + 1;
            } else {
                trace1[INDEX_Y] = trace2[INDEX_Y] = rand() % 100;
            }
        }
        result = formula->eval(&trace1[idx], &trace2[idx]);
        // DEBUG:
        // printf("[%d] %5d %5d %5d %5d %5d --> %d\n", 
        //         (int) good, idx, trace1[INDEX_X], trace1[INDEX_Y], trace2[INDEX_X], trace2[INDEX_Y],
        //         (int) result);
    }

    EXPECT_TRUE(result);

    delete [] trace1;
    delete [] trace2;
}

TEST(PropertyParserTest, InvalidTraceObsDetBadOut) {

    num_lit = 2;
    tr_lit.clear();
    tr_lit.emplace_back("x");
    tr_lit.emplace_back("y");

    Formula *formula = parse("(IMPLIES (EQL (1.x) (2.x)) (G (EQL (1.y) (2.y))))");

    const unsigned traceLength = 100;
    long* trace1 = new long[2];
    long* trace2 = new long[2];

    ProbModel pm;
    bool result = true;
    bool ante;
    bool good = false;
    bool violationIndex = rand() % traceLength;
    // DEBUG:
    // printf("good=%d; violationIndex=%d\n", (int) good, violationIndex);
    const int INDEX_X = 1, INDEX_Y = 0;
    for (unsigned idx = 0; idx < traceLength; ++idx) {
        if (idx == 0) {
            ante = pm.probM(50);
            if (ante) {
                trace1[INDEX_X] = trace2[INDEX_X] = rand() % 100;
            } else {
                trace1[INDEX_X] = rand() % 100;
                trace2[INDEX_X] = trace1[INDEX_X] + (rand() % 5) + 1;
            }
        }
        if (good && ante) {
            trace1[INDEX_Y] = trace2[INDEX_Y] = rand() % 100;
        } else {
            if (idx == violationIndex) {
                trace1[INDEX_Y] = rand() % 100;
                trace2[INDEX_Y] = trace1[INDEX_Y] + 1;
            } else {
                trace1[INDEX_Y] = trace2[INDEX_Y] = rand() % 100;
            }
        }
        // result = result && formula->eval(&trace1[idx], &trace2[idx]);
	result = formula->eval(&trace1[idx], &trace2[idx]);
        // DEBUG:
        // printf("[%d] %5d %5d %5d %5d %5d --> %d\n", 
        //         (int) good, idx, trace1[INDEX_X], trace1[INDEX_Y], trace2[INDEX_X], trace2[INDEX_Y],
        //         (int) result);
    }

    EXPECT_FALSE(result);

    delete [] trace1;
    delete [] trace2;
}
