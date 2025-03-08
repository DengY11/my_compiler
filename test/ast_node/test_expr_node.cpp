#include "ast_node/expr_node/expr_node.hpp"
#include "lexer/lexer.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <string>

// 创建一个测试用的ExprNode派生类，因为ExprNode是抽象类
class TestExprNode : public mycompiler::ExprNode {
public:
    TestExprNode(std::shared_ptr<mycompiler::Lexer> lexer) : ExprNode(lexer) {}
    
    void Parse() override {
        // 简单实现，不做任何事情
    }
    
    // 覆盖虚方法用于测试
    std::string getExpressionType() const override {
        return "test_type";
    }
    
    bool isConstant() const override {
        return true;
    }
    
    bool isLValue() const override {
        return false;
    }
};

// 测试ExprNode的构造函数
TEST(ExprNodeTest, Constructor) {
    std::string code = "test code";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    TestExprNode node(lexer);
    
    EXPECT_EQ(node.getNodeType(), mycompiler::AST_NODE_TYPE::EXPR);
    EXPECT_EQ(node.getLexer(), lexer);
    EXPECT_EQ(node.getChildren().size(), 0);
}

// 测试getExpressionType方法
TEST(ExprNodeTest, GetExpressionType) {
    std::string code = "test code";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    TestExprNode node(lexer);
    
    EXPECT_EQ(node.getExpressionType(), "test_type");
}

// 测试isConstant方法
TEST(ExprNodeTest, IsConstant) {
    std::string code = "test code";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    TestExprNode node(lexer);
    
    EXPECT_TRUE(node.isConstant());
}

// 测试isLValue方法
TEST(ExprNodeTest, IsLValue) {
    std::string code = "test code";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    TestExprNode node(lexer);
    
    EXPECT_FALSE(node.isLValue());
}

// 测试toString方法
TEST(ExprNodeTest, ToString) {
    std::string code = "test code";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    TestExprNode node(lexer);
    
    std::string str = node.toString();
    EXPECT_FALSE(str.empty());
    EXPECT_NE(str.find("Expression"), std::string::npos);
    EXPECT_NE(str.find("test_type"), std::string::npos);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 