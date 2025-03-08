#ifndef OPERATOR_TYPE_HPP
#define OPERATOR_TYPE_HPP

namespace mycompiler {

// 操作符类型枚举
enum class OperatorType {
  PLUS,         // +
  DIV,          // /
  SUB,          // -
  MUL,          // *
  EQUAL,        // =
  DOUBLE_EQUAL, // ==
  NOT_EQUAL,    // !=
  HAT,          // ^
  SELF_ADD,     // ++
  SELF_SUB,     // --
  NOT           // !
};

// 操作符类
class Operator {
public:
  Operator() = delete;
  Operator(OperatorType operatorType) : operatorType_(operatorType) {}

  OperatorType operatorType_;
};
} // namespace mycompiler
#endif // !OPERATOR_TYPE_HPP
