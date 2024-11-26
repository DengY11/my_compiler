#include "ast_node/stat_node/break_stat_node.hpp"
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

void BreakStatNode::Parse() {

  Token &&token = this->lexer_->getCurrentToken();
  if (token.get_token_type() == TokenType::ILLEGAL_OR_EOF) {
    throw std::runtime_error("illegal token or end of file");
  }

  auto child_terminal_break = std::make_shared<BreakStatNode>(this->lexer_);
  child_terminal_break->Parse();

  this->children_.push_back(child_terminal_break);
}

} // namespace mycompiler
