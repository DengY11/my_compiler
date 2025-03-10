#include "token/token.hpp"
#include "token/token_helper_functions.hpp"
#include <gtest/gtest.h>
#include <string>
#include <vector>

// 测试Token的行号和列号功能 - 更全面的测试
class TokenPositionComprehensiveTest : public ::testing::Test {
protected:
    void SetUp() override {
        // 创建各种类型的Token，用于测试
        tokens.push_back(mycompiler::makeConstantToken("123", 1, 1));
        tokens.push_back(mycompiler::makeKeywordToken(mycompiler::KeywordType::LET, 1, 5));
        tokens.push_back(mycompiler::makeIdentifierToken("variable", 1, 9));
        tokens.push_back(mycompiler::makeOperatorToken(mycompiler::OperatorType::PLUS, 1, 18));
        tokens.push_back(mycompiler::makeSeparatorToken(";", 1, 20));
        tokens.push_back(mycompiler::makeEofOrIllegalToken(mycompiler::EofOrIllegalType::EOF_, 1, 21));
    }

    std::vector<mycompiler::Token> tokens;
};

// 测试极限值的行号和列号
TEST_F(TokenPositionComprehensiveTest, ExtremeValues) {
    // 测试非常大的行号和列号
    mycompiler::Token largeToken = mycompiler::makeConstantToken("123", 999999, 999999);
    EXPECT_EQ(largeToken.getLineNumber(), 999999);
    EXPECT_EQ(largeToken.getColumnNumber(), 999999);
    
    // 测试零行号和列号
    mycompiler::Token zeroToken = mycompiler::makeConstantToken("123", 0, 0);
    EXPECT_EQ(zeroToken.getLineNumber(), 0);
    EXPECT_EQ(zeroToken.getColumnNumber(), 0);
}

// 测试不同类型Token的行号和列号一致性
TEST_F(TokenPositionComprehensiveTest, ConsistencyAcrossTypes) {
    // 所有Token都应该正确保存和返回它们的行号和列号
    for (size_t i = 0; i < tokens.size(); ++i) {
        EXPECT_EQ(tokens[i].getLineNumber(), 1);
        EXPECT_GE(tokens[i].getColumnNumber(), 1);
    }
}

// 测试Token的移动构造函数是否正确复制行号和列号
TEST_F(TokenPositionComprehensiveTest, MoveConstructor) {
    mycompiler::Token originalToken = mycompiler::makeConstantToken("123", 10, 20);
    mycompiler::Token movedToken(std::move(originalToken));
    
    EXPECT_EQ(movedToken.getLineNumber(), 10);
    EXPECT_EQ(movedToken.getColumnNumber(), 20);
}

// 测试多行代码中的Token位置
TEST_F(TokenPositionComprehensiveTest, MultiLinePositions) {
    std::vector<mycompiler::Token> multiLineTokens;
    
    // 模拟多行代码中的Token
    multiLineTokens.push_back(mycompiler::makeKeywordToken(mycompiler::KeywordType::LET, 1, 1));
    multiLineTokens.push_back(mycompiler::makeIdentifierToken("x", 1, 5));
    multiLineTokens.push_back(mycompiler::makeOperatorToken(mycompiler::OperatorType::EQUAL, 1, 7));
    multiLineTokens.push_back(mycompiler::makeConstantToken("10", 1, 9));
    multiLineTokens.push_back(mycompiler::makeSeparatorToken(";", 1, 11));
    
    multiLineTokens.push_back(mycompiler::makeKeywordToken(mycompiler::KeywordType::LET, 2, 1));
    multiLineTokens.push_back(mycompiler::makeIdentifierToken("y", 2, 5));
    multiLineTokens.push_back(mycompiler::makeOperatorToken(mycompiler::OperatorType::EQUAL, 2, 7));
    multiLineTokens.push_back(mycompiler::makeConstantToken("20", 2, 9));
    multiLineTokens.push_back(mycompiler::makeSeparatorToken(";", 2, 11));
    
    // 验证每个Token的行号和列号
    for (size_t i = 0; i < 5; ++i) {
        EXPECT_EQ(multiLineTokens[i].getLineNumber(), 1);
    }
    
    for (size_t i = 5; i < 10; ++i) {
        EXPECT_EQ(multiLineTokens[i].getLineNumber(), 2);
    }
}

