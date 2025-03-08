#ifndef NAMESPACE_DECL_NODE_HPP
#define NAMESPACE_DECL_NODE_HPP
#include "ast_node/decl_node/decl_node.hpp"
#include <memory>
#include <string>
#include <vector>

namespace mycompiler {

/**
 * @brief 命名空间声明节点类
 * 
 * 表示命名空间声明，包含命名空间名和命名空间内的声明
 */
class NamespaceDeclNode : public DeclNode {
public:
  /**
   * @brief 构造函数
   * @param lexer 词法分析器的共享指针
   */
  NamespaceDeclNode(std::shared_ptr<Lexer> lexer);

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
   * 从词法分析器中读取标记并构建命名空间声明节点
   */
  virtual auto Parse() -> void override;
  
  /**
   * @brief 获取命名空间内的声明列表
   * @return 命名空间内的声明列表
   */
  const std::vector<std::shared_ptr<DeclNode>>& getDeclarations() const;
  
  /**
   * @brief 添加命名空间内的声明
   * @param declaration 声明节点
   */
  void addDeclaration(std::shared_ptr<DeclNode> declaration);
  
  /**
   * @brief 检查命名空间是否为内联命名空间
   * @return 如果命名空间是内联命名空间，则返回true；否则返回false
   */
  bool isInline() const;
  
  /**
   * @brief 设置命名空间是否为内联命名空间
   * @param isInline 命名空间是否为内联命名空间
   */
  void setInline(bool isInline);
  
  /**
   * @brief 获取命名空间的完整名称
   * @return 命名空间的完整名称，包括嵌套的命名空间
   */
  std::string getFullName() const;
  
  /**
   * @brief 设置命名空间的完整名称
   * @param fullName 命名空间的完整名称
   */
  void setFullName(const std::string& fullName);

  /**
   * @brief 虚析构函数
   */
  virtual ~NamespaceDeclNode() = default;
  
private:
  /** 命名空间内的声明列表 */
  std::vector<std::shared_ptr<DeclNode>> declarations_;
  
  /** 命名空间是否为内联命名空间 */
  bool isInline_;
  
  /** 命名空间的完整名称 */
  std::string fullName_;
};

} // namespace mycompiler

#endif 