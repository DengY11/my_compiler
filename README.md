# 现代C++编译器项目

这是一个使用现代C++（C++20）开发的编译器项目，旨在实现一个完整的编译器前端和后端。目前，项目已完成词法分析和部分语法分析功能，并正在进行语法分析与语义分析的分离工作。

## 项目结构

```
my_compiler/
├── include/                 # 头文件目录
│   ├── token/               # Token模块头文件
│   ├── lexer/               # 词法分析器模块头文件
│   ├── ast_node/            # 抽象语法树节点模块头文件
│   │   ├── expr_node/       # 表达式节点
│   │   ├── stat_node/       # 语句节点
│   │   ├── decl_node/       # 声明节点
│   │   └── terminal_symbols/ # 终结符节点
├── src/                     # 源文件目录
│   ├── token/               # Token模块实现
│   ├── lexer/               # 词法分析器模块实现
│   ├── ast_node/            # 抽象语法树节点模块实现
│   │   ├── expr_node/       # 表达式节点实现
│   │   ├── stat_node/       # 语句节点实现
│   │   ├── decl_node/       # 声明节点实现
│   │   └── terminal_symbols/ # 终结符节点实现
├── test/                    # 测试目录
│   ├── token/               # Token模块测试
│   ├── lexer/               # 词法分析器模块测试
│   ├── ast_node/            # 抽象语法树节点模块测试
│   └── file_reader/         # 文件读取器模块测试
├── CMakeLists.txt           # 主CMake配置文件
└── README.md                # 项目说明文件
```

## 已完成的模块

### 1. 文件读取器 (FileReader)

文件读取器模块负责从文件或字符串中读取源代码，并提供基本的字符访问功能。主要特性包括：

- 支持从文件或字符串读取源代码
- 提供行号和列号跟踪功能
- 支持前瞻（lookahead）操作，便于词法分析

### 2. 标记 (Token)

Token模块定义了编译器识别的各种标记类型，是词法分析的基础。主要特性包括：

- 支持多种标记类型：关键字、标识符、常量、操作符、分隔符等
- 提供完整的位置跟踪功能（行号和列号）
- 支持标记类型的检查和转换
- 实现了拷贝和移动语义

详细信息请参阅 [Token模块README](include/token/README.md)。

### 3. 词法分析器 (Lexer)

词法分析器模块负责将源代码转换为标记序列，是编译器的第一个处理阶段。主要特性包括：

- 支持识别所有定义的标记类型
- 提供精确的行号和列号跟踪
- 支持前瞻操作，便于语法分析
- 高效的字符处理和标记生成

详细信息请参阅 [Lexer模块README](include/lexer/README.md)。

### 4. 抽象语法树节点 (AST Node)

抽象语法树节点模块定义了表示程序结构的各种节点类型，是语法分析的核心。主要特性包括：

- 支持多种节点类型：表达式、语句、声明等
- 提供完整的位置跟踪功能（行号和列号）
- 支持节点之间的层次关系和访问
- 实现了基本的节点操作和遍历

详细信息请参阅 [AST Node模块README](include/ast_node/README.md)。

## 测试覆盖情况

项目采用Google Test框架进行单元测试和集成测试，确保各模块的正确性和稳定性。

### 文件读取器测试

- 基本读取功能测试
- 行号和列号跟踪测试
- 边界情况测试（空文件、大文件等）

### Token测试

- 基本功能测试：创建和访问各种类型的Token
- 位置跟踪测试：验证行号和列号的正确性
- 拷贝和移动语义测试
- 边界情况测试

### 词法分析器测试

- 基本标记化功能测试
- 位置跟踪测试
- 复杂代码测试
- 边界情况测试

### 抽象语法树节点测试

- 基本节点功能测试
- 位置跟踪测试
- 节点关系和访问测试
- 复杂树结构测试

## 如何构建和运行

### 构建项目

```bash
mkdir -p build && cd build
cmake ..
make
```

### 运行测试

```bash
# 运行所有测试
make test

# 运行特定模块的测试
cd test/token/build
cmake ..
make
./TestToken

cd test/lexer/build
cmake ..
make
./TestLexer

cd test/ast_node/build
cmake ..
make
./TestBasicNode
```

## 未来计划

1. **完成语法分析**：实现完整的语法分析器，支持所有语言结构。
2. **实现语义分析**：添加类型检查、符号表和作用域分析。
3. **中间代码生成**：实现从AST到中间表示（IR）的转换。
4. **代码优化**：添加基本的优化pass。
5. **目标代码生成**：实现从IR到目标平台机器码的生成。

## 贡献指南

欢迎贡献代码、报告问题或提出改进建议。请遵循以下步骤：

1. Fork项目仓库
2. 创建特性分支 (`git checkout -b feature/amazing-feature`)
3. 提交更改 (`git commit -m 'Add some amazing feature'`)
4. 推送到分支 (`git push origin feature/amazing-feature`)
5. 创建Pull Request

## 许可证

本项目采用MIT许可证 - 详情请参阅 [LICENSE](LICENSE) 文件。
