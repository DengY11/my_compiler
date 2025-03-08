#include "ast_node/stat_node/expr_stat_node.hpp"
#include "token/token_helper_functions.hpp"
#include <iostream>

namespace mycompiler {

ExprStatNode::ExprStatNode(std::shared_ptr<Lexer> lexer)
    : StatNode(lexer), expression_(nullptr) {
}

auto ExprStatNode::print_info() -> void {
  std::cout << "ExprStatNode: " << std::endl;
  if (expression_) {
    expression_->print_info();
  }
}

std::string ExprStatNode::toString() const {
  std::string result;
  if (expression_) {
    result = expression_->toString();
  }
  result += ";";
  return result;
}

auto ExprStatNode::Parse() -> void {
  // 解析表达式
  expression_ = std::make_shared<ExprNode>(lexer_);
  expression_->Parse();
  
  // 确保下一个token是分号
  auto currentToken = lexer_->getCurrentToken();
  if (!isSeparator(currentToken, ";")) {
    throw std::runtime_error("Expected ';' at the end of expression statement");
  }
  
  // 消费分号
  lexer_->getNextToken();
}

std::shared_ptr<ExprNode> ExprStatNode::getExpression() const {
  return expression_;
}

void ExprStatNode::setExpression(std::shared_ptr<ExprNode> expression) {
  expression_ = expression;
}

bool ExprStatNode::isTerminating() const {
  // 表达式语句通常不是终止语句
  return false;
}

} // namespace mycompiler 