#ifndef FUNCTION_CALLED_RETURN_VALUE_EXPR_NODE_HPP
#define FUNCTION_CALLED_RETURN_VALUE_EXPR_NODE_HPP

#include "ast_node/expr_node/expr_node.hpp"
#include "ast_node/stat_node/parameter_list_stat_node.hpp"
#include <memory>
#include <string>

namespace mycompiler {

/**
 * @brief 函数调用表达式节点类
 * 
 * 表示函数调用表达式，包含函数名和参数列表
 */
class FunctionCalledReturnValueExprNode : public ExprNode {
public:
  /**
   * @brief 构造函数
   * @param lexer 词法分析器的共享指针
   */
  FunctionCalledReturnValueExprNode(std::shared_ptr<Lexer> lexer);

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
   * 从词法分析器中读取标记并构建函数调用表达式节点
   */
  virtual auto Parse() -> void override final;
  
  /**
   * @brief 获取表达式的类型
   * @return 表达式的类型字符串
   */
  virtual std::string getExpressionType() const override;
  
  /**
   * @brief 检查表达式是否为常量
   * @return 如果表达式是常量，则返回false（函数调用不是常量）
   */
  virtual bool isConstant() const override;
  
  /**
   * @brief 检查表达式是否为左值
   * @return 如果表达式是左值，则返回false（函数调用不是左值）
   */
  virtual bool isLValue() const override;
  
  /**
   * @brief 获取函数名
   * @return 函数名
   */
  std::string getFunctionName() const;
  
  /**
   * @brief 获取参数列表
   * @return 参数列表节点的共享指针
   */
  std::shared_ptr<ParameterListStatNode> getParameters() const;

  /**
   * @brief 虚析构函数
   */
  virtual ~FunctionCalledReturnValueExprNode() = default;
  
private:
  /** 函数名 */
  std::string functionName_;
  
  /** 参数列表 */
  std::shared_ptr<ParameterListStatNode> parameters_;
};

} // namespace mycompiler

#endif
