#ifndef WHILE_STAT_NODE_HPP
#define WHILE_STAT_NODE_HPP
#include "ast_node/stat_node/stat_node.hpp"
#include <memory>

namespace mycompiler {

class WhileStatNode : public StatNode {
public:
  WhileStatNode(std::shared_ptr<Lexer> lexer);

  virtual auto print_info() -> void override;

  virtual auto Parse() -> void override;

  virtual ~WhileStatNode() = default;
};

} // namespace mycompiler

#endif
