#include "ast_node/decl_node/decl_node.hpp"
#include "lexer/lexer.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <string>

// 创建一个测试用的DeclNode派生类，因为DeclNode是抽象类
class TestDeclNode : public mycompiler::DeclNode {
public:
    TestDeclNode(std::shared_ptr<mycompiler::Lexer> lexer) : DeclNode(lexer) {
        name_ = "test_name";
        type_ = "test_type";
    }
    
    void Parse() override {
        // 简单实现，不做任何事情
    }
};

// 测试DeclNode的构造函数
TEST(DeclNodeTest, Constructor) {
    std::string code = "test code";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    TestDeclNode node(lexer);
    
    EXPECT_EQ(node.getNodeType(), mycompiler::AST_NODE_TYPE::DECL);
    EXPECT_EQ(node.getLexer(), lexer);
    EXPECT_EQ(node.getChildren().size(), 0);
}

// 测试getName方法
TEST(DeclNodeTest, GetName) {
    std::string code = "test code";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    TestDeclNode node(lexer);
    
    EXPECT_EQ(node.getName(), "test_name");
}

// 测试getType方法
TEST(DeclNodeTest, GetType) {
    std::string code = "test code";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    TestDeclNode node(lexer);
    
    EXPECT_EQ(node.getType(), "test_type");
}

// 测试toString方法
TEST(DeclNodeTest, ToString) {
    std::string code = "test code";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    TestDeclNode node(lexer);
    
    std::string str = node.toString();
    EXPECT_FALSE(str.empty());
    EXPECT_NE(str.find("Declaration"), std::string::npos);
    EXPECT_NE(str.find("test_name"), std::string::npos);
    EXPECT_NE(str.find("test_type"), std::string::npos);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 