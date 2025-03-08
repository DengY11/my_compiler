#include "ast_node/stat_node/empty_stat_node.hpp"
#include "token/token_helper_functions.hpp"
#include <iostream>

namespace mycompiler {

EmptyStatNode::EmptyStatNode(std::shared_ptr<Lexer> lexer)
    : StatNode(lexer) {
}

auto EmptyStatNode::print_info() -> void {
  std::cout << "EmptyStatNode: ;" << std::endl;
}

std::string EmptyStatNode::toString() const {
  return ";";
}

auto EmptyStatNode::Parse() -> void {
  // 确保当前token是分号
  auto currentToken = lexer_->getCurrentToken();
  if (!isSeparator(currentToken, ";")) {
    throw std::runtime_error("Expected ';' for empty statement");
  }
  
  // 消费分号
  lexer_->getNextToken();
}

bool EmptyStatNode::isTerminating() const {
  // 空语句不是终止语句
  return false;
}

} // namespace mycompiler 