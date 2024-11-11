#include "ast_node/stat_node/if_stat_node.hpp"
#include "ast_node/expr_node/literal_expr_node.hpp"
#include "ast_node/stat_node/stat_list_node.hpp"
#include "ast_node/terminal_symbols/terminal_if.hpp"
#include "ast_node/terminal_symbols/terminal_separator.hpp"
#include "token/keyword_type.hpp"
#include "token/token_helper_functions.hpp"
#include <memory>
#include <stdexcept>

namespace mycompiler {

IfStatNode::IfStatNode(std::shared_ptr<Lexer> lexer) : StatNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::IF_STAT;
}

void IfStatNode::print_info() {
  std::cout << "Node type: IF_STAT" << std::endl;
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

void IfStatNode::Parse() {
  Token &&token = this->lexer_->getCurrentToken();
  if (token.get_token_type() == TokenType::ILLEGAL_OR_EOF) {
    throw std::runtime_error("illegal token or end of file");
  }

  auto child_if = std::make_shared<TerminalIf>(this->lexer_);
  child_if->Parse();
  this->children_.push_back(child_if);

  this->lexer_->getNextToken();

  auto child_left = std::make_shared<TerminalSeparator>(this->lexer_);
  child_left->Parse();
  if (child_left->separator_ != "(") {
    throw std::runtime_error("expect (");
  } else {
    this->children_.push_back(child_left);
  }

  this->lexer_->getNextToken();

  auto child_value = std::make_shared<LiteralExprNode>(this->lexer_);
  child_value->Parse();
  this->children_.push_back(child_value);

  this->lexer_->getNextToken();

  auto child_right = std::make_shared<TerminalSeparator>(this->lexer_);
  child_right->Parse();
  if (child_right->separator_ != ")") {
    throw std::runtime_error("expect )");
  } else {
    this->children_.push_back(child_right);
  }

  this->lexer_->getNextToken();

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
