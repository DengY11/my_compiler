#include "ast_node/ast_node.hpp"
#include "ast_node/basic_node.hpp"
#include "ast_node/expr_node/binary_expr_node.hpp"
#include "ast_node/expr_node/literal_expr_node.hpp"
#include "ast_node/expr_node/ident_expr_node.hpp"
#include "ast_node/stat_node/block_stat_node.hpp"
#include "ast_node/stat_node/if_stat_node.hpp"
#include "ast_node/stat_node/return_stat_node.hpp"
#include "ast_node/decl_node/var_decl_node.hpp"
#include "ast_node/decl_node/func_decl_node.hpp"
#include "ast_node/root_node.hpp"
#include "lexer/lexer.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <string>
#include <vector>

// 测试AST节点的行号和列号功能
class ASTNodePositionComprehensiveTest : public ::testing::Test {
protected:
    void SetUp() override {
        // 创建测试用的代码片段
        singleLineCode = "let x = 5;";
        multiLineCode = "let x = 5;\nlet y = 10;\nlet z = x + y;";
        complexCode = "function add(a, b) {\n  return a + b;\n}\n\nlet result = add(5, 10);";
        ifStatCode = "if (x > 5) {\n  let y = 10;\n  return y;\n} else {\n  return x;\n}";
        functionCode = "function factorial(n) {\n  if (n <= 1) {\n    return 1;\n  } else {\n    return n * factorial(n - 1);\n  }\n}";
    }

    std::string singleLineCode;
    std::string multiLineCode;
    std::string complexCode;
    std::string ifStatCode;
    std::string functionCode;
    
    // 辅助方法：创建一个AST节点并设置位置
    template<typename NodeType>
    std::shared_ptr<NodeType> createNodeWithPosition(std::shared_ptr<mycompiler::Lexer> lexer, int line, int column) {
        auto node = std::make_shared<NodeType>(lexer);
        node->setLineNumber(line);
        node->setColumnNumber(column);
        return node;
    }
    
    // 辅助方法：验证节点的位置
    void verifyNodePosition(const mycompiler::ASTNode& node, int expectedLine, int expectedColumn) {
        EXPECT_EQ(node.getLineNumber(), expectedLine);
        EXPECT_EQ(node.getColumnNumber(), expectedColumn);
    }
};

// 测试不同类型的表达式节点的行号和列号
TEST_F(ASTNodePositionComprehensiveTest, ExpressionNodePositions) {
    auto lexer = std::make_shared<mycompiler::Lexer>(multiLineCode);
    
    // 测试字面量表达式节点
    auto literalNode = createNodeWithPosition<mycompiler::LiteralExprNode>(lexer, 1, 10);
    verifyNodePosition(*literalNode, 1, 10);
    
    // 测试标识符表达式节点
    auto identNode = createNodeWithPosition<mycompiler::IdentExprNode>(lexer, 2, 5);
    verifyNodePosition(*identNode, 2, 5);
    
    // 测试二元表达式节点
    auto binaryNode = createNodeWithPosition<mycompiler::BinaryExprNode>(lexer, 3, 15);
    verifyNodePosition(*binaryNode, 3, 15);
    
    // 测试复杂表达式：x + y * z
    auto xNode = createNodeWithPosition<mycompiler::IdentExprNode>(lexer, 1, 1);
    auto yNode = createNodeWithPosition<mycompiler::IdentExprNode>(lexer, 1, 5);
    auto zNode = createNodeWithPosition<mycompiler::IdentExprNode>(lexer, 1, 9);
    
    // y * z
    auto mulNode = createNodeWithPosition<mycompiler::BinaryExprNode>(lexer, 1, 7);
    mulNode->setLeft(yNode);
    mulNode->setRight(zNode);
    
    // x + (y * z)
    auto addNode = createNodeWithPosition<mycompiler::BinaryExprNode>(lexer, 1, 3);
    addNode->setLeft(xNode);
    addNode->setRight(mulNode);
    
    // 验证复杂表达式中各节点的位置
    verifyNodePosition(*xNode, 1, 1);
    verifyNodePosition(*yNode, 1, 5);
    verifyNodePosition(*zNode, 1, 9);
    verifyNodePosition(*mulNode, 1, 7);
    verifyNodePosition(*addNode, 1, 3);
}

