#include "ast_node/decl_node/namespace_decl_node.hpp"
#include "token/token_helper_functions.hpp"
#include <iostream>

namespace mycompiler {

NamespaceDeclNode::NamespaceDeclNode(std::shared_ptr<Lexer> lexer)
    : DeclNode(lexer), isInline_(false) {
}

auto NamespaceDeclNode::print_info() -> void {
  std::cout << "NamespaceDeclNode: " << std::endl;
  std::cout << "Name: " << name_ << std::endl;
  std::cout << "Full Name: " << fullName_ << std::endl;
  std::cout << "Is Inline: " << (isInline_ ? "true" : "false") << std::endl;
  
  std::cout << "Declarations: " << std::endl;
  for (const auto& decl : declarations_) {
    decl->print_info();
  }
}

std::string NamespaceDeclNode::toString() const {
  std::string result;
  
  // 添加inline修饰符
  if (isInline_) {
    result += "inline ";
  }
  
  // 添加namespace关键字和名称
  result += "namespace " + name_ + " {\n";
  
  // 添加声明
  for (const auto& decl : declarations_) {
    result += decl->toString() + "\n";
  }
  
  result += "}";
  return result;
}

auto NamespaceDeclNode::Parse() -> void {
  // 解析修饰符
  auto currentToken = lexer_->getCurrentToken();
  
  // 检查是否有inline修饰符
  if (isKeyword(currentToken, KeywordType::INLINE)) {
    isInline_ = true;
    lexer_->getNextToken();
    currentToken = lexer_->getCurrentToken();
  }
  
  // 确保当前token是namespace关键字
  if (!isKeyword(currentToken, KeywordType::NAMESPACE)) {
    throw std::runtime_error("Expected 'namespace' keyword in namespace declaration");
  }
  
  // 消费namespace关键字
  lexer_->getNextToken();
  currentToken = lexer_->getCurrentToken();
  
  // 解析命名空间名称
  if (currentToken.getTokenType() == TokenType::IDENTIFIER) {
    name_ = getIdentifierValueFromToken(currentToken);
    fullName_ = name_; // 初始化完整名称为当前名称
    lexer_->getNextToken();
    currentToken = lexer_->getCurrentToken();
  } else {
    throw std::runtime_error("Expected namespace name in namespace declaration");
  }
  
  // 确保下一个token是左大括号
  if (!isSeparator(currentToken, "{")) {
    throw std::runtime_error("Expected '{' in namespace declaration");
  }
  
  // 消费左大括号
  lexer_->getNextToken();
  currentToken = lexer_->getCurrentToken();
  
  // 解析命名空间体
  while (!isSeparator(currentToken, "}")) {
    // 根据当前token类型解析不同类型的声明
    if (isKeyword(currentToken, KeywordType::NAMESPACE)) {
      // 嵌套命名空间
      auto nestedNamespace = std::make_shared<NamespaceDeclNode>(lexer_);
      nestedNamespace->Parse();
      declarations_.push_back(nestedNamespace);
    } else if (isKeyword(currentToken, KeywordType::CLASS)) {
      // 类声明
      auto classDecl = std::make_shared<ClassDeclNode>(lexer_);
      classDecl->Parse();
      declarations_.push_back(classDecl);
    } else if (isKeyword(currentToken, KeywordType::ENUM)) {
      // 枚举声明
      auto enumDecl = std::make_shared<EnumDeclNode>(lexer_);
      enumDecl->Parse();
      declarations_.push_back(enumDecl);
    } else if (isKeyword(currentToken, KeywordType::FUNCTION)) {
      // 函数声明
      auto funcDecl = std::make_shared<FuncDeclNode>(lexer_);
      funcDecl->Parse();
      declarations_.push_back(funcDecl);
    } else if (isKeyword(currentToken, KeywordType::CONST) ||
               isKeyword(currentToken, KeywordType::STATIC) ||
               currentToken.getTokenType() == TokenType::IDENTIFIER) {
      // 变量声明
      auto varDecl = std::make_shared<VarDeclNode>(lexer_);
      varDecl->Parse();
      declarations_.push_back(varDecl);
    } else {
      throw std::runtime_error("Unexpected token in namespace body");
    }
    
    currentToken = lexer_->getCurrentToken();
  }
  
  // 消费右大括号
  lexer_->getNextToken();
}

const std::vector<std::shared_ptr<DeclNode>>& NamespaceDeclNode::getDeclarations() const {
  return declarations_;
}

void NamespaceDeclNode::addDeclaration(std::shared_ptr<DeclNode> declaration) {
  declarations_.push_back(declaration);
}

bool NamespaceDeclNode::isInline() const {
  return isInline_;
}

void NamespaceDeclNode::setInline(bool isInline) {
  isInline_ = isInline;
}

std::string NamespaceDeclNode::getFullName() const {
  return fullName_;
}

void NamespaceDeclNode::setFullName(const std::string& fullName) {
  fullName_ = fullName;
}

} // namespace mycompiler 