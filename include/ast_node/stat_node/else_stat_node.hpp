#ifndef ELSE_STAT_NODE_HPP
#define ELSE_STAT_NODE_HPP
#include "ast_node/stat_node/stat_node.hpp"
#include "ast_node/stat_node/block_stat_node.hpp"
#include <memory>
#include <string>

namespace mycompiler {

/**
 * @brief else语句节点类
 * 
 * 表示else语句，用于if语句的替代分支
 */
class ElseStatNode : public StatNode {
public:
  /**
   * @brief 构造函数
   * @param lexer 词法分析器的共享指针
   */
  ElseStatNode(std::shared_ptr<Lexer> lexer);

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
   * 从词法分析器中读取标记并构建else语句节点
   */
  virtual auto Parse() -> void override;
  
  /**
   * @brief 获取else块
   * @return else块节点的共享指针
   */
  std::shared_ptr<BlockStatNode> getBlock() const;
  
  /**
   * @brief 检查语句是否为终止语句
   * @return 如果else块是终止语句，则返回true；否则返回false
   */
  virtual bool isTerminating() const override;

  /**
   * @brief 虚析构函数
   */
  virtual ~ElseStatNode() = default;
  
private:
  /** else块 */
  std::shared_ptr<BlockStatNode> block_;
};

} // namespace mycompiler

#endif
