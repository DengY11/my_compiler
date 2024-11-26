#include "ast_node/stat_node/stat_list_node.hpp"
#include "ast_node/stat_node/parameter_stat_node.hpp"
#include "ast_node/terminal_symbols/terminal_separator.hpp"
#include "magic_enum/magic_enum.hpp"
#include "token/token_helper_functions.hpp"
#include "token/token_type.hpp"

#include <memory>
#include <stdexcept>

namespace mycompiler {

StatListNode::StatListNode(std::shared_ptr<Lexer> lexer) : StatNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::STAT_LIST;
}

void StatListNode::print_info() {
  std::cout << "Node type: " << std::endl;
  std::cout << std::string(magic_enum::enum_name(this->ast_node_type_))
            << std::endl;

  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

void StatListNode::Parse() {
  // TODO:
  Token &&token = this->lexer_->getCurrentToken();
  if (token.get_token_type() == TokenType::ILLEGAL_OR_EOF) {
    throw std::runtime_error("illegal token or end of file");
  }

  size_t cnt_big_trace = 0;
}

} // namespace mycompiler
