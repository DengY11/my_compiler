#ifndef IDENT_TYPE_HPP
#define IDENT_TYPE_HPP

#include <string>
namespace mycompiler {

// 标识符类
class Identifier {
public:
  Identifier() = delete;
  
  // 构造函数，接收标识符名称
  Identifier(std::string value) : value_(value) {}

  // 标识符名称
  std::string value_;
};

} // namespace mycompiler
#endif // !IDENT_TYPE_HPP
