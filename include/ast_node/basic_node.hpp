#ifndef BASIC_NODE_HPP
#define BASIC_NODE_HPP

#include "ast_node/node_type.hpp"
#include "lexer/lexer.hpp"
#include "token/token.hpp"
#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

namespace mycompiler {

class BasicNode {
public:
  BasicNode(std::shared_ptr<Lexer> lexer);
  BasicNode(BasicNode &&other) = default;

  void add_child(std::shared_ptr<BasicNode> childptr);

  virtual void print_info();

  virtual void Parse() = 0;

  virtual ~BasicNode() = default;

protected:
  AST_NODE_TYPE ast_node_type_ = AST_NODE_TYPE::BASIC;
  std::shared_ptr<Lexer> lexer_;

  using ChildPtr = std::shared_ptr<BasicNode>;
  std::vector<ChildPtr> children_;
};

} // namespace mycompiler

#endif
