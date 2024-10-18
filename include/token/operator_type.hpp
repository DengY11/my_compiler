#ifndef OPERATOR_TYPE_HPP
#define OPERATOR_TYPE_HPP

namespace mycompiler {

enum class Operator_Type {
  PLUS,
  DIV,
  SUB,
  MUL,
  EQUAL,
  DOUBLE_EQUAL,
  NOT_EQUAL,
  HAT // ^
};

class Operator {
public:
  Operator() = delete;
  Operator(Operator_Type operator_type) : operator_type_(operator_type) {}

  Operator_Type operator_type_;
};
} // namespace mycompiler
#endif // !OPERATOR_TYPE_HPP