// 测试不同类型的语句节点的行号和列号
TEST_F(ASTNodePositionComprehensiveTest, StatementNodePositions) {
    auto lexer = std::make_shared<mycompiler::Lexer>(ifStatCode);
    
    // 测试块语句节点
    auto blockNode = createNodeWithPosition<mycompiler::BlockStatNode>(lexer, 1, 10);
    verifyNodePosition(*blockNode, 1, 10);
    
    // 测试返回语句节点
    auto returnNode = createNodeWithPosition<mycompiler::ReturnStatNode>(lexer, 3, 3);
    verifyNodePosition(*returnNode, 3, 3);
    
    // 测试if语句节点
    auto ifNode = createNodeWithPosition<mycompiler::IfStatNode>(lexer, 1, 1);
    verifyNodePosition(*ifNode, 1, 1);
    
    // 测试复杂if语句结构
    // if (x > 5) { return y; } else { return x; }
    auto conditionNode = createNodeWithPosition<mycompiler::BinaryExprNode>(lexer, 1, 5);
    auto thenBlockNode = createNodeWithPosition<mycompiler::BlockStatNode>(lexer, 1, 11);
    auto elseBlockNode = createNodeWithPosition<mycompiler::BlockStatNode>(lexer, 4, 8);
    
    auto thenReturnNode = createNodeWithPosition<mycompiler::ReturnStatNode>(lexer, 3, 3);
    auto elseReturnNode = createNodeWithPosition<mycompiler::ReturnStatNode>(lexer, 5, 3);
    
    thenBlockNode->addStatement(thenReturnNode);
    elseBlockNode->addStatement(elseReturnNode);
    
    ifNode->setCondition(conditionNode);
    ifNode->setThenStatement(thenBlockNode);
    ifNode->setElseStatement(elseBlockNode);
    
    // 验证复杂if语句中各节点的位置
    verifyNodePosition(*conditionNode, 1, 5);
    verifyNodePosition(*thenBlockNode, 1, 11);
    verifyNodePosition(*elseBlockNode, 4, 8);
    verifyNodePosition(*thenReturnNode, 3, 3);
    verifyNodePosition(*elseReturnNode, 5, 3);
}

// 测试不同类型的声明节点的行号和列号
TEST_F(ASTNodePositionComprehensiveTest, DeclarationNodePositions) {
    auto lexer = std::make_shared<mycompiler::Lexer>(functionCode);
    
    // 测试变量声明节点
    auto varDeclNode = createNodeWithPosition<mycompiler::VarDeclNode>(lexer, 2, 7);
    verifyNodePosition(*varDeclNode, 2, 7);
    
    // 测试函数声明节点
    auto funcDeclNode = createNodeWithPosition<mycompiler::FuncDeclNode>(lexer, 1, 1);
    verifyNodePosition(*funcDeclNode, 1, 1);
    
    // 测试复杂函数声明结构
    // function factorial(n) { ... }
    auto funcNameNode = createNodeWithPosition<mycompiler::IdentExprNode>(lexer, 1, 10);
    auto paramNode = createNodeWithPosition<mycompiler::IdentExprNode>(lexer, 1, 20);
    auto bodyNode = createNodeWithPosition<mycompiler::BlockStatNode>(lexer, 1, 23);
    
    funcDeclNode->setName(funcNameNode);
    funcDeclNode->addParameter(paramNode);
    funcDeclNode->setBody(bodyNode);
    
    // 验证复杂函数声明中各节点的位置
    verifyNodePosition(*funcNameNode, 1, 10);
    verifyNodePosition(*paramNode, 1, 20);
    verifyNodePosition(*bodyNode, 1, 23);
}

// 测试根节点的行号和列号
TEST_F(ASTNodePositionComprehensiveTest, RootNodePosition) {
    auto lexer = std::make_shared<mycompiler::Lexer>(complexCode);
    
    // 创建根节点
    auto rootNode = createNodeWithPosition<mycompiler::RootNode>(lexer, 1, 1);
    verifyNodePosition(*rootNode, 1, 1);
    
    // 添加子节点
    auto funcDeclNode = createNodeWithPosition<mycompiler::FuncDeclNode>(lexer, 1, 1);
    auto varDeclNode = createNodeWithPosition<mycompiler::VarDeclNode>(lexer, 5, 1);
    
    rootNode->addChild(funcDeclNode);
    rootNode->addChild(varDeclNode);
    
    // 验证根节点及其子节点的位置
    verifyNodePosition(*rootNode, 1, 1);
    verifyNodePosition(*funcDeclNode, 1, 1);
    verifyNodePosition(*varDeclNode, 5, 1);
}

