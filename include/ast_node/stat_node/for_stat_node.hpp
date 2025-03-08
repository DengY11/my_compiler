#ifndef FOR_STAT_NODE_HPP
#define FOR_STAT_NODE_HPP
#include "ast_node/stat_node/stat_node.hpp"
#include "ast_node/expr_node/expr_node.hpp"
#include "ast_node/stat_node/block_stat_node.hpp"
#include <memory>
#include <string>

namespace mycompiler {

/**
 * @brief for语句节点类
 * 
 * 表示for循环语句，包含初始化、条件、增量和循环体
 */
class ForStatNode : public StatNode {
public:
  /**
   * @brief 构造函数
   * @param lexer 词法分析器的共享指针
   */
  ForStatNode(std::shared_ptr<Lexer> lexer);

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
   * 从词法分析器中读取标记并构建for语句节点
   */
  virtual auto Parse() -> void override;
  
  /**
   * @brief 获取初始化表达式
   * @return 初始化表达式的共享指针，如果没有初始化表达式则返回nullptr
   */
  std::shared_ptr<ExprNode> getInitialization() const;
  
  /**
   * @brief 获取条件表达式
   * @return 条件表达式的共享指针，如果没有条件表达式则返回nullptr
   */
  std::shared_ptr<ExprNode> getCondition() const;
  
  /**
   * @brief 获取增量表达式
   * @return 增量表达式的共享指针，如果没有增量表达式则返回nullptr
   */
  std::shared_ptr<ExprNode> getIncrement() const;
  
  /**
   * @brief 获取循环体
   * @return 循环体节点的共享指针
   */
  std::shared_ptr<BlockStatNode> getBody() const;
  
  /**
   * @brief 检查语句是否为终止语句
   * @return 如果循环体是终止语句，则返回true；否则返回false
   */
  virtual bool isTerminating() const override;

  /**
   * @brief 虚析构函数
   */
  virtual ~ForStatNode() = default;
  
private:
  /** 初始化表达式 */
  std::shared_ptr<ExprNode> initialization_;
  
  /** 条件表达式 */
  std::shared_ptr<ExprNode> condition_;
  
  /** 增量表达式 */
  std::shared_ptr<ExprNode> increment_;
  
  /** 循环体 */
  std::shared_ptr<BlockStatNode> body_;
};

} // namespace mycompiler

#endif
