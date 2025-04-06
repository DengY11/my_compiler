# Token模块

Token（标记）模块是编译器的基础组件，负责定义和处理源代码中的各种标记类型。本模块提供了Token类及其相关的类型定义和辅助函数。

## 主要类和结构

### Token类

`Token`类表示源代码中的一个标记单元，可以是关键字、标识符、常量、操作符、分隔符等。

#### 构造函数

- `Token()`: 默认构造函数，创建一个空Token。行号和列号默认设置为1。
- `Token(TokenType type, std::string value, std::size_t line, std::size_t column)`: 创建一个指定类型、值、行号和列号的Token。
- `Token(TokenType type, KeywordType keywordType, std::string value, std::size_t line, std::size_t column)`: 创建一个关键字类型的Token，同时指定行号和列号。
- `Token(TokenType type, OperatorType operatorType, std::string value, std::size_t line, std::size_t column)`: 创建一个操作符类型的Token，同时指定行号和列号。
- `Token(TokenType type, EofOrIllegalType eofOrIllegalType, std::string value, std::size_t line, std::size_t column)`: 创建一个EOF或非法类型的Token，同时指定行号和列号。
- `Token(const Token& other)`: 拷贝构造函数，创建一个与other相同的Token，包括类型、值以及行号和列号信息。
- `Token(Token&& other) noexcept`: 移动构造函数，从other移动资源创建一个新的Token，包括类型、值以及行号和列号信息。确保高效处理大数据量时的性能。

#### 主要方法

- `getTokenType() const -> TokenType`: 获取Token的类型。
- `getValue() const -> std::string`: 获取Token的值。
- `getLine() const -> std::size_t`: 获取Token的行号，表示Token在源代码中的行位置。
- `getColumn() const -> std::size_t`: 获取Token的列号，表示Token在行中的字符位置。
- `getKeywordType() const -> KeywordType`: 获取关键字类型（如果Token是关键字）。
- `getOperatorType() const -> OperatorType`: 获取操作符类型（如果Token是操作符）。
- `getEofOrIllegalType() const -> EofOrIllegalType`: 获取EOF或非法类型（如果Token是EOF或非法字符）。
- `printInfo() const -> void`: 打印Token的信息，包括类型、值和位置信息。
- `operator=(const Token& other) -> Token&`: 赋值操作符，将other的值赋给当前Token，包括行号和列号信息。返回对当前对象的引用，支持链式赋值。
- `operator=(Token&& other) noexcept -> Token&`: 移动赋值操作符，将other的资源移动到当前Token，包括行号和列号信息。高效处理大数据量，避免不必要的复制。返回对当前对象的引用，支持链式赋值。

### 位置跟踪功能

Token类提供了完整的位置跟踪功能，可以精确记录每个标记在源代码中的行号和列号：

- 行号从1开始计数，表示标记在源代码中的行位置。
- 列号从1开始计数，表示标记在行中的字符位置。

位置跟踪功能对于以下方面至关重要：

1. **精确的错误报告**：当编译器遇到错误时，可以准确指出错误发生的位置，包括具体的行号和列号，使开发者能够快速定位问题。例如："语法错误：第15行，第23列，缺少分号"。
2. **源代码映射**：在调试和优化过程中，可以将生成的代码映射回原始源代码位置，便于理解代码的执行流程和性能瓶颈。
3. **IDE集成**：支持IDE中的代码导航、自动补全和语法高亮等功能，提升开发体验。
4. **代码分析工具**：为代码分析工具提供准确的位置信息，便于静态分析和代码审查，如unused variable警告可以精确指向变量定义位置。
5. **断点调试**：支持在源代码的特定位置设置断点，便于调试复杂程序。

**设计考虑**：
- 位置信息在Token创建时设置，并在Token的整个生命周期中保持不变。
- 即使Token被复制或移动，其位置信息也会被正确地保留，这确保了在编译器流水线的各个阶段都能追踪到Token的原始位置。
- 对于跨多行的结构（如多行字符串、多行注释），Token的行号表示结构的起始行，列号表示在该行的起始位置。
- 在处理包含Unicode字符或制表符的源码时，列号计算会适当调整，以确保准确的位置表示。

**实现细节**：
- 位置信息使用`std::size_t`类型存储，支持处理极大的源文件。
- 位置信息作为Token对象的私有成员，通过getter方法访问，确保封装性。
- 在处理诸如宏扩展等复杂情况时，会保留原始位置信息，便于错误追踪。

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
| `CASE` | `case` |
| `DEFAULT` | `default` |
| `SWITCH` | `switch` |

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
| `LESS_THAN` | `<` |
| `GREATER_THAN` | `>` |
| `LESS_EQUAL` | `<=` |
| `GREATER_EQUAL` | `>=` |

#### EofOrIllegalType

`EofOrIllegalType`枚举定义了EOF和非法字符的类型：

- `EOF_TYPE`: 文件结束
- `ILLEGAL_TYPE`: 非法字符

## 工厂函数

Token模块提供了一系列工厂函数，用于创建不同类型的Token：

- `makeConstantToken(std::string value, std::size_t line, std::size_t column) -> Token`: 创建一个常量Token，指定行号和列号。
- `makeKeywordToken(KeywordType type, std::string value, std::size_t line, std::size_t column) -> Token`: 创建一个关键字Token，指定行号和列号。
- `makeCommentToken(std::string value, std::size_t line, std::size_t column) -> Token`: 创建一个注释Token，指定行号和列号。
- `makeIdentifierToken(std::string value, std::size_t line, std::size_t column) -> Token`: 创建一个标识符Token，指定行号和列号。
- `makeOperatorToken(OperatorType type, std::string value, std::size_t line, std::size_t column) -> Token`: 创建一个操作符Token，指定行号和列号。
- `makeEofOrIllegalToken(EofOrIllegalType type, std::string value, std::size_t line, std::size_t column) -> Token`: 创建一个EOF或非法字符Token，指定行号和列号。
- `makeSeparatorToken(std::string value, std::size_t line, std::size_t column) -> Token`: 创建一个分隔符Token，指定行号和列号。
- `makePreprocessorToken(std::string value, std::size_t line, std::size_t column) -> Token`: 创建一个预处理指令Token，指定行号和列号。

