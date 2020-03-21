
///////////////////////////////////////////////////////////////////////////////
// Uncomment this if you want to enable debugging
// #define BOOST_SPIRIT_X3_DEBUG

#include <boost/config/warning_disable.hpp>
#include <boost/spirit/home/x3.hpp>
#include <boost/spirit/home/x3/support/ast/variant.hpp>
#include <boost/fusion/include/adapt_struct.hpp>

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <numeric>
#include <memory>

namespace x3 = boost::spirit::x3;

namespace sexpr::ast
{
///////////////////////////////////////////////////////////////////////////
//  The AST
///////////////////////////////////////////////////////////////////////////

struct nil {};

struct AndNode;
struct OrNode;
struct ImpNode;
struct NotNode;


struct GNode;
struct YNode;
struct ONode;
struct SNode;


struct VarNode : x3::variant < nil,
                               std::string,
                               x3::forward_ast<AndNode>,
                               x3::forward_ast<OrNode>,
                               x3::forward_ast<ImpNode>,
                               x3::forward_ast<NotNode>,
                               x3::forward_ast<GNode>,
                               x3::forward_ast<YNode>,
                               x3::forward_ast<ONode>,
                               x3::forward_ast<SNode>
                               > {
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
struct SNode : UnaryOpNode {};

// print function for debugging
// inline std::ostream& operator<<(std::ostream& out, nil) { out << "nil"; return out; }
}

BOOST_FUSION_ADAPT_STRUCT(sexpr::ast::AndNode,
                          opname, leftArg, rightArg);

BOOST_FUSION_ADAPT_STRUCT(sexpr::ast::OrNode,
                          opname, leftArg, rightArg);

BOOST_FUSION_ADAPT_STRUCT(sexpr::ast::ImpNode,
                          opname, leftArg, rightArg);

BOOST_FUSION_ADAPT_STRUCT(sexpr::ast::NotNode,
                          opname, arg);

BOOST_FUSION_ADAPT_STRUCT(sexpr::ast::GNode,
                          opname, arg);

BOOST_FUSION_ADAPT_STRUCT(sexpr::ast::YNode,
                          opname, arg);

BOOST_FUSION_ADAPT_STRUCT(sexpr::ast::ONode,
                          opname, arg);

BOOST_FUSION_ADAPT_STRUCT(sexpr::ast::SNode,
                          opname, arg);


namespace sexpr::grammar {

///////////////////////////////////////////////////////////////////////////////
//  Grammar
///////////////////////////////////////////////////////////////////////////////

x3::rule<class IdExpr, std::string> idexpr ("idexpr");
x3::rule<class VarExpr, ast::VarNode> varexpr ("varexpr");

x3::rule<class OrExpr, ast::OrNode> orexpr ("orexpr");
x3::rule<class AndExpr, ast::AndNode> andexpr ("andexpr");
x3::rule<class ImpExpr, ast::ImpNode> impexpr ("impexpr");
x3::rule<class NotExpr, ast::NotNode> notexpr ("notexpr");

x3::rule<class GExpr, ast::GNode> gexpr("gexpr");
x3::rule<class YExpr, ast::YNode> yexpr("yexpr");
x3::rule<class OExpr, ast::ONode> oexpr("oexpr");
x3::rule<class SExpr, ast::SNode> sexpr("sexpr");

x3::rule<class TermExpr, ast::VarNode> termexpr ("termexpr");

auto const andstr = x3::string("AND");
auto const orstr = x3::string("OR");
auto const impstr = x3::string("IMPLIES");
auto const notstr = x3::string("NOT");

auto const gstr = x3::string("G");
auto const ystr = x3::string("Y");
auto const ostr = x3::string("O");
auto const sstr = x3::string("S");

auto const keywords = andstr | orstr | notstr | impstr | gstr | ystr | ostr | sstr;

auto const idexpr_def = (x3::lexeme[x3::alpha >> *(x3::alnum)] - keywords);

auto const varexpr_def =
    '(' >>
    	(notexpr | andexpr | orexpr | impexpr | gexpr | yexpr | oexpr | sexpr)
    >> ')';

auto const orexpr_def = orstr >> termexpr >> termexpr;
auto const andexpr_def = andstr >> termexpr >> termexpr;
auto const impexpr_def = impstr >> termexpr >> termexpr;
auto const notexpr_def = notstr >> termexpr;

auto const gexpr_def = gstr >> termexpr;
auto const yexpr_def = ystr >> termexpr;
auto const oexpr_def = ostr >> termexpr;
auto const sexpr_def = sstr >> termexpr;

auto const termexpr_def = idexpr | varexpr;

BOOST_SPIRIT_DEFINE( idexpr, varexpr, notexpr, andexpr, orexpr, impexpr, termexpr,
                     gexpr, yexpr, oexpr, sexpr)

}

namespace sexpr::ast {

///////////////////////////////////////////////////////////////////////////////
//  AST visitor methods
///////////////////////////////////////////////////////////////////////////////

struct HPLTLPrinter {

