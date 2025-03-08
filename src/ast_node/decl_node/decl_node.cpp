#include "ast_node/decl_node/decl_node.hpp"
#include "ast_node/stat_node/stat_node.hpp"
#include "magic_enum/magic_enum.hpp"
#include <sstream>

namespace mycompiler {

DeclNode::DeclNode(std::shared_ptr<Lexer> lexer) : BasicNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::DECL;
}

void DeclNode::print_info() {
  std::cout << "Node type: DECL" << std::endl;
  std::cout << "Name: " << getName() << std::endl;
  std::cout << "Type: " << getType() << std::endl;
  
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

std::string DeclNode::toString() const {
  std::stringstream ss;
  ss << "Declaration of " << getName() << " with type " << getType();
  return ss.str();
}

std::string DeclNode::getName() const {
  return name_;
}

std::string DeclNode::getType() const {
  return type_;
}

} // namespace mycompiler
