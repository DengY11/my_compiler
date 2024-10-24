#include "../../../include/ast_node/decl_node/function_decl_node.hpp"

namespace mycompiler {

FuncDeclNode::FuncDeclNode() : DeclNode() {
  this->ast_node_type_ = AST_NODE_TYPE::FUNCTION_DECL;
}

void FuncDeclNode::print_info() {
  std::cout << "Node type:: FUNCTION_DECL" << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

} // namespace mycompiler
