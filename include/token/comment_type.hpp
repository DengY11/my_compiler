#ifndef COMMENT_TYPE_HPP
#define COMMENT_TYPE_HPP

#include <string>

namespace mycompiler {

class Comment {
public:
  Comment(std::string value) : value_(value) {}
  std::string value_;
};

} // namespace mycompiler
#endif // !COMMENT_TYPE_HPP
