#include "ast_node/decl_node/lambda_decl_node.hpp"
#include <memory>

namespace mycompiler {

LambdaDeclNode::LambdaDeclNode(std::shared_ptr<Lexer> lexer) : DeclNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::LAMBDA_DECL;
}

void LambdaDeclNode::print_info() {
  std::cout << "Node type: LAMBDA_DECL" << std::endl;
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

} // namespace mycompiler
