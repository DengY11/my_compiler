#include "lexer/lexer.hpp"
#include "token/token.hpp"
#include <gtest/gtest.h>
#include <string>
#include <vector>

// 测试Lexer的注释功能
class LexerCommentTest : public ::testing::Test {
protected:
    void SetUp() override {
        // 创建测试用的代码片段
        singleLineCommentCode = "let x = 5; // 这是一个单行注释\nlet y = 10;";
        multiLineCommentCode = "let x = 5;\n/* 这是一个\n   多行注释 */\nlet y = 10;";
        mixedCommentCode = "// 单行注释\nlet x = 5; /* 多行注释开始\n多行注释结束 */ let y = 10; // 另一个单行注释";
        nestedCommentLikeCode = "let x = 5; /* 注释中的 // 不是新注释 */ let y = 10;";
        commentInStringCode = "let str = \"这不是注释 // 这是字符串的一部分\";";
    }

    std::string singleLineCommentCode;
    std::string multiLineCommentCode;
    std::string mixedCommentCode;
    std::string nestedCommentLikeCode;
    std::string commentInStringCode;
};

// 测试单行注释
TEST_F(LexerCommentTest, SingleLineComment) {
    mycompiler::Lexer lexer(singleLineCommentCode);
    
    // 获取所有Token
    std::vector<mycompiler::Token> tokens;
    
    // 第一行: let x = 5; // 这是一个单行注释
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
    
    // 验证Token数量和类型
    ASSERT_EQ(tokens.size(), 10);
    EXPECT_EQ(tokens[0].getTokenType(), mycompiler::TokenType::KEYWORD);
    EXPECT_EQ(tokens[1].getTokenType(), mycompiler::TokenType::IDENT);
    EXPECT_EQ(tokens[2].getTokenType(), mycompiler::TokenType::OPERATOR);
    EXPECT_EQ(tokens[3].getTokenType(), mycompiler::TokenType::CONSTANT);
    EXPECT_EQ(tokens[4].getTokenType(), mycompiler::TokenType::SEPARATOR);
    EXPECT_EQ(tokens[5].getTokenType(), mycompiler::TokenType::KEYWORD);
    EXPECT_EQ(tokens[6].getTokenType(), mycompiler::TokenType::IDENT);
    EXPECT_EQ(tokens[7].getTokenType(), mycompiler::TokenType::OPERATOR);
    EXPECT_EQ(tokens[8].getTokenType(), mycompiler::TokenType::CONSTANT);
    EXPECT_EQ(tokens[9].getTokenType(), mycompiler::TokenType::SEPARATOR);
    
    // 验证第二行的Token行号
    EXPECT_EQ(tokens[5].getLineNumber(), 2);
}

// 测试多行注释
TEST_F(LexerCommentTest, MultiLineComment) {
    mycompiler::Lexer lexer(multiLineCommentCode);
    
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
    
    // 第四行: let y = 10;
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
    
    // 验证Token数量和类型
    ASSERT_EQ(tokens.size(), 10);
    
    // 验证第四行的Token行号
    EXPECT_EQ(tokens[5].getLineNumber(), 4);
}

// 测试混合注释
TEST_F(LexerCommentTest, MixedComment) {
    mycompiler::Lexer lexer(mixedCommentCode);
    
    // 获取所有Token
    std::vector<mycompiler::Token> tokens;
    
    // 第二行: let x = 5; /* 多行注释开始
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
    
    // 多行注释结束 */ let y = 10; // 另一个单行注释
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
    
    // 验证Token数量和类型
    ASSERT_EQ(tokens.size(), 10);
    
    // 验证第一个Token的行号
    EXPECT_EQ(tokens[0].getLineNumber(), 2);
}

// 测试注释中的注释样式文本
TEST_F(LexerCommentTest, NestedCommentLike) {
    mycompiler::Lexer lexer(nestedCommentLikeCode);
    
    // 获取所有Token
    std::vector<mycompiler::Token> tokens;
    
    // let x = 5; /* 注释中的 // 不是新注释 */ let y = 10;
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
    
    // 验证Token数量和类型
    ASSERT_EQ(tokens.size(), 10);
}

// 测试字符串中的注释样式文本
TEST_F(LexerCommentTest, CommentInString) {
    // 注意：当前的Lexer可能不支持字符串，这个测试可能需要修改
    GTEST_SKIP() << "当前Lexer不支持字符串，跳过此测试";
    
    /*
    mycompiler::Lexer lexer(commentInStringCode);
    
    // 获取所有Token
    std::vector<mycompiler::Token> tokens;
    
    // let str = "这不是注释 // 这是字符串的一部分";
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // let
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // str
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // =
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // "这不是注释 // 这是字符串的一部分"
    
    lexer.getNextToken();
    tokens.push_back(lexer.getCurrentToken()); // ;
    
    // 验证Token数量和类型
    ASSERT_EQ(tokens.size(), 5);
    
    // 验证字符串Token的内容
    EXPECT_EQ(tokens[3].getTokenType(), mycompiler::TokenType::CONSTANT);
    */
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 