cmake_minimum_required(VERSION 3.10)
project(ASTNodeTest)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 包含头文件路径
include_directories(${CMAKE_SOURCE_DIR}/../../include)

# 使用系统已安装的Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# 添加 token 模块的源文件
file(GLOB TOKEN_SRC_FILES "${CMAKE_SOURCE_DIR}/../../src/token/*.cpp")

# 添加 lexer 模块的源文件
file(GLOB LEXER_SRC_FILES "${CMAKE_SOURCE_DIR}/../../src/lexer/*.cpp")

# 添加 ast_node 模块的源文件
file(GLOB AST_NODE_SRC_FILES "${CMAKE_SOURCE_DIR}/../../src/ast_node/*.cpp")
file(GLOB AST_NODE_EXPR_SRC_FILES "${CMAKE_SOURCE_DIR}/../../src/ast_node/expr_node/*.cpp")
file(GLOB AST_NODE_DECL_SRC_FILES "${CMAKE_SOURCE_DIR}/../../src/ast_node/decl_node/*.cpp")
file(GLOB AST_NODE_STAT_SRC_FILES "${CMAKE_SOURCE_DIR}/../../src/ast_node/stat_node/*.cpp")
file(GLOB AST_NODE_TERMINAL_SRC_FILES "${CMAKE_SOURCE_DIR}/../../src/ast_node/terminal_symbols/*.cpp")

# 创建token静态库
add_library(TokenLib STATIC ${TOKEN_SRC_FILES})

# 创建lexer静态库
add_library(LexerLib STATIC ${LEXER_SRC_FILES})
target_link_libraries(LexerLib TokenLib)

# 创建ast_node静态库
add_library(ASTNodeLib STATIC 
    ${AST_NODE_SRC_FILES}
    ${AST_NODE_EXPR_SRC_FILES}
    ${AST_NODE_DECL_SRC_FILES}
    ${AST_NODE_STAT_SRC_FILES}
    ${AST_NODE_TERMINAL_SRC_FILES}
)
target_link_libraries(ASTNodeLib LexerLib TokenLib)

# 创建基本节点测试
add_executable(TestBasicNode test_basic_node.cpp)
target_link_libraries(TestBasicNode ASTNodeLib LexerLib TokenLib ${GTEST_BOTH_LIBRARIES} pthread)

# 创建表达式节点测试
add_executable(TestExprNode test_expr_node.cpp)
target_link_libraries(TestExprNode ASTNodeLib LexerLib TokenLib ${GTEST_BOTH_LIBRARIES} pthread)

# 创建二元表达式节点测试
add_executable(TestBinaryExprNode test_binary_expr_node.cpp)
target_link_libraries(TestBinaryExprNode ASTNodeLib LexerLib TokenLib ${GTEST_BOTH_LIBRARIES} pthread)

# 创建声明节点测试
add_executable(TestDeclNode test_decl_node.cpp)
target_link_libraries(TestDeclNode ASTNodeLib LexerLib TokenLib ${GTEST_BOTH_LIBRARIES} pthread)

# 创建函数声明节点测试
add_executable(TestFuncDeclNode test_func_decl_node.cpp)
target_link_libraries(TestFuncDeclNode ASTNodeLib LexerLib TokenLib ${GTEST_BOTH_LIBRARIES} pthread)

# 创建语句节点测试
add_executable(TestStatNode test_stat_node.cpp)
target_link_libraries(TestStatNode ASTNodeLib LexerLib TokenLib ${GTEST_BOTH_LIBRARIES} pthread)

# 创建if语句节点测试
add_executable(TestIfStatNode test_if_stat_node.cpp)
target_link_libraries(TestIfStatNode ASTNodeLib LexerLib TokenLib ${GTEST_BOTH_LIBRARIES} pthread)

# 创建综合测试
add_executable(TestASTNodeComprehensive test_ast_node_comprehensive.cpp)
target_link_libraries(TestASTNodeComprehensive ASTNodeLib LexerLib TokenLib ${GTEST_BOTH_LIBRARIES} pthread) 