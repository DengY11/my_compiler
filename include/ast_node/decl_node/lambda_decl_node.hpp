#ifndef LAMBDA_DECL_NODE_HPP
#define LAMBDA_DECL_NODE_HPP
#include "./decl_node.hpp"

namespace mycompiler {

class LambdaDeclNode : public DeclNode {
public:
  LambdaDeclNode();

  virtual void print_info() final;

  auto parse() -> ChildPtr;

private:
};

} // namespace mycompiler

#endif
