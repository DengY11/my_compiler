#ifndef BREAK_STAT_NODE_HPP
#define BREAK_STAT_NODE_HPP
#include "ast_node/stat_node/stat_node.hpp"
#include <memory>
#include <string>

namespace mycompiler {

/**
 * @brief break语句节点类
 * 
 * 表示break语句，用于跳出循环或switch语句
 */
class BreakStatNode : public StatNode {
public:
  /**
   * @brief 构造函数
   * @param lexer 词法分析器的共享指针
   */
  BreakStatNode(std::shared_ptr<Lexer> lexer);

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
   * 从词法分析器中读取标记并构建break语句节点
   */
  virtual auto Parse() -> void override;
  
  /**
   * @brief 检查语句是否为终止语句
   * @return 总是返回true，因为break语句是终止语句
   */
  virtual bool isTerminating() const override;
  
  /**
   * @brief 获取标签
   * @return 标签字符串，如果没有标签则返回空字符串
   */
  std::string getLabel() const;
  
  /**
   * @brief 设置标签
   * @param label 标签字符串
   */
  void setLabel(const std::string& label);
  
  /**
   * @brief 检查是否有标签
   * @return 如果有标签，则返回true；否则返回false
   */
  bool hasLabel() const;

  /**
   * @brief 虚析构函数
   */
  virtual ~BreakStatNode() = default;
  
private:
  /** 标签 */
  std::string label_;
};

} // namespace mycompiler

#endif
