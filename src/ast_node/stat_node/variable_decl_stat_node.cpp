#include "ast_node/stat_node/variable_decl_stat_node.hpp"
#include "magic_enum/magic_enum.hpp"
#include <memory>

namespace mycompiler {

VariableDeclStatNode::VariableDeclStatNode(std::shared_ptr<Lexer> lexer)
    : StatNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::VAR_DECL_STAT;
}

void VariableDeclStatNode::print_info() {
  std::cout << "Node type: " << std::endl;
  std::cout << std::string(magic_enum::enum_name(this->ast_node_type_))
            << std::endl;

  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

void VariableDeclStatNode::Parse() {}

} // namespace mycompiler
