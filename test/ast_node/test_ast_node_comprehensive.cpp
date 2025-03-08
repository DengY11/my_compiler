#include "ast_node/root_node.hpp"
#include "ast_node/decl_node/function_decl_node.hpp"
#include "ast_node/decl_node/variable_decl_node.hpp"
#include "ast_node/expr_node/binary_expr.hpp"
#include "ast_node/expr_node/literal_expr_node.hpp"
#include "ast_node/stat_node/if_stat_node.hpp"
#include "ast_node/stat_node/return_stat_node.hpp"
#include "ast_node/stat_node/block_stat_node.hpp"
#include "lexer/lexer.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <string>

// 测试简单的表达式解析
TEST(ASTNodeComprehensiveTest, SimpleExpression) {
    std::string code = "a + b * c";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    
    // 创建二元表达式节点
    auto expr = std::make_shared<mycompiler::BinaryExprNode>(lexer);
    
    // 解析表达式
    EXPECT_NO_THROW(expr->Parse());
    
    // 验证解析结果
    EXPECT_GT(expr->getChildren().size(), 0);
}

// 测试变量声明解析
TEST(ASTNodeComprehensiveTest, VariableDeclaration) {
    std::string code = "let x = 42;";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    
    // 创建根节点
    auto root = std::make_shared<mycompiler::RootNode>(lexer);
    
    // 解析代码
    EXPECT_NO_THROW(root->Parse());
    
    // 验证解析结果
    EXPECT_GT(root->getDeclarations().size(), 0);
    EXPECT_EQ(root->getStatements().size(), 0);
}

// 测试函数声明解析
TEST(ASTNodeComprehensiveTest, FunctionDeclaration) {
    std::string code = "func add(a, b) { return a + b; }";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    
    // 创建根节点
    auto root = std::make_shared<mycompiler::RootNode>(lexer);
    
    // 解析代码
    EXPECT_NO_THROW(root->Parse());
    
    // 验证解析结果
    EXPECT_GT(root->getDeclarations().size(), 0);
    EXPECT_EQ(root->getStatements().size(), 0);
    
    // 验证函数声明
    auto funcDecl = std::dynamic_pointer_cast<mycompiler::FuncDeclNode>(root->getDeclarations()[0]);
    EXPECT_NE(funcDecl, nullptr);
    EXPECT_EQ(funcDecl->getName(), "add");
}

// 测试if语句解析
TEST(ASTNodeComprehensiveTest, IfStatement) {
    std::string code = "if (x > 0) { return x; } else { return -x; }";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    
    // 创建根节点
    auto root = std::make_shared<mycompiler::RootNode>(lexer);
    
    // 解析代码
    EXPECT_NO_THROW(root->Parse());
    
    // 验证解析结果
    EXPECT_EQ(root->getDeclarations().size(), 0);
    EXPECT_GT(root->getStatements().size(), 0);
    
    // 验证if语句
    auto ifStat = std::dynamic_pointer_cast<mycompiler::IfStatNode>(root->getStatements()[0]);
    EXPECT_NE(ifStat, nullptr);
    EXPECT_TRUE(ifStat->hasElse());
}

// 测试复杂程序解析
TEST(ASTNodeComprehensiveTest, ComplexProgram) {
    std::string code = R"(
        func abs(x) {
            if (x >= 0) {
                return x;
            } else {
                return -x;
            }
        }
        
        func main() {
            let a = 42;
            let b = -10;
            let c = abs(b);
            return a + c;
        }
    )";
    
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    
    // 创建根节点
    auto root = std::make_shared<mycompiler::RootNode>(lexer);
    
    // 解析代码
    EXPECT_NO_THROW(root->Parse());
    
    // 验证解析结果
    EXPECT_EQ(root->getDeclarations().size(), 2);
    EXPECT_EQ(root->getStatements().size(), 0);
    
    // 验证函数声明
    auto absFunc = std::dynamic_pointer_cast<mycompiler::FuncDeclNode>(root->getDeclarations()[0]);
    EXPECT_NE(absFunc, nullptr);
    EXPECT_EQ(absFunc->getName(), "abs");
    
    auto mainFunc = std::dynamic_pointer_cast<mycompiler::FuncDeclNode>(root->getDeclarations()[1]);
    EXPECT_NE(mainFunc, nullptr);
    EXPECT_EQ(mainFunc->getName(), "main");
}

// 测试错误处理
TEST(ASTNodeComprehensiveTest, ErrorHandling) {
    // 语法错误：缺少右括号
    std::string code = "if (x > 0 { return x; }";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    
    // 创建if语句节点
    auto ifStat = std::make_shared<mycompiler::IfStatNode>(lexer);
    
    // 解析应该抛出异常
    EXPECT_THROW(ifStat->Parse(), std::runtime_error);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 