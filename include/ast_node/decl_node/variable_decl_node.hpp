#ifndef VARIABLE_DECL_NODE_HPP
#define VARIABLE_DECL_NODE_HPP
#include "ast_node/decl_node/decl_node.hpp"
#include <memory>

namespace mycompiler {

class VarDeclNode : public DeclNode {
public:
  VarDeclNode(std::shared_ptr<Lexer> lexer);

  virtual void print_info() override final;

  virtual void Parse() override final; // TODO:

  virtual ~VarDeclNode() = default;
};

} // namespace mycompiler

#endif
