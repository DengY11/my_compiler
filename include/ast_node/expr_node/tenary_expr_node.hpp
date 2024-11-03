#ifndef TENARY_EXPR_NODE_HPP
#define TENARY_EXPR_NODE_HPP
#include "ast_node/expr_node/expr_node.hpp"

namespace mycompiler {

class TenaryExprNode : public ExprNode {
public:
  TenaryExprNode(std::shared_ptr<Lexer> lexer);

  auto virtual Parse() -> void override final;

  auto virtual print_info() -> void override final;
};

} // namespace mycompiler

#endif
