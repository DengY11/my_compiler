#include "ast_node/terminal_symbols/terminal_return.hpp"
#include "ast_node/basic_node.hpp"
#include "ast_node/node_type.hpp"
#include "magic_enum/magic_enum.hpp"
#include "token/keyword_type.hpp"
#include "token/token_helper_functions.hpp"
#include "token/token_type.hpp"
#include <memory>
#include <stdexcept>

namespace mycompiler {

TerminalReturn::TerminalReturn(std::shared_ptr<Lexer> lexer)
    : BasicNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::RETURN;
}

void TerminalReturn::print_info() {
  std::cout << "Node type: " << std::endl;
  std::cout << std::string(magic_enum::enum_name(this->ast_node_type_))
            << std::endl;

  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

void TerminalReturn::Parse() {
  Token token = this->lexer_->getCurrentToken();
  if (token.get_token_type() == TokenType::ILLEGAL_OR_EOF) {
    throw std::runtime_error("illegal or end of file");
  }

  if (!(token.get_token_type() == TokenType::KEYWORD &&
        get_keyword_type_from_token_class(token) == Keyword_Type::RETURN)) {
    throw std::runtime_error("expect return");
  }
}

} // namespace mycompiler
