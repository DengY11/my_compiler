#ifndef COMMENT_TYPE_HPP
#define COMMENT_TYPE_HPP

#include <string>

namespace mycompiler {

// 注释类
class Comment {
public:
  Comment() = delete;
  
  // 构造函数，接收注释内容
  Comment(std::string value) : value_(value) {}

  // 注释内容
  std::string value_;
};

} // namespace mycompiler
#endif // !COMMENT_TYPE_HPP
