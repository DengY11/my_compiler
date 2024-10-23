#include "../../../include/ast_node/decl_node/decl_node.hpp"

namespace mycompiler {

DeclNode::DeclNode() : BasicNode() {
  this->ast_node_type_ = AST_NODE_TYPE::DECL;
}

void DeclNode::print_info() {
  std::cout << "Node type: BASIC_DELC" << std::endl;
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

} // namespace mycompiler
