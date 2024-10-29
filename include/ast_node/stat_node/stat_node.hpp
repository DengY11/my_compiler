#ifndef STAT_NODE_HPP
#define STAT_NODE_HPP
#include "../basic_node.hpp"
#include <memory>

namespace mycompiler {

class StatNode : public BasicNode {
public:
  StatNode(std::shared_ptr<Lexer> lexer);

  virtual auto print_info() -> void override;

  virtual auto Parse() -> void override = 0;
};

} // namespace mycompiler

#endif
