#ifndef TERMINAL_LET_HPP
#define TERMINAL_LET_HPP

#include "ast_node/basic_node.hpp"
#include <memory>

namespace mycompiler {

class TerminalLet : public BasicNode {
public:
  TerminalLet(std::shared_ptr<Lexer> lexer);

  virtual void print_info() override final;

  virtual void Parse() override final;
};

} // namespace mycompiler

#endif
