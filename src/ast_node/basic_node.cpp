#include "../../include/ast_node/basic_node.hpp"
#include <algorithm>
#include <memory>

namespace mycompiler {

BasicNode::BasicNode() : ast_node_type_(mycompiler::AST_NODE_TYPE::BASIC) {}

void BasicNode::print_info() {
  std::cout << "Node type: BASIC" << std::endl;
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

void BasicNode::add_child(std::shared_ptr<BasicNode> childptr) {
  this->children_.emplace_back(childptr);
}

} // namespace mycompiler
