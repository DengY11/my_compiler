#ifndef TERMINAL_BREAK_HPP
#define TERMINAL_BREAK_HPP

#include "ast_node/basic_node.hpp"
#include <memory>

namespace mycompiler {

class TerminalBreak : public BasicNode {
public:
  TerminalBreak(std::shared_ptr<Lexer> lexer);

  virtual void print_info() override final;

  virtual void Parse() override final;

  virtual ~TerminalBreak() = default;
};

} // namespace mycompiler

#endif
