#include "lexer/lexer.hpp"
#include "lexer/lexer_helper_functions.hpp"
#include "token/token_type.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <string>

namespace {

// 测试分隔符的识别
TEST(LexerSeparatorTest, SeparatorRecognition) {
  std::string code = ";";
  mycompiler::Lexer lexer(code);
  
  // 检查分号是否被识别为分隔符
  char semicolon = ';';
  std::cout << "Is ';' a separator? " << (mycompiler::isSeparatorType(semicolon) ? "Yes" : "No") << std::endl;
  
  // 检查分号是否在分隔符池中
  std::string semicolonStr = ";";
  std::cout << "Is ';' in separator pool? " << (lexer.isSeparator(semicolonStr) ? "Yes" : "No") << std::endl;
  
  // 获取分号Token
  lexer.getNextToken();
  
  // 打印Token信息，帮助调试
  std::cout << "Token type: " << static_cast<int>(lexer.getCurrentToken().getTokenType()) << std::endl;
  lexer.getCurrentToken().printInfo();
  
  // 验证Token类型
  EXPECT_EQ(lexer.getCurrentToken().getTokenType(), mycompiler::TokenType::SEPARATOR);
}

} // namespace 