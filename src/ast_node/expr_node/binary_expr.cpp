#include "ast_node/expr_node/binary_expr.hpp"
namespace mycompiler {

BinaryExprNode::BinaryExprNode(std::shared_ptr<Lexer> lexer) : ExprNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::BINNARY_EXPR;
}

void BinaryExprNode::print_info() {
  std::cout << "Node type: BinaryExprNode" << std::endl;
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

} // namespace mycompiler
