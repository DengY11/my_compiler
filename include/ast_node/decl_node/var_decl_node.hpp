#ifndef VAR_DECL_NODE_HPP
#define VAR_DECL_NODE_HPP
#include "ast_node/decl_node/decl_node.hpp"
#include "ast_node/expr_node/expr_node.hpp"
#include <memory>
#include <string>
#include <vector>

namespace mycompiler {

/**
 * @brief 变量声明节点类
 * 
 * 表示变量声明，包含变量名、类型和可选的初始化表达式
 */
class VarDeclNode : public DeclNode {
public:
  /**
   * @brief 构造函数
   * @param lexer 词法分析器的共享指针
   */
  VarDeclNode(std::shared_ptr<Lexer> lexer);

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
   * 从词法分析器中读取标记并构建变量声明节点
   */
  virtual auto Parse() -> void override;
  
  /**
   * @brief 获取变量类型
   * @return 变量类型
   */
  std::string getType() const;
  
  /**
   * @brief 设置变量类型
   * @param type 变量类型
   */
  void setType(const std::string& type);
  
  /**
   * @brief 获取初始化表达式
   * @return 初始化表达式的共享指针，如果没有初始化表达式则返回nullptr
   */
  std::shared_ptr<ExprNode> getInitializer() const;
  
  /**
   * @brief 设置初始化表达式
   * @param initializer 初始化表达式的共享指针
   */
  void setInitializer(std::shared_ptr<ExprNode> initializer);
  
  /**
   * @brief 检查变量是否为常量
   * @return 如果变量是常量，则返回true；否则返回false
   */
  virtual bool isConstant() const override;
  
  /**
   * @brief 设置变量是否为常量
   * @param isConstant 变量是否为常量
   */
  void setConstant(bool isConstant);
  
  /**
   * @brief 检查变量是否为静态
   * @return 如果变量是静态的，则返回true；否则返回false
   */
  virtual bool isStatic() const override;
  
  /**
   * @brief 设置变量是否为静态
   * @param isStatic 变量是否为静态
   */
  void setStatic(bool isStatic);
  
  /**
   * @brief 获取变量的修饰符
   * @return 变量的修饰符列表
   */
  const std::vector<std::string>& getModifiers() const;
  
  /**
   * @brief 添加变量修饰符
   * @param modifier 变量修饰符
   */
  void addModifier(const std::string& modifier);

  /**
   * @brief 虚析构函数
   */
  virtual ~VarDeclNode() = default;
  
private:
  /** 变量类型 */
  std::string type_;
  
  /** 初始化表达式 */
  std::shared_ptr<ExprNode> initializer_;
  
  /** 变量是否为常量 */
  bool isConstant_;
  
  /** 变量是否为静态 */
  bool isStatic_;
  
  /** 变量修饰符 */
  std::vector<std::string> modifiers_;
};

} // namespace mycompiler

#endif 