#include "ast_node/stat_node/self_change_stat_node.hpp"
#include "ast_node/node_type.hpp"
#include "ast_node/stat_node/stat_node.hpp"
#include "ast_node/terminal_symbols/terminal_ident_literal.hpp"
#include "ast_node/terminal_symbols/terminal_operator.hpp"
#include "magic_enum/magic_enum.hpp"
#include "token/token_type.hpp"
#include <memory>
#include <stdexcept>

namespace mycompiler {

SelfChangeStatNode ::SelfChangeStatNode(std::shared_ptr<Lexer> lexer)
    : StatNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::SELF_CHANGE_STAT;
}

SelfChangeStatNode::SelfChangeStatNode(
    std::shared_ptr<TerminalOperator> ops,
    std::shared_ptr<TerminalIdentLiteral> var_name)
    : StatNode(nullptr) {
  this->ast_node_type_ = AST_NODE_TYPE::SELF_CHANGE_STAT;
  this->children_.push_back(ops);
  this->children_.push_back(var_name);
}

SelfChangeStatNode::SelfChangeStatNode(
    std::shared_ptr<TerminalIdentLiteral> var_name,
    std::shared_ptr<TerminalOperator> ops)
    : StatNode(nullptr) {
  this->ast_node_type_ = AST_NODE_TYPE::SELF_CHANGE_STAT;
  this->children_.push_back(var_name);
  this->children_.push_back(ops);
}

void SelfChangeStatNode::print_info() {
  std::cout << "Node type: " << std::endl;
  std::cout << std::string(magic_enum::enum_name(this->ast_node_type_))
            << std::endl;

  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

void SelfChangeStatNode::Parse() {
  if (!this->lexer_) {
    throw std::runtime_error("can not Parse");
  }
  Token &&token = this->lexer_->getCurrentToken();
  if (token.get_token_type() == TokenType::ILLEGAL_OR_EOF) {
    throw std::runtime_error("illegal token or end of file");
  }
  if (token.get_token_type() == TokenType::IDENT) {

    auto child_var_name = std::make_shared<TerminalIdentLiteral>(this->lexer_);
    child_var_name->Parse();
    this->children_.push_back(child_var_name);

    this->lexer_->getNextToken();

    auto child_operator = std::make_shared<TerminalOperator>(this->lexer_);
    if (child_operator->operator_ == "++" ||
        child_operator->operator_ == "--") {
      this->children_.push_back(child_operator);
    } else {
      throw std::runtime_error("expect ++ or -- after a Variable ");
    }

  } else if (token.get_token_type() == TokenType::OPERATOR) {

    auto child_operator = std::make_shared<TerminalOperator>(this->lexer_);
    if (child_operator->operator_ == "++" ||
        child_operator->operator_ == "--") {
      this->children_.push_back(child_operator);
    } else {
      throw std::runtime_error("expect ++ or -- before a Variable ");
    }
    this->lexer_->getNextToken();

    auto child_var_name = std::make_shared<TerminalIdentLiteral>(this->lexer_);
    child_var_name->Parse();
    this->children_.push_back(child_var_name);
  }
}

} // namespace mycompiler