  typedef void result_type;

  void operator()(nil) const {
    std::cout << "NIL" << std::endl;
  };

  void operator()(std::string str) const {
    std::cout << str << " ";
  }

  void operator()(AndNode const& andNode) const {
    std::cout << "AND( ";
    boost::apply_visitor(*this, andNode.leftArg);
    boost::apply_visitor(*this, andNode.rightArg);
    std::cout << ")";
  }

  void operator()(OrNode const& orNode) const {
    std::cout << "OR( ";
    boost::apply_visitor(*this, orNode.leftArg);
    boost::apply_visitor(*this, orNode.rightArg);
    std::cout << ")";
  }

  void operator()(NotNode const& notNode) const {
    std::cout << "NOT( ";
    boost::apply_visitor(*this, notNode.arg);
    std::cout << ")";    
  }
  void operator()(ImpNode const& impNode) const {
    std::cout << "IMPLIES( ";
    boost::apply_visitor(*this, impNode.leftArg);
    boost::apply_visitor(*this, impNode.rightArg);
    std::cout << ")";
  }
  
  void operator()(GNode const& gnode) const {
    std::cout << "G( ";
    boost::apply_visitor(*this, gnode.arg);
    std::cout << ")";
  }
  
  void operator()(YNode const& ynode) const {
    std::cout << "Y( ";
    boost::apply_visitor(*this, ynode.arg);
    std::cout << ")";
  }
  
  void operator()(ONode const& onode) const {
    std::cout << "O( ";
    boost::apply_visitor(*this, onode.arg);
    std::cout << ")";
  }
  
  void operator()(SNode const& snode) const {
    boost::apply_visitor(*this, snode.arg);
  }
  
  void operator()(VarNode const& varNode) const {
    boost::apply_visitor(*this, varNode);
    std::cout << std::endl;
  }
  
};

}


///////////////////////////////////////////////////////////////////////////////
//  Main program
///////////////////////////////////////////////////////////////////////////////
int main()
{
  std::cout << "\n\n/////////////////////////////////////////////////////////\n";
  std::cout << "S-Expression parser...\n";
  std::cout << "/////////////////////////////////////////////////////////\n\n";
  std::cout << "Type an expression...or [q or Q] to quit\n\n";

  typedef std::string::const_iterator iterator_type;
  typedef sexpr::ast::VarNode s_expr;

  std::string str;
  
  while (std::getline(std::cin, str))
  {
    if (str.empty() || str[0] == 'q' || str[0] == 'Q')
      break;

    auto& grammar = sexpr::grammar::varexpr;    // Our grammar
    s_expr expr;                // Our program (AST)

    iterator_type iter = str.begin();
    iterator_type end = str.end();
    boost::spirit::x3::ascii::space_type space;
    bool r = phrase_parse(iter, end, grammar, space, expr);

    if (r && iter == end)
    {
      std::cout << "-------------------------\n";
      std::cout << "Parsing succeeded\n";
      std::cout << "-------------------------\n";
    }
    else
    {
      std::cout << "-------------------------\n";
      std::cout << "Parsing failed\n";
      std::cout << "-------------------------\n";
    }

    // calling visitor method on the AST
    sexpr::ast::HPLTLPrinter printer;
    printer(expr);
  }

  std::cout << "Bye... :-) \n\n";
  return 0;
}
