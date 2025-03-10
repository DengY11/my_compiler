#include "lexer/lexer.hpp"
#include "token/token.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <string>
#include <iostream>
#include <vector>

// 基础AST节点类，用于测试行号和列号功能
class BaseASTNode {
public:
    BaseASTNode(std::shared_ptr<mycompiler::Lexer> lexer) : lexer_(lexer) {
        // 设置行号和列号为词法分析器当前位置
        lineNumber_ = lexer->getCurrentLine();
        columnNumber_ = lexer->getCurrentColumn();
    }
    
    virtual ~BaseASTNode() = default;
    
    virtual void printInfo() const {
        std::cout << "BaseASTNode at line " << lineNumber_ 
                  << ", column " << columnNumber_ << std::endl;
    }
    
    virtual std::string toString() const {
        return "BaseASTNode at line " + std::to_string(lineNumber_) 
               + ", column " + std::to_string(columnNumber_);
    }
    
    int getLineNumber() const { return lineNumber_; }
    void setLineNumber(int lineNumber) { lineNumber_ = lineNumber; }
    
    int getColumnNumber() const { return columnNumber_; }
    void setColumnNumber(int columnNumber) { columnNumber_ = columnNumber; }
    
    std::shared_ptr<mycompiler::Lexer> getLexer() const { return lexer_; }
    
    void addChild(std::shared_ptr<BaseASTNode> child) {
        children_.push_back(child);
    }
    
    const std::vector<std::shared_ptr<BaseASTNode>>& getChildren() const {
        return children_;
    }

protected:
    std::shared_ptr<mycompiler::Lexer> lexer_;
    int lineNumber_;
    int columnNumber_;
    std::vector<std::shared_ptr<BaseASTNode>> children_;
};

// 表达式节点类
class ExprNode : public BaseASTNode {
public:
    ExprNode(std::shared_ptr<mycompiler::Lexer> lexer) : BaseASTNode(lexer) {}
    
    std::string toString() const override {
        return "ExprNode at line " + std::to_string(getLineNumber()) 
               + ", column " + std::to_string(getColumnNumber());
    }
};

// 字面量表达式节点类
class LiteralExprNode : public ExprNode {
public:
    LiteralExprNode(std::shared_ptr<mycompiler::Lexer> lexer, const std::string& value) 
        : ExprNode(lexer), value_(value) {}
    
    std::string toString() const override {
        return "LiteralExprNode(" + value_ + ") at line " + std::to_string(getLineNumber()) 
               + ", column " + std::to_string(getColumnNumber());
    }
    
    const std::string& getValue() const { return value_; }

private:
    std::string value_;
};

// 标识符表达式节点类
class IdentExprNode : public ExprNode {
public:
    IdentExprNode(std::shared_ptr<mycompiler::Lexer> lexer, const std::string& name) 
        : ExprNode(lexer), name_(name) {}
    
    std::string toString() const override {
        return "IdentExprNode(" + name_ + ") at line " + std::to_string(getLineNumber()) 
               + ", column " + std::to_string(getColumnNumber());
    }
    
    const std::string& getName() const { return name_; }

private:
    std::string name_;
};

// 二元表达式节点类
class BinaryExprNode : public ExprNode {
public:
    BinaryExprNode(std::shared_ptr<mycompiler::Lexer> lexer, 
                  std::shared_ptr<ExprNode> left,
                  const std::string& op,
                  std::shared_ptr<ExprNode> right) 
        : ExprNode(lexer), op_(op) {
        addChild(left);
        addChild(right);
    }
    
    std::string toString() const override {
        return "BinaryExprNode(" + op_ + ") at line " + std::to_string(getLineNumber()) 
               + ", column " + std::to_string(getColumnNumber());
    }
    
    std::shared_ptr<ExprNode> getLeft() const { 
        return std::static_pointer_cast<ExprNode>(getChildren()[0]); 
    }
    
    std::shared_ptr<ExprNode> getRight() const { 
        return std::static_pointer_cast<ExprNode>(getChildren()[1]); 
    }
    
