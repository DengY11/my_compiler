#include "token/token.hpp"
#include "token/token_helper_functions.hpp"
#include <gtest/gtest.h>
#include <string>

namespace {

// 测试getKeywordTypeFromToken函数
TEST(TokenHelperFunctionsTest, GetKeywordTypeFromToken) {
  mycompiler::Token ifToken = mycompiler::makeKeywordToken(mycompiler::KeywordType::IF);
  mycompiler::Token forToken = mycompiler::makeKeywordToken(mycompiler::KeywordType::FOR);
  
  EXPECT_EQ(mycompiler::getKeywordTypeFromToken(ifToken), mycompiler::KeywordType::IF);
  EXPECT_EQ(mycompiler::getKeywordTypeFromToken(forToken), mycompiler::KeywordType::FOR);
}

// 测试getOperatorTypeFromToken函数
TEST(TokenHelperFunctionsTest, GetOperatorTypeFromToken) {
  mycompiler::Token plusToken = mycompiler::makeOperatorToken(mycompiler::OperatorType::PLUS);
  mycompiler::Token mulToken = mycompiler::makeOperatorToken(mycompiler::OperatorType::MUL);
  
  EXPECT_EQ(mycompiler::getOperatorTypeFromToken(plusToken), mycompiler::OperatorType::PLUS);
  EXPECT_EQ(mycompiler::getOperatorTypeFromToken(mulToken), mycompiler::OperatorType::MUL);
}

// 测试getIdentifierValueFromToken函数
TEST(TokenHelperFunctionsTest, GetIdentifierValueFromToken) {
  std::string identName = "variableName";
  mycompiler::Token identToken = mycompiler::makeIdentifierToken(identName);
  
  EXPECT_EQ(mycompiler::getIdentifierValueFromToken(identToken), identName);
}

// 测试getConstantValueFromToken函数
TEST(TokenHelperFunctionsTest, GetConstantValueFromToken) {
  int intValue = 42;
  mycompiler::Token intToken = mycompiler::makeConstantToken(intValue);
  
  // 整数常量会被转换为字符串
  EXPECT_EQ(mycompiler::getConstantValueFromToken(intToken), "42");
  
  double doubleValue = 3.14;
  mycompiler::Token doubleToken = mycompiler::makeConstantToken(doubleValue);
  
  // 浮点数常量会被转换为字符串，但格式可能因平台而异
  std::string doubleStr = mycompiler::getConstantValueFromToken(doubleToken);
  EXPECT_TRUE(doubleStr.find("3.14") != std::string::npos);
  
  std::string strValue = "hello";
  mycompiler::Token strToken = mycompiler::makeConstantToken(strValue);
  
  EXPECT_EQ(mycompiler::getConstantValueFromToken(strToken), strValue);
}

// 测试getSeparatorValueFromToken函数
TEST(TokenHelperFunctionsTest, GetSeparatorValueFromToken) {
  std::string sepValue = ";";
  mycompiler::Token sepToken = mycompiler::makeSeparatorToken(sepValue);
  
  EXPECT_EQ(mycompiler::getSeparatorValueFromToken(sepToken), sepValue);
}

// 测试isIdentifierType函数
TEST(TokenHelperFunctionsTest, IsIdentifierType) {
  mycompiler::Token identToken = mycompiler::makeIdentifierToken("variable");
  mycompiler::Token keywordToken = mycompiler::makeKeywordToken(mycompiler::KeywordType::IF);
  
  EXPECT_TRUE(mycompiler::isIdentifierType(identToken));
  EXPECT_FALSE(mycompiler::isIdentifierType(keywordToken));
}

// 测试isUnaryOperator函数
TEST(TokenHelperFunctionsTest, IsUnaryOperator) {
  mycompiler::Token notToken = mycompiler::makeOperatorToken(mycompiler::OperatorType::NOT);
  mycompiler::Token selfAddToken = mycompiler::makeOperatorToken(mycompiler::OperatorType::SELF_ADD);
  mycompiler::Token selfSubToken = mycompiler::makeOperatorToken(mycompiler::OperatorType::SELF_SUB);
  mycompiler::Token plusToken = mycompiler::makeOperatorToken(mycompiler::OperatorType::PLUS);
  
  EXPECT_TRUE(mycompiler::isUnaryOperator(notToken));
  EXPECT_TRUE(mycompiler::isUnaryOperator(selfAddToken));
  EXPECT_TRUE(mycompiler::isUnaryOperator(selfSubToken));
  EXPECT_FALSE(mycompiler::isUnaryOperator(plusToken));
}

// 测试isBinaryOperator函数
TEST(TokenHelperFunctionsTest, IsBinaryOperator) {
  mycompiler::Token plusToken = mycompiler::makeOperatorToken(mycompiler::OperatorType::PLUS);
  mycompiler::Token subToken = mycompiler::makeOperatorToken(mycompiler::OperatorType::SUB);
  mycompiler::Token mulToken = mycompiler::makeOperatorToken(mycompiler::OperatorType::MUL);
  mycompiler::Token divToken = mycompiler::makeOperatorToken(mycompiler::OperatorType::DIV);
  mycompiler::Token notToken = mycompiler::makeOperatorToken(mycompiler::OperatorType::NOT);
  
  EXPECT_TRUE(mycompiler::isBinaryOperator(plusToken));
  EXPECT_TRUE(mycompiler::isBinaryOperator(subToken));
  EXPECT_TRUE(mycompiler::isBinaryOperator(mulToken));
  EXPECT_TRUE(mycompiler::isBinaryOperator(divToken));
  EXPECT_FALSE(mycompiler::isBinaryOperator(notToken));
}

// 测试getOperatorPriority函数（Token版本）
TEST(TokenHelperFunctionsTest, GetOperatorPriorityToken) {
  mycompiler::Token mulToken = mycompiler::makeOperatorToken(mycompiler::OperatorType::MUL);
  mycompiler::Token divToken = mycompiler::makeOperatorToken(mycompiler::OperatorType::DIV);
  mycompiler::Token plusToken = mycompiler::makeOperatorToken(mycompiler::OperatorType::PLUS);
  mycompiler::Token subToken = mycompiler::makeOperatorToken(mycompiler::OperatorType::SUB);
  
  // 乘除法优先级应该相同
  EXPECT_EQ(mycompiler::getOperatorPriority(mulToken), mycompiler::getOperatorPriority(divToken));
  
  // 加减法优先级应该相同
  EXPECT_EQ(mycompiler::getOperatorPriority(plusToken), mycompiler::getOperatorPriority(subToken));
  
  // 乘除法优先级应该高于加减法
  EXPECT_GT(mycompiler::getOperatorPriority(mulToken), mycompiler::getOperatorPriority(plusToken));
}

// 测试getOperatorPriority函数（字符串版本）
TEST(TokenHelperFunctionsTest, GetOperatorPriorityString) {
  // 乘除法优先级应该相同
  EXPECT_EQ(mycompiler::getOperatorPriority("*"), mycompiler::getOperatorPriority("/"));
  
  // 加减法优先级应该相同
  EXPECT_EQ(mycompiler::getOperatorPriority("+"), mycompiler::getOperatorPriority("-"));
  
  // 乘除法优先级应该高于加减法
  EXPECT_GT(mycompiler::getOperatorPriority("*"), mycompiler::getOperatorPriority("+"));
  
  // 测试不存在的操作符
  try {
    mycompiler::getOperatorPriority("unknown");
    FAIL() << "Expected an exception for unknown operator";
  } catch (const std::exception& e) {
    EXPECT_STREQ(e.what(), "无法获取操作符优先级: unknown");
  }
}

} // namespace 