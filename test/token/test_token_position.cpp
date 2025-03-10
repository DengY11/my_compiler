#include "token/token.hpp"
#include "token/token_helper_functions.hpp"
#include <gtest/gtest.h>
#include <string>

// 测试Token的行号和列号功能
TEST(TokenPositionTest, ConstructorWithPosition) {
    // 测试常量Token
    mycompiler::Token constToken = mycompiler::makeConstantToken("123", 10, 20);
    EXPECT_EQ(constToken.getLineNumber(), 10);
    EXPECT_EQ(constToken.getColumnNumber(), 20);
    
    // 测试关键字Token
    mycompiler::Token keywordToken = mycompiler::makeKeywordToken(mycompiler::KeywordType::LET, 15, 25);
    EXPECT_EQ(keywordToken.getLineNumber(), 15);
    EXPECT_EQ(keywordToken.getColumnNumber(), 25);
    
    // 测试标识符Token
    mycompiler::Token identToken = mycompiler::makeIdentifierToken("variable", 30, 40);
    EXPECT_EQ(identToken.getLineNumber(), 30);
    EXPECT_EQ(identToken.getColumnNumber(), 40);
    
    // 测试操作符Token
    mycompiler::Token operatorToken = mycompiler::makeOperatorToken(mycompiler::OperatorType::PLUS, 45, 55);
    EXPECT_EQ(operatorToken.getLineNumber(), 45);
    EXPECT_EQ(operatorToken.getColumnNumber(), 55);
    
    // 测试分隔符Token
    mycompiler::Token separatorToken = mycompiler::makeSeparatorToken(";", 60, 70);
    EXPECT_EQ(separatorToken.getLineNumber(), 60);
    EXPECT_EQ(separatorToken.getColumnNumber(), 70);
    
    // 测试EOF或非法Token
    mycompiler::Token eofToken = mycompiler::makeEofOrIllegalToken(mycompiler::EofOrIllegalType::EOF_, 75, 85);
    EXPECT_EQ(eofToken.getLineNumber(), 75);
    EXPECT_EQ(eofToken.getColumnNumber(), 85);
    
    // 测试注释Token
    mycompiler::Token commentToken = mycompiler::makeCommentToken("// comment", 90, 100);
    EXPECT_EQ(commentToken.getLineNumber(), 90);
    EXPECT_EQ(commentToken.getColumnNumber(), 100);
    
    // 测试预处理器Token
    mycompiler::Token preprocessorToken = mycompiler::makePreprocessorToken("#include", 105, 115);
    EXPECT_EQ(preprocessorToken.getLineNumber(), 105);
    EXPECT_EQ(preprocessorToken.getColumnNumber(), 115);
}

// 测试Token的拷贝构造函数是否正确复制行号和列号
TEST(TokenPositionTest, CopyConstructor) {
    mycompiler::Token originalToken = mycompiler::makeConstantToken("123", 10, 20);
    mycompiler::Token copiedToken = originalToken;
    
    EXPECT_EQ(copiedToken.getLineNumber(), 10);
    EXPECT_EQ(copiedToken.getColumnNumber(), 20);
}

// 测试Token的赋值操作符是否正确复制行号和列号
TEST(TokenPositionTest, AssignmentOperator) {
    mycompiler::Token originalToken = mycompiler::makeConstantToken("123", 10, 20);
    mycompiler::Token assignedToken = mycompiler::makeConstantToken("456", 30, 40);
    
    assignedToken = originalToken;
    
    EXPECT_EQ(assignedToken.getLineNumber(), 10);
    EXPECT_EQ(assignedToken.getColumnNumber(), 20);
}

// 测试不同类型的Token的行号和列号
TEST(TokenPositionTest, DifferentTokenTypes) {
    // 整数常量
    mycompiler::Token intToken = mycompiler::makeConstantToken(123, 10, 20);
    EXPECT_EQ(intToken.getLineNumber(), 10);
    EXPECT_EQ(intToken.getColumnNumber(), 20);
    
    // 浮点数常量
    mycompiler::Token floatToken = mycompiler::makeConstantToken(3.14, 15, 25);
    EXPECT_EQ(floatToken.getLineNumber(), 15);
    EXPECT_EQ(floatToken.getColumnNumber(), 25);
    
    // 字符串常量
    mycompiler::Token stringToken = mycompiler::makeConstantToken("hello", 20, 30);
    EXPECT_EQ(stringToken.getLineNumber(), 20);
    EXPECT_EQ(stringToken.getColumnNumber(), 30);
}

// 测试默认行号和列号
TEST(TokenPositionTest, DefaultPosition) {
    // 使用默认行号和列号
    mycompiler::Token token = mycompiler::makeConstantToken("123");
    
    EXPECT_EQ(token.getLineNumber(), 0);
    EXPECT_EQ(token.getColumnNumber(), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 