    const std::string& getOperator() const { return op_; }

private:
    std::string op_;
};

// 语句节点类
class StatNode : public BaseASTNode {
public:
    StatNode(std::shared_ptr<mycompiler::Lexer> lexer) : BaseASTNode(lexer) {}
    
    std::string toString() const override {
        return "StatNode at line " + std::to_string(getLineNumber()) 
               + ", column " + std::to_string(getColumnNumber());
    }
};

// 块语句节点类
class BlockStatNode : public StatNode {
public:
    BlockStatNode(std::shared_ptr<mycompiler::Lexer> lexer) : StatNode(lexer) {}
    
    std::string toString() const override {
        return "BlockStatNode at line " + std::to_string(getLineNumber()) 
               + ", column " + std::to_string(getColumnNumber());
    }
    
    void addStatement(std::shared_ptr<StatNode> statement) {
        addChild(statement);
    }
    
    const std::vector<std::shared_ptr<BaseASTNode>>& getStatements() const {
        return getChildren();
    }
};

// 返回语句节点类
class ReturnStatNode : public StatNode {
public:
    ReturnStatNode(std::shared_ptr<mycompiler::Lexer> lexer, std::shared_ptr<ExprNode> expr = nullptr) 
        : StatNode(lexer) {
        if (expr) {
            addChild(expr);
        }
    }
    
    std::string toString() const override {
        return "ReturnStatNode at line " + std::to_string(getLineNumber()) 
               + ", column " + std::to_string(getColumnNumber());
    }
    
    std::shared_ptr<ExprNode> getExpression() const { 
        return getChildren().empty() ? nullptr : std::static_pointer_cast<ExprNode>(getChildren()[0]); 
    }
};

// 声明节点类
class DeclNode : public BaseASTNode {
public:
    DeclNode(std::shared_ptr<mycompiler::Lexer> lexer) : BaseASTNode(lexer) {}
    
    std::string toString() const override {
        return "DeclNode at line " + std::to_string(getLineNumber()) 
               + ", column " + std::to_string(getColumnNumber());
    }
};

// 变量声明语句节点类 - 继承自StatNode而不是DeclNode
class VarDeclStatNode : public StatNode {
public:
    VarDeclStatNode(std::shared_ptr<mycompiler::Lexer> lexer, 
                   const std::string& name,
                   std::shared_ptr<ExprNode> initializer = nullptr) 
        : StatNode(lexer), name_(name) {
        if (initializer) {
            addChild(initializer);
        }
    }
    
    std::string toString() const override {
        return "VarDeclStatNode(" + name_ + ") at line " + std::to_string(getLineNumber()) 
               + ", column " + std::to_string(getColumnNumber());
    }
    
    const std::string& getName() const { return name_; }
    
    std::shared_ptr<ExprNode> getInitializer() const { 
        return getChildren().empty() ? nullptr : std::static_pointer_cast<ExprNode>(getChildren()[0]); 
    }

private:
    std::string name_;
};

// 变量声明节点类
class VarDeclNode : public DeclNode {
public:
    VarDeclNode(std::shared_ptr<mycompiler::Lexer> lexer, 
               const std::string& name,
               std::shared_ptr<ExprNode> initializer = nullptr) 
        : DeclNode(lexer), name_(name) {
        if (initializer) {
            addChild(initializer);
        }
    }
    
    std::string toString() const override {
        return "VarDeclNode(" + name_ + ") at line " + std::to_string(getLineNumber()) 
               + ", column " + std::to_string(getColumnNumber());
    }
    
    const std::string& getName() const { return name_; }
    
    std::shared_ptr<ExprNode> getInitializer() const { 
        return getChildren().empty() ? nullptr : std::static_pointer_cast<ExprNode>(getChildren()[0]); 
    }

private:
    std::string name_;
};

// 函数声明节点类
class FuncDeclNode : public DeclNode {
public:
    FuncDeclNode(std::shared_ptr<mycompiler::Lexer> lexer, 
                const std::string& name,
                std::shared_ptr<BlockStatNode> body) 
        : DeclNode(lexer), name_(name) {
        addChild(body);
    }
    
