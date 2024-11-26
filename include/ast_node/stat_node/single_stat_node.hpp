#ifndef BLOCK_STAT_NODE_HPP
#define BLOCK_STAT_NODE_HPP
#include "ast_node/stat_node/stat_node.hpp"
#include <memory>

namespace mycompiler {

class SingleStatNode : public StatNode {
public:
  SingleStatNode(std::shared_ptr<Lexer> lexer);

  auto get_stat_type() const -> StatType;

  virtual auto print_info() -> void override;

  virtual auto Parse() -> void override;

  virtual ~SingleStatNode() = default;

private:
  StatType stat_type_;
};

} // namespace mycompiler

#endif
