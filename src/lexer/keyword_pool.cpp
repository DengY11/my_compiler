#include "lexer/keyword_pool.hpp"
#include "token/keyword_type.hpp"
#include "token/token.hpp"
#include <stdexcept>

namespace mycompiler {

KeywordPool::KeywordPool()
    : keywords_({"let", "if", "else", "for", "return", "func", "while", "break",
                 "continue"}) {}

auto KeywordPool::find(std::string &word) -> bool {
  return this->keywords_.find(word) != keywords_.end();
}

auto getKeywordTypeFromString(std::string &str) -> KeywordType {
  if (str == "func") {
    return KeywordType::FUNC;
  } else if (str == "let") {
    return KeywordType::LET;
  } else if (str == "else") {
    return KeywordType::ELSE;
  } else if (str == "for") {
    return KeywordType::FOR;
  } else if (str == "return") {
    return KeywordType::RETURN;
  } else if (str == "if") {
    return KeywordType::IF;
  } else if (str == "while") {
    return KeywordType::WHILE;
  } else if (str == "continue") {
    return KeywordType::CONTINUE;
  } else if (str == "break") {
    return KeywordType::BREAK;
  }
  throw std::runtime_error(str + "is not a keyword");
}

} // namespace mycompiler
