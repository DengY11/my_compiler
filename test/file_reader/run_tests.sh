#!/bin/bash

# 创建构建目录
mkdir -p build
cd build

# 配置CMake
cmake ..

# 编译测试
make

# 运行测试
./TestFileReader 