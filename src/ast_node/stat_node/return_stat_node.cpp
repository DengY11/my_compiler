#include "ast_node/stat_node/return_stat_node.hpp"
#include "ast_node/expr_node/literal_expr_node.hpp"
#include "ast_node/terminal_symbols/terminal_return.hpp"
#include "ast_node/terminal_symbols/terminal_separator.hpp"
#include "magic_enum/magic_enum.hpp"
#include "token/token_helper_functions.hpp"
#include <memory>
#include <sstream>

namespace mycompiler {

ReturnStatNode::ReturnStatNode(std::shared_ptr<Lexer> lexer) : StatNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::RETURN_STAT;
  this->statType_ = StatType::RETURN_STAT;
}

auto ReturnStatNode::print_info() -> void {
  std::cout << "Node type: RETURN_STAT" << std::endl;
  
  std::cout << "Return value: " << std::endl;
  if (returnValue_) {
    returnValue_->print_info();
  } else {
    std::cout << "None" << std::endl;
  }
  
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

std::string ReturnStatNode::toString() const {
  std::stringstream ss;
  ss << "Return";
  if (returnValue_) {
    ss << " " << returnValue_->toString();
  }
  return ss.str();
}

auto ReturnStatNode::Parse() -> void {
  // 解析return语句：return [expr];
  
  // 解析return关键字
  Token token = lexer_->getCurrentToken();
  if (token.getTokenType() != TokenType::KEYWORD || 
      getKeywordTypeFromToken(token) != KeywordType::RETURN) {
    throw std::runtime_error("Expected 'return' keyword");
  }
  
  auto returnKeyword = std::make_shared<TerminalReturn>(lexer_);
  returnKeyword->Parse();
  add_child(returnKeyword);
  
  // 解析返回值表达式（如果有）
  lexer_->getNextToken();
  token = lexer_->getCurrentToken();
  
  // 如果下一个标记是分号，则没有返回值
  if (token.getTokenType() == TokenType::SEPARATOR && 
      getSeparatorValueFromToken(token) == ";") {
    lexer_->getNextToken();
    return;
  }
  
  // 解析返回值表达式
  returnValue_ = std::make_shared<LiteralExprNode>(lexer_);
  returnValue_->Parse();
  add_child(returnValue_);
  
  // 解析分号
  token = lexer_->getCurrentToken();
  if (token.getTokenType() == TokenType::SEPARATOR && 
      getSeparatorValueFromToken(token) == ";") {
    lexer_->getNextToken();
  }
}

std::shared_ptr<ExprNode> ReturnStatNode::getReturnValue() const {
  return returnValue_;
}

void ReturnStatNode::setReturnValue(std::shared_ptr<ExprNode> returnValue) {
  returnValue_ = returnValue;
}

bool ReturnStatNode::hasReturnValue() const {
  return returnValue_ != nullptr;
}

bool ReturnStatNode::isTerminating() const {
  // return语句总是终止语句
  return true;
}

} // namespace mycompiler
