#include "ast_node/expr_node/literal_expr_node.hpp"
#include "ast_node/terminal_symbols/terminal_value_literal.hpp"
#include "ast_node/terminal_symbols/terminal_ident_literal.hpp"
#include "ast_node/terminal_symbols/terminal_operator.hpp"
#include "lexer/lexer.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <string>

// 测试LiteralExprNode的构造函数
TEST(LiteralExprNodeTest, Constructor) {
    std::string code = "42";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    mycompiler::LiteralExprNode node(lexer);
    
    EXPECT_EQ(node.getNodeType(), mycompiler::AST_NODE_TYPE::LITERAL_EXPR);
    EXPECT_EQ(node.getLexer(), lexer);
    EXPECT_EQ(node.getChildren().size(), 0);
}

// 测试LiteralExprNode的Parse方法 - 整数字面量
TEST(LiteralExprNodeTest, ParseIntegerLiteral) {
    std::string code = "42";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    lexer->getNextToken(); // 获取第一个token
    
    mycompiler::LiteralExprNode node(lexer);
    node.Parse();
    
    EXPECT_GT(node.getChildren().size(), 0);
    // 验证解析结果，这里需要根据实际实现进行调整
}

// 测试LiteralExprNode的Parse方法 - 浮点数字面量
TEST(LiteralExprNodeTest, ParseFloatLiteral) {
    std::string code = "3.14";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    lexer->getNextToken(); // 获取第一个token
    
    mycompiler::LiteralExprNode node(lexer);
    node.Parse();
    
    EXPECT_GT(node.getChildren().size(), 0);
    // 验证解析结果，这里需要根据实际实现进行调整
}

// 测试LiteralExprNode的Parse方法 - 字符串字面量
TEST(LiteralExprNodeTest, ParseStringLiteral) {
    std::string code = "\"hello\"";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    lexer->getNextToken(); // 获取第一个token
    
    mycompiler::LiteralExprNode node(lexer);
    node.Parse();
    
    EXPECT_GT(node.getChildren().size(), 0);
    // 验证解析结果，这里需要根据实际实现进行调整
}

// 测试LiteralExprNode的第二个构造函数
TEST(LiteralExprNodeTest, ConstructorWithTerminals) {
    auto var_name = std::make_shared<mycompiler::TerminalIdentLiteral>(nullptr);
    auto op = std::make_shared<mycompiler::TerminalOperator>(nullptr);
    auto value = std::make_shared<mycompiler::TerminalValueLiteral>(nullptr);
    
    mycompiler::LiteralExprNode node(var_name, op, value);
    
    EXPECT_EQ(node.getNodeType(), mycompiler::AST_NODE_TYPE::LITERAL_EXPR);
    EXPECT_EQ(node.getChildren().size(), 3);
    EXPECT_EQ(node.getChildren()[0], var_name);
    EXPECT_EQ(node.getChildren()[1], op);
    EXPECT_EQ(node.getChildren()[2], value);
}

// 测试LiteralExprNode的add_terminalvalue_node方法
TEST(LiteralExprNodeTest, AddTerminalValueNode) {
    std::string code = "42";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    mycompiler::LiteralExprNode node(lexer);
    
    auto value = std::make_shared<mycompiler::TerminalValueLiteral>(lexer);
    node.add_terminalvalue_node(value);
    
    EXPECT_EQ(node.getChildren().size(), 1);
    EXPECT_EQ(node.getChildren()[0], value);
}

// 测试LiteralExprNode的isConstant方法
TEST(LiteralExprNodeTest, IsConstant) {
    std::string code = "42";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    mycompiler::LiteralExprNode node(lexer);
    
    // 字面量表达式应该始终是常量
    EXPECT_TRUE(node.isConstant());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 