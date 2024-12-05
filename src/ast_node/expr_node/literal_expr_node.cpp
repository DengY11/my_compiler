#include "ast_node/expr_node/literal_expr_node.hpp"
#include "ast_node/expr_node/binary_expr.hpp"
#include "ast_node/expr_node/expr_node.hpp"
#include "ast_node/expr_node/function_called_return_value_expr_node.hpp"
#include "ast_node/expr_node/group_expr_node.hpp"
#include "ast_node/expr_node/ident_expr_node.hpp"
#include "ast_node/expr_node/tenary_expr_node.hpp"
#include "ast_node/expr_node/unary_expr_node.hpp"
#include "ast_node/terminal_symbols/terminal_ident_literal.hpp"
#include "ast_node/terminal_symbols/terminal_operator.hpp"
#include "ast_node/terminal_symbols/terminal_value_literal.hpp"
#include "lexer/lexer_helper_functions.hpp"
#include "token/operator_type.hpp"
#include "token/token_helper_functions.hpp"
#include "token/token_type.hpp"
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

void LiteralExprNode::ParseExpression() {
  // NOTE: while + -

  auto child_term_node = std::make_shared<LiteralExprNode>(this->lexer_);
  child_term_node->ParseTerm();

  std::shared_ptr<ExprNode> current_node = child_term_node;

  while (this->lexer_->getCurrentToken().get_token_type() ==
             TokenType::OPERATOR &&
         get_operator_priority(this->lexer_->getCurrentToken()) == 1) {

    auto child_operator = std::make_shared<TerminalOperator>(this->lexer_);
    child_operator->Parse();

    auto child_right_term_node =
        std::make_shared<LiteralExprNode>(this->lexer_);
    child_term_node->ParseTerm();

    auto binary_expr_node = std::make_shared<BinaryExprNode>(
        current_node, child_operator, child_right_term_node);

    current_node = binary_expr_node;

    this->lexer_->getNextToken();
  }

  this->children_.push_back(current_node);
}

void LiteralExprNode::ParseTerm() {

  auto child_factor_node = std::make_shared<LiteralExprNode>(this->lexer_);
  child_factor_node->ParseFactor();

  std::shared_ptr<ExprNode> current_node = child_factor_node;

  while (this->lexer_->getCurrentToken().get_token_type() ==
             TokenType::OPERATOR &&
         get_operator_priority(this->lexer_->getCurrentToken()) == 2) {

    auto child_operator = std::make_shared<TerminalOperator>(this->lexer_);

    child_operator->Parse();

    auto child_right_factor_node =
        std::make_shared<LiteralExprNode>(this->lexer_);

    child_factor_node->ParseFactor();

    auto binary_expr_node = std::make_shared<BinaryExprNode>(
        current_node, child_operator, child_right_factor_node);

    current_node = binary_expr_node;

    this->lexer_->getNextToken();
  }

  this->children_.push_back(current_node);
}

void LiteralExprNode::ParseFactor() {
  // TODO: while ^
  // NOTE: * / 开头这种情况交给语义分析，正确情况是以优先级=4的UnaryOperator开头
  std::shared_ptr<ExprNode> left_node;
  if (this->lexer_->getCurrentToken().get_token_type() == TokenType::CONSTANT) {
    left_node = dynamic_pointer_cast<LiteralExprNode>(left_node);
  } else if (this->lexer_->getCurrentToken().get_token_type() ==
             TokenType::OPERATOR) {
    left_node = std::dynamic_pointer_cast<UnaryExprNode>(left_node);
  } else if (this->lexer_->getCurrentToken().get_token_type() ==
             TokenType::SEPARATOR) {
    left_node = std::dynamic_pointer_cast<GroupExprNode>(left_node);
  } else {
    throw std::runtime_error("call ParseFactor meet a problem");
  }

  left_node->Parse();
  std::shared_ptr<ExprNode> current_node = left_node;

  while (this->lexer_->getCurrentToken().get_token_type() ==
             TokenType::OPERATOR &&
         get_operator_priority(this->lexer_->getCurrentToken()) == 3) {

    auto child_operator = std::make_shared<TerminalOperator>(this->lexer_);
    child_operator->Parse();

    auto child_right_expr_node =
        std::make_shared<LiteralExprNode>(this->lexer_);
    child_right_expr_node->ParseFactor();

    auto binary_expr_node = std::make_shared<BinaryExprNode>(
        current_node, child_operator, child_right_expr_node);

    current_node = binary_expr_node;

    this->lexer_->getNextToken();
  }

  this->children_.push_back(current_node);
}

