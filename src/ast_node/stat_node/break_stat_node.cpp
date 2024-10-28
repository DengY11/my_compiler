#include "../../../include/ast_node/stat_node/break_stat_node.hpp"
#include <memory>

namespace mycompiler {

BreakStatNode::BreakStatNode(std::shared_ptr<Lexer> lexer) : StatNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::BREAK_STAT;
}

void BreakStatNode::print_info() {
  std::cout << "Node type: BREAK_STAT" << std::endl;
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

} // namespace mycompiler
