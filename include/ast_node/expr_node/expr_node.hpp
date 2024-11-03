#ifndef EXPR_NODE_HPP
#define EXPR_NODE_HPP
#include "ast_node/basic_node.hpp"
#include <memory>

namespace mycompiler {

class ExprNode : public BasicNode {
public:
  ExprNode(std::shared_ptr<Lexer> lexer);

  virtual void print_info() override;

  virtual void Parse() override = 0; // TODO:
};

} // namespace mycompiler

#endif
