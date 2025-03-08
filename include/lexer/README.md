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

### 添加新的分隔符

要添加新的分隔符，需要修改以下文件：

1. **更新分隔符池**：
   在`src/lexer/lexer.cpp`中，找到`SeparatorPool`构造函数，添加新的分隔符：
   ```cpp
   SeparatorPool::SeparatorPool() {
       // 现有分隔符...
       separators_.insert("$");  // 新分隔符
       // 其他分隔符...
   }
   ```

2. **更新分隔符类型检查**：
   在`src/lexer/lexer_helper_functions.cpp`中，找到`isSeparatorType`函数，确保新的分隔符字符被识别：
   ```cpp
   auto isSeparatorType(char ch) -> bool {
       // 现有检查...
       return ch == ';' || ch == ',' || /* ... */ || ch == '$';
   }
   ```

## 错误处理

Lexer模块会在遇到以下情况时抛出异常：

1. 数字中包含多个小数点。
2. 遇到非法操作符。
3. 遇到非法分隔符。

## 测试

Lexer模块包含全面的测试，覆盖了以下方面：

1. 数字常量的词法分析。
2. 标识符的词法分析。
3. 关键字的词法分析。
4. 操作符的词法分析。
5. 分隔符的词法分析。
6. 复杂表达式的词法分析。
7. 辅助函数的测试。
8. 错误处理的测试。 