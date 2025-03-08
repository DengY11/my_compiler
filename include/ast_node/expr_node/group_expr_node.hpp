#ifndef GROUP_EXPR_NODE_HPP
#define GROUP_EXPR_NODE_HPP

#include "ast_node/expr_node/expr_node.hpp"
#include <memory>
#include <string>

namespace mycompiler {

/**
 * @brief 分组表达式节点类
 * 
 * 表示被括号包围的表达式
 */
class GroupExprNode : public ExprNode {
public:
  /**
   * @brief 构造函数
   * @param lexer 词法分析器的共享指针
   */
  GroupExprNode(std::shared_ptr<Lexer> lexer);

  /**
   * @brief 打印节点信息
   */
  virtual auto print_info() -> void override final;
  
  /**
   * @brief 获取节点的字符串表示
   * @return 节点的字符串表示
   */
  virtual std::string toString() const override;

  /**
   * @brief 解析方法
   * 
   * 从词法分析器中读取标记并构建分组表达式节点
   */
  virtual auto Parse() -> void override final;
  
  /**
   * @brief 获取表达式的类型
   * @return 表达式的类型字符串，与内部表达式的类型相同
   */
  virtual std::string getExpressionType() const override;
  
  /**
   * @brief 检查表达式是否为常量
   * @return 如果内部表达式是常量，则返回true；否则返回false
   */
  virtual bool isConstant() const override;
  
  /**
   * @brief 检查表达式是否为左值
   * @return 如果内部表达式是左值，则返回true；否则返回false
   */
  virtual bool isLValue() const override;
  
  /**
   * @brief 获取内部表达式
   * @return 内部表达式的共享指针
   */
  std::shared_ptr<ExprNode> getExpression() const;

  /**
   * @brief 虚析构函数
   */
  virtual ~GroupExprNode() = default;
  
private:
  /** 内部表达式 */
  std::shared_ptr<ExprNode> expression_;
};

} // namespace mycompiler

#endif
