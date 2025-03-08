#ifndef BINARY_EXPR_NODE_HPP
#define BINARY_EXPR_NODE_HPP
#include "ast_node/expr_node/expr_node.hpp"
#include "ast_node/terminal_symbols/terminal_operator.hpp"
#include <memory>
#include <string>

namespace mycompiler {

/**
 * @brief 二元表达式节点类
 * 
 * 表示一个二元操作，如加法、减法等
 */
class BinaryExprNode : public ExprNode {

public:
  /**
   * @brief 构造函数
   * @param lexer 词法分析器的共享指针
   */
  BinaryExprNode(std::shared_ptr<Lexer> lexer);

  /**
   * @brief 构造函数
   * @param left 左操作数
   * @param op 操作符
   * @param right 右操作数
   */
  BinaryExprNode(std::shared_ptr<ExprNode> left,
                 std::shared_ptr<TerminalOperator> op,
                 std::shared_ptr<ExprNode> right);

  /**
   * @brief 打印节点信息
   */
  virtual void print_info() override final;
  
  /**
   * @brief 获取节点的字符串表示
   * @return 节点的字符串表示
   */
  virtual std::string toString() const override;

  /**
   * @brief 解析方法
   * 
   * 从词法分析器中读取标记并构建二元表达式节点
   */
  virtual void Parse() override final;
  
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
   * @brief 添加子节点
   * @param left 左操作数
   * @param op 操作符
   * @param right 右操作数
   */
  auto add_child(std::shared_ptr<ExprNode> left,
                 std::shared_ptr<TerminalOperator> op,
                 std::shared_ptr<ExprNode> right) -> void;
                 
  /**
   * @brief 获取左操作数
   * @return 左操作数的共享指针
   */
  std::shared_ptr<ExprNode> getLeft() const;
  
  /**
   * @brief 获取操作符
   * @return 操作符的共享指针
   */
  std::shared_ptr<TerminalOperator> getOperator() const;
  
  /**
   * @brief 获取右操作数
   * @return 右操作数的共享指针
   */
  std::shared_ptr<ExprNode> getRight() const;

  /**
   * @brief 虚析构函数
   */
  virtual ~BinaryExprNode() = default;
  
private:
  /** 左操作数 */
  std::shared_ptr<ExprNode> left_;
  
  /** 操作符 */
  std::shared_ptr<TerminalOperator> operator_;
  
  /** 右操作数 */
  std::shared_ptr<ExprNode> right_;
};

} // namespace mycompiler

#endif