// 测试节点位置在toString方法中的体现
TEST_F(ASTNodePositionComprehensiveTest, PositionInToString) {
    auto lexer = std::make_shared<mycompiler::Lexer>(singleLineCode);
    
    // 创建不同类型的节点
    auto literalNode = createNodeWithPosition<mycompiler::LiteralExprNode>(lexer, 1, 10);
    auto identNode = createNodeWithPosition<mycompiler::IdentExprNode>(lexer, 2, 5);
    auto varDeclNode = createNodeWithPosition<mycompiler::VarDeclNode>(lexer, 3, 1);
    
    // 验证toString方法中包含位置信息
    EXPECT_NE(literalNode->toString().find("1"), std::string::npos);
    EXPECT_NE(literalNode->toString().find("10"), std::string::npos);
    
    EXPECT_NE(identNode->toString().find("2"), std::string::npos);
    EXPECT_NE(identNode->toString().find("5"), std::string::npos);
    
    EXPECT_NE(varDeclNode->toString().find("3"), std::string::npos);
    EXPECT_NE(varDeclNode->toString().find("1"), std::string::npos);
}

// 测试节点位置在错误处理中的应用
TEST_F(ASTNodePositionComprehensiveTest, PositionInErrorHandling) {
    auto lexer = std::make_shared<mycompiler::Lexer>(ifStatCode);
    
    // 创建一个if语句节点，但故意不设置条件
    auto ifNode = createNodeWithPosition<mycompiler::IfStatNode>(lexer, 1, 1);
    
    // 模拟错误消息
    std::string errorMessage = "Error at line " + std::to_string(ifNode->getLineNumber()) + 
                              ", column " + std::to_string(ifNode->getColumnNumber()) + 
                              ": Missing condition in if statement";
    
    // 验证错误消息中包含正确的位置信息
    EXPECT_NE(errorMessage.find("line 1"), std::string::npos);
    EXPECT_NE(errorMessage.find("column 1"), std::string::npos);
}

// 测试复杂AST树中的位置信息传递
TEST_F(ASTNodePositionComprehensiveTest, PositionPropagationInComplexTree) {
    auto lexer = std::make_shared<mycompiler::Lexer>(functionCode);
    
    // 创建一个完整的函数声明AST树
    auto rootNode = createNodeWithPosition<mycompiler::RootNode>(lexer, 1, 1);
    auto funcDeclNode = createNodeWithPosition<mycompiler::FuncDeclNode>(lexer, 1, 1);
    auto funcNameNode = createNodeWithPosition<mycompiler::IdentExprNode>(lexer, 1, 10);
    auto paramNode = createNodeWithPosition<mycompiler::IdentExprNode>(lexer, 1, 20);
    auto bodyNode = createNodeWithPosition<mycompiler::BlockStatNode>(lexer, 1, 23);
    auto ifNode = createNodeWithPosition<mycompiler::IfStatNode>(lexer, 2, 3);
    auto conditionNode = createNodeWithPosition<mycompiler::BinaryExprNode>(lexer, 2, 7);
    auto thenBlockNode = createNodeWithPosition<mycompiler::BlockStatNode>(lexer, 2, 15);
    auto elseBlockNode = createNodeWithPosition<mycompiler::BlockStatNode>(lexer, 4, 10);
    auto thenReturnNode = createNodeWithPosition<mycompiler::ReturnStatNode>(lexer, 3, 5);
    auto elseReturnNode = createNodeWithPosition<mycompiler::ReturnStatNode>(lexer, 5, 5);
    
    // 构建AST树结构
    thenBlockNode->addStatement(thenReturnNode);
    elseBlockNode->addStatement(elseReturnNode);
    
    ifNode->setCondition(conditionNode);
    ifNode->setThenStatement(thenBlockNode);
    ifNode->setElseStatement(elseBlockNode);
    
    bodyNode->addStatement(ifNode);
    
    funcDeclNode->setName(funcNameNode);
    funcDeclNode->addParameter(paramNode);
    funcDeclNode->setBody(bodyNode);
    
    rootNode->addChild(funcDeclNode);
    
    // 验证整个AST树中各节点的位置
    verifyNodePosition(*rootNode, 1, 1);
    verifyNodePosition(*funcDeclNode, 1, 1);
    verifyNodePosition(*funcNameNode, 1, 10);
    verifyNodePosition(*paramNode, 1, 20);
    verifyNodePosition(*bodyNode, 1, 23);
    verifyNodePosition(*ifNode, 2, 3);
    verifyNodePosition(*conditionNode, 2, 7);
    verifyNodePosition(*thenBlockNode, 2, 15);
    verifyNodePosition(*elseBlockNode, 4, 10);
    verifyNodePosition(*thenReturnNode, 3, 5);
    verifyNodePosition(*elseReturnNode, 5, 5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 