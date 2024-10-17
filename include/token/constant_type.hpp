#ifndef CONSTANT_TYPE_HPP
#define CONSTANT_TYPE_HPP
#include <string>
#include <variant>

namespace mycompiler {

enum ConstantType {

  INT,
  FLOAT,
  STRING

};

class Constant {
public:
  Constant(int value) : value_(value), type_(ConstantType::INT) {}
  Constant(double value) : value_(value), type_(ConstantType::FLOAT) {}
  Constant(std::string value) : value_(value), type_(ConstantType::STRING) {}

  std::variant<int, double, std::string> value_;
  mycompiler::ConstantType type_;
};

} // namespace mycompiler

#endif
