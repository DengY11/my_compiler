#include "ast_node/expr_node/literal_expr_node.hpp"
#include "ast_node/expr_node/expr_node.hpp"
#include "ast_node/expr_node/function_called_return_value_expr_node.hpp"
#include "ast_node/expr_node/ident_expr_node.hpp"
#include "ast_node/expr_node/tenary_expr_node.hpp"
#include "ast_node/terminal_symbols/terminal_ident_literal.hpp"
#include "ast_node/terminal_symbols/terminal_operator.hpp"
#include "ast_node/terminal_symbols/terminal_value_literal.hpp"
#include "lexer/lexer_helper_functions.hpp"
#include <memory>
#include <stdexcept>

namespace mycompiler {

LiteralExprNode::LiteralExprNode(std::shared_ptr<Lexer> lexer)
    : ExprNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::LITERAL_EXPR;
}

LiteralExprNode::LiteralExprNode(std::shared_ptr<TerminalIdentLiteral> var_name,
                                 std::shared_ptr<TerminalOperator> op,
                                 std::shared_ptr<TerminalValueLiteral> value)
    : ExprNode(nullptr) {

  this->ast_node_type_ = AST_NODE_TYPE::LITERAL_EXPR;

  this->children_.push_back(var_name);
  this->children_.push_back(op);
  this->children_.push_back(value);
}

void LiteralExprNode::print_info() {
  std::cout << "Node type: LITERAL_EXPR" << std::endl;
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

void LiteralExprNode::Parse() {
  if (!this->lexer_) {
    throw std::runtime_error("can not Parse");
  }
  Token token = this->lexer_->getCurrentToken();
  if (!(token.get_token_type() == TokenType::CONSTANT ||
        token.get_token_type() == TokenType::IDENT)) {
    throw std::runtime_error("expect a value");
  }
  if (token.get_token_type() == TokenType::CONSTANT) {
    auto child_value_literal = std::make_shared<TerminalValueLiteral>();
    child_value_literal->Parse();
    this->children_.push_back(child_value_literal);
  }
  if (token.get_token_type() == TokenType::IDENT) {
    char nextChar = this->lexer_->lookNextChar();
    if (nextChar == '(') {
      auto child_function_call_return_value =
          std::make_shared<FunctionCalledReturnValueExprNode>(this->lexer_);
      child_function_call_return_value->Parse();

      nextChar = this->lexer_->lookNextChar();
      if (is_operator_type(nextChar)) {
        auto child_operator = std::make_shared<TerminalOperator>(this->lexer_);
        child_operator->Parse();
        auto child_right = std::make_shared<LiteralExprNode>(this->lexer_);
        child_right->Parse();

        auto child_tenaty_expr_node =
            std::make_shared<TenaryExprNode>(this->lexer_);

        child_tenaty_expr_node->add_child(child_function_call_return_value,
                                          child_operator, child_right);

        this->children_.push_back(child_tenaty_expr_node);

      } else {

        this->children_.push_back(child_function_call_return_value);
      }
    } else {

      auto child_variable_value =
          std::make_shared<IdentifierExprNode>(this->lexer_);
      child_variable_value->Parse();

      nextChar = this->lexer_->lookNextChar();

      if (is_operator_type(nextChar)) {
        auto child_operator = std::make_shared<TerminalOperator>(this->lexer_);
        child_operator->Parse();
        auto child_right = std::make_shared<LiteralExprNode>(this->lexer_);
        child_right->Parse();

        auto child_tenaty_expr_node =
            std::make_shared<TenaryExprNode>(this->lexer_);

        child_tenaty_expr_node->add_child(child_variable_value, child_operator,
                                          child_right);

        this->children_.push_back(child_tenaty_expr_node);

      } else {

        this->children_.push_back(child_variable_value);
      }
    }
  } else if (token.get_token_type() == TokenType::CONSTANT) {

    auto child_terminal_value = std::make_shared<TerminalValueLiteral>(lexer_);
    child_terminal_value->Parse();

    char nextChar = this->lexer_->lookNextChar();

    if (is_operator_type(nextChar)) {
      auto child_operator = std::make_shared<TerminalOperator>(this->lexer_);
      child_operator->Parse();
      auto child_right = std::make_shared<LiteralExprNode>(this->lexer_);
      child_right->Parse();

      auto child_tenaty_expr_node =
          std::make_shared<TenaryExprNode>(this->lexer_);

      auto left_value =
          std::make_shared<LiteralExprNode>(nullptr); // NOTE: 别手贱parse了

      left_value->add_terminalvalue_node(child_terminal_value);

      child_tenaty_expr_node->add_child(left_value, child_operator,
                                        child_right);

      this->children_.push_back(child_tenaty_expr_node);

    } else {

      this->children_.push_back(child_terminal_value);
    }
  }
}
} // namespace mycompiler
