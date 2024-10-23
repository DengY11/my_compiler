#ifndef VARIABLE_DECL_NODE_HPP
#define VARIABLE_DECL_NODE_HPP
#include "./decl_node.hpp"

namespace mycompiler {

class VarDeclNode : public DeclNode {
public:
  VarDeclNode();

  virtual void print_info() final;

  auto Parse() -> ChildPtr;
};

} // namespace mycompiler

#endif
