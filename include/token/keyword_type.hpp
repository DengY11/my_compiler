#ifndef KEYWORD_TYPE_HPP
#define KEYWORD_TYPE_HPP
#include <string>

namespace mycompiler {

enum class Keyword_Type { FUNC, LET, RETURN, IF, ELSE, FOR, WHILE };
// NOTE::添加关键词记得修改lexer的keyword_pool

class Keyword {
public:
  Keyword() = delete;
  Keyword(Keyword_Type keyword_type) : Keyword_type_(keyword_type) {}

  Keyword_Type Keyword_type_;
};

} // namespace mycompiler
#endif
