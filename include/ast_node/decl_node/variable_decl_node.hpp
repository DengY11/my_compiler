#ifndef VARIABLE_DECL_NODE_HPP
#define VARIABLE_DECL_NODE_HPP
#include "ast_node/decl_node/decl_node.hpp"
#include "ast_node/expr_node/expr_node.hpp"
#include "ast_node/terminal_symbols/terminal_let.hpp"
#include "ast_node/terminal_symbols/terminal_ident_literal.hpp"
#include "ast_node/terminal_symbols/terminal_operator.hpp"
#include <memory>
#include <string>

namespace mycompiler {

/**
 * @brief 变量声明节点类
 * 
 * 表示变量声明，包含变量名、类型和初始值
 */
class VariableDeclNode : public DeclNode {
public:
  /**
   * @brief 构造函数
   * @param lexer 词法分析器的共享指针
   */
  VariableDeclNode(std::shared_ptr<Lexer> lexer);

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
   * 从词法分析器中读取标记并构建变量声明节点
   */
  virtual void Parse() override final;
  
  /**
   * @brief 获取初始值表达式
   * @return 初始值表达式的共享指针，如果没有初始值则返回nullptr
   */
  std::shared_ptr<ExprNode> getInitialValue() const;
  
  /**
   * @brief 设置初始值表达式
   * @param initialValue 初始值表达式的共享指针
   */
  void setInitialValue(std::shared_ptr<ExprNode> initialValue);
  
  /**
   * @brief 检查是否有初始值
   * @return 如果有初始值，则返回true；否则返回false
   */
  bool hasInitialValue() const;

  /**
   * @brief 虚析构函数
   */
  virtual ~VariableDeclNode() = default;
  
private:
  /** 初始值表达式 */
  std::shared_ptr<ExprNode> initialValue_;
};

} // namespace mycompiler

#endif
