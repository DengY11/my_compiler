#include "ast_node/stat_node/stat_node.hpp"
#include "lexer/lexer.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <string>

// 创建一个测试用的StatNode派生类，因为StatNode是抽象类
class TestStatNode : public mycompiler::StatNode {
public:
    TestStatNode(std::shared_ptr<mycompiler::Lexer> lexer, mycompiler::StatType type = mycompiler::StatType::VOID_STAT) 
        : StatNode(lexer) {
        statType_ = type;
    }
    
    void Parse() override {
        // 简单实现，不做任何事情
    }
};

// 测试StatNode的构造函数
TEST(StatNodeTest, Constructor) {
    std::string code = "test code";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    TestStatNode node(lexer);
    
    EXPECT_EQ(node.getNodeType(), mycompiler::AST_NODE_TYPE::STAT);
    EXPECT_EQ(node.getLexer(), lexer);
    EXPECT_EQ(node.getChildren().size(), 0);
    EXPECT_EQ(node.getStatType(), mycompiler::StatType::VOID_STAT);
}

// 测试getStatType方法
TEST(StatNodeTest, GetStatType) {
    std::string code = "test code";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    
    // 测试不同的语句类型
    TestStatNode voidNode(lexer, mycompiler::StatType::VOID_STAT);
    EXPECT_EQ(voidNode.getStatType(), mycompiler::StatType::VOID_STAT);
    
    TestStatNode ifNode(lexer, mycompiler::StatType::IF_STAT);
    EXPECT_EQ(ifNode.getStatType(), mycompiler::StatType::IF_STAT);
    
    TestStatNode whileNode(lexer, mycompiler::StatType::WHILE_STAT);
    EXPECT_EQ(whileNode.getStatType(), mycompiler::StatType::WHILE_STAT);
}

// 测试isTerminating方法
TEST(StatNodeTest, IsTerminating) {
    std::string code = "test code";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    
    // 非终止语句
    TestStatNode voidNode(lexer, mycompiler::StatType::VOID_STAT);
    EXPECT_FALSE(voidNode.isTerminating());
    
    TestStatNode ifNode(lexer, mycompiler::StatType::IF_STAT);
    EXPECT_FALSE(ifNode.isTerminating());
    
    // 终止语句
    TestStatNode returnNode(lexer, mycompiler::StatType::RETURN_STAT);
    EXPECT_TRUE(returnNode.isTerminating());
    
    TestStatNode breakNode(lexer, mycompiler::StatType::BREAK_STAT);
    EXPECT_TRUE(breakNode.isTerminating());
    
    TestStatNode continueNode(lexer, mycompiler::StatType::CONTINUE_STAT);
    EXPECT_TRUE(continueNode.isTerminating());
}

// 测试toString方法
TEST(StatNodeTest, ToString) {
    std::string code = "test code";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    TestStatNode node(lexer, mycompiler::StatType::IF_STAT);
    
    std::string str = node.toString();
    EXPECT_FALSE(str.empty());
    EXPECT_NE(str.find("Statement"), std::string::npos);
    EXPECT_NE(str.find("IF_STAT"), std::string::npos);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 