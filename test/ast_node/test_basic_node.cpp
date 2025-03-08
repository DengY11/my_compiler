#include "ast_node/basic_node.hpp"
#include "lexer/lexer.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <string>

// 创建一个测试用的BasicNode派生类，因为BasicNode是抽象类
class TestBasicNode : public mycompiler::BasicNode {
public:
    TestBasicNode(std::shared_ptr<mycompiler::Lexer> lexer) : BasicNode(lexer) {}
    
    void Parse() override {
        // 简单实现，不做任何事情
    }
    
    // 暴露protected方法用于测试
    bool testExpectNextToken(mycompiler::TokenType type) {
        return expectNextToken(type);
    }
    
    mycompiler::Token testConsumeToken(mycompiler::TokenType type) {
        return consumeToken(type);
    }
};

// 测试BasicNode的构造函数
TEST(BasicNodeTest, Constructor) {
    std::string code = "test code";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    TestBasicNode node(lexer);
    
    EXPECT_EQ(node.getNodeType(), mycompiler::AST_NODE_TYPE::BASIC);
    EXPECT_EQ(node.getLexer(), lexer);
    EXPECT_EQ(node.getChildren().size(), 0);
}

// 测试添加子节点
TEST(BasicNodeTest, AddChild) {
    std::string code = "test code";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    TestBasicNode parent(lexer);
    auto child = std::make_shared<TestBasicNode>(lexer);
    
    parent.add_child(child);
    
    EXPECT_EQ(parent.getChildren().size(), 1);
    EXPECT_EQ(parent.getChildren()[0], child);
}

// 测试toString方法
TEST(BasicNodeTest, ToString) {
    std::string code = "test code";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    TestBasicNode node(lexer);
    
    std::string str = node.toString();
    EXPECT_FALSE(str.empty());
    EXPECT_NE(str.find("BASIC"), std::string::npos);
}

// 测试expectNextToken方法
TEST(BasicNodeTest, ExpectNextToken) {
    std::string code = "let x = 5;";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    TestBasicNode node(lexer);
    
    // 第一个标记应该是KEYWORD
    EXPECT_TRUE(node.testExpectNextToken(mycompiler::TokenType::KEYWORD));
    // 不应该是OPERATOR
    EXPECT_FALSE(node.testExpectNextToken(mycompiler::TokenType::OPERATOR));
}

// 测试consumeToken方法
TEST(BasicNodeTest, ConsumeToken) {
    std::string code = "let x = 5;";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    TestBasicNode node(lexer);
    
    // 消费KEYWORD标记
    auto token = node.testConsumeToken(mycompiler::TokenType::KEYWORD);
    EXPECT_EQ(token.getTokenType(), mycompiler::TokenType::KEYWORD);
    
    // 现在lexer应该指向下一个标记（IDENT）
    token = lexer->getCurrentToken();
    EXPECT_EQ(token.getTokenType(), mycompiler::TokenType::IDENT);
    
    // 尝试消费错误类型的标记应该抛出异常
    EXPECT_THROW(node.testConsumeToken(mycompiler::TokenType::OPERATOR), std::runtime_error);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 