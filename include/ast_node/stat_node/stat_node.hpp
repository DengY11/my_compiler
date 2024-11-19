#ifndef STAT_NODE_HPP
#define STAT_NODE_HPP
#include "ast_node/basic_node.hpp"
#include <memory>

namespace mycompiler {

enum class StatType {
  VOID_STAT,
  SWITCH_STAT,
  WHILE_STAT,
  SELF_CHANGE_STAT,
  RETURN_STAT,
  IF_STAT,
  FOR_STAT,
  EXPR_STAT,
  CONTINUE_STAT,
  CHANGE_VAR_STAT,
  BREAK_STAT,
  FUNCTION_CALL_WITH_RETURN_VALUE_STAT

};

class StatNode : public BasicNode {
public:
  StatNode(std::shared_ptr<Lexer> lexer);

  auto get_stat_type() const -> StatType;

  virtual auto print_info() -> void override;

  virtual auto Parse() -> void override = 0;

  virtual ~StatNode() = default;

private:
  StatType stat_type_;
};

} // namespace mycompiler

#endif
