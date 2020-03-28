
#ifndef __PARSE_UTIL_H__
#define __PARSE_UTIL_H__

#include "formula.h"

#define PARSE_ERR_MSG "Error : Parsing failed"

namespace HyperPLTL {

PHyperProp parse_formula(std::string const&, PVarMap);

/////////////////////////////////////////////////////////////////////////
// TODO:
// This to be used in testing, may move to test directory.
// will have to separate ast and grammar definitions from implementaiton
// placed together in src/parser.cpp
/////////////////////////////////////////////////////////////////////////

std::string parse_and_regen_string(std::string const& str);

}  // namespace HyperPLTL

#endif
