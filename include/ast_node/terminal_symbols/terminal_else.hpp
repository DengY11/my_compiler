#ifndef TERMINAL_ELSE_HPP
#define TERMINAL_ELSE_HPP
#include "ast_node/basic_node.hpp"
#include <memory>

namespace mycompiler {

class TerminalElse : public BasicNode {
public:
  TerminalElse(std::shared_ptr<Lexer> lexer);

  virtual void print_info() override final;

  virtual void Parse() override final;

  virtual ~TerminalElse() = default;
};

} // namespace mycompiler

#endif
