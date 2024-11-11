#include "ast_node/stat_node/void_stat_node.hpp"

namespace mycompiler {

VoidStatNode ::VoidStatNode(std::shared_ptr<Lexer> lexer) : StatNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::VOID_STAT;
}

void VoidStatNode::print_info() {
  std::cout << "Node type: VOID_STAT" << std::endl;
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

void VoidStatNode::Parse() {}

} // namespace mycompiler
