
#ifndef __PROBMODEL_H__
#define __PROBMODEL_H__

#include <random>

////////////////////////////////////////////////////////////////////////////
// NOTE:                                                                  //
//  - Functionlities current support only unsigned integers               //
//  - Number is draw from a uniform-distribution and it doesn't guarantee //
//    the outcome to satisfy the exact probability distribution provided. //
////////////////////////////////////////////////////////////////////////////

class ProbModel {
 public:
  ProbModel();
  unsigned prob80();
  unsigned probM(unsigned num);

  unsigned nWithProbM(unsigned, unsigned);
  unsigned findMaxBound(unsigned);
  unsigned countDigits(unsigned);

 private:
  std::random_device rd;
  std::mt19937 gen;
};

#endif  // PROPERTYPARSER_PROBMODEL_H
