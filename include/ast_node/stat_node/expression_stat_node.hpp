#ifndef EXPRESSION_STAT_NODE_HPP
#define EXPRESSION_STAT_NODE_HPP
#include "./stat_node.hpp"
#include <memory>

namespace mycompiler {

class ExpressionStatNode : public StatNode {
public:
  ExpressionStatNode(std::shared_ptr<Lexer> lexer);

  virtual auto print_info() -> void override;

  virtual auto Parse() -> void override;
};

} // namespace mycompiler

#endif
