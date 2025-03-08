#ifndef OPERATOR_POOL_HPP
#define OPERATOR_POOL_HPP

#include "token/operator_type.hpp"
#include <string>
#include <unordered_set>

namespace mycompiler {

/**
 * @brief 操作符池类，用于存储和查找操作符
 */
class OperatorPool {
public:
  /**
   * @brief 构造函数，初始化操作符池
   */
  OperatorPool();
  
  /**
   * @brief 查找操作符
   * @param op 要查找的操作符
   * @return 是否找到
   */
  auto find(std::string &op) -> bool;

private:
  const std::unordered_set<std::string> operators_;
};

/**
 * @brief 从字符串获取操作符类型
 * @param str 操作符字符串
 * @return 操作符类型
 */
auto getOperatorTypeFromString(std::string &str) -> OperatorType;

} // namespace mycompiler

#endif
