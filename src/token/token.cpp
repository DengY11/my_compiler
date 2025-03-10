#include "token/token.hpp"
#include "token/keyword_type.hpp"
#include "token/operator_type.hpp"
#include "token/token_helper_functions.hpp"
#include <string>

namespace mycompiler {

Token::Token(TokenType constantType, mycompiler::Constant tokenValue, std::size_t line, std::size_t column)
    : tokenType_(constantType), tokenValue_(tokenValue), line_(line), column_(column) {}

Token::Token(TokenType keywordType, mycompiler::Keyword tokenValue, std::size_t line, std::size_t column)
    : tokenType_(keywordType), tokenValue_(tokenValue), line_(line), column_(column) {}

Token::Token(TokenType commentType, mycompiler::Comment tokenValue, std::size_t line, std::size_t column)
    : tokenType_(commentType), tokenValue_(tokenValue), line_(line), column_(column) {}

Token::Token(TokenType identifierType, mycompiler::Identifier tokenValue, std::size_t line, std::size_t column)
    : tokenType_(identifierType), tokenValue_(tokenValue), line_(line), column_(column) {}

Token::Token(TokenType operatorType, mycompiler::Operator tokenValue, std::size_t line, std::size_t column)
    : tokenType_(operatorType), tokenValue_(tokenValue), line_(line), column_(column) {}

Token::Token(TokenType eofOrIllegalType, mycompiler::EofOrIllegal tokenValue, std::size_t line, std::size_t column)
    : tokenType_(eofOrIllegalType), tokenValue_(tokenValue), line_(line), column_(column) {}

Token::Token(TokenType separatorType, mycompiler::Separator tokenValue, std::size_t line, std::size_t column)
    : tokenType_(separatorType), tokenValue_(tokenValue), line_(line), column_(column) {}

Token::Token(TokenType preprocessorType, mycompiler::Preprocessor tokenValue, std::size_t line, std::size_t column)
    : tokenType_(preprocessorType), tokenValue_(tokenValue), line_(line), column_(column) {}

auto Token::getTokenType() const -> TokenType { 
  return this->tokenType_; 
}

auto Token::getTokenValue() const -> TokenValueType {
  return this->tokenValue_;
}

auto Token::getLineNumber() const -> std::size_t {
  return this->line_;
}

auto Token::getColumnNumber() const -> std::size_t {
  return this->column_;
}

auto makeConstantToken(int value, std::size_t line, std::size_t column) -> Token {
  return Token(TokenType::CONSTANT, Constant(std::to_string(value)), line, column);
}

auto makeConstantToken(double value, std::size_t line, std::size_t column) -> Token {
  return Token(TokenType::CONSTANT, Constant(std::to_string(value)), line, column);
}

auto makeConstantToken(std::string value, std::size_t line, std::size_t column) -> Token {
  return Token(TokenType::CONSTANT, Constant(static_cast<std::string>(value)), line, column);
}

auto makeKeywordToken(KeywordType value, std::size_t line, std::size_t column) -> Token {
  return Token(TokenType::KEYWORD, Keyword(value), line, column);
}

auto makeCommentToken(std::string value, std::size_t line, std::size_t column) -> Token {
  return Token(TokenType::COMMENT, Comment(value), line, column);
}

auto makeIdentifierToken(std::string value, std::size_t line, std::size_t column) -> Token {
  return Token(TokenType::IDENT, Identifier(value), line, column);
}

auto makeOperatorToken(OperatorType value, std::size_t line, std::size_t column) -> Token {
  return Token(TokenType::OPERATOR, Operator(value), line, column);
}

auto makeEofOrIllegalToken(EofOrIllegalType value, std::size_t line, std::size_t column) -> Token {
  return Token(TokenType::ILLEGAL_OR_EOF, EofOrIllegal(value), line, column);
}

auto makeSeparatorToken(std::string value, std::size_t line, std::size_t column) -> Token {
  return Token(TokenType::SEPARATOR, Separator(value), line, column);
}

auto makePreprocessorToken(std::string value, std::size_t line, std::size_t column) -> Token {
  return Token(TokenType::PREPROCESSOR, Preprocessor(value), line, column);
}

auto Token::printInfo() -> void {
  std::cout << "TokenType: ";
  switch (this->tokenType_) {

  case TokenType::ILLEGAL_OR_EOF:
    std::cout << "ILLEGAL_OR_EOF, TokenValue: ";
    if (std::get<mycompiler::EofOrIllegal>(this->tokenValue_)
            .eofOrIllegalType_ == mycompiler::EofOrIllegalType::EOF_) {
      std::cout << "EOF" << std::endl;
    } else if (std::get<mycompiler::EofOrIllegal>(this->tokenValue_)
                   .eofOrIllegalType_ ==
               mycompiler::EofOrIllegalType::ILLEGAL) {
      std::cout << "ILLEGAL" << std::endl;
    }
    break;

  case TokenType::IDENT:
    std::cout << "IDENT, TokenValue: ";
    std::cout << std::get<mycompiler::Identifier>(this->tokenValue_).value_
              << std::endl;
    break;

  case TokenType::CONSTANT:
    std::cout << "CONSTANT, TokenValue: ";
    std::cout << getConstantValueFromToken(*this);
    break;

  case TokenType::KEYWORD:
    std::cout << "KEYWORD, TokenValue: ";
    switch (std::get<mycompiler::Keyword>(this->tokenValue_).keywordType_) {
    case mycompiler::KeywordType::FUNC:
      std::cout << "FUNC" << std::endl;
      break;
    case mycompiler::KeywordType::LET:
      std::cout << "LET" << std::endl;
      break;
    case mycompiler::KeywordType::IF:
      std::cout << "IF" << std::endl;
      break;
    case mycompiler::KeywordType::ELSE:
      std::cout << "ELSE" << std::endl;
      break;
    case mycompiler::KeywordType::FOR:
      std::cout << "FOR" << std::endl;
      break;
    case mycompiler::KeywordType::RETURN:
      std::cout << "RETURN" << std::endl;
      break;
    case mycompiler::KeywordType::WHILE:
      std::cout << "WHILE" << std::endl;
      break;
    }
    break;

  case TokenType::OPERATOR:
    std::cout << "OPERATOR ,TokenValue: ";
    switch (std::get<mycompiler::Operator>(this->tokenValue_).operatorType_) {
    case mycompiler::OperatorType::PLUS:
      std::cout << "PLUS" << std::endl;
      break;
    case mycompiler::OperatorType::DIV:
      std::cout << "DIV" << std::endl;
      break;
    case mycompiler::OperatorType::SUB:
      std::cout << "SUB" << std::endl;
      break;
    case mycompiler::OperatorType::MUL:
      std::cout << "MUL" << std::endl;
      break;
    case mycompiler::OperatorType::EQUAL:
      std::cout << "EQUAL" << std::endl;
      break;
    case mycompiler::OperatorType::DOUBLE_EQUAL:
      std::cout << "DOUBLE_EQUAL" << std::endl;
      break;
    case mycompiler::OperatorType::NOT_EQUAL:
      std::cout << "NOT_EQUAL" << std::endl;
      break;
    case mycompiler::OperatorType::HAT:
      std::cout << "HAT" << std::endl;
      break;
    case mycompiler::OperatorType::SELF_SUB:
      std::cout << "SELF_SUB" << std::endl;
      break;
    case mycompiler::OperatorType::SELF_ADD:
      std::cout << "SELF_ADD" << std::endl;
    }
    break;

  case TokenType::SEPARATOR:
    std::cout << "SEPARATOR, TokenValue: ";
    std::cout << std::get<mycompiler::Separator>(this->tokenValue_).value_
              << std::endl;
    break;

  case TokenType::PREPROCESSOR:
    std::cout << "PREPROCESSOR" << std::endl;
    std::cout << std::get<mycompiler::Preprocessor>(this->tokenValue_).value_
              << std::endl;
    break;
  case TokenType::COMMENT:
    std::cout << "COMMENT, TokenValue: ";
    std::cout << std::get<mycompiler::Comment>(this->tokenValue_).value_
              << std::endl;
  }
}

auto Token::operator=(const Token &other) -> void {
  this->tokenType_ = other.tokenType_;
  this->tokenValue_ = other.tokenValue_;
  this->line_ = other.line_;
  this->column_ = other.column_;
}

} // namespace mycompiler
