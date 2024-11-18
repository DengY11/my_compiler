#ifndef LITERAL_EXPR_NDOE_HPP
#define LITERAL_EXPR_NDOE_HPP

#include "ast_node/expr_node/expr_node.hpp"
#include "ast_node/terminal_symbols/terminal_ident_literal.hpp"
#include "ast_node/terminal_symbols/terminal_operator.hpp"
#include "ast_node/terminal_symbols/terminal_value_literal.hpp"
#include <memory>

namespace mycompiler {

class LiteralExprNode : public ExprNode {
public:
  LiteralExprNode(std::shared_ptr<Lexer> lexer);

  LiteralExprNode(std::shared_ptr<TerminalIdentLiteral> var_name,
                  std::shared_ptr<TerminalOperator> op,
                  std::shared_ptr<TerminalValueLiteral> val);

  virtual auto Parse() -> void override final;

  virtual auto print_info() -> void override final;

  virtual ~LiteralExprNode() = default;

  void add_terminalvalue_node(std::shared_ptr<TerminalValueLiteral> val);
};

} // namespace mycompiler

#endif
