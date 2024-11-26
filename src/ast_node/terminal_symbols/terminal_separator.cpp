#include "ast_node/terminal_symbols/terminal_separator.hpp"
#include "magic_enum/magic_enum.hpp"
#include <memory>
#include <stdexcept>

namespace mycompiler {

TerminalSeparator::TerminalSeparator(std::shared_ptr<Lexer> lexer)
    : BasicNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::TERMINAL_SEPARATOR;
}

void TerminalSeparator::print_info() {
  std::cout << "Node type: " << std::endl;
  std::cout << std::string(magic_enum::enum_name(this->ast_node_type_))
            << std::endl;

  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

void TerminalSeparator::Parse() {
  Token &&token = this->lexer_->getCurrentToken();
  if (!(token.get_token_type() != TokenType::SEPARATOR)) {
    throw std::runtime_error("expect a separator ");
  } else {
    this->separator_ = get_separator_type_from_token_class(token);
  }
}
} // namespace mycompiler
