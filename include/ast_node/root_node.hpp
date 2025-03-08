#ifndef ROOT_NODE
#define ROOT_NODE
#include "ast_node/basic_node.hpp"
#include "ast_node/stat_node/stat_node.hpp"
#include "ast_node/decl_node/decl_node.hpp"
#include <vector>

namespace mycompiler {

/**
 * @brief 抽象语法树的根节点类
 * 
 * 表示整个程序的入口点，包含所有顶级声明和语句
 */
class RootNode : public BasicNode {
public:
  /**
   * @brief 构造函数
   * @param lexer 词法分析器的共享指针
   */
  RootNode(std::shared_ptr<Lexer> lexer);

  /**
   * @brief 打印节点信息
   */
  virtual void print_info() override;
  
  /**
   * @brief 获取节点的字符串表示
   * @return 节点的字符串表示
   */
  virtual std::string toString() const override;

  /**
   * @brief 解析方法
   * 
   * 解析整个程序，构建完整的AST
   */
  virtual void Parse() override;
  
  /**
   * @brief 添加顶级声明
   * @param decl 声明节点的共享指针
   */
  void addDeclaration(std::shared_ptr<DeclNode> decl);
  
  /**
   * @brief 添加顶级语句
   * @param stat 语句节点的共享指针
   */
  void addStatement(std::shared_ptr<StatNode> stat);
  
  /**
   * @brief 获取所有顶级声明
   * @return 声明节点列表
   */
  const std::vector<std::shared_ptr<DeclNode>>& getDeclarations() const;
  
  /**
   * @brief 获取所有顶级语句
   * @return 语句节点列表
   */
  const std::vector<std::shared_ptr<StatNode>>& getStatements() const;

  /**
   * @brief 虚析构函数
   */
  virtual ~RootNode() = default;
  
private:
  /** 顶级声明列表 */
  std::vector<std::shared_ptr<DeclNode>> declarations_;
  
  /** 顶级语句列表 */
  std::vector<std::shared_ptr<StatNode>> statements_;
};

} // namespace mycompiler

#endif
