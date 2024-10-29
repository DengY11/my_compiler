#ifndef LITERAL_EXPR_NDOE_HPP
#define LITERAL_EXPR_NDOE_HPP

#include "expr_node.hpp"
#include <memory>
namespace mycompiler {

class LiteralExprNode : public ExprNode {
public:
  LiteralExprNode(std::shared_ptr<Lexer> lexer);

  virtual auto Parse() -> void override final;

  virtual auto print_info() -> void override final;
};

} // namespace mycompiler

#endif