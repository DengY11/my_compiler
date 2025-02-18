#ifndef IF_STAT_NODE_HPP
#define IF_STAT_NODE_HPP
#include "ast_node/stat_node/stat_node.hpp"
#include <memory>

namespace mycompiler {

class IfStatNode : public StatNode {
public:
  IfStatNode(std::shared_ptr<Lexer> lexer);

  virtual auto print_info() -> void override;

  virtual auto Parse() -> void override;

  virtual ~IfStatNode() = default;
};

} // namespace mycompiler

#endif
