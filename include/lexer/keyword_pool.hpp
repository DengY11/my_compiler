#ifndef KEYWORD_POOL_HPP
#define KEYWORD_POOL_HPP

#include "token/keyword_type.hpp"
#include <string>
#include <unordered_set>

namespace mycompiler {

/**
 * @brief 关键字池类，用于存储和查找关键字
 */
class KeywordPool {

public:
  /**
   * @brief 构造函数，初始化关键字池
   */
  KeywordPool();

  /**
   * @brief 查找关键字
   * @param word 要查找的关键字
   * @return 是否找到
   */
  auto find(std::string &word) -> bool;

private:
  const std::unordered_set<std::string> keywords_;
  // NOTE::到构造函数的实现里添加初始关键字
};

/**
 * @brief 从字符串获取关键字类型
 * @param str 关键字字符串
 * @return 关键字类型
 */
auto getKeywordTypeFromString(std::string &str) -> KeywordType;

} // namespace mycompiler
#endif // !KEYWORD_POOL
