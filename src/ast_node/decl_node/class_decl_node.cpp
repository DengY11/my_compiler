#include "ast_node/decl_node/class_decl_node.hpp"
#include "token/token_helper_functions.hpp"
#include <iostream>

namespace mycompiler {

ClassDeclNode::ClassDeclNode(std::shared_ptr<Lexer> lexer)
    : DeclNode(lexer), isAbstract_(false), accessModifier_("public") {
}

auto ClassDeclNode::print_info() -> void {
  std::cout << "ClassDeclNode: " << std::endl;
  std::cout << "Name: " << name_ << std::endl;
  std::cout << "Access Modifier: " << accessModifier_ << std::endl;
  std::cout << "Is Abstract: " << (isAbstract_ ? "true" : "false") << std::endl;
  
  if (!modifiers_.empty()) {
    std::cout << "Modifiers: ";
    for (const auto& modifier : modifiers_) {
      std::cout << modifier << " ";
    }
    std::cout << std::endl;
  }
  
  if (!baseClasses_.empty()) {
    std::cout << "Base Classes: ";
    for (const auto& baseClass : baseClasses_) {
      std::cout << baseClass << " ";
    }
    std::cout << std::endl;
  }
  
  std::cout << "Member Variables: " << std::endl;
  for (const auto& memberVar : memberVariables_) {
    memberVar->print_info();
  }
  
  std::cout << "Member Functions: " << std::endl;
  for (const auto& memberFunc : memberFunctions_) {
    memberFunc->print_info();
  }
}

std::string ClassDeclNode::toString() const {
  std::string result;
  
  // 添加修饰符
  for (const auto& modifier : modifiers_) {
    result += modifier + " ";
  }
  
  // 添加访问修饰符
  result += accessModifier_ + " ";
  
  // 添加abstract修饰符
  if (isAbstract_) {
    result += "abstract ";
  }
  
  // 添加class关键字和名称
  result += "class " + name_;
  
  // 添加基类列表
  if (!baseClasses_.empty()) {
    result += " : ";
    for (size_t i = 0; i < baseClasses_.size(); ++i) {
      if (i > 0) {
        result += ", ";
      }
      result += baseClasses_[i];
    }
  }
  
  // 添加类体
  result += " {\n";
  
  // 添加成员变量
  for (const auto& memberVar : memberVariables_) {
    result += "  " + memberVar->toString() + "\n";
  }
  
  // 添加成员函数
  for (const auto& memberFunc : memberFunctions_) {
    result += "  " + memberFunc->toString() + "\n";
  }
  
  result += "};";
  return result;
}

auto ClassDeclNode::Parse() -> void {
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
  
  // 检查是否有abstract修饰符
  if (isKeyword(currentToken, KeywordType::ABSTRACT)) {
    isAbstract_ = true;
    modifiers_.push_back("abstract");
    lexer_->getNextToken();
    currentToken = lexer_->getCurrentToken();
  }
  
  // 确保当前token是class关键字
  if (!isKeyword(currentToken, KeywordType::CLASS)) {
    throw std::runtime_error("Expected 'class' keyword in class declaration");
  }
  
  // 消费class关键字
  lexer_->getNextToken();
  currentToken = lexer_->getCurrentToken();
  
  // 解析类名
  if (currentToken.getTokenType() == TokenType::IDENTIFIER) {
    name_ = getIdentifierValueFromToken(currentToken);
    lexer_->getNextToken();
    currentToken = lexer_->getCurrentToken();
  } else {
    throw std::runtime_error("Expected class name in class declaration");
  }
  
  // 检查是否有基类
  if (isSeparator(currentToken, ":")) {
    lexer_->getNextToken();
    currentToken = lexer_->getCurrentToken();
    
    // 解析基类列表
    while (true) {
      if (currentToken.getTokenType() == TokenType::IDENTIFIER) {
        baseClasses_.push_back(getIdentifierValueFromToken(currentToken));
        lexer_->getNextToken();
        currentToken = lexer_->getCurrentToken();
        
        // 检查是否有更多基类
        if (isSeparator(currentToken, ",")) {
          lexer_->getNextToken();
          currentToken = lexer_->getCurrentToken();
        } else {
          break;
        }
      } else {
        throw std::runtime_error("Expected base class name in class declaration");
      }
    }
  }
  
  // 确保下一个token是左大括号
  if (!isSeparator(currentToken, "{")) {
    throw std::runtime_error("Expected '{' in class declaration");
  }
  
  // 消费左大括号
  lexer_->getNextToken();
  currentToken = lexer_->getCurrentToken();
  
  // 解析类体
  while (!isSeparator(currentToken, "}")) {
    // 检查是否是成员变量声明
    if (isKeyword(currentToken, KeywordType::CONST) ||
        isKeyword(currentToken, KeywordType::STATIC) ||
        currentToken.getTokenType() == TokenType::IDENTIFIER) {
      auto memberVar = std::make_shared<VarDeclNode>(lexer_);
      memberVar->Parse();
      memberVariables_.push_back(memberVar);
    }
    // 检查是否是成员函数声明
    else if (isKeyword(currentToken, KeywordType::FUNCTION)) {
      auto memberFunc = std::make_shared<FuncDeclNode>(lexer_);
      memberFunc->Parse();
      memberFunctions_.push_back(memberFunc);
    }
    else {
      throw std::runtime_error("Unexpected token in class body");
    }
    
    currentToken = lexer_->getCurrentToken();
  }
  
  // 消费右大括号
  lexer_->getNextToken();
  currentToken = lexer_->getCurrentToken();
  
  // 确保以分号结束
  if (!isSeparator(currentToken, ";")) {
    throw std::runtime_error("Expected ';' at the end of class declaration");
  }
  
  // 消费分号
  lexer_->getNextToken();
}

const std::vector<std::string>& ClassDeclNode::getBaseClasses() const {
  return baseClasses_;
}

void ClassDeclNode::addBaseClass(const std::string& baseClass) {
  baseClasses_.push_back(baseClass);
}

const std::vector<std::shared_ptr<VarDeclNode>>& ClassDeclNode::getMemberVariables() const {
  return memberVariables_;
}

void ClassDeclNode::addMemberVariable(std::shared_ptr<VarDeclNode> memberVariable) {
  memberVariables_.push_back(memberVariable);
}

const std::vector<std::shared_ptr<FuncDeclNode>>& ClassDeclNode::getMemberFunctions() const {
  return memberFunctions_;
}

void ClassDeclNode::addMemberFunction(std::shared_ptr<FuncDeclNode> memberFunction) {
  memberFunctions_.push_back(memberFunction);
}

bool ClassDeclNode::isAbstract() const {
  return isAbstract_;
}

void ClassDeclNode::setAbstract(bool isAbstract) {
  isAbstract_ = isAbstract;
}

std::string ClassDeclNode::getAccessModifier() const {
  return accessModifier_;
}

void ClassDeclNode::setAccessModifier(const std::string& accessModifier) {
  accessModifier_ = accessModifier;
}

const std::vector<std::string>& ClassDeclNode::getModifiers() const {
  return modifiers_;
}

void ClassDeclNode::addModifier(const std::string& modifier) {
  modifiers_.push_back(modifier);
}

} // namespace mycompiler 