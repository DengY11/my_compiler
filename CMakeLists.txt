cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(MyCompiler)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 包含 include 目录中的头文件
include_directories(${PROJECT_SOURCE_DIR}/include)

# 查找 src 文件夹中的所有源文件
file(GLOB_RECURSE SOURCE_FILES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)

# 编译为静态库
add_library(MyCompilerLib STATIC ${SOURCE_FILES})

# 设置测试子目录
add_subdirectory(test/lexer)

set(CMAKE_BUILD_TYPE Debug)

