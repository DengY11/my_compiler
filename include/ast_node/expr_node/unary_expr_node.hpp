#ifndef UNARY_EXPR_NODE_HPP
#define UNARY_EXPR_NODE_HPP
#include "ast_node/expr_node/expr_node.hpp"
#include "ast_node/terminal_symbols/terminal_operator.hpp"
#include "ast_node/terminal_symbols/terminal_value_literal.hpp"
#include <memory>
#include <string>

namespace mycompiler {

/**
 * @brief 一元表达式节点类
 * 
 * 表示一元操作，如取反、自增等
 */
class UnaryExprNode : public ExprNode {
public:
  /**
   * @brief 构造函数
   * @param lexer 词法分析器的共享指针
   */
  UnaryExprNode(std::shared_ptr<Lexer> lexer);

  /**
   * @brief 构造函数
   * @param op 操作符
   * @param operand 操作数
   */
  UnaryExprNode(std::shared_ptr<TerminalOperator> op,
                std::shared_ptr<ExprNode> operand);

  auto add_child(std::shared_ptr<TerminalOperator> op,
                 std::shared_ptr<ExprNode> right) -> void;

  auto add_child(std::shared_ptr<TerminalOperator> op,
                 std::shared_ptr<TerminalValueLiteral> right) -> void;

  /**
   * @brief 打印节点信息
   */
  virtual void print_info() override;
  
  /**
   * @brief 获取节点的字符串表示
   * @return 节点的字符串表示
   */
  virtual std::string toString() const override;

  /**
   * @brief 解析方法
   * 
   * 从词法分析器中读取标记并构建一元表达式节点
   */
  virtual void Parse() override;
  
  /**
   * @brief 获取表达式的类型
   * @return 表达式的类型字符串
   */
  virtual std::string getExpressionType() const override;
  
  /**
   * @brief 检查表达式是否为常量
   * @return 如果表达式是常量，则返回true；否则返回false
   */
  virtual bool isConstant() const override;
  
  /**
   * @brief 检查表达式是否为左值
   * @return 如果表达式是左值，则返回true；否则返回false
   */
  virtual bool isLValue() const override;
  
  /**
   * @brief 获取操作符
   * @return 操作符的共享指针
   */
  std::shared_ptr<TerminalOperator> getOperator() const;
  
  /**
   * @brief 获取操作数
   * @return 操作数的共享指针
   */
  std::shared_ptr<ExprNode> getOperand() const;

  /**
   * @brief 虚析构函数
   */
  virtual ~UnaryExprNode() = default;
  
private:
  /** 操作符 */
  std::shared_ptr<TerminalOperator> operator_;
  
  /** 操作数 */
  std::shared_ptr<ExprNode> operand_;
};

} // namespace mycompiler

#endif
