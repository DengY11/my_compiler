# Lexer模块

Lexer（词法分析器）模块是编译器的第一个阶段，负责将源代码字符流转换为有意义的标记（Token）序列。本模块定义了词法分析器及其相关辅助类和函数。

## 主要类和结构

### Lexer类

`Lexer`类是词法分析的核心，负责将输入的源代码转换为Token序列。

#### 构造函数

- `Lexer(const std::string &input)`: 创建一个词法分析器，接收源代码字符串作为输入。

#### 主要方法

- `getNextToken() -> Token`: 获取下一个Token并移动指针。
- `getCurrentToken() const -> Token`: 获取当前Token。
- `getCurrentIndex() const -> std::size_t`: 获取当前索引位置。
- `lookNextChar() -> char`: 查看下一个字符但不移动指针。
- `peekNextToken() -> Token`: 查看下一个Token但不移动指针。
- `printSource() -> void`: 打印源代码。
- `isKeyword(std::string &word) -> bool`: 检查字符串是否为关键字。
- `isOperator(std::string &word) -> bool`: 检查字符串是否为操作符。
- `isSeparator(std::string &word) -> bool`: 检查字符串是否为分隔符。
- `getCurrentLine() const -> std::size_t`: 获取当前行号。
- `getCurrentColumn() const -> std::size_t`: 获取当前列号。

### 位置跟踪功能

Lexer类提供了完整的位置跟踪功能，可以精确记录源代码中的行号和列号：

- 行号从1开始计数，表示当前处理位置在源代码中的行位置。
- 列号从1开始计数，表示当前处理位置在行中的字符位置。

当Lexer处理源代码时，它会自动更新行号和列号，确保每个生成的Token都有正确的位置信息。这对于编译器的错误报告功能至关重要，可以帮助开发者准确定位源代码中的问题。

### 辅助类

#### KeywordPool类

`KeywordPool`类用于存储和查找关键字。

- `KeywordPool()`: 构造函数，初始化关键字池。
- `find(std::string &word) -> bool`: 查找关键字。

#### OperatorPool类

`OperatorPool`类用于存储和查找操作符。

- `OperatorPool()`: 构造函数，初始化操作符池。
- `find(std::string &op) -> bool`: 查找操作符。

#### SeparatorPool类

`SeparatorPool`类用于存储和查找分隔符。

- `SeparatorPool()`: 构造函数，初始化分隔符池。
- `find(std::string &sep) -> bool`: 查找分隔符。

### 辅助函数

- `isConstantNumberType(char ch) -> bool`: 检查字符是否为数字类型（数字或小数点）。
- `isConstantStringType(char ch) -> bool`: 检查字符是否为字符串类型（非空字符）。
- `isIdentType(char ch) -> bool`: 检查字符是否为标识符类型（字母、数字或下划线）。
- `isKeywordType(char ch) -> bool`: 检查字符是否为关键字类型（字母）。
- `isOperatorType(char ch) -> bool`: 检查字符是否为操作符类型。
- `isSeparatorType(char ch) -> bool`: 检查字符是否为分隔符类型。
- `maybeBinaryOperator(char ch) -> bool`: 检查字符是否可能是二元操作符。
- `maybeUnaryOperator(char ch) -> bool`: 检查字符是否可能是一元操作符。
- `separatorCanCombine(std::string &pre, char cur) -> bool`: 检查分隔符是否可以组合。
- `getKeywordTypeFromString(std::string &str) -> KeywordType`: 从字符串获取关键字类型。
- `getOperatorTypeFromString(std::string &str) -> OperatorType`: 从字符串获取操作符类型。

## 支持的Token类型

Lexer模块支持以下类型的Token：

1. **关键字**：如`let`、`if`、`else`、`for`、`return`、`func`、`while`、`break`、`continue`。
2. **标识符**：变量名、函数名等，如`a`、`sum`、`variable_name`。
3. **常量**：整数和浮点数，如`42`、`3.14`。
4. **操作符**：如`+`、`-`、`*`、`/`、`=`、`==`、`!=`、`^`、`++`、`--`。
5. **分隔符**：如`;`、`,`、`(`、`)`、`{`、`}`、`"`、`[`、`]`。
6. **EOF或非法字符**：文件结束或无法识别的字符。

### 已支持的关键词列表

当前Lexer模块支持以下关键词：

| 关键词 | 对应的枚举值 |
|-------|------------|
| `let` | `KeywordType::LET` |
| `if` | `KeywordType::IF` |
| `else` | `KeywordType::ELSE` |
| `for` | `KeywordType::FOR` |
| `return` | `KeywordType::RETURN` |
| `func` | `KeywordType::FUNC` |
| `while` | `KeywordType::WHILE` |
| `break` | `KeywordType::BREAK` |
| `continue` | `KeywordType::CONTINUE` |

### 已支持的操作符列表

当前Lexer模块支持以下操作符：

| 操作符 | 对应的枚举值 |
|-------|------------|
| `+` | `OperatorType::PLUS` |
| `-` | `OperatorType::MINUS` |
| `*` | `OperatorType::MULTIPLY` |
| `/` | `OperatorType::DIVIDE` |
| `=` | `OperatorType::ASSIGN` |
| `==` | `OperatorType::EQUAL` |
| `!=` | `OperatorType::NOT_EQUAL` |
| `^` | `OperatorType::POWER` |
| `++` | `OperatorType::INCREMENT` |
| `--` | `OperatorType::DECREMENT` |

### 已支持的分隔符列表

当前Lexer模块支持以下分隔符：

| 分隔符 | 描述 |
|-------|------|
| `;` | 分号 |
| `,` | 逗号 |
| `(` | 左括号 |
| `)` | 右括号 |
| `{` | 左花括号 |
| `}` | 右花括号 |
| `"` | 双引号 |
| `[` | 左方括号 |
| `]` | 右方括号 |

