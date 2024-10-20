# 三种节点

## declaration node

### function declaration

- return type
- function name
- body: statement 和 declaration  的集合

### lambda declaration

- return type
- body

### variable declaration

- type
- identifier
- initial value: expression

---

## statement node

### return statement

- identifier

### expression statement

- expression

### if statement

- condition
- then body
- else body

### while statement

- condition
- body

### for statement

- initialization
- condition
- increment
- body

### break statement

- optional label

### continue statement

- optional label

### block statement

- a set of statement and declaration

### switch statement

- expression
- case clauses
- default clause

---

## expression node

### binary expression

- operator ：+ -
- left
- right

### unary expression

- operator: ++ --
- operand: 操作数(可以是变量或者另一个表达式)

### literal expression

- value
- type

### identifier expression

- name

### function call expression

- function name
- arguments

### grouping expression

- expression:被括号包围的表达式

### ternary expression

- condition
- true expression
- false expression
