#include "ast_node/stat_node/continue_stat_node.hpp"
#include "magic_enum/magic_enum.hpp"
#include <memory>

namespace mycompiler {

ContinueStatNode::ContinueStatNode(std::shared_ptr<Lexer> lexer)
    : StatNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::CONTINUE_STAT;
}

void ContinueStatNode::print_info() {
  std::cout << "Node type: " << std::endl;
  std::cout << std::string(magic_enum::enum_name(this->ast_node_type_))
            << std::endl;

  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

void ContinueStatNode::Parse() {

  Token token = this->lexer_->getCurrentToken();
  if (token.get_token_type() == TokenType::ILLEGAL_OR_EOF) {
    throw std::runtime_error("illegal or end of file");
  }

  auto child_terminal_continue =
      std::make_shared<ContinueStatNode>(this->lexer_);
  child_terminal_continue->Parse();

  this->children_.push_back(child_terminal_continue);
}

} // namespace mycompiler
