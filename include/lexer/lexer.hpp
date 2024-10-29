#ifndef LEXER_HPP
#define LEXER_HPP
#include "../token/token.hpp"
#include "../token/token_helper_functions.hpp"
#include "./keyword_pool.hpp"
#include "./operator_pool.hpp"
#include "./separator_pool.hpp"
#include <cstddef>

namespace mycompiler {

class Lexer {

public:
  Lexer(const std::string &input);
  auto getNextToken() -> Token;
  auto getCurrentToken() const -> Token;
  auto getCurrentIndex() const -> std::size_t;

  void print_source();

private:
  std::string input_;
  size_t index_;
  KeywordPool keyword_pool_;
  OperatorPool operator_pool_;
  SeparatorPool separator_pool_;
  Token curToken_; // TODO:这里想办法改成引用

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
