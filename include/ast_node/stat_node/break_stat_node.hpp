#ifndef BREAK_STAT_NODE_HPP
#define BREAK_STAT_NODE_HPP
#include "ast_node/stat_node/stat_node.hpp"
#include <memory>

namespace mycompiler {

class BreakStatNode : public StatNode {
public:
  BreakStatNode(std::shared_ptr<Lexer> lexer);

  virtual auto print_info() -> void override;

  virtual auto Parse() -> void override;
};

} // namespace mycompiler

#endif
