#ifndef TERMINAL_EQUAL_HPP
#define TERMINAL_EQUAL_HPP
#include "ast_node/basic_node.hpp"
#include <memory>

namespace mycompiler {

class TerminalEqual : public BasicNode {
public:
  TerminalEqual(std::shared_ptr<Lexer> lexer);

  virtual void print_info() override final;

  virtual void Parse() override final;
};

} // namespace mycompiler

#endif
