#ifndef TOKEN_HELPER_FUNCTIONS
#define TOKEN_HELPER_FUNCTIONS
#include "eof_or_illegal_type.hpp"
#include "token/comment_type.hpp"
#include "token/constant_type.hpp"
#include "token/ident_type.hpp"
#include "token/keyword_type.hpp"
#include "token/operator_type.hpp"
#include "token/preprocessor.hpp"
#include "token/separator_type.hpp"
#include "token/token.hpp"
#include "token/token_type.hpp"
#include <iostream>
#include <string>
#include <variant>

namespace mycompiler {

/**
 * 从Token中获取关键字类型
 * @param token 要检查的Token
 * @return 关键字类型
 */
auto getKeywordTypeFromToken(const Token &token) -> KeywordType const;

/**
 * 从Token中获取操作符类型
 * @param token 要检查的Token
 * @return 操作符类型
 */
auto getOperatorTypeFromToken(const Token &token) -> OperatorType const;

/**
 * 从Token中获取标识符值
 * @param token 要检查的Token
 * @return 标识符字符串值
 */
auto getIdentifierValueFromToken(const Token &token) -> std::string const;

/**
 * 从Token中获取常量值
 * @param token 要检查的Token
 * @return 常量字符串值
 */
auto getConstantValueFromToken(const Token &token) -> std::string const;

/**
 * 从Token中获取分隔符值
 * @param token 要检查的Token
 * @return 分隔符字符串值
 */
auto getSeparatorValueFromToken(const Token &token) -> std::string const;

/**
 * 检查Token是否为标识符类型
 * @param token 要检查的Token
 * @return 如果是标识符则返回true
 */
auto isIdentifierType(const Token &token) -> bool;

/**
 * 检查Token是否为一元操作符
 * @param token 要检查的Token
 * @return 如果是一元操作符则返回true
 */
auto isUnaryOperator(const Token &token) -> bool;

/**
 * 检查Token是否为二元操作符
 * @param token 要检查的Token
 * @return 如果是二元操作符则返回true
 */
auto isBinaryOperator(const Token &token) -> bool;

/**
 * 获取操作符字符串的优先级
 * @param op 操作符字符串
 * @return 优先级值
 */
auto getOperatorPriority(const std::string &op) -> int;

/**
 * 获取操作符Token的优先级
 * @param token 操作符Token
 * @return 优先级值
 */
auto getOperatorPriority(const Token &token) -> int;

// TODO:

} // namespace mycompiler

#endif
