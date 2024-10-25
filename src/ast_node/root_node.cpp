#include "../../include/ast_node/root_node.hpp"
#include <ostream>

namespace mycompiler {

RootNode::RootNode(std::shared_ptr<Lexer> lexer) : BasicNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::ROOT;
}

void RootNode::print_info() {
  std::cout << "Node type: ROOT" << std::endl;
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

} // namespace mycompiler
