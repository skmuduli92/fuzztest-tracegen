
#include <gtest/gtest.h>

#include "ast.h"
#include "formula.h"
#include "parse_util.h"
#include "parser.h"

std::string prune_whitespaces(std::string const& str) {
  std::string newstr = "";
  for (const auto c : str)
    if (c != ' ') newstr.push_back(c);

  return newstr;
}
namespace sexpr::ast {

struct HPLTLStringBuilder {
  /////////////////////////////////////////////////////////////////
  // visitor methods to generate formula string back from an AST //
  /////////////////////////////////////////////////////////////////

  using result_t = std::string;
  result_t operator()(EqlNode const& eqlNode) const {
    return "(EQ " + eqlNode.varname + ")";
  }

  result_t operator()(TraceSelNode const& selNode) const {
    return selNode.varname + "." + std::to_string(selNode.traceid) + " ";
  }

  result_t operator()(AndNode const& andNode) const {
    return "(AND " + boost::apply_visitor(*this, andNode.leftArg) +
           boost::apply_visitor(*this, andNode.rightArg) + ")";
  }

  result_t operator()(OrNode const& orNode) const {
    return "(OR " + boost::apply_visitor(*this, orNode.leftArg) +
           boost::apply_visitor(*this, orNode.rightArg) + ")";
  }

  result_t operator()(NotNode const& notNode) const {
    return "(NOT " + boost::apply_visitor(*this, notNode.arg) + ")";
  }

  result_t operator()(ImpNode const& impNode) const {
    return "(IMPLIES " + boost::apply_visitor(*this, impNode.leftArg) +
           boost::apply_visitor(*this, impNode.rightArg) + ")";
  }

  result_t operator()(GNode const& gnode) const {
    return "(G " + boost::apply_visitor(*this, gnode.arg) + ")";
  }

  result_t operator()(YNode const& ynode) const {
    return "(Y " + boost::apply_visitor(*this, ynode.arg) + ")";
  }

  result_t operator()(ONode const& onode) const {
    return "(O " + boost::apply_visitor(*this, onode.arg) + ")";
  }

  result_t operator()(SNode const& snode) const {
    return "(S " + boost::apply_visitor(*this, snode.leftArg) +
           boost::apply_visitor(*this, snode.rightArg) + ")";
  }

  result_t operator()(VarNode const& varNode) const {
    return boost::apply_visitor(*this, varNode);
  }
};

}  // namespace sexpr::ast

TEST(PropertyLibTest, Parse_NOT) {
  std::string prop = "(NOT (EQ x))";
  std::string origPropPruned = prune_whitespaces(prop);
  std::string regenStrPruned =
      prune_whitespaces(HyperPLTL::parse_and_regen_string(prop));

  EXPECT_TRUE(origPropPruned == regenStrPruned);
}

TEST(PropertyLibTest, Parse_AND) {
  std::string prop = "(AND (EQ x11) (EQ y12a))";
  std::string origPropPruned = prune_whitespaces(prop);
  std::string regenStrPruned =
      prune_whitespaces(HyperPLTL::parse_and_regen_string(prop));

  EXPECT_TRUE(origPropPruned == regenStrPruned);
}

TEST(PropertyLibTest, Parse_OR) {
  std::string prop = "(OR (EQ x11) (G (EQ y12a)) )";
  std::string origPropPruned = prune_whitespaces(prop);
  std::string regenStrPruned =
      prune_whitespaces(HyperPLTL::parse_and_regen_string(prop));

  EXPECT_TRUE(origPropPruned == regenStrPruned);
}

TEST(PropertyLibTest, Parse_IMPLIES) {
  std::string prop = "(IMPLIES (OR (EQ ab12) (EQ x11)) (EQ y12a))";
  std::string origPropPruned = prune_whitespaces(prop);
  std::string regenStrPruned =
      prune_whitespaces(HyperPLTL::parse_and_regen_string(prop));

  EXPECT_TRUE(origPropPruned == regenStrPruned);
}

TEST(PropertyLibTest, Parse_TraceSelect) {
  std::string prop = "(O (IMPLIES good.1 good.2))";
  std::string origPropPruned = prune_whitespaces(prop);
  std::string regenStrPruned =
      prune_whitespaces(HyperPLTL::parse_and_regen_string(prop));

  EXPECT_TRUE(origPropPruned == regenStrPruned);
}

TEST(PropertyLibTest, Parse_TestFailure_InvalidVarName) {
  std::string prop = "(NOT (EQ 1x))";  // invalid identifier name

  EXPECT_EXIT(HyperPLTL::parse_and_regen_string(prop),
              ::testing::ExitedWithCode(1), PARSE_ERR_MSG);
}

TEST(PropertyLibTest, Parse_TestFailure_ParenMisMatch) {
  std::string prop = "(NOT (EQ xy)";

  EXPECT_EXIT(HyperPLTL::parse_and_regen_string(prop),
              ::testing::ExitedWithCode(1), PARSE_ERR_MSG);
}

TEST(PropertyLibTest, Parse_TestFailure_OnlyParens) {
  std::string prop = "( )";

  EXPECT_EXIT(HyperPLTL::parse_and_regen_string(prop),
              ::testing::ExitedWithCode(1), PARSE_ERR_MSG);
}

TEST(PropertyLibTest, Parse_TestFailure_VarWithOutEQ) {
  std::string prop = "(OR ab (EQ xy)";

  EXPECT_EXIT(HyperPLTL::parse_and_regen_string(prop),
              ::testing::ExitedWithCode(1), PARSE_ERR_MSG);
}

TEST(PropertyLibTest, Parse_TestFailure_KeywordAsVarName) {
  std::string prop = "(OR ab (EQ AND)";

  EXPECT_EXIT(HyperPLTL::parse_and_regen_string(prop),
              ::testing::ExitedWithCode(1), PARSE_ERR_MSG);
}

TEST(PropertyLibTest, Parse_ComplexProperty) {
  std::string prop =
      "(G (IMPLIES (AND (NOT (EQ ab)) (EQ bc)) (Y (OR (EQ cd) (EQ de)))))";
  std::string origPropPruned = prune_whitespaces(prop);
  std::string regenStrPruned =
      prune_whitespaces(HyperPLTL::parse_and_regen_string(prop));

  EXPECT_TRUE(origPropPruned == regenStrPruned);
}

TEST(PropertyLibTest, Parse_TestFailure_ComplexProperty) {
  std::string prop =
      "(G (IMPLIES (AND (NOT (EQ ab)) (EQ bc)) (Y (OR (EQ cd) (EQ de)))) (EQ ef))";

  EXPECT_EXIT(HyperPLTL::parse_and_regen_string(prop),
              ::testing::ExitedWithCode(1), PARSE_ERR_MSG);
}
