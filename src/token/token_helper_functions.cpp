#include "token/token_helper_functions.hpp"
#include "token/operator_type.hpp"
#include "token/token_type.hpp"
#include <stdexcept>

namespace mycompiler {

auto getKeywordTypeFromToken(const Token &token)
    -> KeywordType const {
  return std::get<Keyword>(token.getTokenValue()).keywordType_;
}

auto getOperatorTypeFromToken(const Token &token)
    -> OperatorType const {
  return std::get<Operator>(token.getTokenValue()).operatorType_;
}

auto getIdentifierValueFromToken(const Token &token)
    -> std::string const {
  return std::get<Identifier>(token.getTokenValue()).value_;
}

auto getConstantValueFromToken(const Token &token)
    -> std::string const {
  return std::get<Constant>(token.getTokenValue()).value_;
}

auto getSeparatorValueFromToken(const Token &token)
    -> std::string const {
  return std::get<Separator>(token.getTokenValue()).value_;
}

auto isIdentifierType(const Token &token) -> bool {
  return token.getTokenType() == TokenType::IDENT;
}

auto isUnaryOperator(const Token &token) -> bool {
  // 实现一元操作符检查逻辑
  if (token.getTokenType() != TokenType::OPERATOR) {
    return false;
  }
  
  OperatorType opType = getOperatorTypeFromToken(token);
  return opType == OperatorType::NOT || 
         opType == OperatorType::SELF_ADD || 
         opType == OperatorType::SELF_SUB;
}

auto isBinaryOperator(const Token &token) -> bool {
  // 实现二元操作符检查逻辑
  if (token.getTokenType() != TokenType::OPERATOR) {
    return false;
  }
  
  OperatorType opType = getOperatorTypeFromToken(token);
  return opType == OperatorType::PLUS || 
         opType == OperatorType::SUB || 
         opType == OperatorType::MUL || 
         opType == OperatorType::DIV || 
         opType == OperatorType::EQUAL || 
         opType == OperatorType::DOUBLE_EQUAL || 
         opType == OperatorType::NOT_EQUAL || 
         opType == OperatorType::HAT;
}

auto getOperatorPriority(const Token &token) -> int {
  switch (getOperatorTypeFromToken(token)) {
  case OperatorType::PLUS: {
    return 1;
  }
  case OperatorType::SUB: {
    return 1;
  }
  case OperatorType::MUL: {
    return 2;
  }
  case OperatorType::DIV: {
    return 2;
  }
  case OperatorType::NOT: {
    return 4;
  }
  case OperatorType::NOT_EQUAL: {
    return 4;
  }
  case OperatorType::SELF_ADD: {
    return 4;
  }
  case OperatorType::SELF_SUB: {
    return 4;
  }
  case OperatorType::DOUBLE_EQUAL: {
    return 4;
  }
  case OperatorType::HAT: {
    return 3;
  }
  default: {
    throw std::runtime_error("无法获取操作符优先级");
  }
  }
}

auto getOperatorPriority(const std::string &op) -> int {
  if (op == "+" || op == "-") {
    return 1;
  }
  if (op == "*" || op == "/") {
    return 2;
  }
  if (op == "^") {
    return 3;
  }
  if (op == "++" || op == "--" || op == "==" || op == "!=") {
    return 4;
  }
  throw std::runtime_error("无法获取操作符优先级: " + op);
}

} // namespace mycompiler
