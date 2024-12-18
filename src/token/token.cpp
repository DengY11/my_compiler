#include "token/token.hpp"
#include "token/keyword_type.hpp"
#include "token/operator_type.hpp"
#include "token/token_helper_functions.hpp"
#include <string>

namespace mycompiler {

Token::Token(TokenType Constant_type, mycompiler::Constant token_value)
    : token_type_(Constant_type), token_value_(token_value) {}

Token::Token(TokenType Keyword_type, mycompiler::Keyword token_value)
    : token_type_(Keyword_type), token_value_(token_value) {}

Token::Token(TokenType Comment_type, mycompiler::Comment token_value)
    : token_type_(Comment_type), token_value_(token_value) {}

Token::Token(TokenType Identifier_type, mycompiler::Identifier token_value)
    : token_type_(Identifier_type), token_value_(token_value) {}

Token::Token(TokenType Operator_type, mycompiler::Operator token_value)
    : token_type_(Operator_type), token_value_(token_value) {}

Token::Token(TokenType eof_or_illegal_type,
             mycompiler::EOF_OR_ILLEGAL token_value)
    : token_type_(eof_or_illegal_type), token_value_(token_value) {}

Token::Token(TokenType Separator_type, mycompiler::Separator token_value)
    : token_type_(Separator_type), token_value_(token_value) {}

Token::Token(TokenType Preprocessor_type, mycompiler::Preprocessor token_value)
    : token_type_(Preprocessor_type), token_value_(token_value) {}

auto Token::get_token_type() const -> TokenType { return this->token_type_; }

auto Token::get_token_value() const -> TokenValueType {
  return this->token_value_;
}

auto make_constant_token(int value) -> Token {
  return Token(TokenType::CONSTANT, Constant(std::to_string(value)));
}
auto make_constant_token(double value) -> Token {
  return Token(TokenType::CONSTANT, Constant(std::to_string(value)));
}
auto make_constant_token(std::string value) -> Token {
  return Token(TokenType::CONSTANT, Constant(static_cast<std::string>(value)));
}

auto make_keyword_token(Keyword_Type value) -> Token {
  return Token(TokenType::KEYWORD, Keyword(value));
}

auto make_comment_tokenokenTyp(std::string value) -> Token {
  return Token(TokenType::COMMENT, Comment(value));
}

auto make_identifier_token(std::string value) -> Token {
  return Token(TokenType::IDENT, Identifier(value));
}

auto make_operator_token(Operator_Type value) -> Token {
  return Token(TokenType::OPERATOR, Operator(value));
}

auto make_eof_or_illegal_token(EOF_OR_ILLEGAL_TYPE value) -> Token {
  return Token(TokenType::ILLEGAL_OR_EOF, EOF_OR_ILLEGAL(value));
}

auto make_separator_token(std::string value) -> Token {
  return Token(TokenType::SEPARATOR, Separator(value));
}

auto make_preprocessor_token(std::string value) -> Token {
  return Token(TokenType::PREPROCESSOR, Preprocessor(value));
}

void Token::print_info() {
  std::cout << "TokenType: ";
  switch (this->token_type_) {

  case TokenType::ILLEGAL_OR_EOF:
    std::cout << "ILLEGAL_OR_EOF, TokenValue: ";
    if (std::get<mycompiler::EOF_OR_ILLEGAL>(this->token_value_)
            .eof_or_illegal_type_ == mycompiler::EOF_OR_ILLEGAL_TYPE::EOF_) {
      std::cout << "EOF" << std::endl;
    } else if (std::get<mycompiler::EOF_OR_ILLEGAL>(this->token_value_)
                   .eof_or_illegal_type_ ==
               mycompiler::EOF_OR_ILLEGAL_TYPE::ILLEGAL) {
      std::cout << "ILLEGAL" << std::endl;
    }
    break;

  case TokenType::IDENT:
    std::cout << "IDENT, TokenValue: ";
    std::cout << std::get<mycompiler::Identifier>(this->token_value_).value_
              << std::endl;
    break;

  case TokenType::CONSTANT:
    std::cout << "CONSTANT, TokenValue: ";
    std::cout << get_value_literal_type_from_token_class(*this);

    break;

  case TokenType::KEYWORD:
    std::cout << "KEYWORD, TokenValue: ";
    switch (std::get<mycompiler::Keyword>(this->token_value_).Keyword_type_) {
    case mycompiler::Keyword_Type::FUNC:
      std::cout << "FUNC" << std::endl;
      break;
    case mycompiler::Keyword_Type::LET:
      std::cout << "LET" << std::endl;
      break;
    case mycompiler::Keyword_Type::IF:
      std::cout << "IF" << std::endl;
      break;
    case mycompiler::Keyword_Type::ELSE:
      std::cout << "ELSE" << std::endl;
      break;
    case mycompiler::Keyword_Type::FOR:
      std::cout << "FOR" << std::endl;
      break;
    case mycompiler::Keyword_Type::RETURN:
      std::cout << "RETURN" << std::endl;
      break;
    case mycompiler::Keyword_Type::WHILE:
      std::cout << "WHILE" << std::endl;
      break;
    }
    break;

  case TokenType::OPERATOR:
    std::cout << "OPERATOR ,TokenValue: ";
    switch (std::get<mycompiler::Operator>(this->token_value_).operator_type_) {
    case mycompiler::Operator_Type::PLUS:
      std::cout << "PLUS" << std::endl;
      break;
    case mycompiler::Operator_Type::DIV:
      std::cout << "DIV" << std::endl;
      break;
    case mycompiler::Operator_Type::SUB:
      std::cout << "SUB" << std::endl;
      break;
    case mycompiler::Operator_Type::MUL:
      std::cout << "MUL" << std::endl;
      break;
    case mycompiler::Operator_Type::EQUAL:
      std::cout << "EQUAL" << std::endl;
      break;
    case mycompiler::Operator_Type::DOUBLE_EQUAL:
      std::cout << "DOUBLE_EQUAL" << std::endl;
      break;
    case mycompiler::Operator_Type::NOT_EQUAL:
      std::cout << "NOT_EQUAL" << std::endl;
      break;
    case mycompiler::Operator_Type::HAT:
      std::cout << "HAT" << std::endl;
      break;
    case mycompiler::Operator_Type::SELF_SUB:
      std::cout << "SELF_SUB" << std::endl;
      break;
    case mycompiler::Operator_Type::SELF_ADD:
      std::cout << "SELF_ADD" << std::endl;
    }
    break;

  case TokenType::SEPARATOR:
    std::cout << "SEPARATOR, TokenValue: ";
    std::cout << std::get<mycompiler::Separator>(this->token_value_).value_
              << std::endl;
    break;

  case TokenType::PREPROCESSOR:
    std::cout << "PREPROCESSOR" << std::endl;
    std::cout << std::get<mycompiler::Preprocessor>(this->token_value_).value_
              << std::endl;
    break;
  case TokenType::COMMENT:
    std::cout << "COMMENT, TokenValue: ";
    std::cout << std::get<mycompiler::Comment>(this->token_value_).value_
              << std::endl;
  }
}

auto Token::operator=(const Token &other) -> void {
  this->token_type_ = other.token_type_;
  this->token_value_ = other.token_value_;
}

} // namespace mycompiler
