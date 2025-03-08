#ifndef LAMBDA_DECL_NODE_HPP
#define LAMBDA_DECL_NODE_HPP
#include "ast_node/decl_node/decl_node.hpp"
#include "ast_node/stat_node/parameter_list_stat_node.hpp"
#include "ast_node/stat_node/block_stat_node.hpp"
#include <memory>
#include <string>

namespace mycompiler {

/**
 * @brief Lambda声明节点类
 * 
 * 表示Lambda表达式声明，包含参数列表和函数体
 */
class LambdaDeclNode : public DeclNode {
public:
  /**
   * @brief 构造函数
   * @param lexer 词法分析器的共享指针
   */
  LambdaDeclNode(std::shared_ptr<Lexer> lexer);

  /**
   * @brief 打印节点信息
   */
  virtual void print_info() override final;
  
  /**
   * @brief 获取节点的字符串表示
   * @return 节点的字符串表示
   */
  virtual std::string toString() const override;

  /**
   * @brief 解析方法
   * 
   * 从词法分析器中读取标记并构建Lambda声明节点
   */
  virtual void Parse() override final;
  
  /**
   * @brief 获取参数列表
   * @return 参数列表节点的共享指针
   */
  std::shared_ptr<ParameterListStatNode> getParameters() const;
  
  /**
   * @brief 获取函数体
   * @return 函数体节点的共享指针
   */
  std::shared_ptr<BlockStatNode> getBody() const;
  
  /**
   * @brief 获取返回类型
   * @return 返回类型字符串
   */
  std::string getReturnType() const;
  
  /**
   * @brief 设置返回类型
   * @param returnType 返回类型字符串
   */
  void setReturnType(const std::string& returnType);

  /**
   * @brief 虚析构函数
   */
  virtual ~LambdaDeclNode() = default;

private:
  /** 参数列表 */
  std::shared_ptr<ParameterListStatNode> parameters_;
  
  /** 函数体 */
  std::shared_ptr<BlockStatNode> body_;
  
  /** 返回类型 */
  std::string returnType_;
};

} // namespace mycompiler

#endif
