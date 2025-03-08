#ifndef CLASS_DECL_NODE_HPP
#define CLASS_DECL_NODE_HPP
#include "ast_node/decl_node/decl_node.hpp"
#include "ast_node/decl_node/var_decl_node.hpp"
#include "ast_node/decl_node/func_decl_node.hpp"
#include <memory>
#include <string>
#include <vector>

namespace mycompiler {

/**
 * @brief 类声明节点类
 * 
 * 表示类声明，包含类名、基类列表、成员变量和成员函数
 */
class ClassDeclNode : public DeclNode {
public:
  /**
   * @brief 构造函数
   * @param lexer 词法分析器的共享指针
   */
  ClassDeclNode(std::shared_ptr<Lexer> lexer);

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
   * 从词法分析器中读取标记并构建类声明节点
   */
  virtual auto Parse() -> void override;
  
  /**
   * @brief 获取基类列表
   * @return 基类列表
   */
  const std::vector<std::string>& getBaseClasses() const;
  
  /**
   * @brief 添加基类
   * @param baseClass 基类名称
   */
  void addBaseClass(const std::string& baseClass);
  
  /**
   * @brief 获取成员变量列表
   * @return 成员变量列表
   */
  const std::vector<std::shared_ptr<VarDeclNode>>& getMemberVariables() const;
  
  /**
   * @brief 添加成员变量
   * @param memberVariable 成员变量
   */
  void addMemberVariable(std::shared_ptr<VarDeclNode> memberVariable);
  
  /**
   * @brief 获取成员函数列表
   * @return 成员函数列表
   */
  const std::vector<std::shared_ptr<FuncDeclNode>>& getMemberFunctions() const;
  
  /**
   * @brief 添加成员函数
   * @param memberFunction 成员函数
   */
  void addMemberFunction(std::shared_ptr<FuncDeclNode> memberFunction);
  
  /**
   * @brief 检查类是否为抽象类
   * @return 如果类是抽象类，则返回true；否则返回false
   */
  bool isAbstract() const;
  
  /**
   * @brief 设置类是否为抽象类
   * @param isAbstract 类是否为抽象类
   */
  void setAbstract(bool isAbstract);
  
  /**
   * @brief 获取类的访问修饰符
   * @return 类的访问修饰符
   */
  std::string getAccessModifier() const;
  
  /**
   * @brief 设置类的访问修饰符
   * @param accessModifier 类的访问修饰符
   */
  void setAccessModifier(const std::string& accessModifier);
  
  /**
   * @brief 获取类的修饰符
   * @return 类的修饰符列表
   */
  const std::vector<std::string>& getModifiers() const;
  
  /**
   * @brief 添加类修饰符
   * @param modifier 类修饰符
   */
  void addModifier(const std::string& modifier);

  /**
   * @brief 虚析构函数
   */
  virtual ~ClassDeclNode() = default;
  
private:
  /** 基类列表 */
  std::vector<std::string> baseClasses_;
  
  /** 成员变量列表 */
  std::vector<std::shared_ptr<VarDeclNode>> memberVariables_;
  
  /** 成员函数列表 */
  std::vector<std::shared_ptr<FuncDeclNode>> memberFunctions_;
  
  /** 类是否为抽象类 */
  bool isAbstract_;
  
  /** 类的访问修饰符 */
  std::string accessModifier_;
  
  /** 类的修饰符 */
  std::vector<std::string> modifiers_;
};

} // namespace mycompiler

#endif 