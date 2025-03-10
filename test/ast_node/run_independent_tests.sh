#!/bin/bash

# 创建构建目录
mkdir -p build
cd build

# 配置CMake
cmake ..

# 只编译我们刚刚创建的独立节点测试
make TestLiteralExprNode TestIdentExprNode TestVarDeclNode TestBlockStatNode TestReturnStatNode

# 运行独立的AST节点测试
echo "Running LiteralExprNode tests..."
./TestLiteralExprNode

echo "Running IdentifierExprNode tests..."
./TestIdentExprNode

echo "Running VarDeclNode tests..."
./TestVarDeclNode

echo "Running BlockStatNode tests..."
./TestBlockStatNode

echo "Running ReturnStatNode tests..."
./TestReturnStatNode

echo "All independent AST node tests completed." 