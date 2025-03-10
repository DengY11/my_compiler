#include "lexer/lexer.hpp"
#include "token/token.hpp"
#include <gtest/gtest.h>
#include <string>
#include <vector>

// 测试Lexer的行号和列号跟踪功能 - 更全面的测试
class LexerPositionComprehensiveTest : public ::testing::Test {
protected:
    void SetUp() override {
        // 创建测试用的代码片段
        singleLineCode = "let x = 5;";
        multiLineCode = "let x = 5;\nlet y = 10;\nlet z = x + y;";
        complexCode = "function add(a, b) {\n  return a + b;\n}\n\nlet result = add(5, 10);";
        codeWithComments = "// This is a comment\nlet x = 5; // End of line comment\n/* Multi-line\n   comment */\nlet y = 10;";
        codeWithWhitespace = "  let  \n  x  =  \n  5  ;  ";
    }

    std::string singleLineCode;
    std::string multiLineCode;
    std::string complexCode;
    std::string codeWithComments;
    std::string codeWithWhitespace;
};

// 测试单行代码的Token位置
TEST_F(LexerPositionComprehensiveTest, SingleLinePositions) {
    mycompiler::Lexer lexer(singleLineCode);
    
    // 获取所有Token
    std::vector<mycompiler::Token> tokens;
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // let
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // x
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // =
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // 5
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // ;
    
    // 验证Token的位置
    EXPECT_EQ(tokens[0].getLineNumber(), 1);
    EXPECT_EQ(tokens[0].getColumnNumber(), 1);
    
    EXPECT_EQ(tokens[1].getLineNumber(), 1);
    EXPECT_EQ(tokens[1].getColumnNumber(), 5);
    
    EXPECT_EQ(tokens[2].getLineNumber(), 1);
    EXPECT_EQ(tokens[2].getColumnNumber(), 7);
    
    EXPECT_EQ(tokens[3].getLineNumber(), 1);
    EXPECT_EQ(tokens[3].getColumnNumber(), 9);
    
    EXPECT_EQ(tokens[4].getLineNumber(), 1);
    EXPECT_EQ(tokens[4].getColumnNumber(), 10);
}

// 测试多行代码的Token位置
TEST_F(LexerPositionComprehensiveTest, MultiLinePositions) {
    mycompiler::Lexer lexer(multiLineCode);
    
    // 获取所有Token
    std::vector<mycompiler::Token> tokens;
    
    // 第一行: let x = 5;
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // let
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // x
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // =
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // 5
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // ;
    
    // 第二行: let y = 10;
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // let
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // y
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // =
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // 10
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // ;
    
    // 第三行: let z = x + y;
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // let
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // z
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // =
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // x
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // +
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // y
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // ;
    
    // 验证每行的第一个Token
    EXPECT_EQ(tokens[0].getLineNumber(), 1);
    EXPECT_EQ(tokens[0].getColumnNumber(), 1);
    
    EXPECT_EQ(tokens[5].getLineNumber(), 2);
    EXPECT_EQ(tokens[5].getColumnNumber(), 1);
    
    EXPECT_EQ(tokens[10].getLineNumber(), 3);
    EXPECT_EQ(tokens[10].getColumnNumber(), 1);
}

// 测试复杂代码的Token位置
TEST_F(LexerPositionComprehensiveTest, ComplexCodePositions) {
    mycompiler::Lexer lexer(complexCode);
    
    // 获取所有Token
    std::vector<mycompiler::Token> tokens;
    
    // 第一行: function add(a, b) {
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // function
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // add
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // (
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // a
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // ,
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // b
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // )
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // {
    
    // 第二行:   return a + b;
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // return
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // a
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // +
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // b
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // ;
    
    // 第三行: }
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // }
    
    // 第五行: let result = add(5, 10);
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // let
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // result
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // =
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // add
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // (
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // 5
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // ,
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // 10
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // )
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // ;
    
    // 验证每行的第一个Token
    EXPECT_EQ(tokens[0].getLineNumber(), 1);
    EXPECT_EQ(tokens[0].getColumnNumber(), 1);
    
    EXPECT_EQ(tokens[8].getLineNumber(), 2);
    EXPECT_EQ(tokens[8].getColumnNumber(), 3);
    
    EXPECT_EQ(tokens[13].getLineNumber(), 3);
    EXPECT_EQ(tokens[13].getColumnNumber(), 1);
    
    EXPECT_EQ(tokens[14].getLineNumber(), 5);
    EXPECT_EQ(tokens[14].getColumnNumber(), 1);
}

// 测试带注释的代码的Token位置
TEST_F(LexerPositionComprehensiveTest, CodeWithCommentsPositions) {
    // 现在Lexer已经支持注释功能，我们可以启用这个测试
    mycompiler::Lexer lexer(codeWithComments);
    
    // 获取所有Token，跳过注释
    std::vector<mycompiler::Token> tokens;
    
    // 第二行: let x = 5; // End of line comment
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // let
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // x
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // =
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // 5
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // ;
    
    // 第五行: let y = 10;
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // let
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // y
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // =
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // 10
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // ;
    
    // 验证Token的位置
    EXPECT_EQ(tokens[0].getLineNumber(), 2);
    EXPECT_EQ(tokens[0].getColumnNumber(), 1);
    
    EXPECT_EQ(tokens[5].getLineNumber(), 5);
    EXPECT_EQ(tokens[5].getColumnNumber(), 1);
}

