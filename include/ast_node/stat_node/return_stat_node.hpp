#ifndef RETURN_STAT_NODE_HPP
#define RETURN_STAT_NODE_HPP
#include "ast_node/stat_node/stat_node.hpp"
#include "ast_node/expr_node/expr_node.hpp"
#include "ast_node/terminal_symbols/terminal_return.hpp"
#include <memory>
#include <string>

namespace mycompiler {

/**
 * @brief 返回语句节点类
 * 
 * 表示return语句，包含返回值表达式
 */
class ReturnStatNode : public StatNode {
public:
  /**
   * @brief 构造函数
   * @param lexer 词法分析器的共享指针
   */
  ReturnStatNode(std::shared_ptr<Lexer> lexer);

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
   * 从词法分析器中读取标记并构建return语句节点
   */
  virtual auto Parse() -> void override;
  
  /**
   * @brief 获取返回值表达式
   * @return 返回值表达式的共享指针，如果没有返回值则返回nullptr
   */
  std::shared_ptr<ExprNode> getReturnValue() const;
  
  /**
   * @brief 设置返回值表达式
   * @param returnValue 返回值表达式的共享指针
   */
  void setReturnValue(std::shared_ptr<ExprNode> returnValue);
  
  /**
   * @brief 检查是否有返回值
   * @return 如果有返回值，则返回true；否则返回false
   */
  bool hasReturnValue() const;
  
  /**
   * @brief 检查语句是否为终止语句
   * @return 总是返回true，因为return语句是终止语句
   */
  virtual bool isTerminating() const override;

  /**
   * @brief 虚析构函数
   */
  virtual ~ReturnStatNode() = default;
  
private:
  /** 返回值表达式 */
  std::shared_ptr<ExprNode> returnValue_;
};

} // namespace mycompiler

#endif
