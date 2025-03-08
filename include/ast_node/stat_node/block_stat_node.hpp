#ifndef BLOCK_STAT_NODE_HPP
#define BLOCK_STAT_NODE_HPP
#include "ast_node/stat_node/stat_node.hpp"
#include <memory>
#include <string>
#include <vector>

namespace mycompiler {

/**
 * @brief 块语句节点类
 * 
 * 表示一个代码块，包含一系列语句
 */
class BlockStatNode : public StatNode {
public:
  /**
   * @brief 构造函数
   * @param lexer 词法分析器的共享指针
   */
  BlockStatNode(std::shared_ptr<Lexer> lexer);

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
   * 从词法分析器中读取标记并构建块语句节点
   */
  virtual auto Parse() -> void override;
  
  /**
   * @brief 添加语句
   * @param statement 语句节点的共享指针
   */
  void addStatement(std::shared_ptr<StatNode> statement);
  
  /**
   * @brief 获取语句列表
   * @return 语句节点列表的常量引用
   */
  const std::vector<std::shared_ptr<StatNode>>& getStatements() const;
  
  /**
   * @brief 检查语句是否为终止语句
   * @return 如果块中的最后一个语句是终止语句，则返回true；否则返回false
   */
  virtual bool isTerminating() const override;

  /**
   * @brief 虚析构函数
   */
  virtual ~BlockStatNode() = default;
  
private:
  /** 语句列表 */
  std::vector<std::shared_ptr<StatNode>> statements_;
};

} // namespace mycompiler

#endif