    std::string toString() const override {
        return "FuncDeclNode(" + name_ + ") at line " + std::to_string(getLineNumber()) 
               + ", column " + std::to_string(getColumnNumber());
    }
    
    const std::string& getName() const { return name_; }
    
    std::shared_ptr<BlockStatNode> getBody() const { 
        return std::static_pointer_cast<BlockStatNode>(getChildren()[0]); 
    }
    
    void addParameter(const std::string& param) {
        parameters_.push_back(param);
    }
    
    const std::vector<std::string>& getParameters() const {
        return parameters_;
    }

private:
    std::string name_;
    std::vector<std::string> parameters_;
};

// if语句节点类
class IfStatNode : public StatNode {
public:
    IfStatNode(std::shared_ptr<mycompiler::Lexer> lexer, 
              std::shared_ptr<ExprNode> condition,
              std::shared_ptr<StatNode> thenStat,
              std::shared_ptr<StatNode> elseStat = nullptr) 
        : StatNode(lexer) {
        addChild(condition);
        addChild(thenStat);
        if (elseStat) {
            addChild(elseStat);
        }
    }
    
    std::string toString() const override {
        return "IfStatNode at line " + std::to_string(getLineNumber()) 
               + ", column " + std::to_string(getColumnNumber());
    }
    
    std::shared_ptr<ExprNode> getCondition() const { 
        return std::static_pointer_cast<ExprNode>(getChildren()[0]); 
    }
    
    std::shared_ptr<StatNode> getThenStatement() const { 
        return std::static_pointer_cast<StatNode>(getChildren()[1]); 
    }
    
    std::shared_ptr<StatNode> getElseStatement() const { 
        return getChildren().size() > 2 ? std::static_pointer_cast<StatNode>(getChildren()[2]) : nullptr; 
    }
};

// 测试不同类型的AST节点的行号和列号功能
class ASTNodeTypesPositionTest : public ::testing::Test {
protected:
    void SetUp() override {
        // 创建测试用的代码片段
        singleLineCode = "let x = 5;";
        multiLineCode = "let x = 5;\nlet y = 10;\nlet z = x + y;";
        complexCode = "function add(a, b) {\n  return a + b;\n}\n\nlet result = add(5, 10);";
        ifStatCode = "if (x > 5) {\n  let y = 10;\n  return y;\n} else {\n  return x;\n}";
    }

    std::string singleLineCode;
    std::string multiLineCode;
    std::string complexCode;
    std::string ifStatCode;
    
    // 辅助方法：验证节点的位置
    void verifyNodePosition(const BaseASTNode& node, int expectedLine, int expectedColumn) {
        EXPECT_EQ(node.getLineNumber(), expectedLine);
        EXPECT_EQ(node.getColumnNumber(), expectedColumn);
    }
};

