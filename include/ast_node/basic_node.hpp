#ifndef BASIC_NODE_HPP
#define BASIC_NODE_HPP

#include "ast_node/node_type.hpp"
#include "lexer/lexer.hpp"
#include "token/token.hpp"
#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>
#include <string>

namespace mycompiler {

/**
 * @brief 抽象语法树的基本节点类
 * 
 * 所有AST节点类型的基类，提供基本的节点功能和接口
 */
class BasicNode {
public:
  /**
   * @brief 构造函数
   * @param lexer 词法分析器的共享指针
   */
  BasicNode(std::shared_ptr<Lexer> lexer);
  
  /**
   * @brief 移动构造函数
   */
  BasicNode(BasicNode &&other) = default;
  
  /**
   * @brief 添加子节点
   * @param childptr 子节点的共享指针
   */
  void add_child(std::shared_ptr<BasicNode> childptr);
  
  /**
   * @brief 获取节点类型
   * @return 节点类型枚举值
   */
  AST_NODE_TYPE getNodeType() const { return ast_node_type_; }
  
  /**
   * @brief 获取子节点列表
   * @return 子节点列表的常量引用
   */
  const std::vector<std::shared_ptr<BasicNode>>& getChildren() const { return children_; }
  
  /**
   * @brief 获取词法分析器
   * @return 词法分析器的共享指针
   */
  std::shared_ptr<Lexer> getLexer() const { return lexer_; }

  /**
   * @brief 打印节点信息
   * 
   * 默认实现打印节点类型和所有子节点的信息
   */
  virtual void print_info();
  
  /**
   * @brief 获取节点的字符串表示
   * @return 节点的字符串表示
   */
  virtual std::string toString() const;

  /**
   * @brief 解析方法
   * 
   * 从词法分析器中读取标记并构建AST节点
   * 每个派生类必须实现此方法
   */
  virtual void Parse() = 0;

  /**
   * @brief 虚析构函数
   */
  virtual ~BasicNode() = default;

protected:
  /** 节点类型 */
  AST_NODE_TYPE ast_node_type_ = AST_NODE_TYPE::BASIC;
  
  /** 词法分析器 */
  std::shared_ptr<Lexer> lexer_;

  /** 子节点类型别名 */
  using ChildPtr = std::shared_ptr<BasicNode>;
  
  /** 子节点列表 */
  std::vector<ChildPtr> children_;
  
  /**
   * @brief 期望下一个标记是指定类型
   * @param type 期望的标记类型
   * @return 如果下一个标记是指定类型，则返回true；否则返回false
   */
  bool expectNextToken(TokenType type);
  
  /**
   * @brief 消费下一个标记，如果它是指定类型
   * @param type 期望的标记类型
   * @return 如果下一个标记是指定类型，则返回该标记；否则抛出异常
   */
  Token consumeToken(TokenType type);
};

} // namespace mycompiler

#endif
