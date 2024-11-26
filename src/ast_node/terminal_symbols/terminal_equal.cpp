#include "ast_node/terminal_symbols/terminal_equal.hpp"
#include "magic_enum/magic_enum.hpp"
#include <memory>
#include <stdexcept>

namespace mycompiler {

TerminalEqual::TerminalEqual(std::shared_ptr<Lexer> lexer) : BasicNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::EQUAL;
}

void TerminalEqual::print_info() {
  std::cout << "Node type: " << std::endl;
  std::cout << std::string(magic_enum::enum_name(this->ast_node_type_))
            << std::endl;

  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

void TerminalEqual::Parse() {
  Token token = this->lexer_->getCurrentToken();
  if (token.get_token_type() == TokenType::ILLEGAL_OR_EOF) {
    throw std::runtime_error("illegal or end of file");
  }
  if (!(token.get_token_type() == TokenType::OPERATOR &&
        get_operator_type_from_token_class(token) == Operator_Type::EQUAL)) {
    throw std::runtime_error("expect =");
  }
}
} // namespace mycompiler
