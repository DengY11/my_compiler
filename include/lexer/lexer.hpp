#ifndef LEXER_HPP
#define LEXER_HPP
#include "lexer/keyword_pool.hpp"
#include "lexer/operator_pool.hpp"
#include "lexer/separator_pool.hpp"
#include "token/token.hpp"
#include "token/token_helper_functions.hpp"
#include <cstddef>

namespace mycompiler {

/**
 * @brief 词法分析器类，负责将源代码转换为Token序列
 */
class Lexer {

public:
  /**
   * @brief 构造函数
   * @param input 输入的源代码
   */
  Lexer(const std::string &input);
  
  /**
   * @brief 获取下一个Token并移动指针
   * @return 下一个Token
   */
  auto getNextToken() -> Token;
  
  /**
   * @brief 获取当前Token
   * @return 当前Token
   */
  auto getCurrentToken() const -> Token;
  
  /**
   * @brief 获取当前索引位置
   * @return 当前索引位置
   */
  auto getCurrentIndex() const -> std::size_t;
  
  /**
   * @brief 查看下一个字符但不移动指针
   * @return 下一个字符
   */
  auto lookNextChar() -> char;
  
  /**
   * @brief 查看下一个Token但不移动指针
   * @return 下一个Token
   */
  auto peekNextToken() -> Token;
  
  /**
   * @brief 打印源代码
   */
  auto printSource() -> void;

  /**
   * @brief 检查字符串是否为关键字
   * @param word 要检查的字符串
   * @return 是否为关键字
   */
  auto isKeyword(std::string &word) -> bool;
  
  /**
   * @brief 检查字符串是否为操作符
   * @param word 要检查的字符串
   * @return 是否为操作符
   */
  auto isOperator(std::string &word) -> bool;
  
  /**
   * @brief 检查字符串是否为分隔符
   * @param word 要检查的字符串
   * @return 是否为分隔符
   */
  auto isSeparator(std::string &word) -> bool;

  /**
   * @brief 获取当前行号
   * @return 当前行号
   */
  auto getCurrentLine() const -> std::size_t;
  
  /**
   * @brief 获取当前列号
   * @return 当前列号
   */
  auto getCurrentColumn() const -> std::size_t;

private:
  std::string input_;         // 输入的源代码
  size_t index_;              // 当前处理位置
  KeywordPool keywordPool_;   // 关键字池
  OperatorPool operatorPool_; // 操作符池
  SeparatorPool separatorPool_; // 分隔符池
  Token curToken_;            // 当前Token
  std::size_t line_;          // 当前行号
  std::size_t column_;        // 当前列号
  
  /**
   * @brief 查看当前字符但不移动指针
   * @return 当前字符
   */
  auto peekChar() -> char;
  
  /**
   * @brief 获取当前字符并移动指针
   * @return 当前字符
   */
  auto advanceChar() -> char;
  
  /**
   * @brief 跳过空白字符
   */
  auto skipWhitespace() -> void;
  
  /**
   * @brief 检查是否到达输入结束
   * @return 是否到达输入结束
   */
  auto isEnd() -> bool;
  
  /**
   * @brief 更新行号和列号
   * @param ch 当前处理的字符
   */
  auto updatePosition(char ch) -> void;
  
  /**
   * @brief 跳过单行注释
   */
  auto skipSingleLineComment() -> void;
  
  /**
   * @brief 跳过多行注释
   */
  auto skipMultiLineComment() -> void;
  
  /**
   * @brief 检查并跳过注释
   * @return 是否跳过了注释
   */
  auto skipComment() -> bool;
};

} // namespace mycompiler

#endif
