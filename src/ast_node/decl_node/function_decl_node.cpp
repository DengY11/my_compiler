#include "ast_node/decl_node/function_decl_node.hpp"
#include "ast_node/stat_node/parameter_list_stat_node.hpp"
#include "ast_node/stat_node/stat_list_node.hpp"
#include "ast_node/terminal_symbols/terminal_func.hpp"
#include "ast_node/terminal_symbols/terminal_ident_literal.hpp"
#include "ast_node/terminal_symbols/terminal_separator.hpp"
#include "token/token_helper_functions.hpp"
#include <memory>
#include <stdexcept>
#include <sstream>

namespace mycompiler {

FuncDeclNode::FuncDeclNode(std::shared_ptr<Lexer> lexer) : DeclNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::FUNCTION_DECL;
  this->returnType_ = "void"; // 默认返回类型为void
}

void FuncDeclNode::print_info() {
  std::cout << "Node type: FUNCTION_DECL" << std::endl;
  std::cout << "Function name: " << name_ << std::endl;
  std::cout << "Return type: " << returnType_ << std::endl;
  
  std::cout << "Parameters: " << std::endl;
  if (parameters_) {
    parameters_->print_info();
  } else {
    std::cout << "None" << std::endl;
  }
  
  std::cout << "Body: " << std::endl;
  if (body_) {
    body_->print_info();
  } else {
    std::cout << "Empty" << std::endl;
  }
  
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

std::string FuncDeclNode::toString() const {
  std::stringstream ss;
  ss << "Function " << name_ << " with return type " << returnType_;
  return ss.str();
}

void FuncDeclNode::Parse() {
  // 解析函数声明：func name(params) { body }
  
  // 解析func关键字
  Token token = lexer_->getCurrentToken();
  if (token.getTokenType() != TokenType::KEYWORD || 
      getKeywordTypeFromToken(token) != KeywordType::FUNC) {
    throw std::runtime_error("Expected 'func' keyword");
  }
  
  auto funcKeyword = std::make_shared<TerminalFunc>(lexer_);
  funcKeyword->Parse();
  add_child(funcKeyword);
  
  // 解析函数名
  lexer_->getNextToken();
  token = lexer_->getCurrentToken();
  if (token.getTokenType() != TokenType::IDENT) {
    throw std::runtime_error("Expected function name");
  }
  
  auto identNode = std::make_shared<TerminalIdentLiteral>(lexer_);
  identNode->Parse();
  add_child(identNode);
  name_ = getIdentifierValueFromToken(token);
  
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
  
  // 解析参数列表
  lexer_->getNextToken();
  parameters_ = std::make_shared<ParameterListStatNode>(lexer_);
  parameters_->Parse();
  add_child(parameters_);
  
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
  
  // 解析函数体
  lexer_->getNextToken();
  body_ = std::make_shared<BlockStatNode>(lexer_);
  body_->Parse();
  add_child(body_);
  
  // 解析右花括号
  token = lexer_->getCurrentToken();
  if (token.getTokenType() != TokenType::SEPARATOR || 
      getSeparatorValueFromToken(token) != "}") {
    throw std::runtime_error("Expected '}'");
  }
  
  auto rightBrace = std::make_shared<TerminalSeparator>(lexer_);
  rightBrace->Parse();
  add_child(rightBrace);
  
  // 移动到下一个标记
  lexer_->getNextToken();
}

std::shared_ptr<ParameterListStatNode> FuncDeclNode::getParameters() const {
  return parameters_;
}

std::shared_ptr<BlockStatNode> FuncDeclNode::getBody() const {
  return body_;
}

std::string FuncDeclNode::getReturnType() const {
  return returnType_;
}

void FuncDeclNode::setReturnType(const std::string& returnType) {
  returnType_ = returnType;
}

} // namespace mycompiler
