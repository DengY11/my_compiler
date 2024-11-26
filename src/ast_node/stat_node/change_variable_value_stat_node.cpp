#include "ast_node/stat_node/change_variable_value_stat_node.hpp"
#include "ast_node/expr_node/literal_expr_node.hpp"
#include "ast_node/stat_node/stat_node.hpp"
#include "ast_node/terminal_symbols/terminal_equal.hpp"
#include "ast_node/terminal_symbols/terminal_ident_literal.hpp"
#include "ast_node/terminal_symbols/terminal_separator.hpp"
#include "magic_enum/magic_enum.hpp"
#include <memory>

namespace mycompiler {

ChangeVariableValueStatNode::ChangeVariableValueStatNode(
    std::shared_ptr<Lexer> lexer)
    : StatNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::CHANGE_VAR_STAT;
}

void ChangeVariableValueStatNode::print_info() {
  std::cout << "Node type: " << std::endl;
  std::cout << std::string(magic_enum::enum_name(this->ast_node_type_))
            << std::endl;

  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

void ChangeVariableValueStatNode::Parse() {

  Token &&token = this->lexer_->getCurrentToken();
  if (token.get_token_type() == TokenType::ILLEGAL_OR_EOF) {
    throw std::runtime_error("illegal token or end of file");
  }

  auto child_var_name = std::make_shared<TerminalIdentLiteral>(this->lexer_);
  child_var_name->Parse();
  this->children_.push_back(child_var_name);

  auto child_equal = std::make_shared<TerminalEqual>(this->lexer_);
  child_equal->Parse();
  this->children_.push_back(child_equal);

  auto child_value = std::make_shared<LiteralExprNode>(this->lexer_);
  child_value->Parse();
  this->children_.push_back(child_value);

  auto child_semicolon = std::make_shared<TerminalSeparator>(this->lexer_);
  child_semicolon->Parse();
  if (child_semicolon->separator_ != ";") {
    throw std::runtime_error("expect ;");
  }
  this->children_.push_back(child_semicolon);
}

} // namespace mycompiler
