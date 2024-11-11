#include "ast_node/stat_node/for_stat_node.hpp"
#include "ast_node/terminal_symbols/terminal_for.hpp"
#include "ast_node/terminal_symbols/terminal_separator.hpp"

#include <memory>
#include <stdexcept>

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

auto ForStatNode::Parse() -> void {
  Token token = this->lexer_->getCurrentToken();
  if (token.get_token_type() == TokenType::ILLEGAL_OR_EOF) {
    throw std::runtime_error("illegal or end of file");
  }

  auto child_for = std::make_shared<TerminalFor>(this->lexer_);
  child_for->Parse();
  this->children_.push_back(child_for);

  this->lexer_->getNextToken();

  auto child_left = std::make_shared<TerminalSeparator>(this->lexer_);
  child_left->Parse();
  if (child_left->separator_ != "(") {
    throw std::runtime_error("expect (");
  }
  this->children_.push_back(child_left);

  this->lexer_->getNextToken();
  // TODO:
}

} // namespace mycompiler
