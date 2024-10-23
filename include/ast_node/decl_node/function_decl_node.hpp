#ifndef FUNCTION_DECL_NODE_HPP
#define FUNCTION_DECL_NODE_HPP
#include "./decl_node.hpp"

namespace mycompiler {

class FuncDeclNode : DeclNode {
public:
  FuncDeclNode();
  virtual void print_info() final;

  auto Parse() -> ChildPtr; // TODO:

private:
  // TODO:
};

} // namespace mycompiler

#endif
