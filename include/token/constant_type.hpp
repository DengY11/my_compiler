#ifndef CONSTANT_TYPE_HPP
#define CONSTANT_TYPE_HPP
#include <string>
#include <variant>

namespace mycompiler {

// 常量类
class Constant {
public:
  Constant() = delete;
  
  // 构造函数，接收常量值字符串
  Constant(std::string value) : value_(value) {}

  // 常量值
  std::string value_;
  // TODO::先全部用string存值，到语义分析再将string转化为int doule之类的
};

} // namespace mycompiler

#endif
