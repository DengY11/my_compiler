#include "ast_node/terminal_symbols/terminal_operator.hpp"
#include "token/token_helper_functions.hpp"
#include <iostream>

namespace mycompiler {

TerminalOperator::TerminalOperator(std::shared_ptr<Lexer> lexer)
    : ASTNode(lexer), operatorType_(OperatorType::PLUS) {
}

auto TerminalOperator::print_info() -> void {
  std::cout << "TerminalOperator: " << toString() << std::endl;
}

std::string TerminalOperator::toString() const {
  // 根据操作符类型返回对应的字符串表示
  switch (operatorType_) {
    case OperatorType::PLUS:
      return "+";
    case OperatorType::MINUS:
      return "-";
    case OperatorType::MULTIPLY:
      return "*";
    case OperatorType::DIVIDE:
      return "/";
    case OperatorType::MODULO:
      return "%";
    case OperatorType::ASSIGN:
      return "=";
    case OperatorType::EQUAL:
      return "==";
    case OperatorType::NOT_EQUAL:
      return "!=";
    case OperatorType::LESS_THAN:
      return "<";
    case OperatorType::LESS_THAN_OR_EQUAL:
      return "<=";
    case OperatorType::GREATER_THAN:
      return ">";
    case OperatorType::GREATER_THAN_OR_EQUAL:
      return ">=";
    case OperatorType::LOGICAL_AND:
      return "&&";
    case OperatorType::LOGICAL_OR:
      return "||";
    case OperatorType::LOGICAL_NOT:
      return "!";
    case OperatorType::BITWISE_AND:
      return "&";
    case OperatorType::BITWISE_OR:
      return "|";
    case OperatorType::BITWISE_XOR:
      return "^";
    case OperatorType::BITWISE_NOT:
      return "~";
    case OperatorType::LEFT_SHIFT:
      return "<<";
    case OperatorType::RIGHT_SHIFT:
      return ">>";
    case OperatorType::INCREMENT:
      return "++";
    case OperatorType::DECREMENT:
      return "--";
    case OperatorType::PLUS_ASSIGN:
      return "+=";
    case OperatorType::MINUS_ASSIGN:
      return "-=";
    case OperatorType::MULTIPLY_ASSIGN:
      return "*=";
    case OperatorType::DIVIDE_ASSIGN:
      return "/=";
    case OperatorType::MODULO_ASSIGN:
      return "%=";
    case OperatorType::AND_ASSIGN:
      return "&=";
    case OperatorType::OR_ASSIGN:
      return "|=";
    case OperatorType::XOR_ASSIGN:
      return "^=";
    case OperatorType::LEFT_SHIFT_ASSIGN:
      return "<<=";
    case OperatorType::RIGHT_SHIFT_ASSIGN:
      return ">>=";
    case OperatorType::ARROW:
      return "->";
    case OperatorType::DOT:
      return ".";
    case OperatorType::SCOPE_RESOLUTION:
      return "::";
    case OperatorType::TERNARY_QUESTION:
      return "?";
    case OperatorType::TERNARY_COLON:
      return ":";
    default:
      return "unknown operator";
  }
}

auto TerminalOperator::Parse() -> void {
  auto currentToken = lexer_->getCurrentToken();
  
  // 确保当前token是操作符
  if (currentToken.getTokenType() != TokenType::OPERATOR) {
    throw std::runtime_error("Expected operator token");
  }
  
  // 获取操作符类型
  operatorType_ = getOperatorTypeFromToken(currentToken);
  
  // 消费操作符token
  lexer_->getNextToken();
}

OperatorType TerminalOperator::getOperatorType() const {
  return operatorType_;
}

void TerminalOperator::setOperatorType(OperatorType operatorType) {
  operatorType_ = operatorType;
}

bool TerminalOperator::isUnaryOperator() const {
  return isUnaryOperator(operatorType_);
}

bool TerminalOperator::isBinaryOperator() const {
  return isBinaryOperator(operatorType_);
}

bool TerminalOperator::isAssignmentOperator() const {
  return isAssignmentOperator(operatorType_);
}

bool TerminalOperator::isComparisonOperator() const {
  return isComparisonOperator(operatorType_);
}

bool TerminalOperator::isLogicalOperator() const {
  return isLogicalOperator(operatorType_);
}

bool TerminalOperator::isArithmeticOperator() const {
  return isArithmeticOperator(operatorType_);
}

bool TerminalOperator::isBitwiseOperator() const {
  return isBitwiseOperator(operatorType_);
}

bool TerminalOperator::isUnaryOperator(OperatorType type) {
  return type == OperatorType::PLUS ||
         type == OperatorType::MINUS ||
         type == OperatorType::LOGICAL_NOT ||
         type == OperatorType::BITWISE_NOT ||
         type == OperatorType::INCREMENT ||
         type == OperatorType::DECREMENT;
}

bool TerminalOperator::isBinaryOperator(OperatorType type) {
  return type == OperatorType::PLUS ||
         type == OperatorType::MINUS ||
         type == OperatorType::MULTIPLY ||
         type == OperatorType::DIVIDE ||
         type == OperatorType::MODULO ||
         type == OperatorType::EQUAL ||
         type == OperatorType::NOT_EQUAL ||
         type == OperatorType::LESS_THAN ||
         type == OperatorType::LESS_THAN_OR_EQUAL ||
         type == OperatorType::GREATER_THAN ||
         type == OperatorType::GREATER_THAN_OR_EQUAL ||
         type == OperatorType::LOGICAL_AND ||
         type == OperatorType::LOGICAL_OR ||
         type == OperatorType::BITWISE_AND ||
         type == OperatorType::BITWISE_OR ||
         type == OperatorType::BITWISE_XOR ||
         type == OperatorType::LEFT_SHIFT ||
         type == OperatorType::RIGHT_SHIFT ||
         type == OperatorType::ASSIGN ||
         type == OperatorType::PLUS_ASSIGN ||
         type == OperatorType::MINUS_ASSIGN ||
         type == OperatorType::MULTIPLY_ASSIGN ||
         type == OperatorType::DIVIDE_ASSIGN ||
         type == OperatorType::MODULO_ASSIGN ||
         type == OperatorType::AND_ASSIGN ||
         type == OperatorType::OR_ASSIGN ||
         type == OperatorType::XOR_ASSIGN ||
         type == OperatorType::LEFT_SHIFT_ASSIGN ||
         type == OperatorType::RIGHT_SHIFT_ASSIGN ||
         type == OperatorType::ARROW ||
         type == OperatorType::DOT ||
         type == OperatorType::SCOPE_RESOLUTION;
}

bool TerminalOperator::isAssignmentOperator(OperatorType type) {
  return type == OperatorType::ASSIGN ||
         type == OperatorType::PLUS_ASSIGN ||
         type == OperatorType::MINUS_ASSIGN ||
         type == OperatorType::MULTIPLY_ASSIGN ||
         type == OperatorType::DIVIDE_ASSIGN ||
         type == OperatorType::MODULO_ASSIGN ||
         type == OperatorType::AND_ASSIGN ||
         type == OperatorType::OR_ASSIGN ||
         type == OperatorType::XOR_ASSIGN ||
         type == OperatorType::LEFT_SHIFT_ASSIGN ||
         type == OperatorType::RIGHT_SHIFT_ASSIGN;
}

bool TerminalOperator::isComparisonOperator(OperatorType type) {
  return type == OperatorType::EQUAL ||
         type == OperatorType::NOT_EQUAL ||
         type == OperatorType::LESS_THAN ||
         type == OperatorType::LESS_THAN_OR_EQUAL ||
         type == OperatorType::GREATER_THAN ||
         type == OperatorType::GREATER_THAN_OR_EQUAL;
}

bool TerminalOperator::isLogicalOperator(OperatorType type) {
  return type == OperatorType::LOGICAL_AND ||
         type == OperatorType::LOGICAL_OR ||
         type == OperatorType::LOGICAL_NOT;
}

bool TerminalOperator::isArithmeticOperator(OperatorType type) {
  return type == OperatorType::PLUS ||
         type == OperatorType::MINUS ||
         type == OperatorType::MULTIPLY ||
         type == OperatorType::DIVIDE ||
         type == OperatorType::MODULO ||
         type == OperatorType::INCREMENT ||
         type == OperatorType::DECREMENT;
}

bool TerminalOperator::isBitwiseOperator(OperatorType type) {
  return type == OperatorType::BITWISE_AND ||
         type == OperatorType::BITWISE_OR ||
         type == OperatorType::BITWISE_XOR ||
         type == OperatorType::BITWISE_NOT ||
         type == OperatorType::LEFT_SHIFT ||
         type == OperatorType::RIGHT_SHIFT;
}

} // namespace mycompiler 