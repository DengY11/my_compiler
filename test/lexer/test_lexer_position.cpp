#include "lexer/lexer.hpp"
#include "token/token.hpp"
#include <gtest/gtest.h>
#include <string>

// 测试Lexer的行号和列号跟踪功能
TEST(LexerPositionTest, SingleLine) {
    std::string code = "let x = 5;";
    mycompiler::Lexer lexer(code);
    
    // 获取第一个Token（let）
    lexer.getNextToken();
    auto token = lexer.getCurrentToken();
    EXPECT_EQ(token.getTokenType(), mycompiler::TokenType::KEYWORD);
    EXPECT_EQ(token.getLineNumber(), 1);
    EXPECT_EQ(token.getColumnNumber(), 1);
    
    // 获取第二个Token（x）
    lexer.getNextToken();
    token = lexer.getCurrentToken();
    EXPECT_EQ(token.getTokenType(), mycompiler::TokenType::IDENT);
    EXPECT_EQ(token.getLineNumber(), 1);
    EXPECT_EQ(token.getColumnNumber(), 5);
    
    // 获取第三个Token（=）
    lexer.getNextToken();
    token = lexer.getCurrentToken();
    EXPECT_EQ(token.getTokenType(), mycompiler::TokenType::OPERATOR);
    EXPECT_EQ(token.getLineNumber(), 1);
    EXPECT_EQ(token.getColumnNumber(), 7);
    
    // 获取第四个Token（5）
    lexer.getNextToken();
    token = lexer.getCurrentToken();
    EXPECT_EQ(token.getTokenType(), mycompiler::TokenType::CONSTANT);
    EXPECT_EQ(token.getLineNumber(), 1);
    EXPECT_EQ(token.getColumnNumber(), 9);
    
    // 获取第五个Token（;）
    lexer.getNextToken();
    token = lexer.getCurrentToken();
    EXPECT_EQ(token.getTokenType(), mycompiler::TokenType::SEPARATOR);
    EXPECT_EQ(token.getLineNumber(), 1);
    EXPECT_EQ(token.getColumnNumber(), 10);
}

// 测试多行代码的行号和列号跟踪
TEST(LexerPositionTest, MultiLine) {
    std::string code = "let x = 5;\nlet y = 10;\nlet z = x + y;";
    mycompiler::Lexer lexer(code);
    
    // 第一行的Token
    lexer.getNextToken(); // let
    auto token = lexer.getCurrentToken();
    EXPECT_EQ(token.getLineNumber(), 1);
    EXPECT_EQ(token.getColumnNumber(), 1);
    
    lexer.getNextToken(); // x
    token = lexer.getCurrentToken();
    EXPECT_EQ(token.getLineNumber(), 1);
    EXPECT_EQ(token.getColumnNumber(), 5);
    
    lexer.getNextToken(); // =
    lexer.getNextToken(); // 5
    lexer.getNextToken(); // ;
    
    // 第二行的Token
    lexer.getNextToken(); // let
    token = lexer.getCurrentToken();
    EXPECT_EQ(token.getLineNumber(), 2);
    EXPECT_EQ(token.getColumnNumber(), 1);
    
    lexer.getNextToken(); // y
    token = lexer.getCurrentToken();
    EXPECT_EQ(token.getLineNumber(), 2);
    EXPECT_EQ(token.getColumnNumber(), 5);
    
    lexer.getNextToken(); // =
    lexer.getNextToken(); // 10
    lexer.getNextToken(); // ;
    
    // 第三行的Token
    lexer.getNextToken(); // let
    token = lexer.getCurrentToken();
    EXPECT_EQ(token.getLineNumber(), 3);
    EXPECT_EQ(token.getColumnNumber(), 1);
    
    lexer.getNextToken(); // z
    token = lexer.getCurrentToken();
    EXPECT_EQ(token.getLineNumber(), 3);
    EXPECT_EQ(token.getColumnNumber(), 5);
    
    lexer.getNextToken(); // =
    token = lexer.getCurrentToken();
    EXPECT_EQ(token.getLineNumber(), 3);
    EXPECT_EQ(token.getColumnNumber(), 7);
    
    lexer.getNextToken(); // x
    token = lexer.getCurrentToken();
    EXPECT_EQ(token.getLineNumber(), 3);
    EXPECT_EQ(token.getColumnNumber(), 9);
    
    lexer.getNextToken(); // +
    token = lexer.getCurrentToken();
    EXPECT_EQ(token.getLineNumber(), 3);
    EXPECT_EQ(token.getColumnNumber(), 11);
    
    lexer.getNextToken(); // y
    token = lexer.getCurrentToken();
    EXPECT_EQ(token.getLineNumber(), 3);
    EXPECT_EQ(token.getColumnNumber(), 13);
    
    lexer.getNextToken(); // ;
    token = lexer.getCurrentToken();
    EXPECT_EQ(token.getLineNumber(), 3);
    EXPECT_EQ(token.getColumnNumber(), 14);
}

