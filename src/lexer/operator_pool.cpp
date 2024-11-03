#include "lexer/operator_pool.hpp"

#include <stdexcept>

namespace mycompiler {

OperatorPool::OperatorPool()
    : operators_({"+", "-", "*", "/", "!=", "==", "=", "^"}) {}

auto OperatorPool::find(std::string &word) -> bool {
  return this->operators_.find(word) != operators_.end();
}

auto get_operator_type_from_string(std::string &str) -> Operator_Type {
  if (str == "+") {
    return Operator_Type::PLUS;
  } else if (str == "-") {
    return Operator_Type::SUB;
  } else if (str == "*") {
    return Operator_Type::MUL;
  } else if (str == "/") {
    return Operator_Type::DIV;
  } else if (str == "==") {
    return Operator_Type::DOUBLE_EQUAL;
  } else if (str == "!=") {
    return Operator_Type::NOT_EQUAL;
  } else if (str == "=") {
    return Operator_Type::EQUAL;
  } else if (str == "^") {
    return Operator_Type::HAT;
  }

  throw std::runtime_error("operator not found: " + str);
}

} // namespace mycompiler
