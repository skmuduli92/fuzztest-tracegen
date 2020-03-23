
#include <gtest/gtest.h>
#include "parse_util.h"

std::string prune_whitespaces(std::string const& str) {
  std::string newstr = "";
  for (const auto c : str)
    if (c != ' ')
      newstr.push_back(c);

  return newstr;
}

TEST(PropertyLibTest, Parse_NOT) {
  std::string prop = "(NOT (EQ x))";

  std::string origPropPruned = prune_whitespaces(prop);
  std::string regenStr = prune_whitespaces(HyperPLTL::parse_and_regen_string(prop));
  
  EXPECT_FALSE(prop == origPropPruned);
  EXPECT_TRUE(origPropPruned == regenStr);
}

TEST(PropertyLibTest, Parse_AND) {}

TEST(PropertyLibTest, Parse_OR) {}

TEST(PropertyLibTest, Parse_IMPLIES) {}

TEST(PropertyLibTest, Parse_Negative_Test1) {}


