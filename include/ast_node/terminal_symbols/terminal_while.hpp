#ifndef TERMINAL_WHILE_HPP
#define TERMINAL_WHILE_HPP
#include "ast_node/basic_node.hpp"
#include <memory>

namespace mycompiler {

class TerminalWhile : public BasicNode {
public:
  TerminalWhile(std::shared_ptr<Lexer> lexer);

  virtual void print_info() override final;

  virtual void Parse() override final;

  virtual ~TerminalWhile() = default;
};

} // namespace mycompiler

#endif
