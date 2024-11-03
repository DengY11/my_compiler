#include "ast_node/expr_node/unary_expr_node.hpp"

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

// TODO::Parse();
} // namespace mycompiler
