#include "ast_node/stat_node/parameter_list_stat_node.hpp"
#include "ast_node/stat_node/parameter_stat_node.hpp"
#include "ast_node/terminal_symbols/terminal_separator.hpp"
#include "magic_enum/magic_enum.hpp"
#include "token/token_helper_functions.hpp"
#include "token/token_type.hpp"

#include <memory>
#include <stdexcept>

namespace mycompiler {

ParameterListStatNode::ParameterListStatNode(std::shared_ptr<Lexer> lexer,
                                             ParameterListType para_type)
    : StatNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::PARAMETER_LIST_STAT;
  this->para_type_ = para_type;
}

void ParameterListStatNode::print_info() {

  std::cout << "Node type: " << std::endl;
  std::cout << std::string(magic_enum::enum_name(this->ast_node_type_))
            << std::endl;

  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

auto ParameterListStatNode::is_parameter_list_type(const Token &token) -> bool {
  auto &&type = token.get_token_type();
  return (type == TokenType::CONSTANT || type == TokenType::IDENT ||
          (type == TokenType::SEPARATOR &&
           get_separator_type_from_token_class(token) == ","));
}

auto ParameterListStatNode::is_decl_func_parameter_list_type(const Token &token)
    -> bool {
  return is_identifier_type(token) ||
         token.get_token_type() == TokenType::IDENT;
}

void ParameterListStatNode::Parse() {

  auto child_left = std::make_shared<TerminalSeparator>(this->lexer_);
  child_left->Parse();
  if (child_left->separator_ != "(") {
    throw std::runtime_error("expect a (");
  } else {
    this->children_.push_back(child_left);
  }

  this->lexer_->getNextToken();

  if (this->para_type_ == ParameterListType::FUNC_CALL) {

    while (is_parameter_list_type(this->lexer_->getCurrentToken())) {
      auto child_parameter = std::make_shared<ParameterStatNode>(this->lexer_);
      child_parameter->Parse();
      this->children_.push_back(child_parameter);
      if (this->lexer_->lookNextChar() == ')') {
        break;
      }

      if (this->lexer_->lookNextChar() == ',') {
        this->lexer_->getNextToken();
        auto child_sep = std::make_shared<TerminalSeparator>(this->lexer_);
        child_sep->Parse();
        if (child_sep->separator_ != ",") {
          throw std::runtime_error("expect ',' between parameters");
        }
        this->children_.push_back(child_sep);
      }

      this->lexer_->getNextToken();
    }

  } else {

    while (is_decl_func_parameter_list_type(this->lexer_->getCurrentToken())) {
      auto child_parameter = std::make_shared<ParameterStatNode>(this->lexer_);
      child_parameter->Parse();
      this->children_.push_back(child_parameter);
      if (this->lexer_->lookNextChar() == ')') {
        break;
      }

      if (this->lexer_->lookNextChar() == ',') {
        this->lexer_->getNextToken();
        auto child_sep = std::make_shared<TerminalSeparator>(this->lexer_);
        child_sep->Parse();
        if (child_sep->separator_ != ",") {
          throw std::runtime_error("expect ',' between parameters");
        }
        this->children_.push_back(child_sep);
      }

      this->lexer_->getNextToken();
    }
  }

  this->lexer_->getNextToken();

  auto child_right = std::make_shared<TerminalSeparator>(this->lexer_);
  child_right->Parse();
  if (child_right->separator_ != ")") {
    throw std::runtime_error("expect a )");
  } else {
    this->children_.push_back(child_right);
  }
}

} // namespace mycompiler
