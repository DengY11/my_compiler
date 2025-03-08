#ifndef DECL_NODE_HPP
#define DECL_NODE_HPP
#include "ast_node/ast_node.hpp"
#include <memory>
#include <string>

namespace mycompiler {

/**
 * @brief 声明节点基类
 * 
 * 所有声明节点的基类，提供声明节点的通用接口
 */
class DeclNode : public ASTNode {
public:
  /**
   * @brief 构造函数
   * @param lexer 词法分析器的共享指针
   */
  DeclNode(std::shared_ptr<Lexer> lexer);

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
   * 从词法分析器中读取标记并构建声明节点
   */
  virtual auto Parse() -> void override = 0;
  
  /**
   * @brief 获取声明的名称
   * @return 声明的名称
   */
  virtual std::string getName() const;
  
  /**
   * @brief 设置声明的名称
   * @param name 声明的名称
   */
  virtual void setName(const std::string& name);
  
  /**
   * @brief 获取声明的类型
   * @return 声明的类型字符串
   */
  virtual std::string getDeclarationType() const;
  
  /**
   * @brief 检查声明是否为常量
   * @return 如果声明是常量，则返回true；否则返回false
   */
  virtual bool isConstant() const;
  
  /**
   * @brief 检查声明是否为静态
   * @return 如果声明是静态的，则返回true；否则返回false
   */
  virtual bool isStatic() const;

  /**
   * @brief 虚析构函数
   */
  virtual ~DeclNode() = default;
  
protected:
  /** 声明的名称 */
  std::string name_;
};

} // namespace mycompiler

#endif
