#include "ast_node/decl_node/func_decl_node.hpp"
#include "token/token_helper_functions.hpp"
#include <iostream>

namespace mycompiler {

FuncDeclNode::FuncDeclNode(std::shared_ptr<Lexer> lexer)
    : DeclNode(lexer), body_(nullptr), isStatic_(false), isVirtual_(false), isPureVirtual_(false) {
}

auto FuncDeclNode::print_info() -> void {
  std::cout << "FuncDeclNode: " << std::endl;
  std::cout << "Name: " << name_ << std::endl;
  std::cout << "Return Type: " << returnType_ << std::endl;
  std::cout << "Is Static: " << (isStatic_ ? "true" : "false") << std::endl;
  std::cout << "Is Virtual: " << (isVirtual_ ? "true" : "false") << std::endl;
  std::cout << "Is Pure Virtual: " << (isPureVirtual_ ? "true" : "false") << std::endl;
  
  if (!modifiers_.empty()) {
    std::cout << "Modifiers: ";
    for (const auto& modifier : modifiers_) {
      std::cout << modifier << " ";
    }
    std::cout << std::endl;
  }
  
  std::cout << "Parameters: " << std::endl;
  for (const auto& param : parameters_) {
    param->print_info();
  }
  
  if (body_) {
    std::cout << "Body: " << std::endl;
    body_->print_info();
  }
}

std::string FuncDeclNode::toString() const {
  std::string result;
  
  // 添加修饰符
  for (const auto& modifier : modifiers_) {
    result += modifier + " ";
  }
  
  // 添加static和virtual修饰符
  if (isStatic_) {
    result += "static ";
  }
  if (isVirtual_) {
    result += "virtual ";
  }
  
  // 添加返回类型和函数名
  result += returnType_ + " " + name_ + "(";
  
  // 添加参数列表
  for (size_t i = 0; i < parameters_.size(); ++i) {
    if (i > 0) {
      result += ", ";
    }
    result += parameters_[i]->toString();
  }
  result += ")";
  
  // 添加纯虚函数标记
  if (isPureVirtual_) {
    result += " = 0";
  }
  
  // 添加函数体或分号
  if (body_) {
    result += " " + body_->toString();
  } else {
    result += ";";
  }
  
  return result;
}

auto FuncDeclNode::Parse() -> void {
  // 解析修饰符
  auto currentToken = lexer_->getCurrentToken();
  
  // 检查是否有static修饰符
  if (isKeyword(currentToken, KeywordType::STATIC)) {
    isStatic_ = true;
    modifiers_.push_back("static");
    lexer_->getNextToken();
    currentToken = lexer_->getCurrentToken();
  }
  
  // 检查是否有virtual修饰符
  if (isKeyword(currentToken, KeywordType::VIRTUAL)) {
    isVirtual_ = true;
    modifiers_.push_back("virtual");
    lexer_->getNextToken();
    currentToken = lexer_->getCurrentToken();
  }
  
  // 确保当前token是function关键字
  if (!isKeyword(currentToken, KeywordType::FUNCTION)) {
    throw std::runtime_error("Expected 'function' keyword in function declaration");
  }
  
  // 消费function关键字
  lexer_->getNextToken();
  currentToken = lexer_->getCurrentToken();
  
  // 解析返回类型
  if (currentToken.getTokenType() == TokenType::IDENTIFIER) {
    returnType_ = getIdentifierValueFromToken(currentToken);
    lexer_->getNextToken();
    currentToken = lexer_->getCurrentToken();
  } else {
    throw std::runtime_error("Expected return type in function declaration");
  }
  
  // 解析函数名
  if (currentToken.getTokenType() == TokenType::IDENTIFIER) {
    name_ = getIdentifierValueFromToken(currentToken);
    lexer_->getNextToken();
    currentToken = lexer_->getCurrentToken();
  } else {
    throw std::runtime_error("Expected function name in function declaration");
  }
  
  // 确保下一个token是左括号
  if (!isSeparator(currentToken, "(")) {
    throw std::runtime_error("Expected '(' in function declaration");
  }
  
  // 消费左括号
  lexer_->getNextToken();
  currentToken = lexer_->getCurrentToken();
  
  // 解析参数列表
  while (!isSeparator(currentToken, ")")) {
    // 解析参数
    auto param = std::make_shared<VarDeclNode>(lexer_);
    param->Parse();
    parameters_.push_back(param);
    
    // 检查是否有逗号
    currentToken = lexer_->getCurrentToken();
    if (isSeparator(currentToken, ",")) {
      lexer_->getNextToken();
      currentToken = lexer_->getCurrentToken();
    }
    // 如果没有逗号，则应该是右括号
    else if (!isSeparator(currentToken, ")")) {
      throw std::runtime_error("Expected ',' or ')' in function parameter list");
    }
  }
  
  // 消费右括号
  lexer_->getNextToken();
  currentToken = lexer_->getCurrentToken();
  
  // 检查是否是纯虚函数
  if (isOperator(currentToken, OperatorType::ASSIGN)) {
    lexer_->getNextToken();
    currentToken = lexer_->getCurrentToken();
    
    if (currentToken.getTokenType() == TokenType::CONSTANT && 
        getConstantValueFromToken(currentToken) == "0") {
      isPureVirtual_ = true;
      lexer_->getNextToken();
      currentToken = lexer_->getCurrentToken();
    } else {
      throw std::runtime_error("Expected '0' after '=' in pure virtual function declaration");
    }
  }
  
  // 检查是否有函数体
  if (isSeparator(currentToken, "{")) {
    // 解析函数体
    body_ = std::make_shared<BlockStatNode>(lexer_);
    body_->Parse();
  }
  // 如果没有函数体，则应该以分号结束
  else if (isSeparator(currentToken, ";")) {
    // 消费分号
    lexer_->getNextToken();
  } else {
    throw std::runtime_error("Expected '{' or ';' in function declaration");
  }
}

std::string FuncDeclNode::getReturnType() const {
  return returnType_;
}

void FuncDeclNode::setReturnType(const std::string& returnType) {
  returnType_ = returnType;
}

const std::vector<std::shared_ptr<VarDeclNode>>& FuncDeclNode::getParameters() const {
  return parameters_;
}

void FuncDeclNode::addParameter(std::shared_ptr<VarDeclNode> parameter) {
  parameters_.push_back(parameter);
}

std::shared_ptr<BlockStatNode> FuncDeclNode::getBody() const {
  return body_;
}

void FuncDeclNode::setBody(std::shared_ptr<BlockStatNode> body) {
  body_ = body;
}

bool FuncDeclNode::isStatic() const {
  return isStatic_;
}

void FuncDeclNode::setStatic(bool isStatic) {
  isStatic_ = isStatic;
}

bool FuncDeclNode::isVirtual() const {
  return isVirtual_;
}

void FuncDeclNode::setVirtual(bool isVirtual) {
  isVirtual_ = isVirtual;
}

bool FuncDeclNode::isPureVirtual() const {
  return isPureVirtual_;
}

void FuncDeclNode::setPureVirtual(bool isPureVirtual) {
  isPureVirtual_ = isPureVirtual;
}

const std::vector<std::string>& FuncDeclNode::getModifiers() const {
  return modifiers_;
}

void FuncDeclNode::addModifier(const std::string& modifier) {
  modifiers_.push_back(modifier);
}

} // namespace mycompiler 