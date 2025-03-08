#ifndef TOKEN_TYPE_HPP
#define TOKEN_TYPE_HPP

namespace mycompiler {

// Token类型枚举
enum class TokenType {
  ILLEGAL_OR_EOF,  // 非法字符或文件结束
  IDENT,           // 标识符，如变量名、函数名
  CONSTANT,        // 常量，如数字、字符串
  KEYWORD,         // 关键字，如if、else、for
  OPERATOR,        // 操作符，如+、-、*、/
  SEPARATOR,       // 分隔符，如,、;、[、{
  COMMENT,         // 注释
  PREPROCESSOR     // 预处理器指令
};

} // namespace mycompiler

#endif
