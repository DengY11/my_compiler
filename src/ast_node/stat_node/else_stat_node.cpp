#include "ast_node/stat_node/else_stat_node.hpp"
#include "ast_node/stat_node/stat_list_node.hpp"
#include "ast_node/terminal_symbols/terminal_else.hpp"
#include "ast_node/terminal_symbols/terminal_separator.hpp"
#include <memory>

namespace mycompiler {

ElseStatNode::ElseStatNode(std::shared_ptr<Lexer> lexer) : StatNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::ELSE_STAT;
}

void ElseStatNode::print_info() {
  std::cout << "Node type: BREAK_STAT" << std::endl;
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

void ElseStatNode::Parse() {

  Token token = this->lexer_->getCurrentToken();
  if (token.get_token_type() == TokenType::ILLEGAL_OR_EOF) {
    throw std::runtime_error("illegal or end of file");
  }

  auto child_terminal_else = std::make_shared<TerminalElse>(this->lexer_);
  child_terminal_else->Parse();

  this->children_.push_back(child_terminal_else);

  auto child_left_big = std::make_shared<TerminalSeparator>(this->lexer_);
  child_left_big->Parse();
  if (child_left_big->separator_ != "{") {
    throw std::runtime_error("expect {");
  } else {
    this->children_.push_back(child_left_big);
  }
  this->lexer_->getNextToken();

  auto child_stat_list = std::make_shared<StatListNode>(this->lexer_);
  child_stat_list->Parse();
  this->children_.push_back(child_stat_list);

  this->lexer_->getNextToken();

  auto child_right_big = std::make_shared<TerminalSeparator>(this->lexer_);
  child_right_big->Parse();
  if (child_right_big->separator_ != "}") {
    throw std::runtime_error("expect }");
  } else {
    this->children_.push_back(child_right_big);
  }
}

} // namespace mycompiler
