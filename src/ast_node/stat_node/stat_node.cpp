#include "ast_node/stat_node/stat_node.hpp"
#include "ast_node/expr_node/function_called_return_value_expr_node.hpp"
#include "ast_node/expr_node/literal_expr_node.hpp"
#include "ast_node/stat_node/change_variable_value_stat_node.hpp"
#include "ast_node/stat_node/expression_stat_node.hpp"
#include "ast_node/stat_node/self_change_stat_node.hpp"
#include "ast_node/terminal_symbols/terminal_ident_literal.hpp"
#include "ast_node/terminal_symbols/terminal_operator.hpp"
#include "ast_node/terminal_symbols/terminal_value_literal.hpp"
#include "token/keyword_type.hpp"
#include "token/token_helper_functions.hpp"
#include "token/token_type.hpp"
#include <functional>
#include <memory>
#include <stdexcept>

namespace mycompiler {

StatNode::StatNode(std::shared_ptr<Lexer> lexer) : BasicNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::STAT;
}

auto StatNode::get_stat_type() const -> StatType { return this->stat_type_; }

void StatNode::print_info() {
  std::cout << "Node type: StatNode" << std::endl;
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

void StatNode::Parse() {
  Token &&token = this->lexer_->getCurrentToken();
  if (token.get_token_type() == TokenType::ILLEGAL_OR_EOF) {
    throw std::runtime_error("illegal token or end of file");
  }

  switch (this->lexer_->getCurrentToken().get_token_type()) {

  case TokenType::CONSTANT: {
    auto child_expr_stat_node =
        std::make_shared<ExpressionStatNode>(this->lexer_);
    child_expr_stat_node->Parse();

    this->children_.push_back(child_expr_stat_node);
    this->stat_type_ = StatType::EXPR_STAT;

    break;
  }

  case TokenType::KEYWORD: {

    switch (
        get_keyword_type_from_token_class(this->lexer_->getCurrentToken())) {

    case Keyword_Type::FUNC: {

      break;
    }

    case Keyword_Type::LET: {

      break;
    }

    case Keyword_Type::RETURN: {

      break;
    }

    case Keyword_Type::IF: {

      break;
    }

    case Keyword_Type::ELSE: {

      break;
    }

    case Keyword_Type::FOR: {
      break;
    }

    case Keyword_Type::WHILE: {
      break;
    }
    }

    break;
  }

  case TokenType::OPERATOR: {
    break;
  }

  case TokenType::IDENT: {
    char next_ch = this->lexer_->lookNextChar();
    if (next_ch == '=') {

      auto child_change_var_stat_node =
          std::make_shared<ChangeVariableValueStatNode>(this->lexer_);
      child_change_var_stat_node->Parse();

      this->children_.push_back(child_change_var_stat_node);
      this->stat_type_ = StatType::CHANGE_VAR_STAT;

    } else if (next_ch == '+' || next_ch == '-') {

      auto var_name = std::make_shared<TerminalIdentLiteral>(this->lexer_);
      var_name->Parse();

      auto op = std::make_shared<TerminalOperator>(this->lexer_);
      op->Parse();

      if (op->operator_ == "++" || op->operator_ == "--") {
        auto child_self_change_stat_node =
            std::make_shared<SelfChangeStatNode>(var_name, op);

        this->children_.push_back(child_self_change_stat_node);
        this->stat_type_ = StatType::SELF_CHANGE_STAT;

      } else {

        auto op_value = std::make_shared<TerminalValueLiteral>(this->lexer_);
        op_value->Parse();

        auto child_literal_expr_node =
            std::make_shared<LiteralExprNode>(var_name, op, op_value);
        auto child_expression_stat =
            std::make_shared<ExpressionStatNode>(child_literal_expr_node);

        this->children_.push_back(child_expression_stat);
        this->stat_type_ = StatType::EXPR_STAT;
      }

    } else if (next_ch == '(') {

      auto child_func_name =
          std::make_shared<FunctionCalledReturnValueExprNode>(this->lexer_);

      this->children_.push_back(child_func_name);
      this->stat_type_ = StatType::FUNCTION_CALL_WITH_RETURN_VALUE_STAT;
    }
  }

  default:
    throw std::runtime_error("expect statment");
  }
}

} // namespace mycompiler
