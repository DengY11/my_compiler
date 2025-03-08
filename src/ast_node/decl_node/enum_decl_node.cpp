#include "ast_node/decl_node/enum_decl_node.hpp"
#include "token/token_helper_functions.hpp"
#include <iostream>

namespace mycompiler {

EnumDeclNode::EnumDeclNode(std::shared_ptr<Lexer> lexer)
    : DeclNode(lexer), isClassEnum_(false), accessModifier_("public") {
}

auto EnumDeclNode::print_info() -> void {
  std::cout << "EnumDeclNode: " << std::endl;
  std::cout << "Name: " << name_ << std::endl;
  std::cout << "Access Modifier: " << accessModifier_ << std::endl;
  std::cout << "Is Class Enum: " << (isClassEnum_ ? "true" : "false") << std::endl;
  
  if (!baseType_.empty()) {
    std::cout << "Base Type: " << baseType_ << std::endl;
  }
  
  std::cout << "Enum Values: " << std::endl;
  for (const auto& enumValue : enumValues_) {
    std::cout << "  " << enumValue.first;
    if (enumValue.second) {
      std::cout << " = ";
      enumValue.second->print_info();
    }
    std::cout << std::endl;
  }
}

std::string EnumDeclNode::toString() const {
  std::string result;
  
  // 添加访问修饰符
  result += accessModifier_ + " ";
  
  // 添加enum关键字
  result += "enum ";
  
  // 添加class修饰符
  if (isClassEnum_) {
    result += "class ";
  }
  
  // 添加枚举名称
  result += name_;
  
  // 添加基础类型
  if (!baseType_.empty()) {
    result += " : " + baseType_;
  }
  
  // 添加枚举体
  result += " {\n";
  
  // 添加枚举值
  for (size_t i = 0; i < enumValues_.size(); ++i) {
    result += "  " + enumValues_[i].first;
    if (enumValues_[i].second) {
      result += " = " + enumValues_[i].second->toString();
    }
    if (i < enumValues_.size() - 1) {
      result += ",";
    }
    result += "\n";
  }
  
  result += "};";
  return result;
}

auto EnumDeclNode::Parse() -> void {
  // 解析修饰符
  auto currentToken = lexer_->getCurrentToken();
  
  // 检查访问修饰符
  if (isKeyword(currentToken, KeywordType::PUBLIC) ||
      isKeyword(currentToken, KeywordType::PRIVATE) ||
      isKeyword(currentToken, KeywordType::PROTECTED)) {
    if (isKeyword(currentToken, KeywordType::PUBLIC)) {
      accessModifier_ = "public";
    } else if (isKeyword(currentToken, KeywordType::PRIVATE)) {
      accessModifier_ = "private";
    } else {
      accessModifier_ = "protected";
    }
    lexer_->getNextToken();
    currentToken = lexer_->getCurrentToken();
  }
  
  // 确保当前token是enum关键字
  if (!isKeyword(currentToken, KeywordType::ENUM)) {
    throw std::runtime_error("Expected 'enum' keyword in enum declaration");
  }
  
  // 消费enum关键字
  lexer_->getNextToken();
  currentToken = lexer_->getCurrentToken();
  
  // 检查是否是class enum
  if (isKeyword(currentToken, KeywordType::CLASS)) {
    isClassEnum_ = true;
    lexer_->getNextToken();
    currentToken = lexer_->getCurrentToken();
  }
  
  // 解析枚举名称
  if (currentToken.getTokenType() == TokenType::IDENTIFIER) {
    name_ = getIdentifierValueFromToken(currentToken);
    lexer_->getNextToken();
    currentToken = lexer_->getCurrentToken();
  } else {
    throw std::runtime_error("Expected enum name in enum declaration");
  }
  
  // 检查是否有基础类型
  if (isSeparator(currentToken, ":")) {
    lexer_->getNextToken();
    currentToken = lexer_->getCurrentToken();
    
    // 解析基础类型
    if (currentToken.getTokenType() == TokenType::IDENTIFIER) {
      baseType_ = getIdentifierValueFromToken(currentToken);
      lexer_->getNextToken();
      currentToken = lexer_->getCurrentToken();
    } else {
      throw std::runtime_error("Expected base type in enum declaration");
    }
  }
  
  // 确保下一个token是左大括号
  if (!isSeparator(currentToken, "{")) {
    throw std::runtime_error("Expected '{' in enum declaration");
  }
  
  // 消费左大括号
  lexer_->getNextToken();
  currentToken = lexer_->getCurrentToken();
  
  // 解析枚举值
  while (!isSeparator(currentToken, "}")) {
    // 解析枚举值名称
    if (currentToken.getTokenType() == TokenType::IDENTIFIER) {
      std::string enumName = getIdentifierValueFromToken(currentToken);
      lexer_->getNextToken();
      currentToken = lexer_->getCurrentToken();
      
      // 检查是否有初始化表达式
      std::shared_ptr<ExprNode> enumValue = nullptr;
      if (isOperator(currentToken, OperatorType::ASSIGN)) {
        lexer_->getNextToken();
        
        // 解析初始化表达式
        enumValue = std::make_shared<ExprNode>(lexer_);
        enumValue->Parse();
        currentToken = lexer_->getCurrentToken();
      }
      
      // 添加枚举值
      enumValues_.push_back(std::make_pair(enumName, enumValue));
      
      // 检查是否有逗号
      if (isSeparator(currentToken, ",")) {
        lexer_->getNextToken();
        currentToken = lexer_->getCurrentToken();
      }
      // 如果没有逗号，则应该是右大括号
      else if (!isSeparator(currentToken, "}")) {
        throw std::runtime_error("Expected ',' or '}' after enum value");
      }
    } else {
      throw std::runtime_error("Expected enum value name in enum declaration");
    }
  }
  
  // 消费右大括号
  lexer_->getNextToken();
  currentToken = lexer_->getCurrentToken();
  
  // 确保以分号结束
  if (!isSeparator(currentToken, ";")) {
    throw std::runtime_error("Expected ';' at the end of enum declaration");
  }
  
  // 消费分号
  lexer_->getNextToken();
}

const std::vector<std::pair<std::string, std::shared_ptr<ExprNode>>>& EnumDeclNode::getEnumValues() const {
  return enumValues_;
}

void EnumDeclNode::addEnumValue(const std::string& name, std::shared_ptr<ExprNode> value) {
  enumValues_.push_back(std::make_pair(name, value));
}

bool EnumDeclNode::isClassEnum() const {
  return isClassEnum_;
}

void EnumDeclNode::setClassEnum(bool isClassEnum) {
  isClassEnum_ = isClassEnum;
}

std::string EnumDeclNode::getBaseType() const {
  return baseType_;
}

void EnumDeclNode::setBaseType(const std::string& baseType) {
  baseType_ = baseType;
}

std::string EnumDeclNode::getAccessModifier() const {
  return accessModifier_;
}

void EnumDeclNode::setAccessModifier(const std::string& accessModifier) {
  accessModifier_ = accessModifier;
}

} // namespace mycompiler 