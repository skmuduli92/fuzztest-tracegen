
///////////////////////////////////////////////////////////////////////////////
// Uncomment this if you want to enable debugging
// #define BOOST_SPIRIT_X3_DEBUG

#include <boost/config/warning_disable.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/spirit/home/x3.hpp>
#include <boost/spirit/home/x3/support/ast/variant.hpp>

#include <fstream>
#include <iostream>
#include <list>
#include <memory>
#include <numeric>
#include <string>

#include "formula.h"
#include "parse_util.h"

namespace x3 = boost::spirit::x3;

namespace sexpr::ast {
///////////////////////////////////////////////////////////////////////////
//  The AST
///////////////////////////////////////////////////////////////////////////

// TODO : modify HyperProp classes to be directly used as a AST node

struct AndNode;
struct OrNode;
struct ImpNode;
struct NotNode;

struct GNode;
struct YNode;
struct ONode;
struct SNode;

struct EqlNode {
  std::string opname;
  std::string varname;
};

struct TraceSelNode {
  std::string varname;
  unsigned traceid;
};

struct VarNode : x3::variant<EqlNode, TraceSelNode, x3::forward_ast<AndNode>,
                             x3::forward_ast<OrNode>, x3::forward_ast<ImpNode>,
                             x3::forward_ast<NotNode>, x3::forward_ast<GNode>,
                             x3::forward_ast<YNode>, x3::forward_ast<ONode>,
                             x3::forward_ast<SNode> > {
  using base_type::base_type;
  using base_type::operator=;
};

struct NotNode {
  std::string opname;
  VarNode arg;
};

struct UnaryOpNode {
  std::string opname;
  VarNode arg;
};

struct BinaryOpNode {
  std::string opname;
  VarNode leftArg, rightArg;
};

struct AndNode : BinaryOpNode {};
struct OrNode : BinaryOpNode {};
struct ImpNode : BinaryOpNode {};

struct GNode : UnaryOpNode {};
struct YNode : UnaryOpNode {};
struct ONode : UnaryOpNode {};
struct SNode : BinaryOpNode {};

// print function for debugging
// inline std::ostream& operator<<(std::ostream& out, nil) { out << "nil";
// return out; }
}  // namespace sexpr::ast

BOOST_FUSION_ADAPT_STRUCT(sexpr::ast::AndNode, opname, leftArg, rightArg);

BOOST_FUSION_ADAPT_STRUCT(sexpr::ast::OrNode, opname, leftArg, rightArg);

BOOST_FUSION_ADAPT_STRUCT(sexpr::ast::ImpNode, opname, leftArg, rightArg);

BOOST_FUSION_ADAPT_STRUCT(sexpr::ast::NotNode, opname, arg);

BOOST_FUSION_ADAPT_STRUCT(sexpr::ast::GNode, opname, arg);

BOOST_FUSION_ADAPT_STRUCT(sexpr::ast::YNode, opname, arg);

BOOST_FUSION_ADAPT_STRUCT(sexpr::ast::ONode, opname, arg);

BOOST_FUSION_ADAPT_STRUCT(sexpr::ast::SNode, opname, leftArg, rightArg);

BOOST_FUSION_ADAPT_STRUCT(sexpr::ast::EqlNode, opname, varname);

BOOST_FUSION_ADAPT_STRUCT(sexpr::ast::TraceSelNode, varname, traceid);

