#ifndef TERMINAL_SEPARATOR_HPP
#define TERMINAL_SEPARATOR_HPP
#include "../../lexer/separator_pool.hpp"
#include "../basic_node.hpp"
#include <memory>

namespace mycompiler {

class TerminalSeparator : public BasicNode {
public:
  TerminalSeparator(std::shared_ptr<Lexer> lexer);

  virtual void print_info() override final;

  virtual void Parse() override final;

  std::string separator_;
};

} // namespace mycompiler

#endif
