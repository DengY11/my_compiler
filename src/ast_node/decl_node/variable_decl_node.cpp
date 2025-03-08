#include "ast_node/decl_node/variable_decl_node.hpp"
#include "ast_node/expr_node/ident_expr_node.hpp"
#include "ast_node/expr_node/literal_expr_node.hpp"
#include "ast_node/terminal_symbols/terminal_equal.hpp"
#include "ast_node/terminal_symbols/terminal_ident_literal.hpp"
#include "ast_node/terminal_symbols/terminal_let.hpp"
#include "ast_node/terminal_symbols/terminal_separator.hpp"
#include "token/token_helper_functions.hpp"
#include <memory>
#include <stdexcept>
#include <sstream>

namespace mycompiler {

VariableDeclNode::VariableDeclNode(std::shared_ptr<Lexer> lexer) : DeclNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::VARIABLE_DECL;
}

void VariableDeclNode::print_info() {
  std::cout << "Node type: VARIABLE_DECL" << std::endl;
  std::cout << "Name: " << name_ << std::endl;
  std::cout << "Type: " << type_ << std::endl;
  
  std::cout << "Initial value: " << std::endl;
  if (initialValue_) {
    initialValue_->print_info();
  } else {
    std::cout << "None" << std::endl;
  }
  
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

std::string VariableDeclNode::toString() const {
  std::stringstream ss;
  ss << "Variable " << name_ << " with type " << type_;
  if (initialValue_) {
    ss << " and initial value: " << initialValue_->toString();
  }
  return ss.str();
}

void VariableDeclNode::Parse() {
  // 解析变量声明：let name = value;
  
  // 解析let关键字
  Token token = lexer_->getCurrentToken();
  if (token.getTokenType() != TokenType::KEYWORD || 
      getKeywordTypeFromToken(token) != KeywordType::LET) {
    throw std::runtime_error("Expected 'let' keyword");
  }
  
  auto letKeyword = std::make_shared<TerminalLet>(lexer_);
  letKeyword->Parse();
  add_child(letKeyword);
  
  // 解析变量名
  lexer_->getNextToken();
  token = lexer_->getCurrentToken();
  if (token.getTokenType() != TokenType::IDENT) {
    throw std::runtime_error("Expected variable name");
  }
  
  auto identNode = std::make_shared<TerminalIdentLiteral>(lexer_);
  identNode->Parse();
  add_child(identNode);
  name_ = getIdentifierValueFromToken(token);
  
  // 默认类型为auto
  type_ = "auto";
  
  // 解析等号
  lexer_->getNextToken();
  token = lexer_->getCurrentToken();
  if (token.getTokenType() != TokenType::OPERATOR || 
      getOperatorTypeFromToken(token) != OperatorType::ASSIGN) {
    // 如果没有等号，则没有初始值
    return;
  }
  
  auto opNode = std::make_shared<TerminalOperator>(lexer_);
  opNode->Parse();
  add_child(opNode);
  
  // 解析初始值
  lexer_->getNextToken();
  initialValue_ = std::make_shared<LiteralExprNode>(lexer_);
  initialValue_->Parse();
  add_child(initialValue_);
  
  // 解析分号
  token = lexer_->getCurrentToken();
  if (token.getTokenType() == TokenType::SEPARATOR && 
      getSeparatorValueFromToken(token) == ";") {
    lexer_->getNextToken();
  }
}

std::shared_ptr<ExprNode> VariableDeclNode::getInitialValue() const {
  return initialValue_;
}

void VariableDeclNode::setInitialValue(std::shared_ptr<ExprNode> initialValue) {
  initialValue_ = initialValue;
}

bool VariableDeclNode::hasInitialValue() const {
  return initialValue_ != nullptr;
}

} // namespace mycompiler
