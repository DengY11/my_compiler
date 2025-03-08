#ifndef TOKEN_HPP
#define TOKEN_HPP
#include "token/comment_type.hpp"
#include "token/constant_type.hpp"
#include "token/eof_or_illegal_type.hpp"
#include "token/ident_type.hpp"
#include "token/keyword_type.hpp"
#include "token/operator_type.hpp"
#include "token/preprocessor.hpp"
#include "token/separator_type.hpp"
#include "token/token_type.hpp"
#include <iostream>
#include <string>
#include <variant>

namespace mycompiler {

// 基本的Token值类型
using TokenValueType_ = std::variant<int, char, double, std::string>;

// Token值类型，使用variant存储不同类型的值
using TokenValueType =
    std::variant<mycompiler::Constant, mycompiler::Keyword, mycompiler::Comment,
                 mycompiler::Identifier, mycompiler::Operator,
                 mycompiler::EofOrIllegal, mycompiler::Separator,
                 mycompiler::Preprocessor>;

class Token {
public:
  // 禁用默认构造函数
  Token() = delete;

  // 允许拷贝构造和移动构造
  Token(const Token &other) = default;
  Token(Token &&other) = default;

  // 各种类型的Token构造函数
  Token(TokenType constantType, mycompiler::Constant tokenValue);
  Token(TokenType keywordType, mycompiler::Keyword tokenValue);
  Token(TokenType commentType, mycompiler::Comment tokenValue);
  Token(TokenType identifierType, mycompiler::Identifier tokenValue);
  Token(TokenType operatorType, mycompiler::Operator tokenValue);
  Token(TokenType eofOrIllegalType, mycompiler::EofOrIllegal tokenValue);
  Token(TokenType separatorType, mycompiler::Separator tokenValue);
  Token(TokenType preprocessorType, mycompiler::Preprocessor tokenValue);

  // 赋值操作符
  auto operator=(const Token &other) -> void;

  // 打印Token信息
  auto printInfo() -> void;

  // 获取Token类型
  auto getTokenType() const -> TokenType;
  
  // 获取Token值
  auto getTokenValue() const -> TokenValueType;

private:
  TokenType tokenType_;     // Token类型
  TokenValueType tokenValue_; // Token值
};

// 创建各种类型的Token的工厂函数
auto makeConstantToken(int value) -> Token;
auto makeConstantToken(double value) -> Token;
auto makeConstantToken(std::string value) -> Token;

auto makeKeywordToken(KeywordType value) -> Token;

auto makeCommentToken(std::string value) -> Token;

auto makeIdentifierToken(std::string value) -> Token;

auto makeOperatorToken(OperatorType value) -> Token;

auto makeEofOrIllegalToken(EofOrIllegalType value) -> Token;

auto makeSeparatorToken(std::string value) -> Token;

auto makePreprocessorToken(std::string value) -> Token;

} // namespace mycompiler

#endif
