#include "ast_node/stat_node/parameter_stat_node.hpp"
#include "ast_node/expr_node/function_called_return_value_expr_node.hpp"
#include "ast_node/expr_node/ident_expr_node.hpp"
#include "ast_node/stat_node/parameter_list_stat_node.hpp"
#include "ast_node/terminal_symbols/terminal_separator.hpp"
#include "ast_node/terminal_symbols/terminal_value_literal.hpp"
#include "magic_enum/magic_enum.hpp"

#include <memory>
#include <stdexcept>

namespace mycompiler {

ParameterStatNode::ParameterStatNode(std::shared_ptr<Lexer> lexer)
    : StatNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::PARAMETER_STAT;
}

void ParameterStatNode::print_info() {
  std::cout << "Node type: " << std::endl;
  std::cout << std::string(magic_enum::enum_name(this->ast_node_type_))
            << std::endl;

  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

void ParameterStatNode::Parse() {
  Token &&token = this->lexer_->getCurrentToken();

  if (token.get_token_type() == TokenType::IDENT) {
    char nextChar = this->lexer_->lookNextChar();
    if (nextChar == '(') {
      auto child_function_call_return_value =
          std::make_shared<FunctionCalledReturnValueExprNode>(this->lexer_);
      child_function_call_return_value->Parse();
      this->children_.push_back(child_function_call_return_value);
    } else {
      auto child_variable_value =
          std::make_shared<IdentifierExprNode>(this->lexer_);
      child_variable_value->Parse();
      this->children_.push_back(child_variable_value);
    }
  } else if (token.get_token_type() == TokenType::CONSTANT) {
    auto child_terminal_value = std::make_shared<TerminalValueLiteral>(lexer_);
    child_terminal_value->Parse();
    this->children_.push_back(child_terminal_value);
  } else {
    throw std::runtime_error("expect a value");
  }
}
} // namespace mycompiler
