#include "ast_node/stat_node/case_stat_node.hpp"
#include "token/token_helper_functions.hpp"
#include <iostream>

namespace mycompiler {

CaseStatNode::CaseStatNode(std::shared_ptr<Lexer> lexer)
    : StatNode(lexer), expression_(nullptr), block_(nullptr), isDefault_(false) {
}

auto CaseStatNode::print_info() -> void {
  std::cout << "CaseStatNode: " << std::endl;
  if (isDefault_) {
    std::cout << "Default case" << std::endl;
  } else {
    std::cout << "Case expression: " << std::endl;
    if (expression_) {
      expression_->print_info();
    }
  }
  std::cout << "Case block: " << std::endl;
  if (block_) {
    block_->print_info();
  }
}

std::string CaseStatNode::toString() const {
  std::string result;
  if (isDefault_) {
    result = "default:";
  } else {
    result = "case ";
    if (expression_) {
      result += expression_->toString();
    }
    result += ":";
  }
  if (block_) {
    result += " " + block_->toString();
  }
  return result;
}

auto CaseStatNode::Parse() -> void {
  auto currentToken = lexer_->getCurrentToken();
  
  // 检查是case还是default
  if (isKeyword(currentToken, KeywordType::CASE)) {
    isDefault_ = false;
    
    // 消费case关键字
    lexer_->getNextToken();
    
    // 解析case表达式
    expression_ = std::make_shared<ExprNode>(lexer_);
    expression_->Parse();
  } else if (isKeyword(currentToken, KeywordType::DEFAULT)) {
    isDefault_ = true;
    
    // 消费default关键字
    lexer_->getNextToken();
  } else {
    throw std::runtime_error("Expected 'case' or 'default' keyword");
  }
  
  // 确保下一个token是冒号
  currentToken = lexer_->getCurrentToken();
  if (!isSeparator(currentToken, ":")) {
    throw std::runtime_error("Expected ':' after case expression or default keyword");
  }
  
  // 消费冒号
  lexer_->getNextToken();
  
  // 解析case块
  block_ = std::make_shared<BlockStatNode>(lexer_);
  block_->Parse();
}

std::shared_ptr<ExprNode> CaseStatNode::getExpression() const {
  return expression_;
}

std::shared_ptr<BlockStatNode> CaseStatNode::getBlock() const {
  return block_;
}

void CaseStatNode::setExpression(std::shared_ptr<ExprNode> expression) {
  expression_ = expression;
}

void CaseStatNode::setBlock(std::shared_ptr<BlockStatNode> block) {
  block_ = block;
}

bool CaseStatNode::isTerminating() const {
  // case语句是否终止取决于其块是否终止
  return block_ && block_->isTerminating();
}

bool CaseStatNode::isDefault() const {
  return isDefault_;
}

void CaseStatNode::setDefault(bool isDefault) {
  isDefault_ = isDefault;
}

} // namespace mycompiler 