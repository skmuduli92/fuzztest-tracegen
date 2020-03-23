
#ifndef __PARSE_UTIL_H__
#define __PARSE_UTIL_H__

#include "formula.h"

namespace HyperPLTL {

PHyperProp parse_formula(std::string const&);

/////////////////////////////////////////////////////////////////////////
// TODO:
// This to be used in testing, may move to test directory.
// will have to separate ast and grammar definitions from implementaiton
// placed together in src/parser.cpp
/////////////////////////////////////////////////////////////////////////

std::string parse_and_regen_string(std::string const& str);

}

#endif
