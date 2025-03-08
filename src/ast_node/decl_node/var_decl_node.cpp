#include "ast_node/decl_node/var_decl_node.hpp"
#include "token/token_helper_functions.hpp"
#include <iostream>

namespace mycompiler {

VarDeclNode::VarDeclNode(std::shared_ptr<Lexer> lexer)
    : DeclNode(lexer), initializer_(nullptr), isConstant_(false), isStatic_(false) {
}

auto VarDeclNode::print_info() -> void {
  std::cout << "VarDeclNode: " << std::endl;
  std::cout << "Name: " << name_ << std::endl;
  std::cout << "Type: " << type_ << std::endl;
  std::cout << "Is Constant: " << (isConstant_ ? "true" : "false") << std::endl;
  std::cout << "Is Static: " << (isStatic_ ? "true" : "false") << std::endl;
  
  if (!modifiers_.empty()) {
    std::cout << "Modifiers: ";
    for (const auto& modifier : modifiers_) {
      std::cout << modifier << " ";
    }
    std::cout << std::endl;
  }
  
  if (initializer_) {
    std::cout << "Initializer: " << std::endl;
    initializer_->print_info();
  }
}

std::string VarDeclNode::toString() const {
  std::string result;
  
  // 添加修饰符
  for (const auto& modifier : modifiers_) {
    result += modifier + " ";
  }
  
  // 添加const和static修饰符
  if (isConstant_) {
    result += "const ";
  }
  if (isStatic_) {
    result += "static ";
  }
  
  // 添加类型和名称
  result += type_ + " " + name_;
  
  // 添加初始化器
  if (initializer_) {
    result += " = " + initializer_->toString();
  }
  
  result += ";";
  return result;
}

auto VarDeclNode::Parse() -> void {
  // 解析修饰符
  auto currentToken = lexer_->getCurrentToken();
  
  // 检查是否有const修饰符
  if (isKeyword(currentToken, KeywordType::CONST)) {
    isConstant_ = true;
    modifiers_.push_back("const");
    lexer_->getNextToken();
    currentToken = lexer_->getCurrentToken();
  }
  
  // 检查是否有static修饰符
  if (isKeyword(currentToken, KeywordType::STATIC)) {
    isStatic_ = true;
    modifiers_.push_back("static");
    lexer_->getNextToken();
    currentToken = lexer_->getCurrentToken();
  }
  
  // 解析类型
  if (currentToken.getTokenType() == TokenType::IDENTIFIER) {
    type_ = getIdentifierValueFromToken(currentToken);
    lexer_->getNextToken();
    currentToken = lexer_->getCurrentToken();
  } else {
    throw std::runtime_error("Expected type name in variable declaration");
  }
  
  // 解析变量名
  if (currentToken.getTokenType() == TokenType::IDENTIFIER) {
    name_ = getIdentifierValueFromToken(currentToken);
    lexer_->getNextToken();
    currentToken = lexer_->getCurrentToken();
  } else {
    throw std::runtime_error("Expected variable name in variable declaration");
  }
  
  // 检查是否有初始化器
  if (isOperator(currentToken, OperatorType::ASSIGN)) {
    lexer_->getNextToken();
    
    // 解析初始化表达式
    initializer_ = std::make_shared<ExprNode>(lexer_);
    initializer_->Parse();
    currentToken = lexer_->getCurrentToken();
  }
  
  // 确保以分号结束
  if (!isSeparator(currentToken, ";")) {
    throw std::runtime_error("Expected ';' at the end of variable declaration");
  }
  
  // 消费分号
  lexer_->getNextToken();
}

std::string VarDeclNode::getType() const {
  return type_;
}

void VarDeclNode::setType(const std::string& type) {
  type_ = type;
}

std::shared_ptr<ExprNode> VarDeclNode::getInitializer() const {
  return initializer_;
}

void VarDeclNode::setInitializer(std::shared_ptr<ExprNode> initializer) {
  initializer_ = initializer;
}

bool VarDeclNode::isConstant() const {
  return isConstant_;
}

void VarDeclNode::setConstant(bool isConstant) {
  isConstant_ = isConstant;
}

bool VarDeclNode::isStatic() const {
  return isStatic_;
}

void VarDeclNode::setStatic(bool isStatic) {
  isStatic_ = isStatic;
}

const std::vector<std::string>& VarDeclNode::getModifiers() const {
  return modifiers_;
}

void VarDeclNode::addModifier(const std::string& modifier) {
  modifiers_.push_back(modifier);
}

} // namespace mycompiler 