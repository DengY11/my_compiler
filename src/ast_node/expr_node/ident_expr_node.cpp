#include "ast_node/expr_node/ident_expr_node.hpp"
#include "ast_node/terminal_symbols/terminal_ident_literal.hpp"
#include <memory>

namespace mycompiler {

IdentifierExprNode::IdentifierExprNode(std::shared_ptr<Lexer> lexer)
    : ExprNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::IDENTIFIER_EXPR;
}

auto IdentifierExprNode::print_info() -> void {
  std::cout << "Node type: IDENTIFIER_EXPR" << std::endl;
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

auto IdentifierExprNode::Parse() -> void {
  Token token = this->lexer_->getCurrentToken();
  auto child_ident_literal = std::make_shared<TerminalIdentLiteral>();
  child_ident_literal->Parse();
  this->children_.push_back(child_ident_literal);
}

} // namespace mycompiler
