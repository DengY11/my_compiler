#include "ast_node/stat_node/expression_stat_node.hpp"
#include "ast_node/expr_node/literal_expr_node.hpp"
#include "ast_node/terminal_symbols/terminal_separator.hpp"
#include <memory>

namespace mycompiler {

ExpressionStatNode::ExpressionStatNode(std::shared_ptr<Lexer> lexer)
    : StatNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::EXPRESSION_STAT;
}

void ExpressionStatNode::print_info() {
  std::cout << "Node type: EXPRESSION_STAT" << std::endl;
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

void ExpressionStatNode::Parse() {
  Token token = this->lexer_->getCurrentToken();
  if (token.get_token_type() == TokenType::ILLEGAL_OR_EOF) {
    throw std::runtime_error("illegal or end of file");
  }

  auto child_expr = std::make_shared<LiteralExprNode>(this->lexer_);
  child_expr->Parse();
  this->children_.push_back(child_expr);

  this->lexer_->getNextToken();

  auto child_semicolon = std::make_shared<TerminalSeparator>(this->lexer_);
  child_semicolon->Parse();
  if (child_semicolon->separator_ != ";") {
    throw std::runtime_error("expect ;");
  } else {
    this->children_.push_back(child_semicolon);
  }
}

} // namespace mycompiler
