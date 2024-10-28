#include "../../../include/ast_node/stat_node/return_stat_node.hpp"
#include <memory>

namespace mycompiler {

ReturnStatNode::ReturnStatNode(std::shared_ptr<Lexer> lexer) : StatNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::RETURN_STAT;
}

void ReturnStatNode::print_info() {
  std::cout << "Node type: RETURN_STAT" << std::endl;
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

} // namespace mycompiler