// 测试复杂表达式中的Token位置
TEST_F(TokenPositionComprehensiveTest, ComplexExpressionPositions) {
    std::vector<mycompiler::Token> exprTokens;
    
    // 模拟复杂表达式中的Token: (a + b) * (c - d) / e
    exprTokens.push_back(mycompiler::makeSeparatorToken("(", 1, 1));
    exprTokens.push_back(mycompiler::makeIdentifierToken("a", 1, 2));
    exprTokens.push_back(mycompiler::makeOperatorToken(mycompiler::OperatorType::PLUS, 1, 4));
    exprTokens.push_back(mycompiler::makeIdentifierToken("b", 1, 6));
    exprTokens.push_back(mycompiler::makeSeparatorToken(")", 1, 7));
    exprTokens.push_back(mycompiler::makeOperatorToken(mycompiler::OperatorType::MUL, 1, 9));
    exprTokens.push_back(mycompiler::makeSeparatorToken("(", 1, 11));
    exprTokens.push_back(mycompiler::makeIdentifierToken("c", 1, 12));
    exprTokens.push_back(mycompiler::makeOperatorToken(mycompiler::OperatorType::SUB, 1, 14));
    exprTokens.push_back(mycompiler::makeIdentifierToken("d", 1, 16));
    exprTokens.push_back(mycompiler::makeSeparatorToken(")", 1, 17));
    exprTokens.push_back(mycompiler::makeOperatorToken(mycompiler::OperatorType::DIV, 1, 19));
    exprTokens.push_back(mycompiler::makeIdentifierToken("e", 1, 21));
    
    // 验证每个Token的行号和列号
    for (size_t i = 0; i < exprTokens.size(); ++i) {
        EXPECT_EQ(exprTokens[i].getLineNumber(), 1);
        EXPECT_GE(exprTokens[i].getColumnNumber(), 1);
    }
    
    // 验证相对位置
    EXPECT_LT(exprTokens[0].getColumnNumber(), exprTokens[1].getColumnNumber());
    EXPECT_LT(exprTokens[1].getColumnNumber(), exprTokens[2].getColumnNumber());
    // ... 以此类推
}

// 测试不同类型的常量Token
TEST_F(TokenPositionComprehensiveTest, DifferentConstantTypes) {
    // 整数常量
    mycompiler::Token intToken = mycompiler::makeConstantToken(123, 1, 1);
    EXPECT_EQ(intToken.getLineNumber(), 1);
    EXPECT_EQ(intToken.getColumnNumber(), 1);
    
    // 浮点数常量
    mycompiler::Token floatToken = mycompiler::makeConstantToken(3.14, 2, 1);
    EXPECT_EQ(floatToken.getLineNumber(), 2);
    EXPECT_EQ(floatToken.getColumnNumber(), 1);
    
    // 字符串常量
    mycompiler::Token stringToken = mycompiler::makeConstantToken("hello", 3, 1);
    EXPECT_EQ(stringToken.getLineNumber(), 3);
    EXPECT_EQ(stringToken.getColumnNumber(), 1);
}

// 测试所有关键字类型的Token
TEST_F(TokenPositionComprehensiveTest, AllKeywordTypes) {
    std::vector<mycompiler::KeywordType> keywordTypes = {
        mycompiler::KeywordType::LET,
        mycompiler::KeywordType::IF,
        mycompiler::KeywordType::ELSE,
        mycompiler::KeywordType::FOR,
        mycompiler::KeywordType::RETURN,
        mycompiler::KeywordType::FUNC,
        mycompiler::KeywordType::WHILE,
        mycompiler::KeywordType::BREAK,
        mycompiler::KeywordType::CONTINUE
    };
    
    for (size_t i = 0; i < keywordTypes.size(); ++i) {
        mycompiler::Token keywordToken = mycompiler::makeKeywordToken(keywordTypes[i], i+1, i+1);
        EXPECT_EQ(keywordToken.getLineNumber(), i+1);
        EXPECT_EQ(keywordToken.getColumnNumber(), i+1);
    }
}

// 测试所有操作符类型的Token
TEST_F(TokenPositionComprehensiveTest, AllOperatorTypes) {
    std::vector<mycompiler::OperatorType> operatorTypes = {
        mycompiler::OperatorType::PLUS,
        mycompiler::OperatorType::SUB,
        mycompiler::OperatorType::MUL,
        mycompiler::OperatorType::DIV,
        mycompiler::OperatorType::EQUAL,
        mycompiler::OperatorType::DOUBLE_EQUAL,
        mycompiler::OperatorType::NOT_EQUAL,
        mycompiler::OperatorType::HAT,
        mycompiler::OperatorType::SELF_ADD,
        mycompiler::OperatorType::SELF_SUB,
        mycompiler::OperatorType::NOT
    };
    
    for (size_t i = 0; i < operatorTypes.size(); ++i) {
        mycompiler::Token operatorToken = mycompiler::makeOperatorToken(operatorTypes[i], i+1, i+1);
        EXPECT_EQ(operatorToken.getLineNumber(), i+1);
        EXPECT_EQ(operatorToken.getColumnNumber(), i+1);
    }
}

// 测试Token的序列化和反序列化是否保留行号和列号
TEST_F(TokenPositionComprehensiveTest, SerializationDeserialization) {
    // 创建一个Token
    mycompiler::Token originalToken = mycompiler::makeConstantToken("123", 10, 20);
    
    // 注释：这个测试是为了未来可能添加的序列化功能
    // 目前Token类没有序列化方法，所以我们只测试基本属性
    
    // 验证行号和列号
    EXPECT_EQ(originalToken.getLineNumber(), 10);
    EXPECT_EQ(originalToken.getColumnNumber(), 20);
    
    // 未来可以添加序列化和反序列化的测试
    // 例如：
    // std::string serialized = originalToken.toString();
    // mycompiler::Token deserializedToken = mycompiler::Token::fromString(serialized);
    // EXPECT_EQ(deserializedToken.getLineNumber(), 10);
    // EXPECT_EQ(deserializedToken.getColumnNumber(), 20);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 