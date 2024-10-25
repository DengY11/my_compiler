#ifndef LAMBDA_DECL_NODE_HPP
#define LAMBDA_DECL_NODE_HPP
#include "./decl_node.hpp"
#include <memory>

namespace mycompiler {

class LambdaDeclNode : public DeclNode {
public:
  LambdaDeclNode(std::shared_ptr<Lexer> lexer);

  virtual void print_info() override final;

  virtual void Parse() override final; // TODO:

private:
};

} // namespace mycompiler

#endif
