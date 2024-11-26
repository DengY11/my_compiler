#include "ast_node/stat_node/function_decl_stat_node.hpp"
#include "ast_node/basic_node.hpp"
#include "ast_node/decl_node/function_decl_node.hpp"
#include "magic_enum/magic_enum.hpp"
#include <memory>

namespace mycompiler {

FunctionDeclStatNode ::FunctionDeclStatNode(std::shared_ptr<Lexer> lexer)
    : StatNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::FUNCTION_DECL_STAT;
}

void FunctionDeclStatNode::print_info() {
  std::cout << "Node type: " << std::endl;
  std::cout << std::string(magic_enum::enum_name(this->ast_node_type_))
            << std::endl;

  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

void FunctionDeclStatNode::Parse() {

  Token &&token = this->lexer_->getCurrentToken();
  if (token.get_token_type() == TokenType::ILLEGAL_OR_EOF) {
    throw std::runtime_error("illegal token or end of file");
  }

  auto function_decl_node = std::make_shared<FuncDeclNode>(this->lexer_);
  function_decl_node->Parse();

  this->children_.push_back(
      std::dynamic_pointer_cast<BasicNode>(function_decl_node));
}

} // namespace mycompiler
