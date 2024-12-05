#include "ast_node/expr_node/binary_expr.hpp"
#include "ast_node/expr_node/expr_node.hpp"
#include "ast_node/expr_node/literal_expr_node.hpp"
#include "ast_node/expr_node/tenary_expr_node.hpp"
#include "ast_node/node_type.hpp"
#include "ast_node/terminal_symbols/terminal_operator.hpp"
namespace mycompiler {

BinaryExprNode::BinaryExprNode(std::shared_ptr<Lexer> lexer) : ExprNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::BINNARY_EXPR;
}
BinaryExprNode::BinaryExprNode(std::shared_ptr<ExprNode> left,
                               std::shared_ptr<TerminalOperator> op,
                               std::shared_ptr<ExprNode> right)
    : ExprNode(nullptr) {
  this->ast_node_type_ = AST_NODE_TYPE::BINNARY_EXPR;
  this->add_child(left, op, right);
}

auto BinaryExprNode::add_child(std::shared_ptr<ExprNode> left,
                               std::shared_ptr<TerminalOperator> op,
                               std::shared_ptr<ExprNode> right) -> void {
  this->children_.push_back(left);
  this->children_.push_back(op);
  this->children_.push_back(right);
}

void BinaryExprNode::print_info() {
  std::cout << "Node type: BinaryExprNode" << std::endl;
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

auto BinaryExprNode::Parse() -> void {

  Token &&token = this->lexer_->getCurrentToken();
  if (token.get_token_type() == TokenType::ILLEGAL_OR_EOF) {
    throw std::runtime_error("illegal token or end of file");
  }

  auto child_left_val = std::make_shared<LiteralExprNode>(this->lexer_);
  child_left_val->Parse();
  this->children_.push_back(child_left_val);

  this->lexer_->getNextToken();

  auto child_operator = std::make_shared<TerminalOperator>(this->lexer_);
  child_operator->Parse();
  this->children_.push_back(child_operator);

  this->lexer_->getNextToken();

  auto child_right_val = std::make_shared<LiteralExprNode>(this->lexer_);
  child_right_val->Parse();
  this->children_.push_back(child_left_val);
}

} // namespace mycompiler
