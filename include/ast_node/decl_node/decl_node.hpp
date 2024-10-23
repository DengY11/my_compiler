#ifndef DELC_NODE_HPP
#define DELC_NODE_HPP
#include "../basic_node.hpp"

namespace mycompiler {

class DeclNode : public BasicNode {
public:
  DeclNode();

  virtual void print_info() override;
};

} // namespace mycompiler

#endif
