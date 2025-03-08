#ifndef STAT_NODE_HPP
#define STAT_NODE_HPP
#include "ast_node/ast_node.hpp"
#include <memory>
#include <string>

namespace mycompiler {

/**
 * @brief 语句类型枚举
 * 
 * 定义了所有支持的语句类型
 */
enum class StatType {
  VOID_STAT,                           // 空语句
  SWITCH_STAT,                         // switch语句
  WHILE_STAT,                          // while循环语句
  SELF_CHANGE_STAT,                    // 自增/自减语句
  RETURN_STAT,                         // return语句
  IF_STAT,                             // if语句
  ELSE_STAT,                           // else语句
  FOR_STAT,                            // for循环语句
  EXPR_STAT,                           // 表达式语句
  CONTINUE_STAT,                       // continue语句
  CHANGE_VAR_STAT,                     // 变量赋值语句
  BREAK_STAT,                          // break语句
  FUNCTION_CALL_WITH_RETURN_VALUE_STAT, // 函数调用语句
  FUNC_DECL,                           // 函数声明语句
  VAR_DECL,                            // 变量声明语句
  BLOCK_STAT,                          // 块语句
  PARAMETER_LIST_STAT,                 // 参数列表语句
  PARAMETER_STAT                       // 参数语句
};

/**
 * @brief 语句节点基类
 * 
 * 所有语句节点的基类，提供语句节点的通用接口
 */
class StatNode : public ASTNode {
public:
  /**
   * @brief 构造函数
   * @param lexer 词法分析器的共享指针
   */
  StatNode(std::shared_ptr<Lexer> lexer);

  /**
   * @brief 打印节点信息
   */
  virtual auto print_info() -> void override = 0;
  
  /**
   * @brief 获取节点的字符串表示
   * @return 节点的字符串表示
   */
  virtual std::string toString() const = 0;

  /**
   * @brief 解析方法
   * 
   * 从词法分析器中读取标记并构建语句节点
   */
  virtual auto Parse() -> void override = 0;
  
  /**
   * @brief 检查语句是否为终止语句
   * 
   * 终止语句是指会导致控制流终止的语句，如return、break、continue等
   * 
   * @return 如果是终止语句，则返回true；否则返回false
   */
  virtual bool isTerminating() const = 0;
  
  /**
   * @brief 获取语句的类型
   * @return 语句的类型字符串
   */
  virtual std::string getStatementType() const;

  /**
   * @brief 虚析构函数
   */
  virtual ~StatNode() = default;
};

} // namespace mycompiler

#endif