// 测试表达式节点的行号和列号
TEST_F(ASTNodeTypesPositionTest, ExpressionNodes) {
    auto lexer = std::make_shared<mycompiler::Lexer>(multiLineCode);
    
    // 创建字面量表达式节点
    lexer->getNextToken(); // 消费"let"
    lexer->getNextToken(); // 消费"x"
    lexer->getNextToken(); // 消费"="
    auto literalNode = std::make_shared<LiteralExprNode>(lexer, "5");
    
    // 创建标识符表达式节点
    lexer->getNextToken(); // 消费"5"
    lexer->getNextToken(); // 消费";"
    lexer->getNextToken(); // 消费"let"
    lexer->getNextToken(); // 消费"y"
    auto identNode = std::make_shared<IdentExprNode>(lexer, "y");
    
    // 创建二元表达式节点
    lexer->getNextToken(); // 消费"="
    lexer->getNextToken(); // 消费"10"
    lexer->getNextToken(); // 消费";"
    lexer->getNextToken(); // 消费"let"
    lexer->getNextToken(); // 消费"z"
    lexer->getNextToken(); // 消费"="
    lexer->getNextToken(); // 消费"x"
    auto leftNode = std::make_shared<IdentExprNode>(lexer, "x");
    auto leftLine = leftNode->getLineNumber();
    auto leftColumn = leftNode->getColumnNumber();
    
    lexer->getNextToken(); // 消费"+"
    auto opPos = lexer->getCurrentColumn();
    auto opLine = lexer->getCurrentLine();
    
    lexer->getNextToken(); // 消费"y"
    auto rightNode = std::make_shared<IdentExprNode>(lexer, "y");
    auto rightLine = rightNode->getLineNumber();
    auto rightColumn = rightNode->getColumnNumber();
    
    auto binaryNode = std::make_shared<BinaryExprNode>(lexer, leftNode, "+", rightNode);
    binaryNode->setLineNumber(opLine);
    binaryNode->setColumnNumber(opPos);
    
    // 验证节点的位置
    EXPECT_EQ(literalNode->getLineNumber(), 1);
    EXPECT_EQ(identNode->getLineNumber(), 2);
    EXPECT_EQ(binaryNode->getLineNumber(), opLine);
    EXPECT_EQ(binaryNode->getColumnNumber(), opPos);
    
    // 验证二元表达式的子节点位置
    EXPECT_EQ(binaryNode->getLeft()->getLineNumber(), leftLine);
    EXPECT_EQ(binaryNode->getLeft()->getColumnNumber(), leftColumn);
    EXPECT_EQ(binaryNode->getRight()->getLineNumber(), rightLine);
    EXPECT_EQ(binaryNode->getRight()->getColumnNumber(), rightColumn);
}

// 测试语句节点的行号和列号
TEST_F(ASTNodeTypesPositionTest, StatementNodes) {
    auto lexer = std::make_shared<mycompiler::Lexer>(ifStatCode);
    
    // 创建if语句节点
    auto ifPos = lexer->getCurrentColumn();
    auto ifLine = lexer->getCurrentLine();
    
    lexer->getNextToken(); // 消费"if"
    lexer->getNextToken(); // 消费"("
    
    auto condLine = lexer->getCurrentLine();
    auto condCol = lexer->getCurrentColumn();
    auto conditionNode = std::make_shared<BinaryExprNode>(
        lexer,
        std::make_shared<IdentExprNode>(lexer, "x"),
        ">",
        std::make_shared<LiteralExprNode>(lexer, "5")
    );
    conditionNode->setLineNumber(condLine);
    conditionNode->setColumnNumber(condCol);
    
    lexer->getNextToken(); // 消费")"
    lexer->getNextToken(); // 消费"{"
    
    // 创建then块
    auto thenLine = lexer->getCurrentLine();
    auto thenCol = lexer->getCurrentColumn();
    auto thenBlockNode = std::make_shared<BlockStatNode>(lexer);
    thenBlockNode->setLineNumber(thenLine);
    thenBlockNode->setColumnNumber(thenCol);
    
    lexer->getNextToken(); // 消费换行和空格
    
    // 创建变量声明语句
    auto varDeclNode = std::make_shared<VarDeclStatNode>(
        lexer,
        "y",
        std::make_shared<LiteralExprNode>(lexer, "10")
    );
    thenBlockNode->addStatement(varDeclNode);
    
    lexer->getNextToken(); // 消费";"
    lexer->getNextToken(); // 消费换行和空格
    
    // 创建return语句
    auto returnNode = std::make_shared<ReturnStatNode>(
        lexer,
        std::make_shared<IdentExprNode>(lexer, "y")
    );
    thenBlockNode->addStatement(returnNode);
    
    lexer->getNextToken(); // 消费";"
    lexer->getNextToken(); // 消费换行和空格
    lexer->getNextToken(); // 消费"}"
    lexer->getNextToken(); // 消费"else"
    lexer->getNextToken(); // 消费"{"
    
    // 创建else块
    auto elseLine = lexer->getCurrentLine();
    auto elseCol = lexer->getCurrentColumn();
    auto elseBlockNode = std::make_shared<BlockStatNode>(lexer);
    elseBlockNode->setLineNumber(elseLine);
    elseBlockNode->setColumnNumber(elseCol);
    
    lexer->getNextToken(); // 消费换行和空格
    
    // 创建return语句
    auto elseReturnNode = std::make_shared<ReturnStatNode>(
        lexer,
        std::make_shared<IdentExprNode>(lexer, "x")
    );
    elseBlockNode->addStatement(elseReturnNode);
    
    // 创建if语句节点
    auto ifNode = std::make_shared<IfStatNode>(lexer, conditionNode, thenBlockNode, elseBlockNode);
    ifNode->setLineNumber(ifLine);
    ifNode->setColumnNumber(ifPos);
    
    // 验证if语句节点的位置
    EXPECT_EQ(ifNode->getLineNumber(), ifLine);
    EXPECT_EQ(ifNode->getColumnNumber(), ifPos);
    
    // 验证条件表达式的位置
    EXPECT_EQ(ifNode->getCondition()->getLineNumber(), condLine);
    EXPECT_EQ(ifNode->getCondition()->getColumnNumber(), condCol);
    
    // 验证then块的位置
    EXPECT_EQ(ifNode->getThenStatement()->getLineNumber(), thenLine);
    EXPECT_EQ(ifNode->getThenStatement()->getColumnNumber(), thenCol);
    
    // 验证else块的位置
    EXPECT_EQ(ifNode->getElseStatement()->getLineNumber(), elseLine);
    EXPECT_EQ(ifNode->getElseStatement()->getColumnNumber(), elseCol);
}

