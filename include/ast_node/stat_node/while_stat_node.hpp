#ifndef WHILE_STAT_NODE_HPP
#define WHILE_STAT_NODE_HPP
#include "ast_node/stat_node/stat_node.hpp"
#include "ast_node/expr_node/expr_node.hpp"
#include "ast_node/stat_node/block_stat_node.hpp"
#include <memory>
#include <string>

namespace mycompiler {

/**
 * @brief while语句节点类
 * 
 * 表示while循环语句，包含条件表达式和循环体
 */
class WhileStatNode : public StatNode {
public:
  /**
   * @brief 构造函数
   * @param lexer 词法分析器的共享指针
   */
  WhileStatNode(std::shared_ptr<Lexer> lexer);

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
   * 从词法分析器中读取标记并构建while语句节点
   */
  virtual auto Parse() -> void override;
  
  /**
   * @brief 获取条件表达式
   * @return 条件表达式的共享指针
   */
  std::shared_ptr<ExprNode> getCondition() const;
  
  /**
   * @brief 获取循环体
   * @return 循环体节点的共享指针
   */
  std::shared_ptr<BlockStatNode> getBody() const;
  
  /**
   * @brief 检查语句是否为终止语句
   * @return 如果循环体是终止语句，则返回true；否则返回false
   */
  virtual bool isTerminating() const override;

  /**
   * @brief 虚析构函数
   */
  virtual ~WhileStatNode() = default;
  
private:
  /** 条件表达式 */
  std::shared_ptr<ExprNode> condition_;
  
  /** 循环体 */
  std::shared_ptr<BlockStatNode> body_;
};

} // namespace mycompiler

#endif
