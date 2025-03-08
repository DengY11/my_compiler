#ifndef IDENT_EXPR_NODE_HPP
#define IDENT_EXPR_NODE_HPP

#include "ast_node/expr_node/expr_node.hpp"
#include <memory>
#include <string>

namespace mycompiler {

/**
 * @brief 标识符表达式节点类
 * 
 * 表示标识符表达式，如变量名
 */
class IdentifierExprNode : public ExprNode {
public:
  /**
   * @brief 构造函数
   * @param lexer 词法分析器的共享指针
   */
  IdentifierExprNode(std::shared_ptr<Lexer> lexer);

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
   * 从词法分析器中读取标记并构建标识符表达式节点
   */
  virtual void Parse() override;
  
  /**
   * @brief 获取表达式的类型
   * @return 表达式的类型字符串
   */
  virtual std::string getExpressionType() const override;
  
  /**
   * @brief 检查表达式是否为常量
   * @return 如果表达式是常量，则返回false（标识符不是常量）
   */
  virtual bool isConstant() const override;
  
  /**
   * @brief 检查表达式是否为左值
   * @return 如果表达式是左值，则返回true（标识符是左值）
   */
  virtual bool isLValue() const override;
  
  /**
   * @brief 获取标识符名称
   * @return 标识符名称
   */
  std::string getName() const;
  
  /**
   * @brief 设置标识符名称
   * @param name 标识符名称
   */
  void setName(const std::string& name);

  /**
   * @brief 虚析构函数
   */
  virtual ~IdentifierExprNode() = default;
  
private:
  /** 标识符名称 */
  std::string name_;
};

} // namespace mycompiler

#endif