// 测试声明节点的行号和列号
TEST_F(ASTNodeTypesPositionTest, DeclarationNodes) {
    auto lexer = std::make_shared<mycompiler::Lexer>(complexCode);
    
    // 创建函数声明节点
    auto funcPos = lexer->getCurrentColumn();
    auto funcLine = lexer->getCurrentLine();
    
    lexer->getNextToken(); // 消费"function"
    auto funcNameNode = std::make_shared<IdentExprNode>(lexer, "add");
    lexer->getNextToken(); // 消费"add"
    lexer->getNextToken(); // 消费"("
    lexer->getNextToken(); // 消费"a"
    lexer->getNextToken(); // 消费","
    lexer->getNextToken(); // 消费"b"
    lexer->getNextToken(); // 消费")"
    lexer->getNextToken(); // 消费"{"
    
    // 创建函数体
    auto bodyLine = lexer->getCurrentLine();
    auto bodyCol = lexer->getCurrentColumn();
    auto bodyNode = std::make_shared<BlockStatNode>(lexer);
    bodyNode->setLineNumber(bodyLine);
    bodyNode->setColumnNumber(bodyCol);
    
    lexer->getNextToken(); // 消费换行和空格
    
    // 创建return语句
    auto returnNode = std::make_shared<ReturnStatNode>(
        lexer,
        std::make_shared<BinaryExprNode>(
            lexer,
            std::make_shared<IdentExprNode>(lexer, "a"),
            "+",
            std::make_shared<IdentExprNode>(lexer, "b")
        )
    );
    bodyNode->addStatement(returnNode);
    
    // 创建函数声明节点
    auto funcDeclNode = std::make_shared<FuncDeclNode>(lexer, "add", bodyNode);
    funcDeclNode->addParameter("a");
    funcDeclNode->addParameter("b");
    funcDeclNode->setLineNumber(funcLine);
    funcDeclNode->setColumnNumber(funcPos);
    
    // 验证函数声明节点的位置
    EXPECT_EQ(funcDeclNode->getLineNumber(), funcLine);
    EXPECT_EQ(funcDeclNode->getColumnNumber(), funcPos);
    
    // 验证函数体的位置
    EXPECT_EQ(funcDeclNode->getBody()->getLineNumber(), bodyLine);
    EXPECT_EQ(funcDeclNode->getBody()->getColumnNumber(), bodyCol);
    
    // 跳到变量声明
    for (int i = 0; i < 10; ++i) {
        lexer->getNextToken();
    }
    
    // 创建变量声明节点
    auto varLine = lexer->getCurrentLine();
    auto varCol = lexer->getCurrentColumn();
    auto varDeclNode = std::make_shared<VarDeclNode>(
        lexer,
        "result",
        std::make_shared<BinaryExprNode>(
            lexer,
            std::make_shared<IdentExprNode>(lexer, "add"),
            "()",
            std::make_shared<LiteralExprNode>(lexer, "5, 10")
        )
    );
    
    // 验证变量声明节点的位置
    EXPECT_EQ(varDeclNode->getLineNumber(), varLine);
    EXPECT_EQ(varDeclNode->getColumnNumber(), varCol);
}

