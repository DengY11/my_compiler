#ifndef TERMINAL_CONTINUE_HPP
#define TERMINAL_CONTINUE_HPP

#include "ast_node/basic_node.hpp"
#include <memory>

namespace mycompiler {

class TerminalContinue : public BasicNode {
public:
  TerminalContinue(std::shared_ptr<Lexer> lexer);

  virtual void print_info() override final;

  virtual void Parse() override final;

  virtual ~TerminalContinue() = default;
};

} // namespace mycompiler

#endif
