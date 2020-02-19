//
// Created by sujit on 19/02/20.
//

#ifndef PROPERTYPARSER_PROBMODEL_H
#define PROPERTYPARSER_PROBMODEL_H

#include <random>

class ProbModel {
public:

    ProbModel();
    int prob80();
    int probM(int num);
    int nWithProbM(int num, int prob);

private:
    std::random_device rd;
    std::mt19937 gen;
};



#endif //PROPERTYPARSER_PROBMODEL_H
