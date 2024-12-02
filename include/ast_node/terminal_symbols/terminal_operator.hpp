#ifndef TERMINAL_OPERATOR_HPP
#define TERMINAL_OPERATOR_HPP
#include "ast_node/basic_node.hpp"
#include <memory>

namespace mycompiler {

class TerminalOperator : public BasicNode {
public:
  TerminalOperator(std::shared_ptr<Lexer> lexer);

  virtual void print_info() override final;

  virtual void Parse() override final;

  auto is_binary_operator() -> bool;

  auto is_unary_operator() -> bool;

  virtual ~TerminalOperator() = default;

  std::string operator_;
};

} // namespace mycompiler

#endif
