#ifndef TERMINAL_RETURN_HPP
#define TERMINAL_RETURN_HPP

#include "ast_node/basic_node.hpp"
#include <memory>
namespace mycompiler {

class TerminalReturn : public BasicNode {
public:
  TerminalReturn(std::shared_ptr<Lexer> lexer);

  virtual void print_info() override final;

  virtual void Parse() override final;

  virtual ~TerminalReturn() = default;
};

} // namespace mycompiler

#endif
