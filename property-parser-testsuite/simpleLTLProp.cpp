//
// Created by sujit on 19/02/20.
//

#include <iostream>
#include <vector>

#include "property_parser.h"

void genPositiveTest(long* trace1, long* trace2, unsigned traceLength) {

}

void genNegativeTest(long* trace1, long* trace2, unsigned traceLength) {

}

void testSimpleLTLProp() {

    num_lit = 1;
    tr_lit.emplace_back("x");
    // property : whenever (1.x > 10), then (2.x > 10)
    char prop[] = "(IMPLIES (GEQ (1.x) (10)) (GEQ (2.x) (10)))";

    std::cout << "=========== TEST SIMPLE LTL PROP ===========" << std::endl;
    Formula *formula = parse(prop);
    formula->display();
    std::cout << "\n\n";

    long *trace1obs = new long(300);
    long *trace2obs = new long(300);

    genPositiveTest(trace1obs, trace2obs, 300);
    formula->eval(trace1obs, trace2obs);

    genNegativeTest(trace1obs, trace2obs, 300);
    formula->eval(trace1obs, trace2obs);

    delete [] trace1obs;
    delete[] trace2obs;

    cleanup();
}