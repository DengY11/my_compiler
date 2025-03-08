#ifndef PREPROCESSOR_HPP
#define PREPROCESSOR_HPP
#include <string>

namespace mycompiler {

// 预处理器类
class Preprocessor {
public:
  Preprocessor() = delete;
  
  // 构造函数，接收预处理器指令
  Preprocessor(std::string value) : value_(value) {}

  // 预处理器指令
  std::string value_;
};

} // namespace mycompiler

#endif
