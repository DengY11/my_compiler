#include "ast_node/expr_node/expr_node.hpp"
#include <memory>

namespace mycompiler {

ExprNode::ExprNode(std::shared_ptr<Lexer> lexer) : BasicNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::EXPR;
}

void ExprNode::print_info() {
  std::cout << "Node type: EXPR" << std::endl;
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

} // namespace mycompiler
