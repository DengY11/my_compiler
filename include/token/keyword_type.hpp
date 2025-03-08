#ifndef KEYWORD_TYPE_HPP
#define KEYWORD_TYPE_HPP
#include <string>

namespace mycompiler {

// 关键字类型枚举
enum class KeywordType {
  FUNC,     // function关键字
  LET,      // let关键字
  IF,       // if关键字
  ELSE,     // else关键字
  FOR,      // for关键字
  RETURN,   // return关键字
  WHILE,    // while关键字
  CONTINUE, // continue关键字
  BREAK     // break关键字
};

// 关键字类
class Keyword {
public:
  Keyword() = delete;
  Keyword(KeywordType keywordType) : keywordType_(keywordType) {}

  KeywordType keywordType_;
};

} // namespace mycompiler
#endif
