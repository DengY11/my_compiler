#ifndef VARIABLE_DECL_STAT_NODE_HPP
#define VARIABLE_DECL_STAT_NODE_HPP
#include "ast_node/decl_node/variable_decl_node.hpp"
#include "ast_node/stat_node/stat_node.hpp"
#include <memory>

namespace mycompiler {

class VariableDeclStatNode : public StatNode {
public:
  VariableDeclStatNode(std::shared_ptr<Lexer> lexer);

  virtual auto print_info() -> void override;

  virtual auto Parse() -> void override;

  virtual ~VariableDeclStatNode() = default;
};

} // namespace mycompiler

#endif
