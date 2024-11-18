#ifndef CHANGE_VARIABLE_VALUE_STAT_NODE_HPP
#define CHANGE_VARIABLE_VALUE_STAT_NODE_HPP
#include "ast_node/stat_node/stat_node.hpp"
#include <memory>

namespace mycompiler {

class ChangeVariableValueStatNodeHpp : public StatNode {
public:
  ChangeVariableValueStatNodeHpp(std::shared_ptr<Lexer> lexer);

  virtual auto print_info() -> void override;

  virtual auto Parse() -> void override;

  virtual ~ChangeVariableValueStatNodeHpp() = default;
};

} // namespace mycompiler

#endif
