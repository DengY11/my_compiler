#ifndef FUNC_DECL_NODE_HPP
#define FUNC_DECL_NODE_HPP
#include "ast_node/decl_node/decl_node.hpp"
#include "ast_node/decl_node/var_decl_node.hpp"
#include "ast_node/stat_node/block_stat_node.hpp"
#include <memory>
#include <string>
#include <vector>

namespace mycompiler {

/**
 * @brief 函数声明节点类
 * 
 * 表示函数声明，包含函数名、返回类型、参数列表和函数体
 */
class FuncDeclNode : public DeclNode {
public:
  /**
   * @brief 构造函数
   * @param lexer 词法分析器的共享指针
   */
  FuncDeclNode(std::shared_ptr<Lexer> lexer);

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
   * 从词法分析器中读取标记并构建函数声明节点
   */
  virtual auto Parse() -> void override;
  
  /**
   * @brief 获取函数返回类型
   * @return 函数返回类型
   */
  std::string getReturnType() const;
  
  /**
   * @brief 设置函数返回类型
   * @param returnType 函数返回类型
   */
  void setReturnType(const std::string& returnType);
  
  /**
   * @brief 获取函数参数列表
   * @return 函数参数列表
   */
  const std::vector<std::shared_ptr<VarDeclNode>>& getParameters() const;
  
  /**
   * @brief 添加函数参数
   * @param parameter 函数参数
   */
  void addParameter(std::shared_ptr<VarDeclNode> parameter);
  
  /**
   * @brief 获取函数体
   * @return 函数体的共享指针
   */
  std::shared_ptr<BlockStatNode> getBody() const;
  
  /**
   * @brief 设置函数体
   * @param body 函数体的共享指针
   */
  void setBody(std::shared_ptr<BlockStatNode> body);
  
  /**
   * @brief 检查函数是否为静态
   * @return 如果函数是静态的，则返回true；否则返回false
   */
  virtual bool isStatic() const override;
  
  /**
   * @brief 设置函数是否为静态
   * @param isStatic 函数是否为静态
   */
  void setStatic(bool isStatic);
  
  /**
   * @brief 检查函数是否为虚函数
   * @return 如果函数是虚函数，则返回true；否则返回false
   */
  bool isVirtual() const;
  
  /**
   * @brief 设置函数是否为虚函数
   * @param isVirtual 函数是否为虚函数
   */
  void setVirtual(bool isVirtual);
  
  /**
   * @brief 检查函数是否为纯虚函数
   * @return 如果函数是纯虚函数，则返回true；否则返回false
   */
  bool isPureVirtual() const;
  
  /**
   * @brief 设置函数是否为纯虚函数
   * @param isPureVirtual 函数是否为纯虚函数
   */
  void setPureVirtual(bool isPureVirtual);
  
  /**
   * @brief 获取函数的修饰符
   * @return 函数的修饰符列表
   */
  const std::vector<std::string>& getModifiers() const;
  
  /**
   * @brief 添加函数修饰符
   * @param modifier 函数修饰符
   */
  void addModifier(const std::string& modifier);

  /**
   * @brief 虚析构函数
   */
  virtual ~FuncDeclNode() = default;
  
private:
  /** 函数返回类型 */
  std::string returnType_;
  
  /** 函数参数列表 */
  std::vector<std::shared_ptr<VarDeclNode>> parameters_;
  
  /** 函数体 */
  std::shared_ptr<BlockStatNode> body_;
  
  /** 函数是否为静态 */
  bool isStatic_;
  
  /** 函数是否为虚函数 */
  bool isVirtual_;
  
  /** 函数是否为纯虚函数 */
  bool isPureVirtual_;
  
  /** 函数修饰符 */
  std::vector<std::string> modifiers_;
};

} // namespace mycompiler

#endif 