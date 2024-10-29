#include "../../../include/ast_node/decl_node/variable_decl_node.hpp"
#include "../../../include/ast_node//terminal_symbols/terminal_let.hpp"
#include <memory>
#include <stdexcept>

namespace mycompiler {

VarDeclNode::VarDeclNode(std::shared_ptr<Lexer> lexer) : DeclNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::VARIABLE_DECL;
}

void VarDeclNode::print_info() {
  std::cout << "Node type: VARIABLE_DECL" << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

void VarDeclNode::Parse() {
  Token &&token = this->lexer_->getCurrentToken();
  if (token.get_token_type() == TokenType::ILLEGAL_OR_EOF) {
    throw std::runtime_error("illegal token or end of file");
  }
  auto child_let = std::make_shared<BasicNode>();
  child_let->Parse();
  this->children_.push_back(child_let);
}

} // namespace mycompiler
