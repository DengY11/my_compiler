#ifndef BASIC_NODE_HPP
#define BASIC_NODE_HPP

#include "../token/token.hpp"
#include "./node_type.hpp"
#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

namespace mycompiler {

class BasicNode {
public:
  BasicNode();
  BasicNode(BasicNode &&other) = default;

  void add_child(std::shared_ptr<BasicNode> childptr);

  virtual void print_info();

protected:
  AST_NODE_TYPE ast_node_type_ = AST_NODE_TYPE::BASIC;

  using ChildPtr = std::shared_ptr<BasicNode>;
  std::vector<ChildPtr> children_;
};

} // namespace mycompiler

#endif
