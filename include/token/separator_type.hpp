#ifndef SEPARATOR_TYPE_HPP
#define SEPARATOR_TYPE_HPP

#include <string>
namespace mycompiler {

// 分隔符类
class Separator {

public:
  Separator() = delete;
  
  // 构造函数，接收分隔符字符串
  Separator(std::string value) : value_(value) {}

  // 分隔符字符串
  std::string value_;
};
// TODO::把string改成强枚举类
//
} // namespace mycompiler
#endif // !SEPARATOR_TYPE_HPP
