#ifndef BLOCK_STAT_NODE_HPP
#define BLOCK_STAT_NODE_HPP
#include "ast_node/stat_node/stat_node.hpp"
#include <memory>

namespace mycompiler {

class BlockStatNode : public StatNode {
public:
  BlockStatNode(std::shared_ptr<Lexer> lexer);

  virtual auto print_info() -> void override;

  virtual auto Parse() -> void override;
};

} // namespace mycompiler

#endif
