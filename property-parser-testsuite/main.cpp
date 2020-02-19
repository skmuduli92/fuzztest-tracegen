#include "property_parser.h"
#include "test_functions.h"

std::vector<std::string> tr_lit;
int num_lit;

void testSample() {

    num_lit = 2;
    tr_lit.emplace_back("x");
    tr_lit.emplace_back("y");

    char prop[] = "(IMPLIES (GEQ (1.x) (10133)) (O (EQL (2.y) (1))))";
    Formula* formula = parse(prop);

    std::cout << "=========== SAMPLE TEST ===========" << std::endl;
    formula->display();
    std::cout << "\n\n";
    cleanup();
}


void testCommutativeProp() {

    // write the property
    // create two trace arrays which satisfies the property
    // create two trace arrays which violates the property

    char prop[] = "";

    std::cout << "=========== COMMUTATIVE PROPERTY TEST ===========" << std::endl;
}


void testTransitiveProp() {
    std::cout << "=========== TRANSITIVE PROPERTY TEST ===========" << std::endl;
}

// NOTE: currently property parser supports two safety property only

int main(void) {

    testSample();
    testSimpleLTLProp();
    testCommutativeProp();
    testTransitiveProp();

    return 0;
}


