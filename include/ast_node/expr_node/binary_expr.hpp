#ifndef BINARY_EXPR_NODE_HPP
#define BINARY_EXPR_NODE_HPP
#include "ast_node/expr_node/expr_node.hpp"
#include <memory>

namespace mycompiler {

class BinaryExprNode : public ExprNode {

public:
  BinaryExprNode(std::shared_ptr<Lexer> lexer);

  virtual void print_info() override final;

  virtual void Parse() override final; // TODO:
};

} // namespace mycompiler

#endif