namespace sexpr::grammar {

///////////////////////////////////////////////////////////////////////////////
//  Grammar
///////////////////////////////////////////////////////////////////////////////

x3::rule<class IdExpr, std::string> idexpr("idexpr");
x3::rule<class VarExpr, ast::VarNode> varexpr("varexpr");

x3::rule<class OrExpr, ast::OrNode> orexpr("orexpr");
x3::rule<class AndExpr, ast::AndNode> andexpr("andexpr");
x3::rule<class ImpExpr, ast::ImpNode> impexpr("impexpr");
x3::rule<class NotExpr, ast::NotNode> notexpr("notexpr");
x3::rule<class EqlExpr, ast::EqlNode> eqlexpr("eqlexpr");
x3::rule<class TraceSelExpr, ast::TraceSelNode> selexpr("selexpr");

x3::rule<class GExpr, ast::GNode> gexpr("gexpr");
x3::rule<class YExpr, ast::YNode> yexpr("yexpr");
x3::rule<class OExpr, ast::ONode> oexpr("oexpr");
x3::rule<class SExpr, ast::SNode> sexpr("sexpr");

x3::rule<class TermExpr, ast::VarNode> termexpr("termexpr");

auto const andstr = x3::string("AND");
auto const orstr = x3::string("OR");
auto const impstr = x3::string("IMPLIES");
auto const notstr = x3::string("NOT");

auto const eqstr = x3::string("EQ");

auto const gstr = x3::string("G");
auto const ystr = x3::string("Y");
auto const ostr = x3::string("O");
auto const sstr = x3::string("S");

auto const keywords =
    andstr | orstr | notstr | impstr | gstr | ystr | ostr | sstr | eqstr;

auto const idexpr_def = (x3::lexeme[x3::alpha >> *(x3::alnum)] - keywords);

auto const varexpr_def = '(' >> (notexpr | andexpr | orexpr | impexpr | gexpr |
                                 yexpr | oexpr | sexpr) >>
                         ')';

auto const orexpr_def = orstr >> termexpr >> termexpr;
auto const andexpr_def = andstr >> termexpr >> termexpr;
auto const impexpr_def = impstr >> termexpr >> termexpr;
auto const notexpr_def = notstr >> termexpr;

auto const gexpr_def = gstr >> termexpr;
auto const yexpr_def = ystr >> termexpr;
auto const oexpr_def = ostr >> termexpr;
auto const sexpr_def = sstr >> termexpr >> termexpr;

auto const termexpr_def = varexpr | ('(' >> eqlexpr >> ')') | selexpr;
auto const eqlexpr_def = eqstr >> idexpr;
auto const selexpr_def = idexpr >> ('[' >> x3::uint_ >> ']');

BOOST_SPIRIT_DEFINE(idexpr, varexpr, notexpr, andexpr, orexpr, impexpr);
BOOST_SPIRIT_DEFINE(gexpr, yexpr, oexpr, sexpr, termexpr);
BOOST_SPIRIT_DEFINE(eqlexpr, selexpr);
}  // namespace sexpr::grammar

namespace sexpr::ast {

///////////////////////////////////////////////////////////////////////////////
//  AST visitor methods
///////////////////////////////////////////////////////////////////////////////

struct HPLTLBuilder {
  using result_t = HyperPLTL::PHyperProp;
  HyperPLTL::PVarMap varmap;

  HPLTLBuilder() { varmap = std::make_shared<HyperPLTL::VarMap>(); }

  result_t operator()(EqlNode const& eqlNode) const {
    // adding identifier to varmap
    unsigned varid = varmap->addVar(eqlNode.varname);

    // TODO : [may consider] re-using the same TermVar object instead creating
    // new one everytime. This method will also work fine as trace values are
    // stored w.r.t varid
    HyperPLTL::PTerm newvar(new HyperPLTL::TermVar(varmap, varid));
    result_t eq(new HyperPLTL::Equal(varmap, newvar));
    return eq;
  }

  result_t operator()(TraceSelNode const& selNode) const {
    unsigned varid = varmap->addVar(selNode.varname);
    HyperPLTL::PTraceProp newvar(new HyperPLTL::PropVar(varmap, varid));
    result_t sel(new HyperPLTL::TraceSelect(varmap, selNode.traceid, newvar));
    return sel;
  }

  result_t operator()(AndNode const& andNode) const {
    result_t leftP = boost::apply_visitor(*this, andNode.leftArg);
    result_t rightP = boost::apply_visitor(*this, andNode.rightArg);
    result_t andP(new HyperPLTL::And(varmap, leftP, rightP));
    return andP;
  }

