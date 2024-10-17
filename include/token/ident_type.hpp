#ifndef IDENT_TYPE_HPP
#define IDENT_TYPE_HPP

#include <string>
namespace mycompiler {
class Identifier {
public:
  Identifier() = default;
  Identifier(std::string value) : value_(value) {}

  std::string value_;
};
} // namespace mycompiler
#endif // !IDENT_TYPE_HPP
