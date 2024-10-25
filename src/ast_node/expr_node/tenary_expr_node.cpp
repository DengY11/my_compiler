#include "../../../include/ast_node/expr_node/tenary_expr_node.hpp"
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

} // namespace mycompiler
