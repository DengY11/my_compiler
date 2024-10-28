#include "../../../include/ast_node/stat_node/for_stat_node.hpp"
#include <memory>

namespace mycompiler {

ForStatNode::ForStatNode(std::shared_ptr<Lexer> lexer) : StatNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::FOR_STAT;
}

void ForStatNode::print_info() {
  std::cout << "Node type: FOR_STAT" << std::endl;
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

} // namespace mycompiler
