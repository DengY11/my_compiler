#ifndef FOR_STAT_NODE_HPP
#define FOR_STAT_NODE_HPP
#include "ast_node/stat_node/stat_node.hpp"
#include <memory>

namespace mycompiler {

class ForStatNode : public StatNode {
public:
  ForStatNode(std::shared_ptr<Lexer> lexer);

  virtual auto print_info() -> void override;

  virtual auto Parse() -> void override;

  virtual ~ForStatNode() = default;
};

} // namespace mycompiler

#endif
