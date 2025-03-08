#include "token/token.hpp"
#include <gtest/gtest.h>
#include <sstream>
#include <string>

namespace {

// 测试Token的构造函数（常量）
TEST(TokenClassTest, ConstantConstructor) {
  mycompiler::Constant constant("123");
  mycompiler::Token token(mycompiler::TokenType::CONSTANT, constant);
  
  EXPECT_EQ(token.getTokenType(), mycompiler::TokenType::CONSTANT);
}

// 测试Token的构造函数（关键字）
TEST(TokenClassTest, KeywordConstructor) {
  mycompiler::Keyword keyword(mycompiler::KeywordType::IF);
  mycompiler::Token token(mycompiler::TokenType::KEYWORD, keyword);
  
  EXPECT_EQ(token.getTokenType(), mycompiler::TokenType::KEYWORD);
}

// 测试Token的构造函数（注释）
TEST(TokenClassTest, CommentConstructor) {
  mycompiler::Comment comment("// This is a comment");
  mycompiler::Token token(mycompiler::TokenType::COMMENT, comment);
  
  EXPECT_EQ(token.getTokenType(), mycompiler::TokenType::COMMENT);
}

// 测试Token的构造函数（标识符）
TEST(TokenClassTest, IdentifierConstructor) {
  mycompiler::Identifier identifier("variableName");
  mycompiler::Token token(mycompiler::TokenType::IDENT, identifier);
  
  EXPECT_EQ(token.getTokenType(), mycompiler::TokenType::IDENT);
}

// 测试Token的构造函数（操作符）
TEST(TokenClassTest, OperatorConstructor) {
  mycompiler::Operator op(mycompiler::OperatorType::PLUS);
  mycompiler::Token token(mycompiler::TokenType::OPERATOR, op);
  
  EXPECT_EQ(token.getTokenType(), mycompiler::TokenType::OPERATOR);
}

// 测试Token的构造函数（EOF或非法）
TEST(TokenClassTest, EofOrIllegalConstructor) {
  mycompiler::EofOrIllegal eofOrIllegal(mycompiler::EofOrIllegalType::EOF_);
  mycompiler::Token token(mycompiler::TokenType::ILLEGAL_OR_EOF, eofOrIllegal);
  
  EXPECT_EQ(token.getTokenType(), mycompiler::TokenType::ILLEGAL_OR_EOF);
}

// 测试Token的构造函数（分隔符）
TEST(TokenClassTest, SeparatorConstructor) {
  mycompiler::Separator separator(";");
  mycompiler::Token token(mycompiler::TokenType::SEPARATOR, separator);
  
  EXPECT_EQ(token.getTokenType(), mycompiler::TokenType::SEPARATOR);
}

// 测试Token的构造函数（预处理器）
TEST(TokenClassTest, PreprocessorConstructor) {
  mycompiler::Preprocessor preprocessor("#include <iostream>");
  mycompiler::Token token(mycompiler::TokenType::PREPROCESSOR, preprocessor);
  
  EXPECT_EQ(token.getTokenType(), mycompiler::TokenType::PREPROCESSOR);
}

// 测试Token的复制构造函数
TEST(TokenClassTest, CopyConstructor) {
  mycompiler::Keyword keyword(mycompiler::KeywordType::IF);
  mycompiler::Token original(mycompiler::TokenType::KEYWORD, keyword);
  mycompiler::Token copy(original);
  
  EXPECT_EQ(copy.getTokenType(), mycompiler::TokenType::KEYWORD);
}

// 测试Token的移动构造函数
TEST(TokenClassTest, MoveConstructor) {
  mycompiler::Keyword keyword(mycompiler::KeywordType::IF);
  mycompiler::Token original(mycompiler::TokenType::KEYWORD, keyword);
  mycompiler::Token moved(std::move(original));
  
  EXPECT_EQ(moved.getTokenType(), mycompiler::TokenType::KEYWORD);
}

// 测试getTokenType方法
TEST(TokenClassTest, GetTokenType) {
  mycompiler::Keyword keyword(mycompiler::KeywordType::IF);
  mycompiler::Token token(mycompiler::TokenType::KEYWORD, keyword);
  
  EXPECT_EQ(token.getTokenType(), mycompiler::TokenType::KEYWORD);
}

// 测试getTokenValue方法
TEST(TokenClassTest, GetTokenValue) {
  mycompiler::Keyword keyword(mycompiler::KeywordType::IF);
  mycompiler::Token token(mycompiler::TokenType::KEYWORD, keyword);
  
  // 获取TokenValue并验证它是一个有效的variant
  auto tokenValue = token.getTokenValue();
  EXPECT_TRUE(std::holds_alternative<mycompiler::Keyword>(tokenValue));
}

// 测试printInfo方法
TEST(TokenClassTest, PrintInfo) {
  // 测试不同类型的Token的printInfo方法
  
  // 关键字Token
  mycompiler::Token keywordToken = mycompiler::makeKeywordToken(mycompiler::KeywordType::IF);
  std::stringstream keywordBuffer;
  std::streambuf* oldCout1 = std::cout.rdbuf(keywordBuffer.rdbuf());
  keywordToken.printInfo();
  std::cout.rdbuf(oldCout1);
  EXPECT_FALSE(keywordBuffer.str().empty());
  
  // 操作符Token
  mycompiler::Token operatorToken = mycompiler::makeOperatorToken(mycompiler::OperatorType::PLUS);
  std::stringstream operatorBuffer;
  std::streambuf* oldCout2 = std::cout.rdbuf(operatorBuffer.rdbuf());
  operatorToken.printInfo();
  std::cout.rdbuf(oldCout2);
  EXPECT_FALSE(operatorBuffer.str().empty());
  
  // EOF或非法Token
  mycompiler::Token eofToken = mycompiler::makeEofOrIllegalToken(mycompiler::EofOrIllegalType::EOF_);
  std::stringstream eofBuffer;
  std::streambuf* oldCout3 = std::cout.rdbuf(eofBuffer.rdbuf());
  eofToken.printInfo();
  std::cout.rdbuf(oldCout3);
  EXPECT_FALSE(eofBuffer.str().empty());
}

// 测试makeConstantToken函数（整数）
TEST(TokenClassTest, MakeConstantTokenInt) {
  mycompiler::Token token = mycompiler::makeConstantToken(42);
  
  EXPECT_EQ(token.getTokenType(), mycompiler::TokenType::CONSTANT);
}

// 测试makeConstantToken函数（浮点数）
TEST(TokenClassTest, MakeConstantTokenDouble) {
  mycompiler::Token token = mycompiler::makeConstantToken(3.14);
  
  EXPECT_EQ(token.getTokenType(), mycompiler::TokenType::CONSTANT);
}

// 测试makeConstantToken函数（字符串）
TEST(TokenClassTest, MakeConstantTokenString) {
  mycompiler::Token token = mycompiler::makeConstantToken("hello");
  
  EXPECT_EQ(token.getTokenType(), mycompiler::TokenType::CONSTANT);
}

// 测试makeKeywordToken函数
TEST(TokenClassTest, MakeKeywordToken) {
  mycompiler::Token token = mycompiler::makeKeywordToken(mycompiler::KeywordType::IF);
  
  EXPECT_EQ(token.getTokenType(), mycompiler::TokenType::KEYWORD);
}

// 测试makeCommentToken函数
TEST(TokenClassTest, MakeCommentToken) {
  mycompiler::Token token = mycompiler::makeCommentToken("// This is a comment");
  
  EXPECT_EQ(token.getTokenType(), mycompiler::TokenType::COMMENT);
}

// 测试makeIdentifierToken函数
TEST(TokenClassTest, MakeIdentifierToken) {
  mycompiler::Token token = mycompiler::makeIdentifierToken("variableName");
  
  EXPECT_EQ(token.getTokenType(), mycompiler::TokenType::IDENT);
}

// 测试makeOperatorToken函数
TEST(TokenClassTest, MakeOperatorToken) {
  mycompiler::Token token = mycompiler::makeOperatorToken(mycompiler::OperatorType::PLUS);
  
  EXPECT_EQ(token.getTokenType(), mycompiler::TokenType::OPERATOR);
}

// 测试makeEofOrIllegalToken函数
TEST(TokenClassTest, MakeEofOrIllegalToken) {
  mycompiler::Token token = mycompiler::makeEofOrIllegalToken(mycompiler::EofOrIllegalType::EOF_);
  
  EXPECT_EQ(token.getTokenType(), mycompiler::TokenType::ILLEGAL_OR_EOF);
}

// 测试makeSeparatorToken函数
TEST(TokenClassTest, MakeSeparatorToken) {
  mycompiler::Token token = mycompiler::makeSeparatorToken(";");
  
  EXPECT_EQ(token.getTokenType(), mycompiler::TokenType::SEPARATOR);
}

// 测试makePreprocessorToken函数
TEST(TokenClassTest, MakePreprocessorToken) {
  mycompiler::Token token = mycompiler::makePreprocessorToken("#include <iostream>");
  
  EXPECT_EQ(token.getTokenType(), mycompiler::TokenType::PREPROCESSOR);
}

} // namespace 