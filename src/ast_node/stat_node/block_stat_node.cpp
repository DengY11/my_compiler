#include "ast_node/stat_node/block_stat_node.hpp"
#include <memory>

namespace mycompiler {

BlockStatNode::BlockStatNode(std::shared_ptr<Lexer> lexer) : StatNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::BLOCK_STAT;
}

void BlockStatNode::print_info() {
  std::cout << "Node type: BLOCK_STAT" << std::endl;
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

} // namespace mycompiler
