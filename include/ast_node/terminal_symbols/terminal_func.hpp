#ifndef TERMINAL_FUNC_HPP
#define TERMINAL_FUNC_HPP

#include "ast_node/basic_node.hpp"
#include <memory>

namespace mycompiler {

class TerminalFunc : public BasicNode {
public:
  TerminalFunc(std::shared_ptr<Lexer> lexer);

  virtual void print_info() override final;

  virtual void Parse() override final;
};

} // namespace mycompiler

#endif
