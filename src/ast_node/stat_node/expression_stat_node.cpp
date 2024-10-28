#include "../../../include/ast_node/stat_node/expression_stat_node.hpp"
#include <memory>

namespace mycompiler {

ExpressionStatNode::ExpressionStatNode(std::shared_ptr<Lexer> lexer)
    : StatNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::EXPRESSION_STAT;
}

void ExpressionStatNode::print_info() {
  std::cout << "Node type: EXPRESSION_STAT" << std::endl;
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

} // namespace mycompiler
