#include "../../include/lexer/keyword_pool.hpp"
#include "../../include/token/token.hpp"
#include <stdexcept>

namespace mycompiler {

KeywordPool::KeywordPool()
    : keywords_({"let", "if", "else", "for", "return", "function"}) {}

auto KeywordPool::find(std::string &word) -> bool {
  return this->keywords_.find(word) != keywords_.end();
}

auto get_keyword_type_from_string(std::string &str) -> Keyword_Type {
  if (str == "function") {
    return Keyword_Type::FUNCTION;
  } else if (str == "let") {
    return Keyword_Type::LET;
  } else if (str == "else") {
    return Keyword_Type::ELSE;
  } else if (str == "for") {
    return Keyword_Type::FOR;
  } else if (str == "return") {
    return Keyword_Type::RETURN;
  } else if (str == "if") {
    return Keyword_Type::IF;
  }
  throw std::runtime_error(str + "is not a keyword");
}

} // namespace mycompiler
