#include "lexer/lexer.hpp"
#include "token/token_type.hpp"
#include <gtest/gtest.h>
#include <string>
#include <vector>

namespace {

// 测试简单的词法分析
TEST(LexerTest, SimpleTokenization) {
  std::string code = "let a = 1;";
  mycompiler::Lexer lexer(code);
  
  // 第一次调用getNextToken来初始化
  lexer.getNextToken();
  
  // 获取第一个Token：let关键字
  EXPECT_EQ(lexer.getCurrentToken().getTokenType(), mycompiler::TokenType::KEYWORD);
  
  // 获取第二个Token：标识符a
  lexer.getNextToken();
  EXPECT_EQ(lexer.getCurrentToken().getTokenType(), mycompiler::TokenType::IDENT);
  
  // 获取第三个Token：等号操作符
  lexer.getNextToken();
  EXPECT_EQ(lexer.getCurrentToken().getTokenType(), mycompiler::TokenType::OPERATOR);
  
  // 获取第四个Token：数字1
  lexer.getNextToken();
  EXPECT_EQ(lexer.getCurrentToken().getTokenType(), mycompiler::TokenType::CONSTANT);
  
  // 获取第五个Token：分号
  lexer.getNextToken();
  EXPECT_EQ(lexer.getCurrentToken().getTokenType(), mycompiler::TokenType::SEPARATOR);
  
  // 确保已经到达文件末尾
  lexer.getNextToken();
  EXPECT_EQ(lexer.getCurrentToken().getTokenType(), mycompiler::TokenType::ILLEGAL_OR_EOF);
}

// 测试peekNextToken方法
TEST(LexerTest, PeekNextToken) {
  std::string code = "let a = 1;";
  mycompiler::Lexer lexer(code);
  
  // 第一次调用getNextToken来初始化
  lexer.getNextToken();
  
  // 使用peekNextToken查看下一个Token
  auto peekToken = lexer.peekNextToken();
  EXPECT_EQ(peekToken.getTokenType(), mycompiler::TokenType::IDENT);
  
  // 确认当前位置没有改变
  EXPECT_EQ(lexer.getCurrentToken().getTokenType(), mycompiler::TokenType::KEYWORD);
  
  // 移动到下一个Token
  lexer.getNextToken();
  EXPECT_EQ(lexer.getCurrentToken().getTokenType(), mycompiler::TokenType::IDENT);
  
  // 再次使用peekNextToken
  peekToken = lexer.peekNextToken();
  EXPECT_EQ(peekToken.getTokenType(), mycompiler::TokenType::OPERATOR);
}

} // namespace 