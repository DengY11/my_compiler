#ifndef VOID_STAT_NODE_HPP
#define VOID_STAT_NODE_HPP
#include "ast_node/stat_node/stat_node.hpp"
#include <memory>

namespace mycompiler {

class VoidStatNode : public StatNode {
public:
  VoidStatNode(std::shared_ptr<Lexer> lexer);

  virtual auto print_info() -> void override;

  virtual auto Parse() -> void override;

  virtual ~VoidStatNode() = default;
};

} // namespace mycompiler

#endif
