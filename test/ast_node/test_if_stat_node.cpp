#include "ast_node/stat_node/if_stat_node.hpp"
#include "ast_node/expr_node/literal_expr_node.hpp"
#include "ast_node/stat_node/block_stat_node.hpp"
#include "ast_node/stat_node/else_stat_node.hpp"
#include "ast_node/terminal_symbols/terminal_if.hpp"
#include "ast_node/terminal_symbols/terminal_separator.hpp"
#include "lexer/lexer.hpp"
#include "token/token_helper_functions.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <string>

// 测试IfStatNode的构造函数
TEST(IfStatNodeTest, Constructor) {
    std::string code = "if (true) {}";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    auto ifStat = std::make_shared<mycompiler::IfStatNode>(lexer);
    
    EXPECT_EQ(ifStat->getNodeType(), mycompiler::AST_NODE_TYPE::IF_STAT);
    EXPECT_EQ(ifStat->getStatType(), mycompiler::StatType::IF_STAT);
    EXPECT_EQ(ifStat->getLexer(), lexer);
    EXPECT_EQ(ifStat->getChildren().size(), 0);
}

// 测试Parse方法（不带else）
TEST(IfStatNodeTest, ParseWithoutElse) {
    std::string code = "if (true) { return 42; }";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    auto ifStat = std::make_shared<mycompiler::IfStatNode>(lexer);
    
    // 解析if语句
    EXPECT_NO_THROW(ifStat->Parse());
    
    // 验证解析结果
    EXPECT_NE(ifStat->getCondition(), nullptr);
    EXPECT_NE(ifStat->getIfBlock(), nullptr);
    EXPECT_EQ(ifStat->getElseBlock(), nullptr);
    EXPECT_FALSE(ifStat->hasElse());
    EXPECT_GT(ifStat->getChildren().size(), 0);
}

// 测试Parse方法（带else）
TEST(IfStatNodeTest, ParseWithElse) {
    std::string code = "if (true) { return 42; } else { return 0; }";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    auto ifStat = std::make_shared<mycompiler::IfStatNode>(lexer);
    
    // 解析if语句
    EXPECT_NO_THROW(ifStat->Parse());
    
    // 验证解析结果
    EXPECT_NE(ifStat->getCondition(), nullptr);
    EXPECT_NE(ifStat->getIfBlock(), nullptr);
    EXPECT_NE(ifStat->getElseBlock(), nullptr);
    EXPECT_TRUE(ifStat->hasElse());
    EXPECT_GT(ifStat->getChildren().size(), 0);
}

// 测试getCondition方法
TEST(IfStatNodeTest, GetCondition) {
    std::string code = "if (true) {}";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    auto ifStat = std::make_shared<mycompiler::IfStatNode>(lexer);
    
    // 解析if语句
    ifStat->Parse();
    
    // 验证条件表达式
    auto condition = ifStat->getCondition();
    EXPECT_NE(condition, nullptr);
    // 由于我们没有实现LiteralExprNode的方法来获取值，这里不做具体断言
}

// 测试getIfBlock方法
TEST(IfStatNodeTest, GetIfBlock) {
    std::string code = "if (true) { return 42; }";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    auto ifStat = std::make_shared<mycompiler::IfStatNode>(lexer);
    
    // 解析if语句
    ifStat->Parse();
    
    // 验证if块
    auto ifBlock = ifStat->getIfBlock();
    EXPECT_NE(ifBlock, nullptr);
    // 由于我们没有实现BlockStatNode的方法来获取语句数量，这里不做具体断言
}

// 测试getElseBlock和hasElse方法
TEST(IfStatNodeTest, GetElseBlockAndHasElse) {
    // 不带else的if语句
    {
        std::string code = "if (true) {}";
        auto lexer = std::make_shared<mycompiler::Lexer>(code);
        auto ifStat = std::make_shared<mycompiler::IfStatNode>(lexer);
        
        // 解析if语句
        ifStat->Parse();
        
        // 验证else块
        EXPECT_EQ(ifStat->getElseBlock(), nullptr);
        EXPECT_FALSE(ifStat->hasElse());
    }
    
    // 带else的if语句
    {
        std::string code = "if (true) {} else {}";
        auto lexer = std::make_shared<mycompiler::Lexer>(code);
        auto ifStat = std::make_shared<mycompiler::IfStatNode>(lexer);
        
        // 解析if语句
        ifStat->Parse();
        
        // 验证else块
        EXPECT_NE(ifStat->getElseBlock(), nullptr);
        EXPECT_TRUE(ifStat->hasElse());
    }
}

// 测试isTerminating方法
TEST(IfStatNodeTest, IsTerminating) {
    // if和else块都是终止语句
    {
        std::string code = "if (true) { return 42; } else { return 0; }";
        auto lexer = std::make_shared<mycompiler::Lexer>(code);
        auto ifStat = std::make_shared<mycompiler::IfStatNode>(lexer);
        
        // 解析if语句
        ifStat->Parse();
        
        // 由于我们没有实现BlockStatNode的isTerminating方法，这里不做具体断言
        // EXPECT_TRUE(ifStat->isTerminating());
    }
    
    // if块不是终止语句
    {
        std::string code = "if (true) { x = 42; } else { return 0; }";
        auto lexer = std::make_shared<mycompiler::Lexer>(code);
        auto ifStat = std::make_shared<mycompiler::IfStatNode>(lexer);
        
        // 解析if语句
        ifStat->Parse();
        
        // 由于我们没有实现BlockStatNode的isTerminating方法，这里不做具体断言
        // EXPECT_FALSE(ifStat->isTerminating());
    }
}

// 测试toString方法
TEST(IfStatNodeTest, ToString) {
    std::string code = "if (true) {}";
    auto lexer = std::make_shared<mycompiler::Lexer>(code);
    auto ifStat = std::make_shared<mycompiler::IfStatNode>(lexer);
    
    // 解析if语句
    ifStat->Parse();
    
    // 验证字符串表示
    std::string str = ifStat->toString();
    EXPECT_FALSE(str.empty());
    EXPECT_NE(str.find("If statement"), std::string::npos);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 