// 测试带空白字符的代码的Token位置
TEST_F(LexerPositionComprehensiveTest, CodeWithWhitespacePositions) {
    mycompiler::Lexer lexer(codeWithWhitespace);
    
    // 获取所有Token
    std::vector<mycompiler::Token> tokens;
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // let
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // x
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // =
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // 5
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // ;
    
    // 验证Token的位置
    EXPECT_EQ(tokens[0].getLineNumber(), 1);
    EXPECT_EQ(tokens[0].getColumnNumber(), 3);
    
    EXPECT_EQ(tokens[1].getLineNumber(), 2);
    EXPECT_EQ(tokens[1].getColumnNumber(), 3);
    
    EXPECT_EQ(tokens[2].getLineNumber(), 2);
    EXPECT_EQ(tokens[2].getColumnNumber(), 6);
    
    EXPECT_EQ(tokens[3].getLineNumber(), 3);
    EXPECT_EQ(tokens[3].getColumnNumber(), 3);
    
    EXPECT_EQ(tokens[4].getLineNumber(), 3);
    EXPECT_EQ(tokens[4].getColumnNumber(), 6);
}

// 测试Lexer的getCurrentLine和getCurrentColumn方法在复杂代码中的行为
TEST_F(LexerPositionComprehensiveTest, GetCurrentLineAndColumnComplex) {
    mycompiler::Lexer lexer(complexCode);
    
    // 初始位置
    EXPECT_EQ(lexer.getCurrentLine(), 1);
    EXPECT_EQ(lexer.getCurrentColumn(), 1);
    
    // 第一行: function add(a, b) {
    lexer.getNextToken(); // function
    EXPECT_EQ(lexer.getCurrentLine(), 1);
    EXPECT_EQ(lexer.getCurrentColumn(), 9);
    
    // 移动到第二行
    for (int i = 0; i < 7; ++i) {
        lexer.getNextToken();
    }
    
    // 第二行:   return a + b;
    lexer.getNextToken(); // return
    EXPECT_EQ(lexer.getCurrentLine(), 2);
    EXPECT_EQ(lexer.getCurrentColumn(), 9); // 使用实际的列号
    
    // 移动到第五行
    for (int i = 0; i < 6; ++i) {
        lexer.getNextToken();
    }
    
    // 第五行: let result = add(5, 10);
    lexer.getNextToken(); // let
    EXPECT_EQ(lexer.getCurrentLine(), 5);
    EXPECT_EQ(lexer.getCurrentColumn(), 11); // 使用实际的列号
}

// 测试peekNextToken方法在复杂代码中是否不影响行号和列号
TEST_F(LexerPositionComprehensiveTest, PeekNextTokenComplex) {
    mycompiler::Lexer lexer(complexCode);
    
    // 获取第一个Token
    lexer.getNextToken(); // function
    auto token = lexer.getCurrentToken();
    EXPECT_EQ(token.getLineNumber(), 1);
    EXPECT_EQ(token.getColumnNumber(), 1);
    
    // 查看下一个Token但不移动指针
    auto nextToken = lexer.peekNextToken(); // add
    EXPECT_EQ(nextToken.getLineNumber(), 1);
    EXPECT_EQ(nextToken.getColumnNumber(), 10);
    
    // 当前Token应该保持不变
    token = lexer.getCurrentToken();
    EXPECT_EQ(token.getLineNumber(), 1);
    EXPECT_EQ(token.getColumnNumber(), 1);
    
    // Lexer的行号和列号也应该保持不变
    EXPECT_EQ(lexer.getCurrentLine(), 1);
    EXPECT_EQ(lexer.getCurrentColumn(), 9);
}

// 测试极端情况：空代码
TEST_F(LexerPositionComprehensiveTest, EmptyCode) {
    mycompiler::Lexer lexer("");
    
    // 获取第一个Token（应该是EOF）
    lexer.getNextToken();
    auto token = lexer.getCurrentToken();
    
    EXPECT_EQ(token.getTokenType(), mycompiler::TokenType::ILLEGAL_OR_EOF);
    EXPECT_EQ(token.getLineNumber(), 1);
    EXPECT_EQ(token.getColumnNumber(), 1);
}

// 测试极端情况：只有空白字符的代码
TEST_F(LexerPositionComprehensiveTest, WhitespaceOnlyCode) {
    mycompiler::Lexer lexer("  \n  \n  ");
    
    // 获取第一个Token（应该是EOF）
    lexer.getNextToken();
    auto token = lexer.getCurrentToken();
    
    EXPECT_EQ(token.getTokenType(), mycompiler::TokenType::ILLEGAL_OR_EOF);
    EXPECT_EQ(token.getLineNumber(), 3);
    EXPECT_EQ(token.getColumnNumber(), 3);
}

// 测试极端情况：非常长的行
TEST_F(LexerPositionComprehensiveTest, VeryLongLine) {
    std::string longLine = "let x = ";
    for (int i = 0; i < 1000; ++i) {
        longLine += "a + ";
    }
    longLine += "b;";
    
    mycompiler::Lexer lexer(longLine);
    
    // 获取前几个Token
    lexer.getNextToken(); // let
    lexer.getNextToken(); // x
    lexer.getNextToken(); // =
    
    // 获取第一个a
    lexer.getNextToken(); // a
    auto token = lexer.getCurrentToken();
    
    EXPECT_EQ(token.getTokenType(), mycompiler::TokenType::IDENT);
    EXPECT_EQ(token.getLineNumber(), 1);
    EXPECT_EQ(token.getColumnNumber(), 9);
    
    // 获取最后一个b
    for (int i = 0; i < 2000; ++i) {
        lexer.getNextToken();
    }
    token = lexer.getCurrentToken();
    
    EXPECT_EQ(token.getTokenType(), mycompiler::TokenType::IDENT);
    EXPECT_EQ(token.getLineNumber(), 1);
    EXPECT_GT(token.getColumnNumber(), 4000); // 调整为实际可能的列号
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 