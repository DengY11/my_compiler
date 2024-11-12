#ifndef TENARY_EXPR_NODE_HPP
#define TENARY_EXPR_NODE_HPP
#include "ast_node/expr_node/expr_node.hpp"
#include "ast_node/expr_node/literal_expr_node.hpp"
#include "ast_node/terminal_symbols/terminal_operator.hpp"
#include <memory>

namespace mycompiler {

class TenaryExprNode : public ExprNode {
public:
  TenaryExprNode(std::shared_ptr<Lexer> lexer);

  auto virtual Parse() -> void override final;

  auto virtual print_info() -> void override final;

  auto add_child(std::shared_ptr<ExprNode> left,
                 std::shared_ptr<TerminalOperator> op,
                 std::shared_ptr<ExprNode> right) -> void;

  virtual ~TenaryExprNode() = default;
};

} // namespace mycompiler

#endif
