#ifndef PREPROCESSOR_HPP
#define PREPROCESSOR_HPP
#include <string>

namespace mycompiler {

class Preprocessor {
public:
  Preprocessor(std::string value) : value_(value) {}
  std::string value_;
};

} // namespace mycompiler

#endif
