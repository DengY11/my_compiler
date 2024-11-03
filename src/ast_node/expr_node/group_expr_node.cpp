#include "ast_node/expr_node/group_expr_node.hpp"
#include <memory>

namespace mycompiler {

GroupExprNode::GroupExprNode(std::shared_ptr<Lexer> lexer) : ExprNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::GROUPING_EXPR;
}

auto GroupExprNode::print_info() -> void {
  std::cout << "Node type: GROUPING_EXPR" << std::endl;
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

} // namespace mycompiler
