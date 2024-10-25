#include "../../../include/ast_node/expr_node/ident_expr_node.hpp"
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

} // namespace mycompiler
