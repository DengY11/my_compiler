#ifndef LEXER_HELPER_FUNCTIONS_HPP
#define LEXER_HELPER_FUNCTIONS_HPP

#include "lexer/lexer.hpp"
namespace mycompiler {

/**
 * @brief 检查字符是否为数字类型（数字或小数点）
 * @param ch 要检查的字符
 * @return 是否为数字类型
 */
auto isConstantNumberType(char ch) -> bool;

/**
 * @brief 检查字符是否为字符串类型（非空字符）
 * @param ch 要检查的字符
 * @return 是否为字符串类型
 */
auto isConstantStringType(char ch) -> bool;

/**
 * @brief 检查字符是否为标识符类型（字母、数字或下划线）
 * @param ch 要检查的字符
 * @return 是否为标识符类型
 */
auto isIdentType(char ch) -> bool;

/**
 * @brief 检查字符是否为关键字类型（字母）
 * @param ch 要检查的字符
 * @return 是否为关键字类型
 */
auto isKeywordType(char ch) -> bool;

/**
 * @brief 检查字符是否为操作符类型
 * @param ch 要检查的字符
 * @return 是否为操作符类型
 */
auto isOperatorType(char ch) -> bool;

/**
 * @brief 检查字符是否为分隔符类型
 * @param ch 要检查的字符
 * @return 是否为分隔符类型
 */
auto isSeparatorType(char ch) -> bool;

/**
 * @brief 检查字符是否可能是二元操作符
 * @param ch 要检查的字符
 * @return 是否可能是二元操作符
 */
auto maybeBinaryOperator(char ch) -> bool;

/**
 * @brief 检查字符是否可能是一元操作符
 * @param ch 要检查的字符
 * @return 是否可能是一元操作符
 */
auto maybeUnaryOperator(char ch) -> bool;

/**
 * @brief 检查分隔符是否可以组合
 * @param pre 前一个分隔符
 * @param cur 当前字符
 * @return 是否可以组合
 */
auto separatorCanCombine(std::string &pre, char cur) -> bool;

} // namespace mycompiler
#endif // !LEXER_HELPER_FUNCTIONS_HPP
