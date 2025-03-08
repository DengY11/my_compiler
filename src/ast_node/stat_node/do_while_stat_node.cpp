#include "ast_node/stat_node/do_while_stat_node.hpp"
#include "token/token_helper_functions.hpp"
#include <iostream>

namespace mycompiler {

DoWhileStatNode::DoWhileStatNode(std::shared_ptr<Lexer> lexer)
    : StatNode(lexer), body_(nullptr), condition_(nullptr) {
}

auto DoWhileStatNode::print_info() -> void {
  std::cout << "DoWhileStatNode: " << std::endl;
  if (body_) {
    std::cout << "Body: " << std::endl;
    body_->print_info();
  }
  if (condition_) {
    std::cout << "Condition: " << std::endl;
    condition_->print_info();
  }
}

std::string DoWhileStatNode::toString() const {
  std::string result = "do ";
  if (body_) {
    result += body_->toString();
  }
  result += " while (";
  if (condition_) {
    result += condition_->toString();
  }
  result += ");";
  return result;
}

auto DoWhileStatNode::Parse() -> void {
  // 确保当前token是do关键字
  auto currentToken = lexer_->getCurrentToken();
  if (!isKeyword(currentToken, KeywordType::DO)) {
    throw std::runtime_error("Expected 'do' keyword at the beginning of do-while statement");
  }
  
  // 消费do关键字
  lexer_->getNextToken();
  
  // 解析循环体
  body_ = std::make_shared<BlockStatNode>(lexer_);
  body_->Parse();
  
  // 确保下一个token是while关键字
  currentToken = lexer_->getCurrentToken();
  if (!isKeyword(currentToken, KeywordType::WHILE)) {
    throw std::runtime_error("Expected 'while' keyword after do block");
  }
  
  // 消费while关键字
  lexer_->getNextToken();
  
  // 确保下一个token是左括号
  currentToken = lexer_->getCurrentToken();
  if (!isSeparator(currentToken, "(")) {
    throw std::runtime_error("Expected '(' after 'while' keyword");
  }
  
  // 消费左括号
  lexer_->getNextToken();
  
  // 解析条件表达式
  condition_ = std::make_shared<ExprNode>(lexer_);
  condition_->Parse();
  
  // 确保下一个token是右括号
  currentToken = lexer_->getCurrentToken();
  if (!isSeparator(currentToken, ")")) {
    throw std::runtime_error("Expected ')' after condition in do-while statement");
  }
  
  // 消费右括号
  lexer_->getNextToken();
  
  // 确保下一个token是分号
  currentToken = lexer_->getCurrentToken();
  if (!isSeparator(currentToken, ";")) {
    throw std::runtime_error("Expected ';' at the end of do-while statement");
  }
  
  // 消费分号
  lexer_->getNextToken();
}

std::shared_ptr<BlockStatNode> DoWhileStatNode::getBody() const {
  return body_;
}

std::shared_ptr<ExprNode> DoWhileStatNode::getCondition() const {
  return condition_;
}

void DoWhileStatNode::setBody(std::shared_ptr<BlockStatNode> body) {
  body_ = body;
}

void DoWhileStatNode::setCondition(std::shared_ptr<ExprNode> condition) {
  condition_ = condition;
}

bool DoWhileStatNode::isTerminating() const {
  // do-while循环只有在条件为常量true且循环体是终止语句时才是终止语句
  if (condition_ && condition_->isConstant()) {
    // 检查条件是否为常量true
    // 这里需要进一步实现，判断条件的值是否为true
    // 暂时简化处理，假设不是常量true
    return false;
  }
  return false;
}

} // namespace mycompiler 