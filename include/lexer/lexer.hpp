#ifndef LEXER_HPP
#define LEXER_HPP
#include "../token/token.hpp"
#include "./keyword_pool.hpp"
#include "./operator_pool.hpp"
#include "./separator_pool.hpp"

namespace mycompiler {

class Lexer {

public:
  Lexer(const std::string &input);
  auto getNextToken() -> Token;

private:
  std::string input_;
  size_t index_;
  KeywordPool keyword_pool_;
  OperatorPool operator_pool_;
  SeparatorPool separator_pool_;

  auto is_keyword(std::string &word) -> bool;
  auto is_operator(std::string &word) -> bool;
  auto is_separator(std::string &word) -> bool;

  auto peekChar() -> char;    // get a char and not move
  auto advanceChar() -> char; // get a char and move
  void skipWhitespace();
  auto is_end() -> bool;
};

} // namespace mycompiler

#endif