// 测试复杂AST树中的位置信息传递
TEST_F(ASTNodeTypesPositionTest, ComplexASTTree) {
    auto lexer = std::make_shared<mycompiler::Lexer>(complexCode);
    
    // 创建一个完整的函数声明AST树
    auto funcDeclNode = std::make_shared<FuncDeclNode>(lexer, "add", std::make_shared<BlockStatNode>(lexer));
    funcDeclNode->setLineNumber(1);
    funcDeclNode->setColumnNumber(1);
    
    auto bodyNode = funcDeclNode->getBody();
    bodyNode->setLineNumber(1);
    bodyNode->setColumnNumber(23);
    
    auto returnNode = std::make_shared<ReturnStatNode>(lexer);
    returnNode->setLineNumber(2);
    returnNode->setColumnNumber(3);
    
    auto binaryNode = std::make_shared<BinaryExprNode>(
        lexer,
        std::make_shared<IdentExprNode>(lexer, "a"),
        "+",
        std::make_shared<IdentExprNode>(lexer, "b")
    );
    binaryNode->setLineNumber(2);
    binaryNode->setColumnNumber(10);
    
    binaryNode->getLeft()->setLineNumber(2);
    binaryNode->getLeft()->setColumnNumber(10);
    
    binaryNode->getRight()->setLineNumber(2);
    binaryNode->getRight()->setColumnNumber(14);
    
    returnNode->addChild(binaryNode);
    bodyNode->addStatement(returnNode);
    
    // 验证整个AST树中各节点的位置
    verifyNodePosition(*funcDeclNode, 1, 1);
    verifyNodePosition(*bodyNode, 1, 23);
    verifyNodePosition(*returnNode, 2, 3);
    verifyNodePosition(*binaryNode, 2, 10);
    verifyNodePosition(*binaryNode->getLeft(), 2, 10);
    verifyNodePosition(*binaryNode->getRight(), 2, 14);
}

// 测试toString方法包含行号和列号
TEST_F(ASTNodeTypesPositionTest, ToStringIncludesPosition) {
    auto lexer = std::make_shared<mycompiler::Lexer>(singleLineCode);
    
    // 创建不同类型的节点
    auto exprNode = std::make_shared<ExprNode>(lexer);
    exprNode->setLineNumber(1);
    exprNode->setColumnNumber(5);
    
    auto literalNode = std::make_shared<LiteralExprNode>(lexer, "42");
    literalNode->setLineNumber(2);
    literalNode->setColumnNumber(10);
    
    auto statNode = std::make_shared<StatNode>(lexer);
    statNode->setLineNumber(3);
    statNode->setColumnNumber(15);
    
    auto declNode = std::make_shared<DeclNode>(lexer);
    declNode->setLineNumber(4);
    declNode->setColumnNumber(20);
    
    // 验证toString方法包含位置信息
    EXPECT_NE(exprNode->toString().find("line 1"), std::string::npos);
    EXPECT_NE(exprNode->toString().find("column 5"), std::string::npos);
    
    EXPECT_NE(literalNode->toString().find("line 2"), std::string::npos);
    EXPECT_NE(literalNode->toString().find("column 10"), std::string::npos);
    
    EXPECT_NE(statNode->toString().find("line 3"), std::string::npos);
    EXPECT_NE(statNode->toString().find("column 15"), std::string::npos);
    
    EXPECT_NE(declNode->toString().find("line 4"), std::string::npos);
    EXPECT_NE(declNode->toString().find("column 20"), std::string::npos);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 