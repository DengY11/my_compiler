#ifndef SEPARATOR_POOL_HPP
#define SEPARATOR_POOL_HPP

#include "token/separator_type.hpp"
#include <string>
#include <unordered_set>

namespace mycompiler {

class SeparatorPool {
public:
  SeparatorPool();
  auto find(std::string &sep) -> bool;

private:
  const std::unordered_set<std::string> separators_;
};

} // namespace mycompiler

#endif
