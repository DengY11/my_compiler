#ifndef LEXER_HPP
#define LEXER_HPP
#include "../token/token.hpp"
#include "./keyword_pool.hpp"

namespace mycompiler {

class Lexer {

public:
  Lexer(const std::string &input);
  auto getNextToken() -> Token;

private:
  std::string input_;
  size_t index_;
  KeywordPool keyword_pool_;

  auto is_keyword(std::string &word) -> bool;
  auto peekChar() -> char;    // get a char and not move
  auto advanceChar() -> char; // get a char and move
  void skipWhitespace();
  auto is_end() -> bool;
};

} // namespace mycompiler

#endif
