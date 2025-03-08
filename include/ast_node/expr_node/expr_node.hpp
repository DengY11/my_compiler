#ifndef EXPR_NODE_HPP
#define EXPR_NODE_HPP
#include "ast_node/ast_node.hpp"
#include <memory>
#include <string>

namespace mycompiler {

/**
 * @brief 表达式节点基类
 * 
 * 所有表达式节点的基类，提供表达式节点的通用接口
 */
class ExprNode : public ASTNode {
public:
  /**
   * @brief 构造函数
   * @param lexer 词法分析器的共享指针
   */
  ExprNode(std::shared_ptr<Lexer> lexer);

  /**
   * @brief 打印节点信息
   */
  virtual auto print_info() -> void override = 0;
  
  /**
   * @brief 获取节点的字符串表示
   * @return 节点的字符串表示
   */
  virtual std::string toString() const override = 0;

  /**
   * @brief 解析方法
   * 
   * 从词法分析器中读取标记并构建表达式节点
   */
  virtual auto Parse() -> void override = 0;
  
  /**
   * @brief 检查表达式是否为常量
   * @return 如果表达式是常量，则返回true；否则返回false
   */
  virtual bool isConstant() const;
  
  /**
   * @brief 检查表达式是否为左值
   * @return 如果表达式是左值，则返回true；否则返回false
   */
  virtual bool isLValue() const;
  
  /**
   * @brief 获取表达式的类型
   * @return 表达式的类型字符串
   */
  virtual std::string getExpressionType() const;
  
  /**
   * @brief 获取表达式的优先级
   * @return 表达式的优先级
   */
  virtual int getPrecedence() const;

  /**
   * @brief 虚析构函数
   */
  virtual ~ExprNode() = default;
};

} // namespace mycompiler

#endif
