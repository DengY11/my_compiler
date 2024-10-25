#ifndef GROUP_EXPR_NODE_HPP
#define GROUP_EXPR_NODE_HPP

#include "./expr_node.hpp"
namespace mycompiler {

class GroupExprNode : public ExprNode {
public:
  GroupExprNode(std::shared_ptr<Lexer> lexer);

  virtual auto print_info() -> void override final;

  virtual auto Parse() -> void override final;
};

} // namespace mycompiler

#endif
