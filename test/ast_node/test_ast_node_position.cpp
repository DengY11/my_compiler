#include "ast_node/ast_node.hpp"
#include "ast_node/basic_node.hpp"
#include "ast_node/expr_node/binary_expr_node.hpp"
#include "ast_node/expr_node/literal_expr_node.hpp"
#include "ast_node/expr_node/ident_expr_node.hpp"
#include "ast_node/stat_node/block_stat_node.hpp"
#include "ast_node/stat_node/if_stat_node.hpp"
#include "ast_node/stat_node/return_stat_node.hpp"
#include "ast_node/decl_node/var_decl_node.hpp"
#include "ast_node/decl_node/func_decl_node.hpp"
#include "lexer/lexer.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <string>

// 创建一个测试用的ASTNode派生类，用于测试行号和列号功能
class TestASTNode : public mycompiler::ASTNode {
public:
    TestASTNode(std::shared_ptr<mycompiler::Lexer> lexer) : ASTNode(lexer) {
        // 设置行号和列号为词法分析器当前位置
        setLineNumber(lexer->getCurrentLine());
        setColumnNumber(lexer->getCurrentColumn());
    }
    
    void print_info() override {
        std::cout << "TestASTNode at line " << getLineNumber() 
                  << ", column " << getColumnNumber() << std::endl;
    }
    
    std::string toString() const override {
        return "TestASTNode at line " + std::to_string(getLineNumber()) 
               + ", column " + std::to_string(getColumnNumber());
    }
    
    void Parse() override {
        // 简单实现，不做任何事情
    }
};

// 测试ASTNode的行号和列号功能
class ASTNodePositionTest : public ::testing::Test {
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

// 测试ASTNode的构造函数设置行号和列号
TEST_F(ASTNodePositionTest, Constructor) {
    auto lexer = std::make_shared<mycompiler::Lexer>(singleLineCode);
    
    // 初始位置应该是1,1
    TestASTNode node(lexer);
    EXPECT_EQ(node.getLineNumber(), 1);
    EXPECT_EQ(node.getColumnNumber(), 1);
    
    // 移动词法分析器位置
    lexer->getNextToken(); // 消费"let"
    TestASTNode node2(lexer);
    EXPECT_EQ(node2.getLineNumber(), 1);
    EXPECT_EQ(node2.getColumnNumber(), 4); // "let"后的位置
}

// 测试设置和获取行号和列号
TEST_F(ASTNodePositionTest, SetAndGetPosition) {
    auto lexer = std::make_shared<mycompiler::Lexer>(singleLineCode);
    TestASTNode node(lexer);
    
    // 设置行号和列号
    node.setLineNumber(10);
    node.setColumnNumber(20);
    
    // 验证行号和列号
    EXPECT_EQ(node.getLineNumber(), 10);
    EXPECT_EQ(node.getColumnNumber(), 20);
}

// 测试多行代码中的行号和列号
TEST_F(ASTNodePositionTest, MultiLinePosition) {
    auto lexer = std::make_shared<mycompiler::Lexer>(multiLineCode);
    
    // 第一行
    lexer->getNextToken(); // 消费"let"
    TestASTNode node1(lexer);
    EXPECT_EQ(node1.getLineNumber(), 1);
    EXPECT_EQ(node1.getColumnNumber(), 4);
    
    // 移动到第二行
    for (int i = 0; i < 5; ++i) {
        lexer->getNextToken();
    }
    TestASTNode node2(lexer);
    EXPECT_EQ(node2.getLineNumber(), 2);
    EXPECT_EQ(node2.getColumnNumber(), 1);
    
    // 移动到第三行
    for (int i = 0; i < 5; ++i) {
        lexer->getNextToken();
    }
    TestASTNode node3(lexer);
    EXPECT_EQ(node3.getLineNumber(), 3);
    EXPECT_EQ(node3.getColumnNumber(), 1);
}

// 测试复杂代码中的行号和列号
TEST_F(ASTNodePositionTest, ComplexCodePosition) {
    auto lexer = std::make_shared<mycompiler::Lexer>(complexCode);
    
    // 第一行: function add(a, b) {
    lexer->getNextToken(); // 消费"function"
    TestASTNode node1(lexer);
    EXPECT_EQ(node1.getLineNumber(), 1);
    EXPECT_EQ(node1.getColumnNumber(), 9);
    
    // 移动到第二行: return a + b;
    for (int i = 0; i < 8; ++i) {
        lexer->getNextToken();
    }
    TestASTNode node2(lexer);
    EXPECT_EQ(node2.getLineNumber(), 2);
    EXPECT_EQ(node2.getColumnNumber(), 3);
    
    // 移动到第五行: let result = add(5, 10);
    for (int i = 0; i < 6; ++i) {
        lexer->getNextToken();
    }
    TestASTNode node3(lexer);
    EXPECT_EQ(node3.getLineNumber(), 5);
    EXPECT_EQ(node3.getColumnNumber(), 1);
}

// 测试toString方法包含行号和列号
TEST_F(ASTNodePositionTest, ToStringIncludesPosition) {
    auto lexer = std::make_shared<mycompiler::Lexer>(singleLineCode);
    TestASTNode node(lexer);
    
    // 设置行号和列号
    node.setLineNumber(10);
    node.setColumnNumber(20);
    
    // 验证toString包含行号和列号
    std::string str = node.toString();
    EXPECT_NE(str.find("line 10"), std::string::npos);
    EXPECT_NE(str.find("column 20"), std::string::npos);
}

// 测试实际AST节点类型的行号和列号
TEST_F(ASTNodePositionTest, RealASTNodeTypes) {
    auto lexer = std::make_shared<mycompiler::Lexer>(complexCode);
    
    // 测试LiteralExprNode
    lexer->getNextToken(); // 移动到合适的位置
    auto literalNode = std::make_shared<mycompiler::LiteralExprNode>(lexer);
    literalNode->setLineNumber(1);
    literalNode->setColumnNumber(10);
    EXPECT_EQ(literalNode->getLineNumber(), 1);
    EXPECT_EQ(literalNode->getColumnNumber(), 10);
    
    // 测试IdentExprNode
    auto identNode = std::make_shared<mycompiler::IdentExprNode>(lexer);
    identNode->setLineNumber(2);
    identNode->setColumnNumber(20);
    EXPECT_EQ(identNode->getLineNumber(), 2);
    EXPECT_EQ(identNode->getColumnNumber(), 20);
    
    // 测试VarDeclNode
    auto varDeclNode = std::make_shared<mycompiler::VarDeclNode>(lexer);
    varDeclNode->setLineNumber(3);
    varDeclNode->setColumnNumber(30);
    EXPECT_EQ(varDeclNode->getLineNumber(), 3);
    EXPECT_EQ(varDeclNode->getColumnNumber(), 30);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 