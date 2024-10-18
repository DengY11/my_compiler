#include "../../include/lexer/separator_pool.hpp"

namespace mycompiler {

SeparatorPool::SeparatorPool()
    : separators_({";", ",", "(", ")", "{", "}", "\"", "[", "]"}) {}

auto SeparatorPool::find(std::string &word) -> bool {
  return this->separators_.find(word) != separators_.end();
}

} // namespace mycompiler
