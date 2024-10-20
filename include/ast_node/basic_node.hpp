#ifndef BASIC_NODE_HPP
#define BASIC_NODE_HPP

#include "../token/token.hpp"
#include <memory>
#include <vector>

namespace mycompiler {

class BasicNode {
public:
  BasicNode(mycompiler::Token token);
  BasicNode(mycompiler::Token &&token);
  BasicNode(BasicNode &&other) = default;

private:
  using ChildPtr = std::shared_ptr<BasicNode>;
  std::vector<ChildPtr> children_;
};

} // namespace mycompiler

#endif
