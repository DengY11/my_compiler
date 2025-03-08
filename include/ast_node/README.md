# AST节点模块

抽象语法树（Abstract Syntax Tree，AST）节点模块是编译器的核心组件，负责将词法分析器生成的标记序列转换为结构化的语法树。本模块定义了各种类型的AST节点及其相关操作。

## 主要类和结构

### 基本节点

#### BasicNode

`BasicNode`是所有AST节点的基类，提供了基本的节点功能和接口：

- 添加子节点
- 打印节点信息
- 获取节点类型
- 获取子节点列表
- 解析标记序列

#### RootNode

`RootNode`是AST的根节点，表示整个程序的入口点：

- 包含所有顶级声明和语句
- 管理程序的整体结构
- 提供对顶级声明和语句的访问

### 表达式节点

表达式节点表示程序中的表达式，包括：

#### BinaryExprNode

表示二元操作，如加法、减法等：

- 包含左操作数、操作符和右操作数
- 支持各种二元操作符
- 提供类型推断功能

#### UnaryExprNode

表示一元操作，如取反、自增等：

- 包含操作符和操作数
- 支持前缀和后缀一元操作符

#### LiteralExprNode

表示字面量表达式，如数字、字符串等：

- 存储字面量的值和类型
- 支持不同类型的字面量

#### IdentifierExprNode

表示标识符表达式，如变量名：

- 存储标识符的名称
- 提供对标识符的访问

#### GroupExprNode

表示被括号包围的表达式：

- 包含内部表达式
- 处理括号的优先级

#### TenaryExprNode

表示三元条件表达式：

- 包含条件、真值表达式和假值表达式
- 提供条件执行的语义

#### FunctionCalledReturnValueExprNode

表示函数调用表达式：

- 包含函数名和参数列表
- 处理函数调用的语义

### 声明节点

声明节点表示程序中的声明，包括：

#### FuncDeclNode

表示函数声明：

- 包含函数名、参数列表和函数体
- 管理函数的返回类型
- 提供对函数组件的访问

#### VariableDeclNode

表示变量声明：

- 包含变量名、类型和初始值
- 管理变量的作用域和生命周期

#### LambdaDeclNode

表示Lambda表达式声明：

- 包含参数列表和函数体
- 支持闭包语义

### 语句节点

语句节点表示程序中的语句，包括：

#### IfStatNode

表示if条件语句：

- 包含条件表达式、if块和可选的else块
- 提供条件执行的语义
- 支持嵌套条件结构

#### WhileStatNode

表示while循环语句：

- 包含条件表达式和循环体
- 提供循环执行的语义

#### ForStatNode

表示for循环语句：

- 包含初始化、条件、增量和循环体
- 提供复杂循环结构的语义

#### ReturnStatNode

表示return语句：

- 包含返回值表达式
- 处理函数返回的语义

#### BreakStatNode

表示break语句：

- 处理循环和switch语句的跳出

#### ContinueStatNode

表示continue语句：

- 处理循环的继续执行

#### BlockStatNode

表示块语句：

- 包含一系列语句
- 管理语句的作用域

#### SwitchStatNode

表示switch语句：

- 包含表达式和case子句
- 提供多路分支的语义

### 终端符号

终端符号是AST的叶子节点，直接对应源代码中的标记：

- `TerminalIf`：if关键字
- `TerminalFunc`：func关键字
- `TerminalLet`：let关键字
- `TerminalOperator`：操作符
- `TerminalSeparator`：分隔符
- `TerminalIdentLiteral`：标识符字面量
- `TerminalValueLiteral`：值字面量

## 表达式解析

AST节点模块使用Pratt解析技术来解析表达式：

### PrattParser

`PrattParser`实现了Pratt解析算法：

- 支持前缀和中缀表达式的解析
- 处理不同优先级的操作符
- 提供可扩展的解析框架

## 使用示例

```cpp
// 创建词法分析器
std::string code = "if (x > 0) { return x; } else { return -x; }";
auto lexer = std::make_shared<mycompiler::Lexer>(code);

// 创建根节点
auto root = std::make_shared<mycompiler::RootNode>(lexer);

// 解析代码
root->Parse();

// 访问AST节点
auto statements = root->getStatements();
for (const auto& statement : statements) {
    // 处理语句
    statement->print_info();
}

// 检查特定类型的节点
auto ifStatement = std::dynamic_pointer_cast<mycompiler::IfStatNode>(statements[0]);
if (ifStatement) {
    auto condition = ifStatement->getCondition();
    auto ifBlock = ifStatement->getIfBlock();
    auto elseBlock = ifStatement->getElseBlock();
    
    // 处理条件和块
}
```

## 如何扩展AST节点

### 添加新的表达式节点

1. 创建新的表达式节点类，继承自`ExprNode`
2. 实现`Parse()`方法，从词法分析器中读取标记并构建节点
3. 实现`print_info()`方法，打印节点信息
4. 实现`toString()`方法，返回节点的字符串表示
5. 实现特定于节点类型的方法

### 添加新的语句节点

1. 创建新的语句节点类，继承自`StatNode`
2. 设置适当的`statType_`
3. 实现`Parse()`方法，从词法分析器中读取标记并构建节点
4. 实现`print_info()`方法，打印节点信息
5. 实现`toString()`方法，返回节点的字符串表示
6. 实现`isTerminating()`方法，判断语句是否为终止语句

### 添加新的声明节点

1. 创建新的声明节点类，继承自`DeclNode`
2. 实现`Parse()`方法，从词法分析器中读取标记并构建节点
3. 实现`print_info()`方法，打印节点信息
4. 实现`toString()`方法，返回节点的字符串表示
5. 实现`getName()`和`getType()`方法，返回声明的名称和类型

## 错误处理

AST节点模块在解析过程中会抛出以下异常：

1. 语法错误：当遇到不符合语法规则的标记序列时
2. 类型错误：当表达式的类型不匹配时
3. 未定义错误：当引用未定义的标识符时

## 测试

AST节点模块的测试应该覆盖以下方面：

1. 基本节点的创建和操作
2. 表达式节点的解析和求值
3. 声明节点的解析和语义
4. 语句节点的解析和执行
5. 错误处理和恢复 