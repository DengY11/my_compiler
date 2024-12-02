#ifndef BINARY_EXPR_NODE_HPP
#define BINARY_EXPR_NODE_HPP
#include "ast_node/expr_node/expr_node.hpp"
#include "ast_node/terminal_symbols/terminal_operator.hpp"
#include <memory>

namespace mycompiler {

class BinaryExprNode : public ExprNode {

public:
  BinaryExprNode(std::shared_ptr<Lexer> lexer);

  BinaryExprNode(std::shared_ptr<ExprNode> left,
                 std::shared_ptr<TerminalOperator> op,
                 std::shared_ptr<ExprNode> right);

  virtual void print_info() override final;

  virtual void Parse() override final; // TODO:

  auto add_child(std::shared_ptr<ExprNode> left,
                 std::shared_ptr<TerminalOperator> op,
                 std::shared_ptr<ExprNode> right) -> void;

  virtual ~BinaryExprNode() = default;
};

} // namespace mycompiler

#endif
