#ifndef EXPR_STAT_NODE_HPP
#define EXPR_STAT_NODE_HPP
#include "ast_node/stat_node/stat_node.hpp"
#include "ast_node/expr_node/expr_node.hpp"
#include <memory>
#include <string>

namespace mycompiler {

/**
 * @brief 表达式语句节点类
 * 
 * 表示一个表达式语句，包含一个表达式
 */
class ExprStatNode : public StatNode {
public:
  /**
   * @brief 构造函数
   * @param lexer 词法分析器的共享指针
   */
  ExprStatNode(std::shared_ptr<Lexer> lexer);

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
   * 从词法分析器中读取标记并构建表达式语句节点
   */
  virtual auto Parse() -> void override;
  
  /**
   * @brief 获取表达式
   * @return 表达式的共享指针
   */
  std::shared_ptr<ExprNode> getExpression() const;
  
  /**
   * @brief 设置表达式
   * @param expression 表达式的共享指针
   */
  void setExpression(std::shared_ptr<ExprNode> expression);
  
  /**
   * @brief 检查语句是否为终止语句
   * @return 表达式语句通常不是终止语句，所以返回false
   */
  virtual bool isTerminating() const override;

  /**
   * @brief 虚析构函数
   */
  virtual ~ExprStatNode() = default;
  
private:
  /** 表达式 */
  std::shared_ptr<ExprNode> expression_;
};

} // namespace mycompiler

#endif 