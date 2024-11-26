#ifndef ELSE_STAT_NODE_HPP
#define ELSE_STAT_NODE_HPP
#include "ast_node/stat_node/stat_node.hpp"
#include <memory>

namespace mycompiler {

class ElseStatNode : public StatNode {
public:
  ElseStatNode(std::shared_ptr<Lexer> lexer);

  virtual auto print_info() -> void override;

  virtual auto Parse() -> void override;

  virtual ~ElseStatNode() = default;
};

} // namespace mycompiler

#endif
