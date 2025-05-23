#include "ast_node/stat_node/while_stat_node.hpp"
#include "ast_node/expr_node/condition_expr_node.hpp"
#include "ast_node/expr_node/literal_expr_node.hpp"
#include "ast_node/stat_node/stat_list_node.hpp"
#include "ast_node/terminal_symbols/terminal_separator.hpp"
#include "ast_node/terminal_symbols/terminal_while.hpp"
#include "magic_enum/magic_enum.hpp"
#include <memory>
#include <stdexcept>

namespace mycompiler {

WhileStatNode::WhileStatNode(std::shared_ptr<Lexer> lexer) : StatNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::WHILE_STAT;
}

void WhileStatNode::print_info() {
  std::cout << "Node type: " << std::endl;
  std::cout << std::string(magic_enum::enum_name(this->ast_node_type_))
            << std::endl;

  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

void WhileStatNode::Parse() {

  Token &&token = this->lexer_->getCurrentToken();
  if (token.get_token_type() == TokenType::ILLEGAL_OR_EOF) {
    throw std::runtime_error("illegal token or end of file");
  }

  auto child_while = std::make_shared<TerminalWhile>(this->lexer_);
  child_while->Parse();
  this->children_.push_back(child_while);

  this->lexer_->getNextToken();

  auto child_left = std::make_shared<TerminalSeparator>(this->lexer_);
  child_left->Parse();
  if (child_left->separator_ != "(") {
    throw std::runtime_error("expect (");
  } else {
    this->children_.push_back(child_left);
  }

  auto child_right = std::make_shared<TerminalSeparator>(this->lexer_);
  child_right->Parse();
  if (child_right->separator_ != ")") {
    throw std::runtime_error("expect )");
  } else {
    this->children_.push_back(child_right);
  }

  this->lexer_->getNextToken();

  auto child_value = std::make_shared<ConditionExprNode>(this->lexer_);
  child_value->Parse();
  this->children_.push_back(child_value);

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

  this->lexer_->getNextToken();

  auto child_semicolon = std::make_shared<TerminalSeparator>(this->lexer_);
  child_semicolon->Parse();
  if (child_semicolon->separator_ != ";") {
    throw std::runtime_error("expect ;");
  } else {
    this->children_.push_back(child_semicolon);
  }
}

} // namespace mycompiler
