#include "ast_node/expr_node/tenary_expr_node.hpp"
#include "ast_node/expr_node/literal_expr_node.hpp"
#include "ast_node/terminal_symbols/terminal_operator.hpp"
#include <memory>

namespace mycompiler {

TenaryExprNode::TenaryExprNode(std::shared_ptr<Lexer> lexer) : ExprNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::TENARY_EXPR;
}

auto TenaryExprNode::print_info() -> void {
  std::cout << "Node type: TENARY_EXPR" << std::endl;
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

auto TenaryExprNode::Parse() -> void {

  Token &&token = this->lexer_->getCurrentToken();
  if (token.get_token_type() == TokenType::ILLEGAL_OR_EOF) {
    throw std::runtime_error("illegal token or end of file");
  }

  auto child_left_val = std::make_shared<LiteralExprNode>(this->lexer_);
  child_left_val->Parse();
  this->children_.push_back(child_left_val);

  auto child_operator = std::make_shared<TerminalOperator>(this->lexer_);
  child_operator->Parse();
  this->children_.push_back(child_operator);

  auto child_right_val = std::make_shared<LiteralExprNode>(this->lexer_);
  child_right_val->Parse();
  this->children_.push_back(child_left_val);
}

} // namespace mycompiler
