#ifndef DEFAULT_STAT_NODE_HPP
#define DEFAULT_STAT_NODE_HPP
#include "ast_node/stat_node/stat_node.hpp"
#include "ast_node/stat_node/block_stat_node.hpp"
#include <memory>
#include <string>

namespace mycompiler {

/**
 * @brief default语句节点类
 * 
 * 表示switch语句中的default子句，包含一个语句块
 */
class DefaultStatNode : public StatNode {
public:
  /**
   * @brief 构造函数
   * @param lexer 词法分析器的共享指针
   */
  DefaultStatNode(std::shared_ptr<Lexer> lexer);

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
   * 从词法分析器中读取标记并构建default语句节点
   */
  virtual auto Parse() -> void override;
  
  /**
   * @brief 获取default语句块
   * @return default语句块的共享指针
   */
  std::shared_ptr<BlockStatNode> getBlock() const;
  
  /**
   * @brief 设置default语句块
   * @param block default语句块的共享指针
   */
  void setBlock(std::shared_ptr<BlockStatNode> block);
  
  /**
   * @brief 检查语句是否为终止语句
   * @return 如果语句块是终止语句，则返回true；否则返回false
   */
  virtual bool isTerminating() const override;

  /**
   * @brief 虚析构函数
   */
  virtual ~DefaultStatNode() = default;
  
private:
  /** default语句块 */
  std::shared_ptr<BlockStatNode> block_;
};

} // namespace mycompiler

#endif 