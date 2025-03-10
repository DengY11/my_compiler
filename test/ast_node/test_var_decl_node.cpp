#include "ast_node/decl_node/var_decl_node.hpp"
#include "lexer/lexer.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <string>

// 测试VarDeclNode的构造函数
TEST(VarDeclNodeTest, Constructor) {
    std::string code = "int x = 5;";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    mycompiler::VarDeclNode node(lexer);
    
    EXPECT_EQ(node.getNodeType(), mycompiler::AST_NODE_TYPE::DECL);
    EXPECT_EQ(node.getLexer(), lexer);
    EXPECT_EQ(node.getChildren().size(), 0);
    EXPECT_EQ(node.getName(), "");
    EXPECT_EQ(node.getType(), "");
    EXPECT_EQ(node.getInitializer(), nullptr);
    EXPECT_FALSE(node.isConstant());
    EXPECT_FALSE(node.isStatic());
}

// 测试VarDeclNode的Parse方法 - 基本变量声明
TEST(VarDeclNodeTest, ParseBasicDeclaration) {
    std::string code = "int x;";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    lexer->getNextToken(); // 获取第一个token
    
    mycompiler::VarDeclNode node(lexer);
    node.Parse();
    
    EXPECT_EQ(node.getName(), "x");
    EXPECT_EQ(node.getType(), "int");
    EXPECT_EQ(node.getInitializer(), nullptr);
    EXPECT_FALSE(node.isConstant());
    EXPECT_FALSE(node.isStatic());
}

// 测试VarDeclNode的Parse方法 - 带初始化的变量声明
TEST(VarDeclNodeTest, ParseWithInitializer) {
    std::string code = "int x = 5;";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    lexer->getNextToken(); // 获取第一个token
    
    mycompiler::VarDeclNode node(lexer);
    node.Parse();
    
    EXPECT_EQ(node.getName(), "x");
    EXPECT_EQ(node.getType(), "int");
    EXPECT_NE(node.getInitializer(), nullptr);
    EXPECT_FALSE(node.isConstant());
    EXPECT_FALSE(node.isStatic());
}

// 测试VarDeclNode的Parse方法 - 常量变量声明
TEST(VarDeclNodeTest, ParseConstDeclaration) {
    std::string code = "const int x = 5;";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    lexer->getNextToken(); // 获取第一个token
    
    mycompiler::VarDeclNode node(lexer);
    node.Parse();
    
    EXPECT_EQ(node.getName(), "x");
    EXPECT_EQ(node.getType(), "int");
    EXPECT_NE(node.getInitializer(), nullptr);
    EXPECT_TRUE(node.isConstant());
    EXPECT_FALSE(node.isStatic());
}

// 测试VarDeclNode的Parse方法 - 静态变量声明
TEST(VarDeclNodeTest, ParseStaticDeclaration) {
    std::string code = "static int x = 5;";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    lexer->getNextToken(); // 获取第一个token
    
    mycompiler::VarDeclNode node(lexer);
    node.Parse();
    
    EXPECT_EQ(node.getName(), "x");
    EXPECT_EQ(node.getType(), "int");
    EXPECT_NE(node.getInitializer(), nullptr);
    EXPECT_FALSE(node.isConstant());
    EXPECT_TRUE(node.isStatic());
}

// 测试VarDeclNode的Parse方法 - 常量静态变量声明
TEST(VarDeclNodeTest, ParseConstStaticDeclaration) {
    std::string code = "const static int x = 5;";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    lexer->getNextToken(); // 获取第一个token
    
    mycompiler::VarDeclNode node(lexer);
    node.Parse();
    
    EXPECT_EQ(node.getName(), "x");
    EXPECT_EQ(node.getType(), "int");
    EXPECT_NE(node.getInitializer(), nullptr);
    EXPECT_TRUE(node.isConstant());
    EXPECT_TRUE(node.isStatic());
}

// 测试VarDeclNode的toString方法
TEST(VarDeclNodeTest, ToString) {
    std::string code = "int x = 5;";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    lexer->getNextToken(); // 获取第一个token
    
    mycompiler::VarDeclNode node(lexer);
    node.Parse();
    
    std::string str = node.toString();
    EXPECT_NE(str.find("int"), std::string::npos);
    EXPECT_NE(str.find("x"), std::string::npos);
    EXPECT_NE(str.find("="), std::string::npos);
}

// 测试VarDeclNode的getter和setter方法
TEST(VarDeclNodeTest, GetterSetter) {
    std::string code = "int x;";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    mycompiler::VarDeclNode node(lexer);
    
    node.setName("y");
    EXPECT_EQ(node.getName(), "y");
    
    node.setType("float");
    EXPECT_EQ(node.getType(), "float");
    
    node.setConstant(true);
    EXPECT_TRUE(node.isConstant());
    
    node.setStatic(true);
    EXPECT_TRUE(node.isStatic());
    
    // 设置初始化表达式需要一个ExprNode，这里我们不测试
}

// 测试VarDeclNode的修饰符方法
TEST(VarDeclNodeTest, Modifiers) {
    std::string code = "int x;";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    mycompiler::VarDeclNode node(lexer);
    
    EXPECT_EQ(node.getModifiers().size(), 0);
    
    node.addModifier("extern");
    EXPECT_EQ(node.getModifiers().size(), 1);
    EXPECT_EQ(node.getModifiers()[0], "extern");
    
    node.addModifier("volatile");
    EXPECT_EQ(node.getModifiers().size(), 2);
    EXPECT_EQ(node.getModifiers()[1], "volatile");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 