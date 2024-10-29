#ifndef CONSTANT_TYPE_HPP
#define CONSTANT_TYPE_HPP
#include <string>
#include <variant>

namespace mycompiler {

class Constant {
public:
  Constant(std::string value) : value_(value) {}

  std::string value_;
  // TODO::先全部用string存值，到语义分析再将string转化为int doule之类的
};

} // namespace mycompiler

#endif
