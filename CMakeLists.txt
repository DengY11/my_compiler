cmake_minimum_required(VERSION 3.10)
project(MyCompiler)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 包含头文件路径
include_directories(include)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 添加 src 目录下的所有源文件
file(GLOB_RECURSE SRC_FILES "src/**/*.cpp")

# 创建静态库
add_library(MyCompilerLib STATIC ${SRC_FILES})

# 添加子目录
add_subdirectory(test/lexer)
add_subdirectory(test/token)
