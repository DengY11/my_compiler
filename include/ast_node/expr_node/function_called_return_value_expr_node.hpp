#ifndef FUNCTION_CALLED_RETURN_VALUE_EXPR_NODE_HPP
#define FUNCTION_CALLED_RETURN_VALUE_EXPR_NODE_HPP

#include "ast_node/expr_node/expr_node.hpp"
namespace mycompiler {

class FunctionCalledReturnValueExprNode : public ExprNode {
public:
  FunctionCalledReturnValueExprNode(std::shared_ptr<Lexer> lexer);

  virtual auto print_info() -> void override final;

  virtual auto Parse() -> void override final;
};

} // namespace mycompiler

#endif
