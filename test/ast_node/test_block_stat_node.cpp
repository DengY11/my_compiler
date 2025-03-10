#include "ast_node/stat_node/block_stat_node.hpp"
#include "ast_node/stat_node/return_stat_node.hpp"
#include "ast_node/stat_node/expr_stat_node.hpp"
#include "lexer/lexer.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <string>

// 测试BlockStatNode的构造函数
TEST(BlockStatNodeTest, Constructor) {
    std::string code = "{ return 0; }";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    mycompiler::BlockStatNode node(lexer);
    
    EXPECT_EQ(node.getNodeType(), mycompiler::AST_NODE_TYPE::BLOCK_STAT);
    EXPECT_EQ(node.getLexer(), lexer);
    EXPECT_EQ(node.getChildren().size(), 0);
    EXPECT_EQ(node.getStatements().size(), 0);
}

// 测试BlockStatNode的Parse方法 - 空块
TEST(BlockStatNodeTest, ParseEmptyBlock) {
    std::string code = "{ }";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    lexer->getNextToken(); // 获取第一个token
    
    mycompiler::BlockStatNode node(lexer);
    node.Parse();
    
    EXPECT_GT(node.getChildren().size(), 0); // 至少有左右花括号
    EXPECT_EQ(node.getStatements().size(), 0);
    EXPECT_FALSE(node.isTerminating());
}

// 测试BlockStatNode的Parse方法 - 包含一个语句的块
TEST(BlockStatNodeTest, ParseSingleStatementBlock) {
    std::string code = "{ return 0; }";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    lexer->getNextToken(); // 获取第一个token
    
    mycompiler::BlockStatNode node(lexer);
    node.Parse();
    
    EXPECT_GT(node.getChildren().size(), 0);
    EXPECT_EQ(node.getStatements().size(), 1);
    // return语句是终止语句，所以块也是终止语句
    EXPECT_TRUE(node.isTerminating());
}

// 测试BlockStatNode的Parse方法 - 包含多个语句的块
TEST(BlockStatNodeTest, ParseMultipleStatementsBlock) {
    std::string code = "{ int x = 5; return x; }";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    lexer->getNextToken(); // 获取第一个token
    
    mycompiler::BlockStatNode node(lexer);
    node.Parse();
    
    EXPECT_GT(node.getChildren().size(), 0);
    EXPECT_EQ(node.getStatements().size(), 2);
    // 最后一个语句是return，所以块是终止语句
    EXPECT_TRUE(node.isTerminating());
}

// 测试BlockStatNode的Parse方法 - 包含非终止语句的块
TEST(BlockStatNodeTest, ParseNonTerminatingBlock) {
    std::string code = "{ int x = 5; x = 10; }";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    lexer->getNextToken(); // 获取第一个token
    
    mycompiler::BlockStatNode node(lexer);
    node.Parse();
    
    EXPECT_GT(node.getChildren().size(), 0);
    EXPECT_EQ(node.getStatements().size(), 2);
    // 最后一个语句不是终止语句，所以块不是终止语句
    EXPECT_FALSE(node.isTerminating());
}

// 测试BlockStatNode的addStatement方法
TEST(BlockStatNodeTest, AddStatement) {
    std::string code = "{ }";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    mycompiler::BlockStatNode node(lexer);
    
    auto returnStat = std::make_shared<mycompiler::ReturnStatNode>(lexer);
    node.addStatement(returnStat);
    
    EXPECT_EQ(node.getStatements().size(), 1);
    EXPECT_EQ(node.getStatements()[0], returnStat);
    
    auto exprStat = std::make_shared<mycompiler::ExprStatNode>(lexer);
    node.addStatement(exprStat);
    
    EXPECT_EQ(node.getStatements().size(), 2);
    EXPECT_EQ(node.getStatements()[1], exprStat);
}

// 测试BlockStatNode的toString方法
TEST(BlockStatNodeTest, ToString) {
    std::string code = "{ return 0; }";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    lexer->getNextToken(); // 获取第一个token
    
    mycompiler::BlockStatNode node(lexer);
    node.Parse();
    
    std::string str = node.toString();
    EXPECT_NE(str.find("Block"), std::string::npos);
    EXPECT_NE(str.find("1"), std::string::npos); // 1个语句
}

// 测试BlockStatNode的isTerminating方法 - 空块
TEST(BlockStatNodeTest, IsTerminatingEmptyBlock) {
    std::string code = "{ }";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    mycompiler::BlockStatNode node(lexer);
    
    EXPECT_FALSE(node.isTerminating());
}

// 测试BlockStatNode的isTerminating方法 - 终止块
TEST(BlockStatNodeTest, IsTerminatingTerminatingBlock) {
    std::string code = "{ }";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    mycompiler::BlockStatNode node(lexer);
    
    // 添加一个终止语句（ReturnStatNode）
    auto returnStat = std::make_shared<mycompiler::ReturnStatNode>(lexer);
    node.addStatement(returnStat);
    
    EXPECT_TRUE(node.isTerminating());
}

// 测试BlockStatNode的isTerminating方法 - 非终止块
TEST(BlockStatNodeTest, IsTerminatingNonTerminatingBlock) {
    std::string code = "{ }";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    mycompiler::BlockStatNode node(lexer);
    
    // 添加一个非终止语句（ExprStatNode）
    auto exprStat = std::make_shared<mycompiler::ExprStatNode>(lexer);
    node.addStatement(exprStat);
    
    EXPECT_FALSE(node.isTerminating());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 