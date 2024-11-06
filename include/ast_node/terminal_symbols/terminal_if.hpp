#ifndef TERMINAL_IF_HPP
#define TERMINAL_IF_HPP

#include "ast_node/basic_node.hpp"
#include <memory>

namespace mycompiler {

class TerminalIf : public BasicNode {
public:
  TerminalIf(std::shared_ptr<Lexer> lexer);

  virtual void print_info() override final;

  virtual void Parse() override final;

  virtual ~TerminalIf() = default;
};

} // namespace mycompiler

#endif
