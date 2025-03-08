#ifndef ENUM_DECL_NODE_HPP
#define ENUM_DECL_NODE_HPP
#include "ast_node/decl_node/decl_node.hpp"
#include "ast_node/expr_node/expr_node.hpp"
#include <memory>
#include <string>
#include <vector>
#include <utility>

namespace mycompiler {

/**
 * @brief 枚举声明节点类
 * 
 * 表示枚举声明，包含枚举名和枚举值列表
 */
class EnumDeclNode : public DeclNode {
public:
  /**
   * @brief 构造函数
   * @param lexer 词法分析器的共享指针
   */
  EnumDeclNode(std::shared_ptr<Lexer> lexer);

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
   * 从词法分析器中读取标记并构建枚举声明节点
   */
  virtual auto Parse() -> void override;
  
  /**
   * @brief 获取枚举值列表
   * @return 枚举值列表，每个枚举值是一个名称和可选的初始化表达式的对
   */
  const std::vector<std::pair<std::string, std::shared_ptr<ExprNode>>>& getEnumValues() const;
  
  /**
   * @brief 添加枚举值
   * @param name 枚举值名称
   * @param value 枚举值的初始化表达式，可以为nullptr
   */
  void addEnumValue(const std::string& name, std::shared_ptr<ExprNode> value);
  
  /**
   * @brief 检查枚举是否为类枚举
   * @return 如果枚举是类枚举，则返回true；否则返回false
   */
  bool isClassEnum() const;
  
  /**
   * @brief 设置枚举是否为类枚举
   * @param isClassEnum 枚举是否为类枚举
   */
  void setClassEnum(bool isClassEnum);
  
  /**
   * @brief 获取枚举的基础类型
   * @return 枚举的基础类型，如果没有指定则为空字符串
   */
  std::string getBaseType() const;
  
  /**
   * @brief 设置枚举的基础类型
   * @param baseType 枚举的基础类型
   */
  void setBaseType(const std::string& baseType);
  
  /**
   * @brief 获取枚举的访问修饰符
   * @return 枚举的访问修饰符
   */
  std::string getAccessModifier() const;
  
  /**
   * @brief 设置枚举的访问修饰符
   * @param accessModifier 枚举的访问修饰符
   */
  void setAccessModifier(const std::string& accessModifier);

  /**
   * @brief 虚析构函数
   */
  virtual ~EnumDeclNode() = default;
  
private:
  /** 枚举值列表 */
  std::vector<std::pair<std::string, std::shared_ptr<ExprNode>>> enumValues_;
  
  /** 枚举是否为类枚举 */
  bool isClassEnum_;
  
  /** 枚举的基础类型 */
  std::string baseType_;
  
  /** 枚举的访问修饰符 */
  std::string accessModifier_;
};

} // namespace mycompiler

#endif 