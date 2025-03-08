#include "ast_node/stat_node/if_stat_node.hpp"
#include "ast_node/expr_node/condition_expr_node.hpp"
#include "ast_node/expr_node/literal_expr_node.hpp"
#include "ast_node/stat_node/stat_list_node.hpp"
#include "ast_node/terminal_symbols/terminal_if.hpp"
#include "ast_node/terminal_symbols/terminal_separator.hpp"
#include "magic_enum/magic_enum.hpp"
#include "token/keyword_type.hpp"
#include "token/token_helper_functions.hpp"
#include <memory>
#include <stdexcept>
#include <sstream>

namespace mycompiler {

IfStatNode::IfStatNode(std::shared_ptr<Lexer> lexer) : StatNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::IF_STAT;
  this->statType_ = StatType::IF_STAT;
}

auto IfStatNode::print_info() -> void {
  std::cout << "Node type: IF_STAT" << std::endl;
  
  std::cout << "Condition: " << std::endl;
  if (condition_) {
    condition_->print_info();
  } else {
    std::cout << "None" << std::endl;
  }
  
  std::cout << "If block: " << std::endl;
  if (ifBlock_) {
    ifBlock_->print_info();
  } else {
    std::cout << "Empty" << std::endl;
  }
  
  std::cout << "Else block: " << std::endl;
  if (elseBlock_) {
    elseBlock_->print_info();
  } else {
    std::cout << "None" << std::endl;
  }
  
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

std::string IfStatNode::toString() const {
  std::stringstream ss;
  ss << "If statement with condition: " << (condition_ ? condition_->toString() : "None");
  if (hasElse()) {
    ss << " and else block";
  }
  return ss.str();
}

auto IfStatNode::Parse() -> void {
  // 解析if语句：if (condition) { block } [else { block }]
  
  // 解析if关键字
  Token token = lexer_->getCurrentToken();
  if (token.getTokenType() != TokenType::KEYWORD || 
      getKeywordTypeFromToken(token) != KeywordType::IF) {
    throw std::runtime_error("Expected 'if' keyword");
  }
  
  auto ifKeyword = std::make_shared<TerminalIf>(lexer_);
  ifKeyword->Parse();
  add_child(ifKeyword);
  
  // 解析左括号
  lexer_->getNextToken();
  token = lexer_->getCurrentToken();
  if (token.getTokenType() != TokenType::SEPARATOR || 
      getSeparatorValueFromToken(token) != "(") {
    throw std::runtime_error("Expected '('");
  }
  
  auto leftParen = std::make_shared<TerminalSeparator>(lexer_);
  leftParen->Parse();
  add_child(leftParen);
  
  // 解析条件表达式
  lexer_->getNextToken();
  condition_ = std::make_shared<LiteralExprNode>(lexer_);
  condition_->Parse();
  add_child(condition_);
  
  // 解析右括号
  token = lexer_->getCurrentToken();
  if (token.getTokenType() != TokenType::SEPARATOR || 
      getSeparatorValueFromToken(token) != ")") {
    throw std::runtime_error("Expected ')'");
  }
  
  auto rightParen = std::make_shared<TerminalSeparator>(lexer_);
  rightParen->Parse();
  add_child(rightParen);
  
  // 解析左花括号
  lexer_->getNextToken();
  token = lexer_->getCurrentToken();
  if (token.getTokenType() != TokenType::SEPARATOR || 
      getSeparatorValueFromToken(token) != "{") {
    throw std::runtime_error("Expected '{'");
  }
  
  auto leftBrace = std::make_shared<TerminalSeparator>(lexer_);
  leftBrace->Parse();
  add_child(leftBrace);
  
  // 解析if块
  lexer_->getNextToken();
  ifBlock_ = std::make_shared<BlockStatNode>(lexer_);
  ifBlock_->Parse();
  add_child(ifBlock_);
  
  // 解析右花括号
  token = lexer_->getCurrentToken();
  if (token.getTokenType() != TokenType::SEPARATOR || 
      getSeparatorValueFromToken(token) != "}") {
    throw std::runtime_error("Expected '}'");
  }
  
  auto rightBrace = std::make_shared<TerminalSeparator>(lexer_);
  rightBrace->Parse();
  add_child(rightBrace);
  
  // 检查是否有else块
  lexer_->getNextToken();
  token = lexer_->peekNextToken();
  if (token.getTokenType() == TokenType::KEYWORD && 
      getKeywordTypeFromToken(token) == KeywordType::ELSE) {
    elseBlock_ = std::make_shared<ElseStatNode>(lexer_);
    elseBlock_->Parse();
    add_child(elseBlock_);
  }
}

std::shared_ptr<ExprNode> IfStatNode::getCondition() const {
  return condition_;
}

std::shared_ptr<BlockStatNode> IfStatNode::getIfBlock() const {
  return ifBlock_;
}

std::shared_ptr<ElseStatNode> IfStatNode::getElseBlock() const {
  return elseBlock_;
}

bool IfStatNode::hasElse() const {
  return elseBlock_ != nullptr;
}

bool IfStatNode::isTerminating() const {
  // 如果if块和else块都是终止语句，则if语句是终止语句
  return ifBlock_ && elseBlock_ && 
         ifBlock_->isTerminating() && 
         elseBlock_->isTerminating();
}

} // namespace mycompiler
