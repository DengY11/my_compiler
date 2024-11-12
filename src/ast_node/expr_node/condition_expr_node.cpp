#include "ast_node/expr_node/condition_expr_node.hpp"
#include "ast_node/expr_node/expr_node.hpp"
#include "ast_node/expr_node/literal_expr_node.hpp"
#include "ast_node/expr_node/tenary_expr_node.hpp"
#include "ast_node/node_type.hpp"
#include <algorithm>
#include <memory>

namespace mycompiler {

ConditionExprNode::ConditionExprNode(std::shared_ptr<Lexer> lexer)
    : ExprNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::COMPARE_EXPR;
}

void ConditionExprNode::print_info() {
  std::cout << "Node type: COMPARE_EXPR" << std::endl;
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

void ConditionExprNode::Parse() {
  Token &&token = this->lexer_->getCurrentToken();
  if (token.get_token_type() == TokenType::ILLEGAL_OR_EOF) {
    throw std::runtime_error("illegal token or end of file");
  }

  auto child_literal_expr_node =
      std::make_shared<LiteralExprNode>(this->lexer_);
  child_literal_expr_node->Parse();
  this->children_.push_back(child_literal_expr_node);
}

} // namespace mycompiler
