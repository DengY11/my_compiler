#include "../../../include/ast_node/decl_node/variable_decl_node.hpp"

namespace mycompiler {

VarDeclNode::VarDeclNode() : DeclNode() {
  this->ast_node_type_ = AST_NODE_TYPE::VARIABLE_DECL;
}

} // namespace mycompiler
