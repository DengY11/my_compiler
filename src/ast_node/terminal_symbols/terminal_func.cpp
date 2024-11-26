#include "ast_node/terminal_symbols/terminal_func.hpp"
#include <memory>
#include <stdexcept>

namespace mycompiler {

TerminalFunc::TerminalFunc(std::shared_ptr<Lexer> lexer) : BasicNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::FUNC;
}

void TerminalFunc::print_info() {
  std::cout << "Node type: FUNC" << std::endl;
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

void TerminalFunc::Parse() {
  Token token = this->lexer_->getCurrentToken();
  if (token.get_token_type() == TokenType::ILLEGAL_OR_EOF) {
    throw std::runtime_error("illegal or end of file");
  }
  if (!(token.get_token_type() == TokenType::KEYWORD &&
        get_keyword_type_from_token_class(token) == Keyword_Type::FUNC)) {
    throw std::runtime_error("expect func");
  }
}
} // namespace mycompiler
