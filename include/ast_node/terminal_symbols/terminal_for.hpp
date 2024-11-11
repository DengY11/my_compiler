#ifndef TERMINAL_FOR_HPP
#define TERMINAL_FOR_HPP

#include "ast_node/basic_node.hpp"
#include <memory>

namespace mycompiler {

class TerminalFor : public BasicNode {
public:
  TerminalFor(std::shared_ptr<Lexer> lexer);

  virtual void print_info() override final;

  virtual void Parse() override final;

  virtual ~TerminalFor() = default;
};

} // namespace mycompiler

#endif
