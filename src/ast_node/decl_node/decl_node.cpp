#include "ast_node/decl_node/decl_node.hpp"
#include "ast_node/stat_node/stat_node.hpp"

namespace mycompiler {

DeclNode::DeclNode(std::shared_ptr<Lexer> lexer) : BasicNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::DECL;
}

void DeclNode::print_info() {
  std::cout << "Node type: DELC" << std::endl;
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

} // namespace mycompiler
