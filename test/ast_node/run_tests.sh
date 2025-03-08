#!/bin/bash

# 创建构建目录
mkdir -p build
cd build

# 配置CMake
cmake ..

# 编译测试
make

# 运行测试
echo "运行基本节点测试..."
./TestBasicNode

echo "运行表达式节点测试..."
./TestExprNode

echo "运行二元表达式节点测试..."
./TestBinaryExprNode

echo "运行声明节点测试..."
./TestDeclNode

echo "运行函数声明节点测试..."
./TestFuncDeclNode

echo "运行语句节点测试..."
./TestStatNode

echo "运行if语句节点测试..."
./TestIfStatNode

echo "运行综合测试..."
./TestASTNodeComprehensive

echo "所有测试完成！" 