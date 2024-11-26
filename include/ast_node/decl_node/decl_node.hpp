#ifndef DELC_NODE_HPP
#define DELC_NODE_HPP
#include "ast_node/basic_node.hpp"
#include "ast_node/stat_node/stat_node.hpp"

namespace mycompiler {

class DeclNode : public StatNode {
public:
  DeclNode(std::shared_ptr<Lexer> lexer);

  virtual void print_info() override;

  virtual void Parse() override = 0; // TODO:

  virtual ~DeclNode() = default;
};

} // namespace mycompiler

#endif
