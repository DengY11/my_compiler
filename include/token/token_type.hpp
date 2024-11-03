#ifndef TOKEN_TYPE_HPP
#define TOKEN_TYPE_HPP

namespace mycompiler {

enum class TokenType {
  ILLEGAL_OR_EOF,

  IDENT, // add,foobar,x,y

  CONSTANT, // 10,"hello"

  KEYWORD, // let, function,if,else,for

  OPERATOR, // + - ==

  SEPARATOR, // , : [ {

  COMMENT,

  PREPROCESSOR

};

}

#endif