void LiteralExprNode::ParseUnary() {
  // TODO:
  auto &&current_token = this->lexer_->getCurrentToken();

  if (current_token.get_token_type() != TokenType::OPERATOR ||
      !is_unary_operator_token(current_token)) {
    throw std::runtime_error("call ParseUnary happen error");
  }

  auto child_unary_operator_node =
      std::make_shared<TerminalOperator>(this->lexer_);
  child_unary_operator_node->Parse();

  auto &&next_token = this->lexer_->getNextToken();

  if (next_token.get_token_type() == TokenType::SEPARATOR &&
      get_separator_type_from_token_class(next_token) == "(") {
    auto child_group_expr = std::make_shared<GroupExprNode>(this->lexer_);
    child_group_expr->Parse();

    auto unary_expr = std::make_shared<UnaryExprNode>(child_unary_operator_node,
                                                      child_group_expr);

    this->children_.push_back(unary_expr);

    this->lexer_->getNextToken();
  }

  if (next_token.get_token_type() == TokenType::CONSTANT) {
    auto child_terminal_literal_value =
        std::make_shared<TerminalValueLiteral>(this->lexer_);

    auto unary_expr = std::make_shared<UnaryExprNode>(
        child_unary_operator_node, child_terminal_literal_value);

    this->children_.push_back(unary_expr);

    this->lexer_->getNextToken();
  }
}

void LiteralExprNode::Parse() {

  if (!this->lexer_) {
    throw std::runtime_error("can not Parse");
  }

  auto child_expr_node = std::make_shared<LiteralExprNode>(this->lexer_);

  child_expr_node->ParseExpression();

  this->children_.push_back(child_expr_node);
  /*
  if (!this->lexer_) {
    throw std::runtime_error("can not Parse");
  }
  Token token = this->lexer_->getCurrentToken();

  if (token.get_token_type() == TokenType::OPERATOR &&
      is_unary_operator_token(token)) {

    auto child_unary_operator_node =
        std::make_shared<TerminalOperator>(this->lexer_);
    child_unary_operator_node->Parse();

    auto child_unary_expr_node = std::make_shared<UnaryExprNode>(nullptr);

    char nextChar = this->lexer_->lookNextChar();

    if (nextChar == '(') {

      this->lexer_->getNextToken();

      auto child_group_expr = std::make_shared<GroupExprNode>(this->lexer_);
      child_group_expr->Parse();

      child_unary_expr_node->add_child(child_unary_operator_node,
                                       child_group_expr);

    } else {

      auto &&next_token = this->lexer_->getNextToken();

      switch (next_token.get_token_type()) {

      case TokenType::IDENT: {
        nextChar = this->lexer_->lookNextChar();
        if (nextChar == '(') {
          auto function_called_return_value_expr_node =
              std::make_shared<FunctionCalledReturnValueExprNode>(this->lexer_);
          function_called_return_value_expr_node->Parse();
          child_unary_expr_node->add_child(
              child_unary_operator_node,
              function_called_return_value_expr_node);
        }
        break;
      }
      case TokenType::CONSTANT: {

        auto child_terminal_literal_value =
            std::make_shared<TerminalValueLiteral>(this->lexer_);
        child_terminal_literal_value->Parse();

        child_unary_expr_node->add_child(child_unary_operator_node,
                                         child_terminal_literal_value);
        break;
      }
      case TokenType::OPERATOR: {
        if (get_operator_type_from_token_class(next_token) ==
            Operator_Type::NOT) {
          auto right_child_unary_expr_node =
              std::make_shared<UnaryExprNode>(this->lexer_);
          right_child_unary_expr_node->Parse();

          child_unary_expr_node->add_child(child_unary_operator_node,
                                           right_child_unary_expr_node);

          break;
        }
      }
      default: {
        throw std::runtime_error("expect a ident or constant behind !");
      }
      }
    }
    token = this->lexer_->getNextToken();
    if (token.get_token_type() == TokenType::OPERATOR &&
        is_binary_operator_token(token)) {
    }
  }

  if (token.get_token_type() == TokenType::CONSTANT) {

    auto child_value_literal = std::make_shared<TerminalValueLiteral>();
    child_value_literal->Parse();
    if (maybe_binary_operator(this->lexer_->lookNextChar())) {
      this->lexer_->getNextToken();
      auto child_binary_operator =
          std::make_shared<TerminalOperator>(this->lexer_);
      child_binary_operator->Parse();

      this->lexer_->getNextToken();

      auto child_right = std::make_shared<LiteralExprNode>(this->lexer_);
      child_right->Parse();

      auto binary_expr_node = std::make_shared<BinaryExprNode>(
          child_value_literal, child_binary_operator, child_right);
    } else {
      this->children_.push_back(child_value_literal);
    }
  }

  if (token.get_token_type() == TokenType::IDENT) {
    char nextChar = this->lexer_->lookNextChar();
    if (nextChar == '(') {
      auto child_function_call_return_value =
          std::make_shared<FunctionCalledReturnValueExprNode>(this->lexer_);
      child_function_call_return_value->Parse();

      nextChar = this->lexer_->lookNextChar();
      if (maybe_binary_operator(nextChar)) {
        auto child_operator = std::make_shared<TerminalOperator>(this->lexer_);
        child_operator->Parse();
        auto child_right = std::make_shared<LiteralExprNode>(this->lexer_);
        child_right->Parse();

        auto child_binary_expr_node = std::make_shared<TenaryExprNode>(
            child_function_call_return_value, child_operator, child_right);

        this->children_.push_back(child_binary_expr_node);

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

        auto child_binary_expr_node = std::make_shared<BinaryExprNode>(
            child_variable_value, child_operator, child_right);

        this->children_.push_back(child_binary_expr_node);

      } else {

        this->children_.push_back(child_variable_value);
      }
    }
  }
  */
}
} // namespace mycompiler
