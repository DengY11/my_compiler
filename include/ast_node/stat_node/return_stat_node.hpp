#ifndef RETURN_STAT_NODE_HPP
#define RETURN_STAT_NODE_HPP
#include "ast_node/stat_node/stat_node.hpp"
#include <memory>

namespace mycompiler {

class ReturnStatNode : public StatNode {
public:
  ReturnStatNode(std::shared_ptr<Lexer> lexer);

  virtual auto print_info() -> void override;

  virtual auto Parse() -> void override;

  virtual ~ReturnStatNode() = default;
};

} // namespace mycompiler

#endif