  result_t operator()(OrNode const& orNode) const {
    result_t leftP = boost::apply_visitor(*this, orNode.leftArg);
    result_t rightP = boost::apply_visitor(*this, orNode.rightArg);
    result_t orP(new HyperPLTL::Or(varmap, leftP, rightP));
    return orP;
  }

  result_t operator()(NotNode const& notNode) const {
    result_t argP = boost::apply_visitor(*this, notNode.arg);
    result_t notP(new HyperPLTL::Not(varmap, argP));
    return notP;
  }

  result_t operator()(ImpNode const& impNode) const {
    result_t leftP = boost::apply_visitor(*this, impNode.leftArg);
    result_t rightP = boost::apply_visitor(*this, impNode.rightArg);
    result_t imp(new HyperPLTL::Implies(varmap, leftP, rightP));
    return imp;
  }

  result_t operator()(GNode const& gnode) const {
    result_t argP = boost::apply_visitor(*this, gnode.arg);
    result_t always(new HyperPLTL::Always(varmap, argP));
    return always;
  }

  result_t operator()(YNode const& ynode) const {
    result_t argP = boost::apply_visitor(*this, ynode.arg);
    result_t yesterday(new HyperPLTL::Yesterday(varmap, argP));
    return yesterday;
  }

  result_t operator()(ONode const& onode) const {
    result_t argP = boost::apply_visitor(*this, onode.arg);
    result_t once(new HyperPLTL::Once(varmap, argP));
    return once;
  }

  result_t operator()(SNode const& snode) const {
    result_t leftP = boost::apply_visitor(*this, snode.leftArg);
    result_t rightP = boost::apply_visitor(*this, snode.rightArg);
    result_t since(new HyperPLTL::Since(varmap, leftP, rightP));
    return since;
  }

  result_t operator()(VarNode const& varNode) const {
    return boost::apply_visitor(*this, varNode);
  }
};

struct HPLTLStringBuilder {
  /////////////////////////////////////////////////////////////////
  // visitor methods to generate formula string back from an AST //
  /////////////////////////////////////////////////////////////////

  using result_t = std::string;
  result_t operator()(EqlNode const& eqlNode) const {
    return "(EQ " + eqlNode.varname + ")";
  }

  result_t operator()(TraceSelNode const& selNode) const {
    return selNode.varname + "[" + std::to_string(selNode.traceid) + "] ";
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
    return "(IMPLIES" + boost::apply_visitor(*this, impNode.leftArg) +
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

///////////////////////////////////////////////////////////////////////////////
//  Parse Formula (Main Program)
///////////////////////////////////////////////////////////////////////////////

namespace HyperPLTL {

PHyperProp parse_formula(std::string const& str) {
  typedef std::string::const_iterator iterator_type;
  typedef sexpr::ast::VarNode SExprAst;

  auto& grammar = sexpr::grammar::varexpr;
  SExprAst exprAst;

  iterator_type iter = str.begin();
  iterator_type end = str.end();
  boost::spirit::x3::ascii::space_type space;
  bool r = phrase_parse(iter, end, grammar, space, exprAst);

  if (!r || iter != end) {
    std::cerr << PARSE_ERR_MSG << std::endl;
    exit(1);
  }

  sexpr::ast::HPLTLBuilder propbuilder;
  PHyperProp prop = propbuilder(exprAst);
  return prop;
}

std::string parse_and_regen_string(std::string const& str) {
  typedef std::string::const_iterator iterator_type;
  typedef sexpr::ast::VarNode SExprAst;

  auto& grammar = sexpr::grammar::varexpr;
  SExprAst exprAst;

  iterator_type iter = str.begin();
  iterator_type end = str.end();

  boost::spirit::x3::ascii::space_type space;
  bool r = phrase_parse(iter, end, grammar, space, exprAst);

  if (!r || iter != end) {
    std::cerr << "Error : Parsing failed\n";
    exit(1);
  }

  sexpr::ast::HPLTLStringBuilder strbuilder;
  return strbuilder(exprAst);
}

}  // namespace HyperPLTL
