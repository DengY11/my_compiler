#include "ast_node/terminal_symbols/terminal_switch.hpp"
#include "token/token_helper_functions.hpp"
#include <iostream>

namespace mycompiler {

TerminalSwitch::TerminalSwitch(std::shared_ptr<Lexer> lexer)
    : ASTNode(lexer) {
}

auto TerminalSwitch::print_info() -> void {
  std::cout << "TerminalSwitch: switch" << std::endl;
}

std::string TerminalSwitch::toString() const {
  return "switch";
}

auto TerminalSwitch::Parse() -> void {
  auto currentToken = lexer_->getCurrentToken();
  
  // 确保当前token是switch关键字
  if (!isKeyword(currentToken, KeywordType::SWITCH)) {
    throw std::runtime_error("Expected 'switch' keyword");
  }
  
  // 消费switch关键字
  lexer_->getNextToken();
}

} // namespace mycompiler