每个工厂函数都接受行号和列号参数，确保创建的Token具有正确的位置信息。这些函数简化了Token的创建过程，减少了重复代码，并确保位置信息始终被正确设置。

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
- `getTokenPosition(const Token &token) -> std::pair<std::size_t, std::size_t>`: 获取Token的位置信息（行号和列号）作为一个pair。
- `formatTokenPosition(const Token &token) -> std::string`: 格式化Token的位置信息为字符串，如"行15，列23"。

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

// 获取Token的位置信息
auto line = constantToken.getLine(); // 1
auto column = constantToken.getColumn(); // 16

// 示例：使用位置信息进行错误报告
if (/* 检测到错误 */) {
    std::cerr << "Error at line " << line << ", column " << column
              << ": Invalid constant value\n";
}

// 示例：使用拷贝构造函数和移动构造函数
Token copiedToken = constantToken; // 拷贝构造
Token movedToken = std::move(copiedToken); // 移动构造

// 位置信息会被正确保留
assert(movedToken.getLine() == 1);
assert(movedToken.getColumn() == 16);

// 示例：使用位置信息处理跨行代码
// 假设有一个多行字符串
std::string multilineStr = R"(
line1
line2
line3
)";

// 使用词法分析器处理多行字符串时，它会追踪行号和列号
// 当处理到"line3"时，Token会记录正确的行号（4）和列号（1）
```

## 测试

Token模块有专门的测试套件，覆盖了各种Token类型的创建、处理和位置跟踪功能。测试包括：

1. **基本功能测试**：测试Token的基本创建和访问功能。
   - 测试各种类型Token的创建
   - 测试Token属性的获取和设置
   - 测试Token类型的检查和转换

2. **位置跟踪测试**：测试Token的行号和列号功能，确保正确跟踪源代码中的位置。
   - 测试不同位置的Token创建
   - 测试行号和列号的获取
   - 测试位置信息在Token操作（如复制、移动）中的保留
   - 测试位置信息在错误报告中的使用

3. **全面位置测试**：测试更复杂的位置跟踪场景。
   - 测试极端值（如非常大的行号和列号）
   - 测试跨行的Token位置处理
   - 测试不同类型Token的位置一致性
   - 测试位置信息在复杂表达式中的传播
   - 测试Unicode字符和制表符对列号计算的影响

4. **拷贝和移动语义测试**：测试Token的拷贝构造、移动构造和赋值操作。
   - 测试拷贝构造函数和拷贝赋值操作符，验证所有属性（包括位置信息）的正确复制
   - 测试移动构造函数和移动赋值操作符，确保资源的有效移动和位置信息的保留
   - 测试链式赋值和复合赋值情况下的行为
   - 测试与标准库容器（如vector和map）的兼容性

5. **边界情况测试**：测试各种边界情况，如空值、极大值等。
   - 测试空字符串值的Token
   - 测试极大行号和列号
   - 测试非法字符和EOF类型的Token
   - 测试在资源受限环境下的行为

要运行Token模块的测试，请执行以下命令：

```bash
cd test/token
mkdir -p build && cd build
cmake ..
make
./TestToken  # 基本测试
./TestTokenPosition  # 位置测试
./TestTokenPositionComprehensive  # 全面的位置测试
```

所有测试都应该通过，表明Token模块的功能正常工作。测试报告会显示详细的测试结果，包括任何失败的测试和相关的错误信息。

## 性能考虑

Token模块的设计考虑了性能因素：

1. **最小化内存使用**：Token类的设计尽量减少内存占用，只存储必要的信息。对于固定的枚举类型，使用紧凑的整数表示而不是字符串，节省内存。
2. **高效的拷贝和移动操作**：实现了高效的拷贝和移动语义，减少不必要的内存分配。特别是移动构造和移动赋值操作符对于处理大型源代码文件时的性能至关重要。
3. **避免虚函数**：Token类不使用虚函数，减少运行时开销和内存占用。
4. **工厂函数优化**：工厂函数设计为内联函数，减少函数调用开销，提高编译时优化机会。
5. **缓存友好**：数据成员的排列考虑了缓存行对齐，提高CPU缓存的使用效率。
6. **预分配内存**：在处理大型源文件时，可以预先分配足够的内存，减少动态分配次数。

这些优化确保了Token模块在处理大型源代码文件时仍然保持高效，能够满足现代编译器的性能要求。

## 已知问题和限制

- 当前的行列跟踪不处理Unicode字符的宽度问题，在处理某些非ASCII字符时可能导致列号不准确。
- 极大的源代码文件可能导致行号和列号超出`std::size_t`的范围（虽然实际上几乎不可能发生）。
- 词法分析阶段的错误可能会导致随后的位置信息不准确。

## 未来改进计划

1. 添加对Unicode字符宽度的正确处理，以提高列号的准确性。
2. 实现更高级的错误恢复机制，保证即使在遇到词法错误后仍能维持准确的位置跟踪。
3. 优化内存使用，特别是对于大型项目中的大量Token对象。
4. 增强与IDE工具的集成能力，提供更丰富的源代码映射信息。 