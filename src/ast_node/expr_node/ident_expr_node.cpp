#include "ast_node/expr_node/ident_expr_node.hpp"
#include "ast_node/terminal_symbols/terminal_ident_literal.hpp"
#include "token/token_helper_functions.hpp"
#include <sstream>

namespace mycompiler {

IdentifierExprNode::IdentifierExprNode(std::shared_ptr<Lexer> lexer)
    : ExprNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::IDENTIFIER_EXPR;
}

void IdentifierExprNode::print_info() {
  std::cout << "Node type: IDENTIFIER_EXPR" << std::endl;
  std::cout << "Name: " << name_ << std::endl;
  
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

std::string IdentifierExprNode::toString() const {
  return name_;
}

void IdentifierExprNode::Parse() {
  // 解析标识符
  Token token = lexer_->getCurrentToken();
  if (token.getTokenType() != TokenType::IDENT) {
    throw std::runtime_error("Expected identifier");
  }
  
  // 获取标识符名称
  name_ = getIdentifierValueFromToken(token);
  
  // 创建终端标识符字面量节点
  auto identLiteral = std::make_shared<TerminalIdentLiteral>(lexer_);
  identLiteral->Parse();
  add_child(identLiteral);
  
  // 移动到下一个标记
  lexer_->getNextToken();
}

std::string IdentifierExprNode::getExpressionType() const {
  // 在实际实现中，这里应该查询符号表获取标识符的类型
  // 但在这个简化的实现中，我们返回"unknown"
  return "unknown";
}

bool IdentifierExprNode::isConstant() const {
  // 标识符不是常量
  return false;
}

bool IdentifierExprNode::isLValue() const {
  // 标识符是左值
  return true;
}

std::string IdentifierExprNode::getName() const {
  return name_;
}

void IdentifierExprNode::setName(const std::string& name) {
  name_ = name;
}

} // namespace mycompiler
