#include "lexer/operator_pool.hpp"
#include "token/operator_type.hpp"

#include <stdexcept>

namespace mycompiler {

OperatorPool::OperatorPool()
    : operators_({"+", "-", "*", "/", "!=", "==", "=", "^", "++", "--"}) {}

auto OperatorPool::find(std::string &word) -> bool {
  return this->operators_.find(word) != operators_.end();
}

auto getOperatorTypeFromString(std::string &str) -> OperatorType {
  if (str == "+") {
    return OperatorType::PLUS;
  } else if (str == "-") {
    return OperatorType::SUB;
  } else if (str == "*") {
    return OperatorType::MUL;
  } else if (str == "/") {
    return OperatorType::DIV;
  } else if (str == "==") {
    return OperatorType::DOUBLE_EQUAL;
  } else if (str == "!=") {
    return OperatorType::NOT_EQUAL;
  } else if (str == "=") {
    return OperatorType::EQUAL;
  } else if (str == "^") {
    return OperatorType::HAT;
  } else if (str == "++") {
    return OperatorType::SELF_ADD;
  } else if (str == "--") {
    return OperatorType::SELF_SUB;
  }

  throw std::runtime_error("operator not found: " + str);
}

} // namespace mycompiler
