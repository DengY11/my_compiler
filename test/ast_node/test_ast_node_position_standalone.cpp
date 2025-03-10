#include "lexer/lexer.hpp"
#include "token/token.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <string>
#include <iostream>

// 创建一个简单的AST节点类，用于测试行号和列号功能
class SimpleASTNode {
public:
    SimpleASTNode(std::shared_ptr<mycompiler::Lexer> lexer) : lexer_(lexer) {
        // 设置行号和列号为词法分析器当前位置
        lineNumber_ = lexer->getCurrentLine();
        columnNumber_ = lexer->getCurrentColumn();
    }
    
    void printInfo() const {
        std::cout << "SimpleASTNode at line " << lineNumber_ 
                  << ", column " << columnNumber_ << std::endl;
    }
    
    std::string toString() const {
        return "SimpleASTNode at line " + std::to_string(lineNumber_) 
               + ", column " + std::to_string(columnNumber_);
    }
    
    int getLineNumber() const { return lineNumber_; }
    void setLineNumber(int lineNumber) { lineNumber_ = lineNumber; }
    
    int getColumnNumber() const { return columnNumber_; }
    void setColumnNumber(int columnNumber) { columnNumber_ = columnNumber; }
    
    std::shared_ptr<mycompiler::Lexer> getLexer() const { return lexer_; }

private:
    std::shared_ptr<mycompiler::Lexer> lexer_;
    int lineNumber_;
    int columnNumber_;
};

// 测试AST节点的行号和列号功能
class ASTNodePositionStandaloneTest : public ::testing::Test {
protected:
    void SetUp() override {
        // 创建测试用的代码片段
        singleLineCode = "let x = 5;";
        multiLineCode = "let x = 5;\nlet y = 10;\nlet z = x + y;";
        complexCode = "function add(a, b) {\n  return a + b;\n}\n\nlet result = add(5, 10);";
    }

    std::string singleLineCode;
    std::string multiLineCode;
    std::string complexCode;
};

// 测试AST节点的构造函数设置行号和列号
TEST_F(ASTNodePositionStandaloneTest, Constructor) {
    auto lexer = std::make_shared<mycompiler::Lexer>(singleLineCode);
    
    // 初始位置应该是1,1
    SimpleASTNode node(lexer);
    EXPECT_EQ(node.getLineNumber(), 1);
    EXPECT_EQ(node.getColumnNumber(), 1);
    
    // 移动词法分析器位置
    lexer->getNextToken(); // 消费"let"
    SimpleASTNode node2(lexer);
    EXPECT_EQ(node2.getLineNumber(), 1);
    EXPECT_EQ(node2.getColumnNumber(), 4); // "let"后的位置
}

// 测试设置和获取行号和列号
TEST_F(ASTNodePositionStandaloneTest, SetAndGetPosition) {
    auto lexer = std::make_shared<mycompiler::Lexer>(singleLineCode);
    SimpleASTNode node(lexer);
    
    // 设置行号和列号
    node.setLineNumber(10);
    node.setColumnNumber(20);
    
    // 验证行号和列号
    EXPECT_EQ(node.getLineNumber(), 10);
    EXPECT_EQ(node.getColumnNumber(), 20);
}

// 测试多行代码中的行号和列号
TEST_F(ASTNodePositionStandaloneTest, MultiLinePosition) {
    auto lexer = std::make_shared<mycompiler::Lexer>(multiLineCode);
    
    // 第一行
    lexer->getNextToken(); // 消费"let"
    SimpleASTNode node1(lexer);
    EXPECT_EQ(node1.getLineNumber(), 1);
    EXPECT_EQ(node1.getColumnNumber(), 4);
    
    // 移动到第二行
    for (int i = 0; i < 5; ++i) {
        lexer->getNextToken();
    }
    SimpleASTNode node2(lexer);
    EXPECT_EQ(node2.getLineNumber(), 2);
    EXPECT_EQ(node2.getColumnNumber(), 4);
    
    // 移动到第三行
    for (int i = 0; i < 5; ++i) {
        lexer->getNextToken();
    }
    SimpleASTNode node3(lexer);
    EXPECT_EQ(node3.getLineNumber(), 3);
    EXPECT_EQ(node3.getColumnNumber(), 4);
}

// 测试复杂代码中的行号和列号
TEST_F(ASTNodePositionStandaloneTest, ComplexCodePosition) {
    auto lexer = std::make_shared<mycompiler::Lexer>(complexCode);
    
    // 第一行: function add(a, b) {
    lexer->getNextToken(); // 消费"function"
    SimpleASTNode node1(lexer);
    EXPECT_EQ(node1.getLineNumber(), 1);
    EXPECT_EQ(node1.getColumnNumber(), 9);
    
    // 移动到第二行: return a + b;
    for (int i = 0; i < 8; ++i) {
        lexer->getNextToken();
    }
    SimpleASTNode node2(lexer);
    EXPECT_EQ(node2.getLineNumber(), 2);
    EXPECT_EQ(node2.getColumnNumber(), 9);
    
    // 移动到第五行: let result = add(5, 10);
    for (int i = 0; i < 6; ++i) {
        lexer->getNextToken();
    }
    SimpleASTNode node3(lexer);
    EXPECT_EQ(node3.getLineNumber(), 5);
    EXPECT_EQ(node3.getColumnNumber(), 4);
}

// 测试toString方法包含行号和列号
TEST_F(ASTNodePositionStandaloneTest, ToStringIncludesPosition) {
    auto lexer = std::make_shared<mycompiler::Lexer>(singleLineCode);
    SimpleASTNode node(lexer);
    
    // 设置行号和列号
    node.setLineNumber(10);
    node.setColumnNumber(20);
    
    // 验证toString包含行号和列号
    std::string str = node.toString();
    EXPECT_NE(str.find("line 10"), std::string::npos);
    EXPECT_NE(str.find("column 20"), std::string::npos);
}

// 测试错误位置报告
TEST_F(ASTNodePositionStandaloneTest, ErrorReporting) {
    auto lexer = std::make_shared<mycompiler::Lexer>(complexCode);
    
    // 移动到某个位置
    lexer->getNextToken(); // 消费"function"
    lexer->getNextToken(); // 消费"add"
    SimpleASTNode node(lexer);
    
    // 模拟错误消息
    std::string errorMessage = "Error at line " + std::to_string(node.getLineNumber()) + 
                              ", column " + std::to_string(node.getColumnNumber()) + 
                              ": Unexpected token";
    
    // 验证错误消息中包含正确的位置信息
    EXPECT_NE(errorMessage.find("line 1"), std::string::npos);
    EXPECT_NE(errorMessage.find("column 13"), std::string::npos);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 