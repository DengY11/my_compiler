cmake_minimum_required(VERSION 3.10)
project(MyCompiler)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 包含头文件路径
include_directories(include)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 使用系统已安装的Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# 添加 token 模块的源文件
file(GLOB TOKEN_SRC_FILES "src/token/*.cpp")

# 添加 lexer 模块的源文件
file(GLOB LEXER_SRC_FILES "src/lexer/*.cpp")

# 创建共享的token静态库
add_library(TokenLib STATIC ${TOKEN_SRC_FILES})

# 创建共享的lexer静态库
add_library(LexerLib STATIC ${LEXER_SRC_FILES})
target_link_libraries(LexerLib TokenLib)

# 启用测试
enable_testing()

# 添加子目录
add_subdirectory(test/lexer)
add_subdirectory(test/token)
