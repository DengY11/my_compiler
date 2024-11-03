#ifndef KEYWORD_POOL_HPP
#define KEYWORD_POOL_HPP

#include "token/keyword_type.hpp"
#include <string>
#include <unordered_set>

namespace mycompiler {

class KeywordPool {

public:
  KeywordPool();

  auto find(std::string &word) -> bool;

private:
  const std::unordered_set<std::string> keywords_;
  // NOTE::到构造函数的实现里添加初始关键字
};

auto get_keyword_type_from_string(std::string &str) -> Keyword_Type;

} // namespace mycompiler
#endif // !KEYWORD_POOL
