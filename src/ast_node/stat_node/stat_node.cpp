#include "../../../include/ast_node/stat_node/stat_node.hpp"
#include <memory>

namespace mycompiler {

StatNode::StatNode(std::shared_ptr<Lexer> lexer) : BasicNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::STAT;
}

void StatNode::print_info() {
  std::cout << "Node type: StatNode" << std::endl;
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

} // namespace mycompiler
