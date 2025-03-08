#include "ast_node/stat_node/default_stat_node.hpp"
#include "token/token_helper_functions.hpp"
#include <iostream>

namespace mycompiler {

DefaultStatNode::DefaultStatNode(std::shared_ptr<Lexer> lexer)
    : StatNode(lexer), block_(nullptr) {
}

auto DefaultStatNode::print_info() -> void {
  std::cout << "DefaultStatNode: " << std::endl;
  std::cout << "Default block: " << std::endl;
  if (block_) {
    block_->print_info();
  }
}

std::string DefaultStatNode::toString() const {
  std::string result = "default:";
  if (block_) {
    result += " " + block_->toString();
  }
  return result;
}

auto DefaultStatNode::Parse() -> void {
  // 确保当前token是default关键字
  auto currentToken = lexer_->getCurrentToken();
  if (!isKeyword(currentToken, KeywordType::DEFAULT)) {
    throw std::runtime_error("Expected 'default' keyword");
  }
  
  // 消费default关键字
  lexer_->getNextToken();
  
  // 确保下一个token是冒号
  currentToken = lexer_->getCurrentToken();
  if (!isSeparator(currentToken, ":")) {
    throw std::runtime_error("Expected ':' after default keyword");
  }
  
  // 消费冒号
  lexer_->getNextToken();
  
  // 解析default块
  block_ = std::make_shared<BlockStatNode>(lexer_);
  block_->Parse();
}

std::shared_ptr<BlockStatNode> DefaultStatNode::getBlock() const {
  return block_;
}

void DefaultStatNode::setBlock(std::shared_ptr<BlockStatNode> block) {
  block_ = block;
}

bool DefaultStatNode::isTerminating() const {
  // default语句是否终止取决于其块是否终止
  return block_ && block_->isTerminating();
}

} // namespace mycompiler 