#ifndef STAT_LIST_NODE_HPP
#define STAT_LIST_NODE_HPP
#include "ast_node/stat_node/stat_node.hpp"
#include <memory>

namespace mycompiler {

class StatListNode : public StatNode {
public:
  StatListNode(std::shared_ptr<Lexer> lexer);

  virtual auto print_info() -> void override;

  virtual auto Parse() -> void override;
  // TODO:
  virtual ~StatListNode() = default;
};

} // namespace mycompiler

#endif
