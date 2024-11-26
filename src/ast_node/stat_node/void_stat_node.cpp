#include "ast_node/stat_node/void_stat_node.hpp"

#include "magic_enum/magic_enum.hpp"
namespace mycompiler {

VoidStatNode ::VoidStatNode(std::shared_ptr<Lexer> lexer) : StatNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::VOID_STAT;
}

void VoidStatNode::print_info() {
  std::cout << "Node type: " << std::endl;
  std::cout << std::string(magic_enum::enum_name(this->ast_node_type_))
            << std::endl;

  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

void VoidStatNode::Parse() {}

} // namespace mycompiler
