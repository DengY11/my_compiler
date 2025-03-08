#ifndef EMPTY_STAT_NODE_HPP
#define EMPTY_STAT_NODE_HPP
#include "ast_node/stat_node/stat_node.hpp"
#include <memory>
#include <string>

namespace mycompiler {

/**
 * @brief 空语句节点类
 * 
 * 表示一个空语句，通常是一个单独的分号
 */
class EmptyStatNode : public StatNode {
public:
  /**
   * @brief 构造函数
   * @param lexer 词法分析器的共享指针
   */
  EmptyStatNode(std::shared_ptr<Lexer> lexer);

  /**
   * @brief 打印节点信息
   */
  virtual auto print_info() -> void override;
  
  /**
   * @brief 获取节点的字符串表示
   * @return 节点的字符串表示
   */
  virtual std::string toString() const override;

  /**
   * @brief 解析方法
   * 
   * 从词法分析器中读取标记并构建空语句节点
   */
  virtual auto Parse() -> void override;
  
  /**
   * @brief 检查语句是否为终止语句
   * @return 空语句不是终止语句，所以返回false
   */
  virtual bool isTerminating() const override;

  /**
   * @brief 虚析构函数
   */
  virtual ~EmptyStatNode() = default;
};

} // namespace mycompiler

#endif 