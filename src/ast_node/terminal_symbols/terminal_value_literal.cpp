#include "ast_node/terminal_symbols/terminal_value_literal.hpp"
#include "magic_enum/magic_enum.hpp"
#include <memory>
#include <stdexcept>

namespace mycompiler {

TerminalValueLiteral::TerminalValueLiteral(std::shared_ptr<Lexer> lexer)
    : BasicNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::VALUE_LITERAL;
}

void TerminalValueLiteral::print_info() {
  std::cout << "Node type: " << std::endl;
  std::cout << std::string(magic_enum::enum_name(this->ast_node_type_))
            << std::endl;

  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

void TerminalValueLiteral::Parse() {
  Token token = this->lexer_->getCurrentToken();
  if (token.get_token_type() == TokenType::ILLEGAL_OR_EOF) {
    throw std::runtime_error("illegal or end of file");
  }
  if (!(token.get_token_type() == TokenType::CONSTANT)) {
    throw std::runtime_error("expect a value");
  } else {
    this->literal_ = get_value_literal_type_from_token_class(token);
  }
}
} // namespace mycompiler
