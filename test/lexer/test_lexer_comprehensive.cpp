#include "lexer/lexer.hpp"
#include "lexer/lexer_helper_functions.hpp"
#include "token/token_helper_functions.hpp"
#include "token/token_type.hpp"
#include <gtest/gtest.h>
#include <string>
#include <vector>

namespace {

// 测试数字常量的词法分析
TEST(LexerComprehensiveTest, NumberConstant) {
  // 测试整数
  {
    std::string code = "42";
    mycompiler::Lexer lexer(code);
    
    lexer.getNextToken();
    EXPECT_EQ(lexer.getCurrentToken().getTokenType(), mycompiler::TokenType::CONSTANT);
    EXPECT_EQ(mycompiler::getConstantValueFromToken(lexer.getCurrentToken()), "42");
    
    // 确保已经到达文件末尾
    lexer.getNextToken();
    EXPECT_EQ(lexer.getCurrentToken().getTokenType(), mycompiler::TokenType::ILLEGAL_OR_EOF);
  }
  
  // 测试浮点数
  {
    std::string code = "3.14";
    mycompiler::Lexer lexer(code);
    
    lexer.getNextToken();
    EXPECT_EQ(lexer.getCurrentToken().getTokenType(), mycompiler::TokenType::CONSTANT);
    std::string value = mycompiler::getConstantValueFromToken(lexer.getCurrentToken());
    EXPECT_TRUE(value.find("3.14") != std::string::npos);
    
    // 确保已经到达文件末尾
    lexer.getNextToken();
    EXPECT_EQ(lexer.getCurrentToken().getTokenType(), mycompiler::TokenType::ILLEGAL_OR_EOF);
  }
}

// 测试标识符的词法分析
TEST(LexerComprehensiveTest, Identifier) {
  // 测试简单标识符
  {
    std::string code = "variable";
    mycompiler::Lexer lexer(code);
    
    lexer.getNextToken();
    EXPECT_EQ(lexer.getCurrentToken().getTokenType(), mycompiler::TokenType::IDENT);
    EXPECT_EQ(mycompiler::getIdentifierValueFromToken(lexer.getCurrentToken()), "variable");
    
    // 确保已经到达文件末尾
    lexer.getNextToken();
    EXPECT_EQ(lexer.getCurrentToken().getTokenType(), mycompiler::TokenType::ILLEGAL_OR_EOF);
  }
  
  // 测试带下划线的标识符
  {
    std::string code = "variable_name";
    mycompiler::Lexer lexer(code);
    
    lexer.getNextToken();
    EXPECT_EQ(lexer.getCurrentToken().getTokenType(), mycompiler::TokenType::IDENT);
    EXPECT_EQ(mycompiler::getIdentifierValueFromToken(lexer.getCurrentToken()), "variable_name");
    
    // 确保已经到达文件末尾
    lexer.getNextToken();
    EXPECT_EQ(lexer.getCurrentToken().getTokenType(), mycompiler::TokenType::ILLEGAL_OR_EOF);
  }
}

// 测试关键字的词法分析
TEST(LexerComprehensiveTest, Keyword) {
  // 测试所有关键字
  std::vector<std::string> keywords = {"let", "if", "else", "for", "return", "func", "while", "break", "continue"};
  
  for (const auto& keyword : keywords) {
    mycompiler::Lexer lexer(keyword);
    
    lexer.getNextToken();
    EXPECT_EQ(lexer.getCurrentToken().getTokenType(), mycompiler::TokenType::KEYWORD);
    
    // 确保已经到达文件末尾
    lexer.getNextToken();
    EXPECT_EQ(lexer.getCurrentToken().getTokenType(), mycompiler::TokenType::ILLEGAL_OR_EOF);
  }
}

// 测试操作符的词法分析
TEST(LexerComprehensiveTest, Operator) {
  // 测试所有操作符
  std::vector<std::string> operators = {"+", "-", "*", "/", "=", "==", "!=", "^", "++", "--"};
  
  for (const auto& op : operators) {
    mycompiler::Lexer lexer(op);
    
    lexer.getNextToken();
    EXPECT_EQ(lexer.getCurrentToken().getTokenType(), mycompiler::TokenType::OPERATOR);
    
    // 确保已经到达文件末尾
    lexer.getNextToken();
    EXPECT_EQ(lexer.getCurrentToken().getTokenType(), mycompiler::TokenType::ILLEGAL_OR_EOF);
  }
}

// 测试分隔符的词法分析
TEST(LexerComprehensiveTest, Separator) {
  // 测试所有分隔符
  std::vector<std::string> separators = {";", ",", "(", ")", "{", "}", "\"", "[", "]"};
  
  for (const auto& sep : separators) {
    mycompiler::Lexer lexer(sep);
    
    lexer.getNextToken();
    EXPECT_EQ(lexer.getCurrentToken().getTokenType(), mycompiler::TokenType::SEPARATOR);
    EXPECT_EQ(mycompiler::getSeparatorValueFromToken(lexer.getCurrentToken()), sep);
    
    // 确保已经到达文件末尾
    lexer.getNextToken();
    EXPECT_EQ(lexer.getCurrentToken().getTokenType(), mycompiler::TokenType::ILLEGAL_OR_EOF);
  }
}

// 测试复杂表达式的词法分析
TEST(LexerComprehensiveTest, ComplexExpression) {
  std::string code = "let sum = a + b * (c - d);";
  mycompiler::Lexer lexer(code);
  
  // let
  lexer.getNextToken();
  EXPECT_EQ(lexer.getCurrentToken().getTokenType(), mycompiler::TokenType::KEYWORD);
  
  // sum
  lexer.getNextToken();
  EXPECT_EQ(lexer.getCurrentToken().getTokenType(), mycompiler::TokenType::IDENT);
  EXPECT_EQ(mycompiler::getIdentifierValueFromToken(lexer.getCurrentToken()), "sum");
  
  // =
  lexer.getNextToken();
  EXPECT_EQ(lexer.getCurrentToken().getTokenType(), mycompiler::TokenType::OPERATOR);
  
  // a
  lexer.getNextToken();
  EXPECT_EQ(lexer.getCurrentToken().getTokenType(), mycompiler::TokenType::IDENT);
  EXPECT_EQ(mycompiler::getIdentifierValueFromToken(lexer.getCurrentToken()), "a");
  
  // +
  lexer.getNextToken();
  EXPECT_EQ(lexer.getCurrentToken().getTokenType(), mycompiler::TokenType::OPERATOR);
  
  // b
  lexer.getNextToken();
  EXPECT_EQ(lexer.getCurrentToken().getTokenType(), mycompiler::TokenType::IDENT);
  EXPECT_EQ(mycompiler::getIdentifierValueFromToken(lexer.getCurrentToken()), "b");
  
  // *
  lexer.getNextToken();
  EXPECT_EQ(lexer.getCurrentToken().getTokenType(), mycompiler::TokenType::OPERATOR);
  
  // (
  lexer.getNextToken();
  EXPECT_EQ(lexer.getCurrentToken().getTokenType(), mycompiler::TokenType::SEPARATOR);
  EXPECT_EQ(mycompiler::getSeparatorValueFromToken(lexer.getCurrentToken()), "(");
  
  // c
  lexer.getNextToken();
  EXPECT_EQ(lexer.getCurrentToken().getTokenType(), mycompiler::TokenType::IDENT);
  EXPECT_EQ(mycompiler::getIdentifierValueFromToken(lexer.getCurrentToken()), "c");
  
  // -
  lexer.getNextToken();
  EXPECT_EQ(lexer.getCurrentToken().getTokenType(), mycompiler::TokenType::OPERATOR);
  
  // d
  lexer.getNextToken();
  EXPECT_EQ(lexer.getCurrentToken().getTokenType(), mycompiler::TokenType::IDENT);
  EXPECT_EQ(mycompiler::getIdentifierValueFromToken(lexer.getCurrentToken()), "d");
  
  // )
  lexer.getNextToken();
  EXPECT_EQ(lexer.getCurrentToken().getTokenType(), mycompiler::TokenType::SEPARATOR);
  EXPECT_EQ(mycompiler::getSeparatorValueFromToken(lexer.getCurrentToken()), ")");
  
  // ;
  lexer.getNextToken();
  EXPECT_EQ(lexer.getCurrentToken().getTokenType(), mycompiler::TokenType::SEPARATOR);
  EXPECT_EQ(mycompiler::getSeparatorValueFromToken(lexer.getCurrentToken()), ";");
  
  // 确保已经到达文件末尾
  lexer.getNextToken();
  EXPECT_EQ(lexer.getCurrentToken().getTokenType(), mycompiler::TokenType::ILLEGAL_OR_EOF);
}

// 测试辅助函数
TEST(LexerHelperFunctionsTest, HelperFunctions) {
  // 测试isConstantNumberType
  EXPECT_TRUE(mycompiler::isConstantNumberType('0'));
  EXPECT_TRUE(mycompiler::isConstantNumberType('9'));
  EXPECT_TRUE(mycompiler::isConstantNumberType('.'));
  EXPECT_FALSE(mycompiler::isConstantNumberType('a'));
  
  // 测试isConstantStringType
  EXPECT_TRUE(mycompiler::isConstantStringType('a'));
  EXPECT_FALSE(mycompiler::isConstantStringType('\0'));
  
  // 测试isIdentType
  EXPECT_TRUE(mycompiler::isIdentType('a'));
  EXPECT_TRUE(mycompiler::isIdentType('Z'));
  EXPECT_TRUE(mycompiler::isIdentType('0'));
  EXPECT_TRUE(mycompiler::isIdentType('_'));
  EXPECT_FALSE(mycompiler::isIdentType('+'));
  
  // 测试isKeywordType
  EXPECT_TRUE(mycompiler::isKeywordType('a'));
  EXPECT_TRUE(mycompiler::isKeywordType('Z'));
  EXPECT_FALSE(mycompiler::isKeywordType('0'));
  EXPECT_FALSE(mycompiler::isKeywordType('_'));
  
  // 测试isOperatorType
  EXPECT_TRUE(mycompiler::isOperatorType('+'));
  EXPECT_TRUE(mycompiler::isOperatorType('-'));
  EXPECT_TRUE(mycompiler::isOperatorType('*'));
  EXPECT_TRUE(mycompiler::isOperatorType('/'));
  EXPECT_TRUE(mycompiler::isOperatorType('='));
  EXPECT_TRUE(mycompiler::isOperatorType('!'));
  EXPECT_TRUE(mycompiler::isOperatorType('^'));
  EXPECT_FALSE(mycompiler::isOperatorType('a'));
  
  // 测试isSeparatorType
  EXPECT_TRUE(mycompiler::isSeparatorType('('));
  EXPECT_TRUE(mycompiler::isSeparatorType(')'));
  EXPECT_TRUE(mycompiler::isSeparatorType('{'));
  EXPECT_TRUE(mycompiler::isSeparatorType('}'));
  EXPECT_TRUE(mycompiler::isSeparatorType('['));
  EXPECT_TRUE(mycompiler::isSeparatorType(']'));
  EXPECT_TRUE(mycompiler::isSeparatorType(','));
  EXPECT_TRUE(mycompiler::isSeparatorType(';'));
  EXPECT_TRUE(mycompiler::isSeparatorType('"'));
  EXPECT_FALSE(mycompiler::isSeparatorType('a'));
  
  // 测试maybeBinaryOperator
  EXPECT_TRUE(mycompiler::maybeBinaryOperator('+'));
  EXPECT_TRUE(mycompiler::maybeBinaryOperator('-'));
  EXPECT_TRUE(mycompiler::maybeBinaryOperator('*'));
  EXPECT_TRUE(mycompiler::maybeBinaryOperator('/'));
  EXPECT_TRUE(mycompiler::maybeBinaryOperator('^'));
  EXPECT_TRUE(mycompiler::maybeBinaryOperator('='));
  EXPECT_FALSE(mycompiler::maybeBinaryOperator('!'));
  
  // 测试maybeUnaryOperator
  EXPECT_TRUE(mycompiler::maybeUnaryOperator('!'));
  EXPECT_FALSE(mycompiler::maybeUnaryOperator('+'));
  
  // 测试separatorCanCombine
  std::string bracket1 = "[";
  EXPECT_TRUE(mycompiler::separatorCanCombine(bracket1, '['));
  std::string bracket2 = "]";
  EXPECT_TRUE(mycompiler::separatorCanCombine(bracket2, ']'));
  std::string bracket3 = "(";
  EXPECT_FALSE(mycompiler::separatorCanCombine(bracket3, '('));
}

// 测试错误处理
TEST(LexerErrorHandlingTest, ErrorHandling) {
  // 测试非法操作符
  {
    std::string code = "@";
    mycompiler::Lexer lexer(code);
    
    lexer.getNextToken();
    EXPECT_EQ(lexer.getCurrentToken().getTokenType(), mycompiler::TokenType::ILLEGAL_OR_EOF);
  }
  
  // 测试多个小数点的数字
  {
    std::string code = "3.14.159";
    mycompiler::Lexer lexer(code);
    
    EXPECT_THROW(lexer.getNextToken(), std::runtime_error);
  }
}

} // namespace 