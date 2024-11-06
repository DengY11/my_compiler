#ifndef SWITCH_STAT_NODE_HPP
#define SWITCH_STAT_NODE_HPP
#include "ast_node/stat_node/stat_node.hpp"
#include <memory>

namespace mycompiler {

class SwitchStatNode : public StatNode {
public:
  SwitchStatNode(std::shared_ptr<Lexer> lexer);

  virtual auto print_info() -> void override;

  virtual auto Parse() -> void override;

  virtual ~SwitchStatNode() = default;
};

} // namespace mycompiler

#endif
