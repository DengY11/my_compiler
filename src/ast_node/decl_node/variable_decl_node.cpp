#include "../../../include/ast_node/decl_node/variable_decl_node.hpp"

namespace mycompiler {

VarDeclNode::VarDeclNode(std::shared_ptr<Lexer> lexer) : DeclNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::VARIABLE_DECL;
}

void VarDeclNode::print_info() {
  std::cout << "Node type: VARIABLE_DECL" << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

} // namespace mycompiler
