#include "property_parser.h"
#include "test_functions.h"


std::vector<std::string> tr_lit;
int num_lit;


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

    testSimpleLTLProp();
    testCommutativeProp();
    testTransitiveProp();

    return 0;
}


