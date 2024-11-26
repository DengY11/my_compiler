#include "ast_node/expr_node/unary_expr_node.hpp"
#include "ast_node/expr_node/literal_expr_node.hpp"
#include "ast_node/terminal_symbols/terminal_operator.hpp"
#include <memory>

namespace mycompiler {

UnaryExprNode::UnaryExprNode(std::shared_ptr<Lexer> lexer) : ExprNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::UNARY_EXPR;
}

auto UnaryExprNode::print_info() -> void {
  std::cout << "Node type: UNARY_EXPR" << std::endl;
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

auto UnaryExprNode::Parse() -> void {

  Token &&token = this->lexer_->getCurrentToken();
  if (token.get_token_type() == TokenType::ILLEGAL_OR_EOF) {
    throw std::runtime_error("illegal token or end of file");
  }

  auto child_operator = std::make_shared<TerminalOperator>(this->lexer_);
  child_operator->Parse();
  this->children_.push_back(child_operator);

  this->lexer_->getCurrentToken();
  auto child_val = std::make_shared<LiteralExprNode>(this->lexer_);
  child_val->Parse();
  this->children_.push_back(child_val);
}

} // namespace mycompiler
