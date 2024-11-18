#ifndef SELF_CHANGE_STAT_NODE_HPP
#define SELF_CHANGE_STAT_NODE_HPP
#include "ast_node/stat_node/stat_node.hpp"
#include "ast_node/terminal_symbols/terminal_ident_literal.hpp"
#include "ast_node/terminal_symbols/terminal_operator.hpp"
#include <memory>

namespace mycompiler {

class SelfChangeStatNode : public StatNode {
public:
  SelfChangeStatNode(std::shared_ptr<Lexer> lexer);

  SelfChangeStatNode(std::shared_ptr<TerminalIdentLiteral> var_name,
                     std::shared_ptr<TerminalOperator> ops);

  SelfChangeStatNode(std::shared_ptr<TerminalOperator> ops,
                     std::shared_ptr<TerminalIdentLiteral> var_name);

  virtual auto print_info() -> void override;

  virtual auto Parse() -> void override;

  virtual ~SelfChangeStatNode() = default;
};

} // namespace mycompiler

#endif
