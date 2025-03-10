#include "ast_node/stat_node/return_stat_node.hpp"
#include "ast_node/expr_node/literal_expr_node.hpp"
#include "lexer/lexer.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <string>

// 测试ReturnStatNode的构造函数
TEST(ReturnStatNodeTest, Constructor) {
    std::string code = "return 0;";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    mycompiler::ReturnStatNode node(lexer);
    
    EXPECT_EQ(node.getNodeType(), mycompiler::AST_NODE_TYPE::RETURN_STAT);
    EXPECT_EQ(node.getLexer(), lexer);
    EXPECT_EQ(node.getChildren().size(), 0);
    EXPECT_EQ(node.getReturnValue(), nullptr);
    EXPECT_FALSE(node.hasReturnValue());
}

// 测试ReturnStatNode的Parse方法 - 无返回值
TEST(ReturnStatNodeTest, ParseNoReturnValue) {
    std::string code = "return;";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    lexer->getNextToken(); // 获取第一个token
    
    mycompiler::ReturnStatNode node(lexer);
    node.Parse();
    
    EXPECT_GT(node.getChildren().size(), 0);
    EXPECT_EQ(node.getReturnValue(), nullptr);
    EXPECT_FALSE(node.hasReturnValue());
}

// 测试ReturnStatNode的Parse方法 - 整数返回值
TEST(ReturnStatNodeTest, ParseIntegerReturnValue) {
    std::string code = "return 42;";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    lexer->getNextToken(); // 获取第一个token
    
    mycompiler::ReturnStatNode node(lexer);
    node.Parse();
    
    EXPECT_GT(node.getChildren().size(), 0);
    EXPECT_NE(node.getReturnValue(), nullptr);
    EXPECT_TRUE(node.hasReturnValue());
}

// 测试ReturnStatNode的Parse方法 - 表达式返回值
TEST(ReturnStatNodeTest, ParseExpressionReturnValue) {
    std::string code = "return x + 5;";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    lexer->getNextToken(); // 获取第一个token
    
    mycompiler::ReturnStatNode node(lexer);
    node.Parse();
    
    EXPECT_GT(node.getChildren().size(), 0);
    EXPECT_NE(node.getReturnValue(), nullptr);
    EXPECT_TRUE(node.hasReturnValue());
}

// 测试ReturnStatNode的toString方法 - 无返回值
TEST(ReturnStatNodeTest, ToStringNoReturnValue) {
    std::string code = "return;";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    lexer->getNextToken(); // 获取第一个token
    
    mycompiler::ReturnStatNode node(lexer);
    node.Parse();
    
    std::string str = node.toString();
    EXPECT_EQ(str, "Return");
}

// 测试ReturnStatNode的toString方法 - 有返回值
TEST(ReturnStatNodeTest, ToStringWithReturnValue) {
    std::string code = "return 42;";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    lexer->getNextToken(); // 获取第一个token
    
    mycompiler::ReturnStatNode node(lexer);
    node.Parse();
    
    std::string str = node.toString();
    EXPECT_NE(str.find("Return"), std::string::npos);
    // 具体的返回值字符串取决于LiteralExprNode的toString实现
}

// 测试ReturnStatNode的setReturnValue方法
TEST(ReturnStatNodeTest, SetReturnValue) {
    std::string code = "return;";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    mycompiler::ReturnStatNode node(lexer);
    
    EXPECT_FALSE(node.hasReturnValue());
    
    auto returnValue = std::make_shared<mycompiler::LiteralExprNode>(lexer);
    node.setReturnValue(returnValue);
    
    EXPECT_TRUE(node.hasReturnValue());
    EXPECT_EQ(node.getReturnValue(), returnValue);
}

// 测试ReturnStatNode的isTerminating方法
TEST(ReturnStatNodeTest, IsTerminating) {
    std::string code = "return;";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    mycompiler::ReturnStatNode node(lexer);
    
    // return语句总是终止语句
    EXPECT_TRUE(node.isTerminating());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 