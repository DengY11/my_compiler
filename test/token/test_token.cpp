#include "token/token.hpp"
#include "token/token_helper_functions.hpp"
#include "token/token_type.hpp"
#include <gtest/gtest.h>
#include <regex>
#include <string>

namespace {

// 测试操作符Token的创建和属性
TEST(TokenTest, OperatorToken) {
  mycompiler::Token token = mycompiler::makeOperatorToken(mycompiler::OperatorType::DIV);
  
  EXPECT_EQ(token.getTokenType(), mycompiler::TokenType::OPERATOR);
  
  // 获取操作符类型并验证
  mycompiler::OperatorType opType = mycompiler::getOperatorTypeFromToken(token);
  EXPECT_EQ(opType, mycompiler::OperatorType::DIV);
}

// 测试分隔符Token的创建和属性
TEST(TokenTest, SeparatorToken) {
  mycompiler::Token token = mycompiler::makeSeparatorToken(";");
  
  EXPECT_EQ(token.getTokenType(), mycompiler::TokenType::SEPARATOR);
  
  // 获取分隔符值并验证
  std::string separator = mycompiler::getSeparatorValueFromToken(token);
  EXPECT_EQ(separator, ";");
}

// 测试整数常量Token的创建和属性
TEST(TokenTest, IntConstantToken) {
  int value = 42;
  mycompiler::Token token = mycompiler::makeConstantToken(value);
  
  EXPECT_EQ(token.getTokenType(), mycompiler::TokenType::CONSTANT);
  
  // 获取常量值并验证
  std::string constantValue = mycompiler::getConstantValueFromToken(token);
  EXPECT_EQ(constantValue, "42");
}

// 测试浮点数常量Token的创建和属性
TEST(TokenTest, FloatConstantToken) {
  double value = 3.14;
  mycompiler::Token token = mycompiler::makeConstantToken(value);
  
  EXPECT_EQ(token.getTokenType(), mycompiler::TokenType::CONSTANT);
  
  // 获取常量值并验证
  std::string constantValue = mycompiler::getConstantValueFromToken(token);
  
  // 使用正则表达式匹配浮点数，因为不同平台可能有不同的格式化方式
  std::regex floatPattern("3\\.14.*");
  EXPECT_TRUE(std::regex_match(constantValue, floatPattern)) 
      << "Expected a string starting with 3.14, got: " << constantValue;
}

// 测试字符串常量Token的创建和属性
TEST(TokenTest, StringConstantToken) {
  std::string value = "hello";
  mycompiler::Token token = mycompiler::makeConstantToken(value);
  
  EXPECT_EQ(token.getTokenType(), mycompiler::TokenType::CONSTANT);
  
  // 获取常量值并验证
  std::string constantValue = mycompiler::getConstantValueFromToken(token);
  EXPECT_EQ(constantValue, "hello");
}

// 测试关键字Token的创建和属性
TEST(TokenTest, KeywordToken) {
  mycompiler::Token token = mycompiler::makeKeywordToken(mycompiler::KeywordType::ELSE);
  
  EXPECT_EQ(token.getTokenType(), mycompiler::TokenType::KEYWORD);
  
  // 获取关键字类型并验证
  mycompiler::KeywordType keywordType = mycompiler::getKeywordTypeFromToken(token);
  EXPECT_EQ(keywordType, mycompiler::KeywordType::ELSE);
}

// 测试标识符Token的创建和属性
TEST(TokenTest, IdentifierToken) {
  std::string ident = "variable_name";
  mycompiler::Token token = mycompiler::makeIdentifierToken(ident);
  
  EXPECT_EQ(token.getTokenType(), mycompiler::TokenType::IDENT);
  
  // 获取标识符值并验证
  std::string identValue = mycompiler::getIdentifierValueFromToken(token);
  EXPECT_EQ(identValue, "variable_name");
}

// 测试非法Token的创建和属性
TEST(TokenTest, IllegalToken) {
  mycompiler::Token token = mycompiler::makeEofOrIllegalToken(mycompiler::EofOrIllegalType::ILLEGAL);
  
  EXPECT_EQ(token.getTokenType(), mycompiler::TokenType::ILLEGAL_OR_EOF);
}

// 测试EOF Token的创建和属性
TEST(TokenTest, EOFToken) {
  mycompiler::Token token = mycompiler::makeEofOrIllegalToken(mycompiler::EofOrIllegalType::EOF_);
  
  EXPECT_EQ(token.getTokenType(), mycompiler::TokenType::ILLEGAL_OR_EOF);
}

// 测试注释Token的创建和属性
TEST(TokenTest, CommentToken) {
  std::string comment = "// This is a comment";
  mycompiler::Token token = mycompiler::makeCommentToken(comment);
  
  EXPECT_EQ(token.getTokenType(), mycompiler::TokenType::COMMENT);
}

// 测试预处理器Token的创建和属性
TEST(TokenTest, PreprocessorToken) {
  std::string preprocessor = "#include <iostream>";
  mycompiler::Token token = mycompiler::makePreprocessorToken(preprocessor);
  
  EXPECT_EQ(token.getTokenType(), mycompiler::TokenType::PREPROCESSOR);
}

// 测试Token的复制构造函数
TEST(TokenTest, CopyConstructor) {
  mycompiler::Token original = mycompiler::makeKeywordToken(mycompiler::KeywordType::IF);
  mycompiler::Token copy(original);
  
  EXPECT_EQ(copy.getTokenType(), mycompiler::TokenType::KEYWORD);
  EXPECT_EQ(mycompiler::getKeywordTypeFromToken(copy), mycompiler::KeywordType::IF);
}

// 测试Token的移动构造函数
TEST(TokenTest, MoveConstructor) {
  mycompiler::Token original = mycompiler::makeKeywordToken(mycompiler::KeywordType::IF);
  mycompiler::Token moved(std::move(original));
  
  EXPECT_EQ(moved.getTokenType(), mycompiler::TokenType::KEYWORD);
  EXPECT_EQ(mycompiler::getKeywordTypeFromToken(moved), mycompiler::KeywordType::IF);
}

// 测试isUnaryOperator函数
TEST(TokenHelperTest, IsUnaryOperator) {
  mycompiler::Token notOp = mycompiler::makeOperatorToken(mycompiler::OperatorType::NOT);
  mycompiler::Token selfAdd = mycompiler::makeOperatorToken(mycompiler::OperatorType::SELF_ADD);
  mycompiler::Token plus = mycompiler::makeOperatorToken(mycompiler::OperatorType::PLUS);
  
  EXPECT_TRUE(mycompiler::isUnaryOperator(notOp));
  EXPECT_TRUE(mycompiler::isUnaryOperator(selfAdd));
  EXPECT_FALSE(mycompiler::isUnaryOperator(plus));
}

// 测试isBinaryOperator函数
TEST(TokenHelperTest, IsBinaryOperator) {
  mycompiler::Token plus = mycompiler::makeOperatorToken(mycompiler::OperatorType::PLUS);
  mycompiler::Token notOp = mycompiler::makeOperatorToken(mycompiler::OperatorType::NOT);
  
  EXPECT_TRUE(mycompiler::isBinaryOperator(plus));
  EXPECT_FALSE(mycompiler::isBinaryOperator(notOp));
}

// 测试getOperatorPriority函数
TEST(TokenHelperTest, GetOperatorPriority) {
  mycompiler::Token mul = mycompiler::makeOperatorToken(mycompiler::OperatorType::MUL);
  mycompiler::Token plus = mycompiler::makeOperatorToken(mycompiler::OperatorType::PLUS);
  
  // 乘法优先级应该高于加法
  EXPECT_GT(mycompiler::getOperatorPriority(mul), mycompiler::getOperatorPriority(plus));
}

// 测试isIdentifierType函数
TEST(TokenHelperTest, IsIdentifierType) {
  mycompiler::Token ident = mycompiler::makeIdentifierToken("variable");
  mycompiler::Token keyword = mycompiler::makeKeywordToken(mycompiler::KeywordType::IF);
  
  EXPECT_TRUE(mycompiler::isIdentifierType(ident));
  EXPECT_FALSE(mycompiler::isIdentifierType(keyword));
}

// 测试printInfo方法
TEST(TokenTest, PrintInfo) {
  // 这个测试主要是确保printInfo方法不会崩溃
  mycompiler::Token token = mycompiler::makeKeywordToken(mycompiler::KeywordType::IF);
  
  // 重定向cout到一个字符串流
  std::stringstream buffer;
  std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
  
  // 调用printInfo方法
  token.printInfo();
  
  // 恢复cout
  std::cout.rdbuf(oldCout);
  
  // 验证输出不为空
  EXPECT_FALSE(buffer.str().empty());
}

} // namespace
