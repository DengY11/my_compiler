#ifndef TERMINAL_IDENT_LITERAL_HPP
#define TERMINAL_IDENT_LITERAL_HPP
#include "ast_node/basic_node.hpp"
#include <memory>

namespace mycompiler {

class TerminalIdentLiteral : public BasicNode {
public:
  TerminalIdentLiteral(std::shared_ptr<Lexer> lexer);

  virtual void print_info() override final;

  virtual void Parse() override final;

  virtual ~TerminalIdentLiteral() = default;

  std::string literal_;
};

} // namespace mycompiler

#endif
