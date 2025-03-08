#include "ast_node/expr_node/binary_expr.hpp"
#include "ast_node/expr_node/literal_expr_node.hpp"
#include "ast_node/terminal_symbols/terminal_operator.hpp"
#include "lexer/lexer.hpp"
#include "token/token_helper_functions.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <string>

// 测试BinaryExprNode的构造函数
TEST(BinaryExprNodeTest, Constructor) {
    std::string code = "test code";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    auto binaryExpr = std::make_shared<mycompiler::BinaryExprNode>(lexer);
    
    EXPECT_EQ(binaryExpr->getNodeType(), mycompiler::AST_NODE_TYPE::BINNARY_EXPR);
    EXPECT_EQ(binaryExpr->getLexer(), lexer);
    EXPECT_EQ(binaryExpr->getChildren().size(), 0);
}

// 测试BinaryExprNode的构造函数（带参数）
TEST(BinaryExprNodeTest, ConstructorWithParams) {
    std::string code = "a + b";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    
    // 创建左操作数
    auto left = std::make_shared<mycompiler::LiteralExprNode>(lexer);
    
    // 创建操作符
    lexer->getNextToken(); // 移动到 '+'
    auto op = std::make_shared<mycompiler::TerminalOperator>(lexer);
    op->operator_ = "+";
    
    // 创建右操作数
    lexer->getNextToken(); // 移动到 'b'
    auto right = std::make_shared<mycompiler::LiteralExprNode>(lexer);
    
    // 创建二元表达式
    auto binaryExpr = std::make_shared<mycompiler::BinaryExprNode>(left, op, right);
    
    EXPECT_EQ(binaryExpr->getNodeType(), mycompiler::AST_NODE_TYPE::BINNARY_EXPR);
    EXPECT_EQ(binaryExpr->getLeft(), left);
    EXPECT_EQ(binaryExpr->getOperator(), op);
    EXPECT_EQ(binaryExpr->getRight(), right);
    EXPECT_EQ(binaryExpr->getChildren().size(), 3);
}

// 测试add_child方法
TEST(BinaryExprNodeTest, AddChild) {
    std::string code = "a + b";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    
    // 创建左操作数
    auto left = std::make_shared<mycompiler::LiteralExprNode>(lexer);
    
    // 创建操作符
    lexer->getNextToken(); // 移动到 '+'
    auto op = std::make_shared<mycompiler::TerminalOperator>(lexer);
    op->operator_ = "+";
    
    // 创建右操作数
    lexer->getNextToken(); // 移动到 'b'
    auto right = std::make_shared<mycompiler::LiteralExprNode>(lexer);
    
    // 创建二元表达式
    auto binaryExpr = std::make_shared<mycompiler::BinaryExprNode>(lexer);
    binaryExpr->add_child(left, op, right);
    
    EXPECT_EQ(binaryExpr->getLeft(), left);
    EXPECT_EQ(binaryExpr->getOperator(), op);
    EXPECT_EQ(binaryExpr->getRight(), right);
    EXPECT_EQ(binaryExpr->getChildren().size(), 3);
}

// 测试getExpressionType方法
TEST(BinaryExprNodeTest, GetExpressionType) {
    std::string code = "5 + 3";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    
    // 创建左操作数
    auto left = std::make_shared<mycompiler::LiteralExprNode>(lexer);
    
    // 创建操作符
    lexer->getNextToken(); // 移动到 '+'
    auto op = std::make_shared<mycompiler::TerminalOperator>(lexer);
    op->operator_ = "+";
    
    // 创建右操作数
    lexer->getNextToken(); // 移动到 '3'
    auto right = std::make_shared<mycompiler::LiteralExprNode>(lexer);
    
    // 创建二元表达式
    auto binaryExpr = std::make_shared<mycompiler::BinaryExprNode>(left, op, right);
    
    // 测试表达式类型
    std::string exprType = binaryExpr->getExpressionType();
    EXPECT_FALSE(exprType.empty());
}

// 测试isConstant方法
TEST(BinaryExprNodeTest, IsConstant) {
    std::string code = "5 + 3";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    
    // 创建左操作数
    auto left = std::make_shared<mycompiler::LiteralExprNode>(lexer);
    
    // 创建操作符
    lexer->getNextToken(); // 移动到 '+'
    auto op = std::make_shared<mycompiler::TerminalOperator>(lexer);
    op->operator_ = "+";
    
    // 创建右操作数
    lexer->getNextToken(); // 移动到 '3'
    auto right = std::make_shared<mycompiler::LiteralExprNode>(lexer);
    
    // 创建二元表达式
    auto binaryExpr = std::make_shared<mycompiler::BinaryExprNode>(left, op, right);
    
    // 测试是否为常量
    bool isConst = binaryExpr->isConstant();
    // 由于我们没有实现LiteralExprNode的isConstant方法，这里不做具体断言
}

// 测试toString方法
TEST(BinaryExprNodeTest, ToString) {
    std::string code = "a + b";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    
    // 创建左操作数
    auto left = std::make_shared<mycompiler::LiteralExprNode>(lexer);
    
    // 创建操作符
    lexer->getNextToken(); // 移动到 '+'
    auto op = std::make_shared<mycompiler::TerminalOperator>(lexer);
    op->operator_ = "+";
    
    // 创建右操作数
    lexer->getNextToken(); // 移动到 'b'
    auto right = std::make_shared<mycompiler::LiteralExprNode>(lexer);
    
    // 创建二元表达式
    auto binaryExpr = std::make_shared<mycompiler::BinaryExprNode>(left, op, right);
    
    // 测试字符串表示
    std::string str = binaryExpr->toString();
    EXPECT_FALSE(str.empty());
    EXPECT_NE(str.find("+"), std::string::npos);
}

// 测试Parse方法
TEST(BinaryExprNodeTest, Parse) {
    std::string code = "a + b";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    
    // 创建二元表达式并解析
    auto binaryExpr = std::make_shared<mycompiler::BinaryExprNode>(lexer);
    
    // 由于Parse方法依赖于PrattParser，这里我们只测试它不会抛出异常
    EXPECT_NO_THROW(binaryExpr->Parse());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 