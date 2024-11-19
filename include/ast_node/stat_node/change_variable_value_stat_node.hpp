#ifndef CHANGE_VARIABLE_VALUE_STAT_NODE_HPP
#define CHANGE_VARIABLE_VALUE_STAT_NODE_HPP
#include "ast_node/stat_node/stat_node.hpp"
#include <memory>

namespace mycompiler {

class ChangeVariableValueStatNode : public StatNode {
public:
  ChangeVariableValueStatNode(std::shared_ptr<Lexer> lexer);

  virtual auto print_info() -> void override;

  virtual auto Parse() -> void override;

  virtual ~ChangeVariableValueStatNode() = default;
};

} // namespace mycompiler

#endif
