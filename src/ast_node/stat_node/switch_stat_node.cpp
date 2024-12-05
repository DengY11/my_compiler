#include "ast_node/stat_node/switch_stat_node.hpp"
#include "ast_node/terminal_symbols/terminal_switch.hpp"
#include "magic_enum/magic_enum.hpp"
#include <memory>

namespace mycompiler {

SwitchStatNode::SwitchStatNode(std::shared_ptr<Lexer> lexer) : StatNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::SWITCH_STAT;
}

void SwitchStatNode::print_info() {
  std::cout << "Node type: " << std::endl;
  std::cout << std::string(magic_enum::enum_name(this->ast_node_type_))
            << std::endl;

  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

void SwitchStatNode::Parse() {

  Token &&token = this->lexer_->getCurrentToken();
  if (token.get_token_type() == TokenType::ILLEGAL_OR_EOF) {
    throw std::runtime_error("illegal token or end of file");
  }

  auto child_terminal_switch_stat =
      std::make_shared<TerminalSwitch>(this->lexer_);
  child_terminal_switch_stat->Parse();
  this->children_.push_back(child_terminal_switch_stat);

  // TODO:
}

} // namespace mycompiler
