#ifndef TENARY_EXPR_NODE_HPP
#define TENARY_EXPR_NODE_HPP
#include "ast_node/expr_node/expr_node.hpp"
#include "ast_node/expr_node/literal_expr_node.hpp"
#include "ast_node/terminal_symbols/terminal_operator.hpp"
#include <memory>
#include <string>

namespace mycompiler {

/**
 * @brief 三元表达式节点类
 * 
 * 表示三元条件表达式，如 condition ? trueExpr : falseExpr
 */
class TenaryExprNode : public ExprNode {
public:
  /**
   * @brief 构造函数
   * @param lexer 词法分析器的共享指针
   */
  TenaryExprNode(std::shared_ptr<Lexer> lexer);

  /**
   * @brief 解析方法
   * 
   * 从词法分析器中读取标记并构建三元表达式节点
   */
  auto virtual Parse() -> void override final;

  /**
   * @brief 打印节点信息
   */
  auto virtual print_info() -> void override final;

  /**
   * @brief 获取节点的字符串表示
   * @return 节点的字符串表示
   */
  virtual std::string toString() const override;

  /**
   * @brief 获取表达式的类型
   * @return 表达式的类型字符串，通常是trueExpr和falseExpr的共同类型
   */
  virtual std::string getExpressionType() const override;

  /**
   * @brief 检查表达式是否为常量
   * @return 如果condition、trueExpr和falseExpr都是常量，则返回true；否则返回false
   */
  virtual bool isConstant() const override;

  /**
   * @brief 检查表达式是否为左值
   * @return 如果表达式是左值，则返回false（三元表达式不是左值）
   */
  virtual bool isLValue() const override;

  /**
   * @brief 添加子节点
   * @param condition 条件表达式
   * @param trueExpr 条件为真时的表达式
   * @param falseExpr 条件为假时的表达式
   */
  auto add_child(std::shared_ptr<ExprNode> condition,
                 std::shared_ptr<ExprNode> trueExpr,
                 std::shared_ptr<ExprNode> falseExpr) -> void;

  /**
   * @brief 获取条件表达式
   * @return 条件表达式的共享指针
   */
  std::shared_ptr<ExprNode> getCondition() const;

  /**
   * @brief 获取条件为真时的表达式
   * @return 条件为真时的表达式的共享指针
   */
  std::shared_ptr<ExprNode> getTrueExpression() const;

  /**
   * @brief 获取条件为假时的表达式
   * @return 条件为假时的表达式的共享指针
   */
  std::shared_ptr<ExprNode> getFalseExpression() const;

  /**
   * @brief 虚析构函数
   */
  virtual ~TenaryExprNode() = default;

private:
  /** 条件表达式 */
  std::shared_ptr<ExprNode> condition_;
  
  /** 条件为真时的表达式 */
  std::shared_ptr<ExprNode> trueExpr_;
  
  /** 条件为假时的表达式 */
  std::shared_ptr<ExprNode> falseExpr_;
};

} // namespace mycompiler

#endif