// 测试空白字符和换行符的处理
TEST(LexerPositionTest, WhitespaceAndNewlines) {
    std::string code = "  let  \n  x  =  \n  5  ;  ";
    mycompiler::Lexer lexer(code);
    
    lexer.getNextToken(); // let
    auto token = lexer.getCurrentToken();
    EXPECT_EQ(token.getLineNumber(), 1);
    EXPECT_EQ(token.getColumnNumber(), 3);
    
    lexer.getNextToken(); // x
    token = lexer.getCurrentToken();
    EXPECT_EQ(token.getLineNumber(), 2);
    EXPECT_EQ(token.getColumnNumber(), 3);
    
    lexer.getNextToken(); // =
    token = lexer.getCurrentToken();
    EXPECT_EQ(token.getLineNumber(), 2);
    EXPECT_EQ(token.getColumnNumber(), 6);
    
    lexer.getNextToken(); // 5
    token = lexer.getCurrentToken();
    EXPECT_EQ(token.getLineNumber(), 3);
    EXPECT_EQ(token.getColumnNumber(), 3);
    
    lexer.getNextToken(); // ;
    token = lexer.getCurrentToken();
    EXPECT_EQ(token.getLineNumber(), 3);
    EXPECT_EQ(token.getColumnNumber(), 6);
}

// 测试Lexer的getCurrentLine和getCurrentColumn方法
TEST(LexerPositionTest, GetCurrentLineAndColumn) {
    std::string code = "let x = 5;\nlet y = 10;";
    mycompiler::Lexer lexer(code);
    
    // 初始位置
    EXPECT_EQ(lexer.getCurrentLine(), 1);
    EXPECT_EQ(lexer.getCurrentColumn(), 1);
    
    // 获取第一个Token后
    lexer.getNextToken(); // let
    EXPECT_EQ(lexer.getCurrentLine(), 1);
    EXPECT_EQ(lexer.getCurrentColumn(), 4); // 'let'的长度是3，所以列号应该是4
    
    // 获取更多Token
    lexer.getNextToken(); // x
    lexer.getNextToken(); // =
    lexer.getNextToken(); // 5
    lexer.getNextToken(); // ;
    
    // 获取第二行的Token
    lexer.getNextToken(); // let
    EXPECT_EQ(lexer.getCurrentLine(), 2);
    EXPECT_EQ(lexer.getCurrentColumn(), 4);
}

// 测试peekNextToken方法是否不影响行号和列号
TEST(LexerPositionTest, PeekNextToken) {
    std::string code = "let x = 5;";
    mycompiler::Lexer lexer(code);
    
    // 获取第一个Token
    lexer.getNextToken(); // let
    auto token = lexer.getCurrentToken();
    EXPECT_EQ(token.getLineNumber(), 1);
    EXPECT_EQ(token.getColumnNumber(), 1);
    
    // 查看下一个Token但不移动指针
    auto nextToken = lexer.peekNextToken(); // x
    EXPECT_EQ(nextToken.getLineNumber(), 1);
    EXPECT_EQ(nextToken.getColumnNumber(), 5);
    
    // 当前Token应该保持不变
    token = lexer.getCurrentToken();
    EXPECT_EQ(token.getLineNumber(), 1);
    EXPECT_EQ(token.getColumnNumber(), 1);
    
    // Lexer的行号和列号也应该保持不变
    EXPECT_EQ(lexer.getCurrentLine(), 1);
    EXPECT_EQ(lexer.getCurrentColumn(), 4);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 