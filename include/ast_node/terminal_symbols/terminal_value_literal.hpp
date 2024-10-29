#ifndef TERMINAL_VALUE_LITERAL_HPP
#define TERMINAL_VALUE_LITERAL_HPP
#include "../basic_node.hpp"
#include <memory>

namespace mycompiler {

class TerminalValueLiteral : public BasicNode {
public:
  TerminalValueLiteral(std::shared_ptr<Lexer> lexer);

  virtual void print_info() override final;

  virtual void Parse() override final;

  std::string literal_;
};

} // namespace mycompiler

#endif
