#ifndef TOKEN_HPP
#define TOKEN_HPP
#include "./comment_type.hpp"
#include "./constant_type.hpp"
#include "./ident_type.hpp"
#include "./keyword_type.hpp"
#include "./operator_type.hpp"
#include "./preprocessor.hpp"
#include "./separator_type.hpp"
#include "./token_type.hpp"
#include "eof_or_illegal_type.hpp"
#include <iostream>
#include <string>
#include <variant>

namespace mycompiler {

using TokenValueType_ = std::variant<int, char, double, std::string>;
using TokenValueType =
    std::variant<mycompiler::Constant, mycompiler::Keyword, mycompiler::Comment,
                 mycompiler::Identifier, mycompiler::Operator,
                 mycompiler::EOF_OR_ILLEGAL, mycompiler::Separator,
                 mycompiler::Preprocessor>;

class Token {
public:
  Token() = delete;

  Token(const Token &other) = default;

  Token(Token &&other) = default;

  Token(TokenType Constant_type, mycompiler::Constant token_value);
  Token(TokenType Keyword_type, mycompiler::Keyword token_value);
  Token(TokenType Comment_type, mycompiler::Comment token_value);
  Token(TokenType Identifier_type, mycompiler::Identifier token_value);
  Token(TokenType Operator_type, mycompiler::Operator token_value);
  Token(TokenType eof_or_illegal_type, mycompiler::EOF_OR_ILLEGAL token_value);
  Token(TokenType Separator_type, mycompiler::Separator token_value);
  Token(TokenType Preprocessor_type, mycompiler::Preprocessor token_value);

  auto operator=(const Token &other) -> void; // TODO:

  void print_info();

  auto get_token_type() const -> TokenType;
  auto get_token_value() const -> TokenValueType;

private:
  TokenType token_type_;
  TokenValueType token_value_;
};

auto make_constant_token(int value) -> Token;
auto make_constant_token(double value) -> Token;
auto make_constant_token(std::string value) -> Token;

auto make_keyword_token(Keyword_Type value) -> Token;

auto make_comment_tokenokenTyp(std::string value) -> Token;

auto make_identifier_token(std::string value) -> Token;

auto make_operator_token(Operator_Type value) -> Token;

auto make_eof_or_illegal_token(EOF_OR_ILLEGAL_TYPE value) -> Token;

auto make_separator_token(std::string value) -> Token;

auto make_preprocessor_token(std::string value) -> Token;

} // namespace mycompiler

#endif
