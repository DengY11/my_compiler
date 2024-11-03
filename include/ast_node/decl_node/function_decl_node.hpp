#ifndef FUNCTION_DECL_NODE_HPP
#define FUNCTION_DECL_NODE_HPP
#include "ast_node/decl_node/decl_node.hpp"
#include <memory>

namespace mycompiler {

class FuncDeclNode : DeclNode {
public:
  FuncDeclNode(std::shared_ptr<Lexer> lexer);
  virtual void print_info() override final;

  virtual void Parse() override final; // TODO:

private:
  // TODO:
};

} // namespace mycompiler

#endif
