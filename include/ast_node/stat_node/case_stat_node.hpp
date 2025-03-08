#ifndef CASE_STAT_NODE_HPP
#define CASE_STAT_NODE_HPP
#include "ast_node/stat_node/stat_node.hpp"
#include "ast_node/expr_node/expr_node.hpp"
#include "ast_node/stat_node/block_stat_node.hpp"
#include <memory>
#include <string>

namespace mycompiler {

/**
 * @brief case语句节点类
 * 
 * 表示switch语句中的case子句，包含一个表达式和一个语句块
 */
class CaseStatNode : public StatNode {
public:
  /**
   * @brief 构造函数
   * @param lexer 词法分析器的共享指针
   */
  CaseStatNode(std::shared_ptr<Lexer> lexer);

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
   * 从词法分析器中读取标记并构建case语句节点
   */
  virtual auto Parse() -> void override;
  
  /**
   * @brief 获取case表达式
   * @return case表达式的共享指针
   */
  std::shared_ptr<ExprNode> getExpression() const;
  
  /**
   * @brief 获取case语句块
   * @return case语句块的共享指针
   */
  std::shared_ptr<BlockStatNode> getBlock() const;
  
  /**
   * @brief 设置case表达式
   * @param expression case表达式的共享指针
   */
  void setExpression(std::shared_ptr<ExprNode> expression);
  
  /**
   * @brief 设置case语句块
   * @param block case语句块的共享指针
   */
  void setBlock(std::shared_ptr<BlockStatNode> block);
  
  /**
   * @brief 检查语句是否为终止语句
   * @return 如果语句块是终止语句，则返回true；否则返回false
   */
  virtual bool isTerminating() const override;
  
  /**
   * @brief 检查是否为default case
   * @return 如果是default case，则返回true；否则返回false
   */
  bool isDefault() const;
  
  /**
   * @brief 设置是否为default case
   * @param isDefault 是否为default case
   */
  void setDefault(bool isDefault);

  /**
   * @brief 虚析构函数
   */
  virtual ~CaseStatNode() = default;
  
private:
  /** case表达式 */
  std::shared_ptr<ExprNode> expression_;
  
  /** case语句块 */
  std::shared_ptr<BlockStatNode> block_;
  
  /** 是否为default case */
  bool isDefault_;
};

} // namespace mycompiler

#endif 