## 使用示例

```cpp
// 创建一个词法分析器
std::string code = "let a = 1;";
mycompiler::Lexer lexer(code);

// 获取第一个Token
lexer.getNextToken();
auto token = lexer.getCurrentToken();

// 检查Token类型
if (token.getTokenType() == mycompiler::TokenType::KEYWORD) {
    // 处理关键字
}

// 获取下一个Token
lexer.getNextToken();
token = lexer.getCurrentToken();

// 查看下一个Token但不移动指针
auto nextToken = lexer.peekNextToken();

// 获取当前位置信息
auto line = lexer.getCurrentLine();
auto column = lexer.getCurrentColumn();
```

## 如何运行测试

Lexer模块包含多个测试文件，用于验证其功能的正确性。以下是运行测试的步骤：

1. **进入测试目录**：
   ```bash
   cd test/lexer
   ```

2. **创建并进入构建目录**：
   ```bash
   mkdir -p build && cd build
   ```

3. **配置CMake**：
   ```bash
   cmake ..
   ```

4. **编译测试**：
   ```bash
   make
   ```

5. **运行特定测试**：
   - 运行分隔符测试：
     ```bash
     ./TestSeparator
     ```
   - 运行词法分析器调试测试：
     ```bash
     ./TestLexerDebug
     ```
   - 运行词法分析器分隔符测试：
     ```bash
     ./TestLexer
     ```
   - 运行全面测试：
     ```bash
     ./TestLexerComprehensive
     ```
   - 运行位置跟踪测试：
     ```bash
     ./TestLexerPosition
     ```

### 测试覆盖范围

Lexer模块的测试覆盖了以下方面：

1. **基本功能测试**：测试Lexer的基本标记化功能，包括关键字、标识符、常量、操作符和分隔符的识别。
2. **位置跟踪测试**：测试Lexer的行号和列号跟踪功能，确保正确跟踪源代码中的位置。
3. **复杂代码测试**：测试Lexer处理复杂代码的能力，包括多行代码、嵌套结构等。
4. **边界情况测试**：测试各种边界情况，如空输入、非法字符等。

所有测试都应该通过，表明Lexer模块的功能正常工作。

## 如何添加新的关键词和符号

### 添加新的关键词

要添加新的关键词，需要修改以下文件：

1. **修改关键词枚举类型**：
   在`include/token/token_type.hpp`中，找到`KeywordType`枚举，添加新的关键词类型：
   ```cpp
   enum class KeywordType {
       // 现有关键词...
       NEW_KEYWORD,
       // 其他关键词...
   };
   ```

2. **更新关键词池**：
   在`src/lexer/lexer.cpp`中，找到`KeywordPool`构造函数，添加新的关键词：
   ```cpp
   KeywordPool::KeywordPool() {
       // 现有关键词...
       keywords_.insert("new_keyword");
       // 其他关键词...
   }
   ```

3. **添加关键词类型映射**：
   在`src/lexer/lexer_helper_functions.cpp`中，找到`getKeywordTypeFromString`函数，添加新的关键词映射：
   ```cpp
   auto getKeywordTypeFromString(std::string &str) -> KeywordType {
       // 现有映射...
       if (str == "new_keyword") return KeywordType::NEW_KEYWORD;
       // 其他映射...
   }
   ```

### 添加新的操作符

要添加新的操作符，需要修改以下文件：

1. **修改操作符枚举类型**：
   在`include/token/token_type.hpp`中，找到`OperatorType`枚举，添加新的操作符类型：
   ```cpp
   enum class OperatorType {
       // 现有操作符...
       NEW_OPERATOR,
       // 其他操作符...
   };
   ```

2. **更新操作符池**：
   在`src/lexer/lexer.cpp`中，找到`OperatorPool`构造函数，添加新的操作符：
   ```cpp
   OperatorPool::OperatorPool() {
       // 现有操作符...
       operators_.insert("@");  // 新操作符
       // 其他操作符...
   }
   ```

3. **添加操作符类型映射**：
   在`src/lexer/lexer_helper_functions.cpp`中，找到`getOperatorTypeFromString`函数，添加新的操作符映射：
   ```cpp
   auto getOperatorTypeFromString(std::string &str) -> OperatorType {
       // 现有映射...
       if (str == "@") return OperatorType::NEW_OPERATOR;
       // 其他映射...
   }
   ```

4. **更新操作符类型检查**：
   在`src/lexer/lexer_helper_functions.cpp`中，找到`isOperatorType`函数，确保新的操作符字符被识别：
   ```cpp
   auto isOperatorType(char ch) -> bool {
       // 现有检查...
       return ch == '+' || ch == '-' || /* ... */ || ch == '@';
   }
   ```

5. **更新操作符优先级**：
   如果需要，在`src/token/token_helper_functions.cpp`中，找到`getOperatorPriority`函数，为新的操作符添加优先级：
   ```cpp
   auto getOperatorPriority(const Token &token) -> int {
       // 现有优先级...
       if (token.getOperatorType() == OperatorType::NEW_OPERATOR) return X; // X是优先级值
       // 其他优先级...
   }
   ```

## 性能考虑

Lexer模块的设计考虑了性能因素：

1. **高效的字符处理**：使用直接的字符比较和简单的状态机，避免复杂的正则表达式匹配。
2. **最小化内存分配**：尽可能重用字符串和其他对象，减少内存分配和释放的开销。
3. **预先计算的查找表**：使用预先填充的关键字、操作符和分隔符池，加速查找过程。

这些优化确保了Lexer模块在处理大型源代码文件时仍然保持高效。 