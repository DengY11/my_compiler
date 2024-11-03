#ifndef CONTINUE_STAT_NODE_HPP
#define CONTINUE_STAT_NODE_HPP
#include "ast_node/stat_node/stat_node.hpp"
#include <memory>

namespace mycompiler {

class ContinueStatNode : public StatNode {
public:
  ContinueStatNode(std::shared_ptr<Lexer> lexer);

  virtual auto print_info() -> void override;

  virtual auto Parse() -> void override;
};

} // namespace mycompiler

#endif
