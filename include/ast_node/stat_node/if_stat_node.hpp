#ifndef IF_STAT_NODE_HPP
#define IF_STAT_NODE_HPP
#include "ast_node/stat_node/stat_node.hpp"
#include "ast_node/expr_node/expr_node.hpp"
#include "ast_node/stat_node/block_stat_node.hpp"
#include "ast_node/stat_node/else_stat_node.hpp"
#include <memory>
#include <string>

namespace mycompiler {

/**
 * @brief if语句节点类
 * 
 * 表示if条件语句，包含条件表达式和执行块
 */
class IfStatNode : public StatNode {
public:
  /**
   * @brief 构造函数
   * @param lexer 词法分析器的共享指针
   */
  IfStatNode(std::shared_ptr<Lexer> lexer);

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
   * 从词法分析器中读取标记并构建if语句节点
   */
  virtual auto Parse() -> void override;
  
  /**
   * @brief 获取条件表达式
   * @return 条件表达式节点的共享指针
   */
  std::shared_ptr<ExprNode> getCondition() const;
  
  /**
   * @brief 获取if块
   * @return if块节点的共享指针
   */
  std::shared_ptr<BlockStatNode> getIfBlock() const;
  
  /**
   * @brief 获取else块
   * @return else块节点的共享指针，如果没有else块则返回nullptr
   */
  std::shared_ptr<ElseStatNode> getElseBlock() const;
  
  /**
   * @brief 检查是否有else块
   * @return 如果有else块，则返回true；否则返回false
   */
  bool hasElse() const;
  
  /**
   * @brief 检查语句是否为终止语句
   * @return 如果if和else块都是终止语句，则返回true；否则返回false
   */
  virtual bool isTerminating() const override;

  /**
   * @brief 虚析构函数
   */
  virtual ~IfStatNode() = default;
  
private:
  /** 条件表达式 */
  std::shared_ptr<ExprNode> condition_;
  
  /** if块 */
  std::shared_ptr<BlockStatNode> ifBlock_;
  
  /** else块 */
  std::shared_ptr<ElseStatNode> elseBlock_;
};

} // namespace mycompiler

#endif
