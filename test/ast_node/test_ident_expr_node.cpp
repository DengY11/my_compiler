#include "ast_node/expr_node/ident_expr_node.hpp"
#include "lexer/lexer.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <string>

// 测试IdentifierExprNode的构造函数
TEST(IdentifierExprNodeTest, Constructor) {
    std::string code = "variable";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    mycompiler::IdentifierExprNode node(lexer);
    
    EXPECT_EQ(node.getNodeType(), mycompiler::AST_NODE_TYPE::IDENTIFIER_EXPR);
    EXPECT_EQ(node.getLexer(), lexer);
    EXPECT_EQ(node.getChildren().size(), 0);
    EXPECT_EQ(node.getName(), "");
}

// 测试IdentifierExprNode的Parse方法
TEST(IdentifierExprNodeTest, Parse) {
    std::string code = "variable";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    lexer->getNextToken(); // 获取第一个token
    
    mycompiler::IdentifierExprNode node(lexer);
    node.Parse();
    
    EXPECT_EQ(node.getName(), "variable");
    EXPECT_GT(node.getChildren().size(), 0);
}

// 测试IdentifierExprNode的Parse方法 - 多个标识符
TEST(IdentifierExprNodeTest, ParseMultipleIdentifiers) {
    std::string code = "var1 var2";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    lexer->getNextToken(); // 获取第一个token
    
    mycompiler::IdentifierExprNode node1(lexer);
    node1.Parse();
    
    EXPECT_EQ(node1.getName(), "var1");
    
    mycompiler::IdentifierExprNode node2(lexer);
    node2.Parse();
    
    EXPECT_EQ(node2.getName(), "var2");
}

// 测试IdentifierExprNode的toString方法
TEST(IdentifierExprNodeTest, ToString) {
    std::string code = "variable";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    lexer->getNextToken(); // 获取第一个token
    
    mycompiler::IdentifierExprNode node(lexer);
    node.Parse();
    
    EXPECT_EQ(node.toString(), "variable");
}

// 测试IdentifierExprNode的getName和setName方法
TEST(IdentifierExprNodeTest, GetSetName) {
    std::string code = "variable";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    mycompiler::IdentifierExprNode node(lexer);
    
    node.setName("newVariable");
    EXPECT_EQ(node.getName(), "newVariable");
}

// 测试IdentifierExprNode的isConstant方法
TEST(IdentifierExprNodeTest, IsConstant) {
    std::string code = "variable";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    mycompiler::IdentifierExprNode node(lexer);
    
    // 标识符不是常量
    EXPECT_FALSE(node.isConstant());
}

// 测试IdentifierExprNode的isLValue方法
TEST(IdentifierExprNodeTest, IsLValue) {
    std::string code = "variable";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    mycompiler::IdentifierExprNode node(lexer);
    
    // 标识符是左值
    EXPECT_TRUE(node.isLValue());
}

// 测试IdentifierExprNode的getExpressionType方法
TEST(IdentifierExprNodeTest, GetExpressionType) {
    std::string code = "variable";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    mycompiler::IdentifierExprNode node(lexer);
    
    // 在简化实现中，表达式类型为"unknown"
    EXPECT_EQ(node.getExpressionType(), "unknown");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 