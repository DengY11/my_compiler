# Token模块

Token（标记）模块是编译器的基础组件，负责定义和处理源代码中的各种标记类型。本模块提供了Token类及其相关的类型定义和辅助函数。

## 主要类和结构

### Token类

`Token`类表示源代码中的一个标记单元，可以是关键字、标识符、常量、操作符、分隔符等。

#### 构造函数

- `Token()`: 默认构造函数，创建一个空Token。
- `Token(TokenType type, std::string value, std::size_t line, std::size_t column)`: 创建一个指定类型、值、行号和列号的Token。
- `Token(TokenType type, KeywordType keywordType, std::string value, std::size_t line, std::size_t column)`: 创建一个关键字类型的Token。
- `Token(TokenType type, OperatorType operatorType, std::string value, std::size_t line, std::size_t column)`: 创建一个操作符类型的Token。
- `Token(TokenType type, EofOrIllegalType eofOrIllegalType, std::string value, std::size_t line, std::size_t column)`: 创建一个EOF或非法类型的Token。

#### 主要方法

- `getTokenType() const -> TokenType`: 获取Token的类型。
- `getValue() const -> std::string`: 获取Token的值。
- `getLine() const -> std::size_t`: 获取Token的行号。
- `getColumn() const -> std::size_t`: 获取Token的列号。
- `getKeywordType() const -> KeywordType`: 获取关键字类型（如果Token是关键字）。
- `getOperatorType() const -> OperatorType`: 获取操作符类型（如果Token是操作符）。
- `getEofOrIllegalType() const -> EofOrIllegalType`: 获取EOF或非法类型（如果Token是EOF或非法字符）。
- `printInfo() const -> void`: 打印Token的信息。

### 枚举类型

#### TokenType

`TokenType`枚举定义了Token的基本类型：

- `KEYWORD`: 关键字
- `IDENT`: 标识符
- `CONSTANT`: 常量
- `OPERATOR`: 操作符
- `SEPARATOR`: 分隔符
- `COMMENT`: 注释
- `PREPROCESSOR`: 预处理指令
- `ILLEGAL_OR_EOF`: 非法字符或文件结束

#### KeywordType

`KeywordType`枚举定义了所有支持的关键字类型：

| 枚举值 | 对应的关键词 |
|-------|------------|
| `LET` | `let` |
| `IF` | `if` |
| `ELSE` | `else` |
| `FOR` | `for` |
| `RETURN` | `return` |
| `FUNC` | `func` |
| `WHILE` | `while` |
| `BREAK` | `break` |
| `CONTINUE` | `continue` |

#### OperatorType

`OperatorType`枚举定义了所有支持的操作符类型：

| 枚举值 | 对应的操作符 |
|-------|------------|
| `PLUS` | `+` |
| `MINUS` | `-` |
| `MULTIPLY` | `*` |
| `DIVIDE` | `/` |
| `ASSIGN` | `=` |
| `EQUAL` | `==` |
| `NOT_EQUAL` | `!=` |
| `POWER` | `^` |
| `INCREMENT` | `++` |
| `DECREMENT` | `--` |

#### EofOrIllegalType

`EofOrIllegalType`枚举定义了EOF和非法字符的类型：

- `EOF_TYPE`: 文件结束
- `ILLEGAL_TYPE`: 非法字符

## 工厂函数

Token模块提供了一系列工厂函数，用于创建不同类型的Token：

- `makeConstantToken(std::string value, std::size_t line, std::size_t column) -> Token`: 创建一个常量Token。
- `makeKeywordToken(KeywordType type, std::string value, std::size_t line, std::size_t column) -> Token`: 创建一个关键字Token。
- `makeCommentToken(std::string value, std::size_t line, std::size_t column) -> Token`: 创建一个注释Token。
- `makeIdentifierToken(std::string value, std::size_t line, std::size_t column) -> Token`: 创建一个标识符Token。
- `makeOperatorToken(OperatorType type, std::string value, std::size_t line, std::size_t column) -> Token`: 创建一个操作符Token。
- `makeEofOrIllegalToken(EofOrIllegalType type, std::string value, std::size_t line, std::size_t column) -> Token`: 创建一个EOF或非法字符Token。
- `makeSeparatorToken(std::string value, std::size_t line, std::size_t column) -> Token`: 创建一个分隔符Token。
- `makePreprocessorToken(std::string value, std::size_t line, std::size_t column) -> Token`: 创建一个预处理指令Token。

## 辅助函数

Token模块提供了一系列辅助函数，用于获取和检查Token的信息：

- `getKeywordTypeFromToken(const Token &token) -> KeywordType`: 从Token获取关键字类型。
- `getOperatorTypeFromToken(const Token &token) -> OperatorType`: 从Token获取操作符类型。
- `getIdentifierValueFromToken(const Token &token) -> std::string`: 从Token获取标识符值。
- `getConstantValueFromToken(const Token &token) -> std::string`: 从Token获取常量值。
- `getSeparatorValueFromToken(const Token &token) -> std::string`: 从Token获取分隔符值。
- `isUnaryOperator(const Token &token) -> bool`: 检查Token是否为一元操作符。
- `isBinaryOperator(const Token &token) -> bool`: 检查Token是否为二元操作符。
- `getOperatorPriority(const Token &token) -> int`: 获取操作符的优先级。

## 如何添加新的Token类型

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

## 使用示例

```cpp
// 创建一个关键字Token
auto keywordToken = mycompiler::makeKeywordToken(
    mycompiler::KeywordType::LET, "let", 1, 1);

// 创建一个标识符Token
auto identToken = mycompiler::makeIdentifierToken("variable", 1, 5);

// 创建一个操作符Token
auto operatorToken = mycompiler::makeOperatorToken(
    mycompiler::OperatorType::ASSIGN, "=", 1, 14);

// 创建一个常量Token
auto constantToken = mycompiler::makeConstantToken("42", 1, 16);

// 获取Token的类型
auto tokenType = keywordToken.getTokenType(); // TokenType::KEYWORD

// 获取关键字类型
auto keywordType = mycompiler::getKeywordTypeFromToken(keywordToken); // KeywordType::LET

// 检查操作符类型
bool isBinary = mycompiler::isBinaryOperator(operatorToken); // true
```

## 测试

Token模块的测试包含在Lexer模块的测试中，覆盖了各种Token类型的创建和处理。要运行测试，请参考Lexer模块的测试说明。 