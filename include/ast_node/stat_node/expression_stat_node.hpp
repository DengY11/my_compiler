#ifndef EXPRESSION_STAT_NODE_HPP
#define EXPRESSION_STAT_NODE_HPP
#include "ast_node/expr_node/literal_expr_node.hpp"
#include "ast_node/stat_node/stat_node.hpp"
#include <memory>

namespace mycompiler {

class ExpressionStatNode : public StatNode {
public:
  ExpressionStatNode(std::shared_ptr<Lexer> lexer);

  ExpressionStatNode(std::shared_ptr<LiteralExprNode> val);

  virtual auto print_info() -> void override;

  virtual auto Parse() -> void override;

  virtual ~ExpressionStatNode() = default;
};

} // namespace mycompiler

#endif
