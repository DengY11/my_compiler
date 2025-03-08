#ifndef AST_NODE_HPP
#define AST_NODE_HPP
#include "lexer/lexer.hpp"
#include <memory>
#include <string>

namespace mycompiler {

/**
 * @brief 抽象语法树节点基类
 * 
 * 所有AST节点的基类，提供AST节点的通用接口
 */
class ASTNode {
public:
  /**
   * @brief 构造函数
   * @param lexer 词法分析器的共享指针
   */
  ASTNode(std::shared_ptr<Lexer> lexer);

  /**
   * @brief 打印节点信息
   */
  virtual auto print_info() -> void = 0;
  
  /**
   * @brief 获取节点的字符串表示
   * @return 节点的字符串表示
   */
  virtual std::string toString() const = 0;

  /**
   * @brief 解析方法
   * 
   * 从词法分析器中读取标记并构建AST节点
   */
  virtual auto Parse() -> void = 0;
  
  /**
   * @brief 获取词法分析器
   * @return 词法分析器的共享指针
   */
  std::shared_ptr<Lexer> getLexer() const;
  
  /**
   * @brief 设置词法分析器
   * @param lexer 词法分析器的共享指针
   */
  void setLexer(std::shared_ptr<Lexer> lexer);
  
  /**
   * @brief 获取节点的行号
   * @return 节点的行号
   */
  int getLineNumber() const;
  
  /**
   * @brief 设置节点的行号
   * @param lineNumber 节点的行号
   */
  void setLineNumber(int lineNumber);
  
  /**
   * @brief 获取节点的列号
   * @return 节点的列号
   */
  int getColumnNumber() const;
  
  /**
   * @brief 设置节点的列号
   * @param columnNumber 节点的列号
   */
  void setColumnNumber(int columnNumber);
  
  /**
   * @brief 获取节点的类型
   * @return 节点的类型字符串
   */
  virtual std::string getNodeType() const;

  /**
   * @brief 虚析构函数
   */
  virtual ~ASTNode() = default;
  
protected:
  /** 词法分析器 */
  std::shared_ptr<Lexer> lexer_;
  
  /** 节点的行号 */
  int lineNumber_;
  
  /** 节点的列号 */
  int columnNumber_;
};

} // namespace mycompiler

#endif 