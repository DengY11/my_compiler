#include "ast_node/decl_node/function_decl_node.hpp"
#include "ast_node/stat_node/parameter_list_stat_node.hpp"
#include "ast_node/stat_node/block_stat_node.hpp"
#include "ast_node/terminal_symbols/terminal_func.hpp"
#include "ast_node/terminal_symbols/terminal_ident_literal.hpp"
#include "ast_node/terminal_symbols/terminal_separator.hpp"
#include "lexer/lexer.hpp"
#include "token/token_helper_functions.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <string>

// 测试FuncDeclNode的构造函数
TEST(FuncDeclNodeTest, Constructor) {
    std::string code = "func test() {}";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    auto funcDecl = std::make_shared<mycompiler::FuncDeclNode>(lexer);
    
    EXPECT_EQ(funcDecl->getNodeType(), mycompiler::AST_NODE_TYPE::FUNCTION_DECL);
    EXPECT_EQ(funcDecl->getLexer(), lexer);
    EXPECT_EQ(funcDecl->getChildren().size(), 0);
    EXPECT_EQ(funcDecl->getReturnType(), "void"); // 默认返回类型为void
}

// 测试Parse方法
TEST(FuncDeclNodeTest, Parse) {
    std::string code = "func test() {}";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    auto funcDecl = std::make_shared<mycompiler::FuncDeclNode>(lexer);
    
    // 解析函数声明
    EXPECT_NO_THROW(funcDecl->Parse());
    
    // 验证解析结果
    EXPECT_EQ(funcDecl->getName(), "test");
    EXPECT_EQ(funcDecl->getReturnType(), "void");
    EXPECT_NE(funcDecl->getParameters(), nullptr);
    EXPECT_NE(funcDecl->getBody(), nullptr);
    EXPECT_GT(funcDecl->getChildren().size(), 0);
}

// 测试getParameters方法
TEST(FuncDeclNodeTest, GetParameters) {
    std::string code = "func test(a, b) {}";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    auto funcDecl = std::make_shared<mycompiler::FuncDeclNode>(lexer);
    
    // 解析函数声明
    funcDecl->Parse();
    
    // 验证参数列表
    auto params = funcDecl->getParameters();
    EXPECT_NE(params, nullptr);
    // 由于我们没有实现ParameterListStatNode的方法来获取参数数量，这里不做具体断言
}

// 测试getBody方法
TEST(FuncDeclNodeTest, GetBody) {
    std::string code = "func test() { return 42; }";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    auto funcDecl = std::make_shared<mycompiler::FuncDeclNode>(lexer);
    
    // 解析函数声明
    funcDecl->Parse();
    
    // 验证函数体
    auto body = funcDecl->getBody();
    EXPECT_NE(body, nullptr);
    // 由于我们没有实现BlockStatNode的方法来获取语句数量，这里不做具体断言
}

// 测试getReturnType和setReturnType方法
TEST(FuncDeclNodeTest, ReturnType) {
    std::string code = "func test() {}";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    auto funcDecl = std::make_shared<mycompiler::FuncDeclNode>(lexer);
    
    // 默认返回类型为void
    EXPECT_EQ(funcDecl->getReturnType(), "void");
    
    // 设置返回类型
    funcDecl->setReturnType("int");
    EXPECT_EQ(funcDecl->getReturnType(), "int");
}

// 测试toString方法
TEST(FuncDeclNodeTest, ToString) {
    std::string code = "func test() {}";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    auto funcDecl = std::make_shared<mycompiler::FuncDeclNode>(lexer);
    
    // 解析函数声明
    funcDecl->Parse();
    
    // 验证字符串表示
    std::string str = funcDecl->toString();
    EXPECT_FALSE(str.empty());
    EXPECT_NE(str.find("Function"), std::string::npos);
    EXPECT_NE(str.find("test"), std::string::npos);
    EXPECT_NE(str.find("void"), std::string::npos);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 