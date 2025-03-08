#include "ast_node/expr_node/literal_expr_node.hpp"
#include "ast_node/expr_node/binary_expr.hpp"
#include "ast_node/expr_node/expr_node.hpp"
#include "ast_node/expr_node/function_called_return_value_expr_node.hpp"
#include "ast_node/expr_node/group_expr_node.hpp"
#include "ast_node/expr_node/ident_expr_node.hpp"
#include "ast_node/expr_node/pratt_parser.hpp"
#include "ast_node/expr_node/tenary_expr_node.hpp"
#include "ast_node/expr_node/unary_expr_node.hpp"
#include "ast_node/terminal_symbols/terminal_ident_literal.hpp"
#include "ast_node/terminal_symbols/terminal_operator.hpp"
#include "ast_node/terminal_symbols/terminal_value_literal.hpp"
#include "lexer/lexer_helper_functions.hpp"
#include "token/operator_type.hpp"
#include "token/token_helper_functions.hpp"
#include "token/token_type.hpp"
#include <memory>
#include <stdexcept>

namespace mycompiler {

LiteralExprNode::LiteralExprNode(std::shared_ptr<Lexer> lexer)
    : ExprNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::LITERAL_EXPR;
  if (lexer) {
    pratt_parser_ = std::make_shared<PrattParser>(lexer);
  }
}

LiteralExprNode::LiteralExprNode(std::shared_ptr<TerminalIdentLiteral> var_name,
                                 std::shared_ptr<TerminalOperator> op,
                                 std::shared_ptr<TerminalValueLiteral> value)
    : ExprNode(nullptr) {

  this->ast_node_type_ = AST_NODE_TYPE::LITERAL_EXPR;

  this->children_.push_back(var_name);
  this->children_.push_back(op);
  this->children_.push_back(value);
}

void LiteralExprNode::print_info() {
  std::cout << "Node type: LITERAL_EXPR" << std::endl;
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

void LiteralExprNode::ParseExpression() {
  // 使用Pratt解析器解析表达式
  if (!pratt_parser_) {
    throw std::runtime_error("Pratt parser not initialized");
  }
  
  auto expr = pratt_parser_->parseExpression();
  this->children_.push_back(expr);
}

void LiteralExprNode::ParseTerm() {
  // 使用Pratt解析器解析项
  if (!pratt_parser_) {
    throw std::runtime_error("Pratt parser not initialized");
  }
  
  auto expr = pratt_parser_->parseExpression(Precedence::TERM);
  this->children_.push_back(expr);
}

void LiteralExprNode::ParseFactor() {
  // 使用Pratt解析器解析因子
  if (!pratt_parser_) {
    throw std::runtime_error("Pratt parser not initialized");
  }
  
  auto expr = pratt_parser_->parseExpression(Precedence::FACTOR);
  this->children_.push_back(expr);
}

void LiteralExprNode::ParseUnary() {
  // 使用Pratt解析器解析一元表达式
  if (!pratt_parser_) {
    throw std::runtime_error("Pratt parser not initialized");
  }
  
  auto expr = pratt_parser_->parseExpression(Precedence::UNARY);
  this->children_.push_back(expr);
}

void LiteralExprNode::Parse() {
  if (!this->lexer_) {
    throw std::runtime_error("can not Parse");
  }

  // 使用Pratt解析器解析表达式
  if (!pratt_parser_) {
    pratt_parser_ = std::make_shared<PrattParser>(this->lexer_);
  }
  
  auto expr = pratt_parser_->parseExpression();
  this->children_.push_back(expr);
}

void LiteralExprNode::add_terminalvalue_node(std::shared_ptr<TerminalValueLiteral> val) {
  this->children_.push_back(val);
}

} // namespace mycompiler
