//
// Created by sujit on 19/02/20.
//

#include <iostream>
#include "ProbModel.h"

int ProbModel::prob80() {
    /*
      function p80 will generate 1 with propability 0.8 and will generate
      0 with propability 0.2
    */

    std::uniform_int_distribution<> dis(1,100);
    return dis(gen) <= 20 ? 0 : 1;
}

int ProbModel::probM(int num) {
    // generic version of prob80, generates 1 with probability (num / 100) and
    // 0 with probability (1/num)%

    if (num < 1 || num > 100) {
        std::cerr << "int probM(int num) :: 'num' should be 0 < num < 101" << std::endl;
        exit(1);
    }

    std::uniform_int_distribution<> dis(1,100);
    return (dis(gen) <= num)? 1: 0;
}

int ProbModel::nWithProbM(int num, int prob) {
    std::cout << "This function is not implemented yet" << std::endl;
    exit(0);
}

ProbModel::ProbModel(): rd(), gen(rd()) {}
