#ifndef LITERAL_EXPR_NDOE_HPP
#define LITERAL_EXPR_NDOE_HPP

#include "ast_node/expr_node/expr_node.hpp"
#include "ast_node/terminal_symbols/terminal_value_literal.hpp"
#include <memory>

namespace mycompiler {

class LiteralExprNode : public ExprNode {
public:
  LiteralExprNode(std::shared_ptr<Lexer> lexer);

  virtual auto Parse() -> void override final;

  virtual auto print_info() -> void override final;

  virtual ~LiteralExprNode() = default;

  void add_terminalvalue_node(std::shared_ptr<TerminalValueLiteral> val);
};

} // namespace mycompiler

#endif
