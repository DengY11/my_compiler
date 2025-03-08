#ifndef SEPARATOR_POOL_HPP
#define SEPARATOR_POOL_HPP

#include "token/separator_type.hpp"
#include <string>
#include <unordered_set>

namespace mycompiler {

/**
 * @brief 分隔符池类，用于存储和查找分隔符
 */
class SeparatorPool {
public:
  /**
   * @brief 构造函数，初始化分隔符池
   */
  SeparatorPool();
  
  /**
   * @brief 查找分隔符
   * @param sep 要查找的分隔符
   * @return 是否找到
   */
  auto find(std::string &sep) -> bool;

private:
  const std::unordered_set<std::string> separators_;
};

} // namespace mycompiler

#endif
