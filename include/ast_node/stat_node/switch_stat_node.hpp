#ifndef SWITCH_STAT_NODE_HPP
#define SWITCH_STAT_NODE_HPP
#include "ast_node/stat_node/stat_node.hpp"
#include "ast_node/expr_node/expr_node.hpp"
#include "ast_node/stat_node/block_stat_node.hpp"
#include <memory>
#include <string>
#include <vector>
#include <utility>

namespace mycompiler {

/**
 * @brief switch语句节点类
 * 
 * 表示switch语句，包含表达式和case子句
 */
class SwitchStatNode : public StatNode {
public:
  /**
   * @brief 构造函数
   * @param lexer 词法分析器的共享指针
   */
  SwitchStatNode(std::shared_ptr<Lexer> lexer);

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
   * 从词法分析器中读取标记并构建switch语句节点
   */
  virtual auto Parse() -> void override;
  
  /**
   * @brief 获取表达式
   * @return 表达式的共享指针
   */
  std::shared_ptr<ExprNode> getExpression() const;
  
  /**
   * @brief 获取case子句
   * @return case子句的列表，每个子句是一个表达式和块的对
   */
  const std::vector<std::pair<std::shared_ptr<ExprNode>, std::shared_ptr<BlockStatNode>>>& getCases() const;
  
  /**
   * @brief 获取default子句
   * @return default子句的共享指针，如果没有default子句则返回nullptr
   */
  std::shared_ptr<BlockStatNode> getDefaultCase() const;
  
  /**
   * @brief 添加case子句
   * @param caseExpr case表达式
   * @param caseBlock case块
   */
  void addCase(std::shared_ptr<ExprNode> caseExpr, std::shared_ptr<BlockStatNode> caseBlock);
  
  /**
   * @brief 设置default子句
   * @param defaultBlock default块
   */
  void setDefaultCase(std::shared_ptr<BlockStatNode> defaultBlock);
  
  /**
   * @brief 检查语句是否为终止语句
   * @return 如果所有case子句和default子句都是终止语句，则返回true；否则返回false
   */
  virtual bool isTerminating() const override;

  /**
   * @brief 虚析构函数
   */
  virtual ~SwitchStatNode() = default;
  
private:
  /** 表达式 */
  std::shared_ptr<ExprNode> expression_;
  
  /** case子句 */
  std::vector<std::pair<std::shared_ptr<ExprNode>, std::shared_ptr<BlockStatNode>>> cases_;
  
  /** default子句 */
  std::shared_ptr<BlockStatNode> defaultCase_;
};

} // namespace mycompiler

#endif
