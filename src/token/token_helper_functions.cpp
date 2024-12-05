#include "token/token_helper_functions.hpp"
#include "token/operator_type.hpp"
#include "token/token_type.hpp"
#include <stdexcept>

namespace mycompiler {

auto get_keyword_type_from_token_class(const Token &token)
    -> Keyword_Type const {
  return std::get<Keyword>(token.get_token_value()).Keyword_type_;
}

auto get_operator_type_from_token_class(const Token &token)
    -> Operator_Type const {
  return std::get<Operator>(token.get_token_value()).operator_type_;
}

auto get_ident_literal_type_from_token_class(const Token &token)
    -> std::string const {
  return std::get<Identifier>(token.get_token_value()).value_;
}

auto get_value_literal_type_from_token_class(const Token &token)
    -> std::string const {
  return std::get<Identifier>(token.get_token_value()).value_;
}

auto get_separator_type_from_token_class(const Token &token)
    -> std::string const {
  return std::get<Separator>(token.get_token_value()).value_;
}

auto is_identifier_type(const Token &token) -> bool {
  return token.get_token_type() == TokenType::IDENT;
}

auto get_operator_priority(const Token &token) -> int {

  switch (get_operator_type_from_token_class(token)) {
  case Operator_Type::PLUS: {
    return 1;
  }
  case Operator_Type::SUB: {
    return 1;
  }
  case Operator_Type::MUL: {
    return 2;
  }
  case Operator_Type::DIV: {
    return 2;
  }
  case Operator_Type::NOT: {
    return 4;
  }
  case Operator_Type::NOT_EQUAL: {
    return 4;
  }
  case Operator_Type::SELF_ADD: {
    return 4;
  }
  case Operator_Type::SELF_SUB: {
    return 4;
  }
  case Operator_Type::DOUBLE_EQUAL: {
    return 4;
  }
  case Operator_Type::HAT: {
    return 3;
  }
  default: {
    throw std::runtime_error("can't get operator priority");
  }
  }
}

auto get_operator_priority(const std::string &op) -> int {
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
  throw std::runtime_error("can't get operator priority");
}

} // namespace mycompiler
