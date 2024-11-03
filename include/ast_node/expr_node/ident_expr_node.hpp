#ifndef IDENT_EXPR_NODE_HPP
#define IDENT_EXPR_NODE_HPP

#include "ast_node/expr_node/expr_node.hpp"
#include <memory>

namespace mycompiler {

class IdentifierExprNode : public ExprNode {
public:
  IdentifierExprNode(std::shared_ptr<Lexer> lexer);
  virtual auto print_info() -> void override final;
  virtual auto Parse() -> void override final;
};

} // namespace mycompiler

#endif
