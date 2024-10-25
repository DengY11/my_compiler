#include "../../../include/ast_node/expr_node/literal_expr_node.hpp"
#include <memory>

namespace mycompiler {

LiteralExprNode::LiteralExprNode(std::shared_ptr<Lexer> lexer)
    : ExprNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::LITERAL_EXPR;
}

void LiteralExprNode::print_info() {
  std::cout << "Node type: LITERAL_EXPR" << std::endl;
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

} // namespace mycompiler
