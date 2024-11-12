#ifndef COMPARE_EXPR_NODE_HPP
#define COMPARE_EXPR_NODE_HPP

#include "ast_node/expr_node/expr_node.hpp"
#include "ast_node/expr_node/ident_expr_node.hpp"
#include "lexer/lexer.hpp"
#include <memory>

// TODO: literal op literal

namespace mycompiler {

class ConditionExprNode : public ExprNode {
public:
  ConditionExprNode(std::shared_ptr<Lexer> lexer);

  virtual auto print_info() -> void override final;

  virtual auto Parse() -> void override final;

  virtual ~ConditionExprNode() = default;
};

} // namespace mycompiler

#endif
