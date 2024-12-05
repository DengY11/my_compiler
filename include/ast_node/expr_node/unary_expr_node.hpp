#ifndef UNARY_EXPR_NODE_HPP
#define UNARY_EXPR_NODE_HPP
#include "ast_node/expr_node/expr_node.hpp"
#include "ast_node/terminal_symbols/terminal_operator.hpp"
#include "ast_node/terminal_symbols/terminal_value_literal.hpp"
#include <memory>

namespace mycompiler {

class UnaryExprNode : public ExprNode {
public:
  UnaryExprNode(std::shared_ptr<Lexer> lexer);

  UnaryExprNode(std::shared_ptr<TerminalOperator> op,
                std::shared_ptr<ExprNode> right);

  auto add_child(std::shared_ptr<TerminalOperator> op,
                 std::shared_ptr<ExprNode> right) -> void;

  auto add_child(std::shared_ptr<TerminalOperator> op,
                 std::shared_ptr<TerminalValueLiteral> right) -> void;

  virtual auto Parse() -> void override final;

  virtual auto print_info() -> void override final;

  virtual ~UnaryExprNode() = default;
};

} // namespace mycompiler

#endif
