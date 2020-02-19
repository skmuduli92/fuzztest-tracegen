
#include <iostream>
#include "ProbModel.h"


unsigned ProbModel::prob80() {
    //  function p80 will generate 1 with propability 0.8 and will generate
    //  0 with propability 0.2

    std::uniform_int_distribution<> dis(1,100);
    return dis(gen) <= 20 ? 0 : 1;
}

unsigned ProbModel::probM(unsigned num) {
    // generic version of prob80, generates 1 with probability (num / 100) and
    // 0 with probability (1/num)

    if (num < 0 || num > 100) {
        std::cerr << "int probM (int num) :: 'num' should be 0 < num < 101" << std::endl;
        exit(1);
    }

    std::uniform_int_distribution<> dis(1,100);
    return (dis(gen) <= num)? 1: 0;
}

unsigned ProbModel::countDigits(unsigned num) {    
    return snprintf(NULL, 0, "%u", num);
}

unsigned ProbModel::findMaxBound(unsigned num) {

    unsigned numDigits = countDigits(num);
    unsigned maxBound = 1;

    while (((maxBound * 10) % 10 == 0) && (numDigits--))
	maxBound = maxBound * 10;
    
    return maxBound;
}

unsigned ProbModel::nWithProbM(unsigned num, unsigned prob) {

    unsigned maxBound = findMaxBound(num);

    if (maxBound < num) {
	std::cerr << "Error: 'num' should be less than or equal to "
		  << findMaxBound(std::numeric_limits<unsigned>::max())
		  << std::endl;
	
	exit(1);
    }


    std::cerr << "Function not yet implemented" << std::endl;
    exit(1);
}

ProbModel::ProbModel(): rd(), gen(rd()) {}
