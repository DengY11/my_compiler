#ifndef ROOT_NODE
#define ROOT_NODE
#include "./basic_node.hpp"

namespace mycompiler {

class RootNode : public BasicNode {
public:
  RootNode();

  virtual void print_info() override;
};

} // namespace mycompiler

#endif
