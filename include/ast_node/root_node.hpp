#ifndef ROOT_NODE
#define ROOT_NODE
#include "./basic_node.hpp"

namespace mycompiler {

class RootNode : public BasicNode {
public:
  RootNode(std::shared_ptr<Lexer> lexer);

  virtual void print_info() override;

  virtual void Parse() override; // TODO:
};

} // namespace mycompiler

#endif
