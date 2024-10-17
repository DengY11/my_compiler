#ifndef SEPARATOR_TYPE
#define SEPARATOR_TYPE

#include <string>
namespace mycompiler {
class Separator {

public:
  Separator() = delete;
  Separator(std::string value) : value_(value) {}
  std::string value_;
};
// TODO::把string改成强枚举类
//
} // namespace mycompiler
#endif // !SEPARATOR_TYPE
