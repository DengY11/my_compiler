#include "ast_node/basic_node.hpp"
#include "magic_enum/magic_enum.hpp"
#include <algorithm>
#include <memory>

namespace mycompiler {

BasicNode::BasicNode(std::shared_ptr<Lexer> lexer)
    : ast_node_type_(mycompiler::AST_NODE_TYPE::BASIC), lexer_(lexer) {}

void BasicNode::print_info() {
  std::cout << "Node type: " << std::endl;
  std::cout << std::string(magic_enum::enum_name(this->ast_node_type_))
            << std::endl;

  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

void BasicNode::add_child(std::shared_ptr<BasicNode> childptr) {
  this->children_.emplace_back(childptr);
}

} // namespace mycompiler
