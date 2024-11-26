#include "ast_node/stat_node/single_stat_node.hpp"
#include "ast_node/decl_node/variable_decl_node.hpp"
#include "ast_node/expr_node/function_called_return_value_expr_node.hpp"
#include "ast_node/expr_node/literal_expr_node.hpp"
#include "ast_node/stat_node/break_stat_node.hpp"
#include "ast_node/stat_node/change_variable_value_stat_node.hpp"
#include "ast_node/stat_node/continue_stat_node.hpp"
#include "ast_node/stat_node/else_stat_node.hpp"
#include "ast_node/stat_node/expression_stat_node.hpp"
#include "ast_node/stat_node/for_stat_node.hpp"
#include "ast_node/stat_node/function_decl_stat_node.hpp"
#include "ast_node/stat_node/if_stat_node.hpp"
#include "ast_node/stat_node/return_stat_node.hpp"
#include "ast_node/stat_node/self_change_stat_node.hpp"
#include "ast_node/stat_node/stat_node.hpp"
#include "ast_node/stat_node/variable_decl_stat_node.hpp"
#include "ast_node/stat_node/while_stat_node.hpp"
#include "ast_node/terminal_symbols/terminal_func.hpp"
#include "ast_node/terminal_symbols/terminal_ident_literal.hpp"
#include "ast_node/terminal_symbols/terminal_operator.hpp"
#include "ast_node/terminal_symbols/terminal_value_literal.hpp"
#include "magic_enum/magic_enum.hpp"
#include "token/keyword_type.hpp"
#include "token/token_helper_functions.hpp"
#include "token/token_type.hpp"
#include <functional>
#include <memory>
#include <stdexcept>

namespace mycompiler {

SingleStatNode::SingleStatNode(std::shared_ptr<Lexer> lexer) : StatNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::STAT;
}

auto SingleStatNode::get_stat_type() const -> StatType {
  return this->stat_type_;
}

void SingleStatNode::print_info() {
  std::cout << "Node type: " << std::endl;
  std::cout << std::string(magic_enum::enum_name(this->ast_node_type_))
            << std::endl;

  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

void SingleStatNode::Parse() {
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
      auto child_function_decl_node =
          std::make_shared<FunctionDeclStatNode>(this->lexer_);
      child_function_decl_node->Parse();

      this->children_.push_back(child_function_decl_node);
      this->stat_type_ = StatType::FUNC_DECL;
      break;
    }

    case Keyword_Type::LET: {
      auto child_decl_stat =
          std::make_shared<VariableDeclStatNode>(this->lexer_);
      child_decl_stat->Parse();

      this->children_.push_back(child_decl_stat);
      this->stat_type_ = StatType::VAR_DECL;

      break;
    }

    case Keyword_Type::RETURN: {
      auto child_return_stat = std::make_shared<ReturnStatNode>(this->lexer_);
      child_return_stat->Parse();

      this->children_.push_back(child_return_stat);
      this->stat_type_ = StatType::RETURN_STAT;

      break;
    }

    case Keyword_Type::IF: {
      auto child_if_stat = std::make_shared<IfStatNode>(this->lexer_);
      child_if_stat->Parse();

      this->children_.push_back(child_if_stat);
      this->stat_type_ = StatType::IF_STAT;

      break;
    }

    case Keyword_Type::ELSE: {
      auto child_else_stat = std::make_shared<ElseStatNode>(this->lexer_);
      child_else_stat->Parse();

      this->children_.push_back(child_else_stat);
      this->stat_type_ = StatType::ELSE_STAT;
      break;
    }

    case Keyword_Type::FOR: {
      auto child_for_stat = std::make_shared<ForStatNode>(this->lexer_);
      child_for_stat->Parse();

      this->children_.push_back(child_for_stat);
      this->stat_type_ = StatType::FOR_STAT;

      break;
    }

    case Keyword_Type::WHILE: {
      auto child_while_stat = std::make_shared<WhileStatNode>(this->lexer_);
      child_while_stat->Parse();

      this->children_.push_back(child_while_stat);
      this->stat_type_ = StatType::WHILE_STAT;
      break;
    }
    case Keyword_Type::BREAK: {
      auto child_break_stat = std::make_shared<BreakStatNode>(this->lexer_);
      child_break_stat->Parse();

      this->children_.push_back(child_break_stat);
      this->stat_type_ = StatType::BREAK_STAT;
    }
    case Keyword_Type::CONTINUE: {

      auto child_continue_stat =
          std::make_shared<ContinueStatNode>(this->lexer_);
      child_continue_stat->Parse();

      this->children_.push_back(child_continue_stat);
      this->stat_type_ = StatType::BREAK_STAT;
    }
    }

    break;
  }

  case TokenType::OPERATOR: {
    auto cur_operator = std::make_shared<TerminalOperator>(this->lexer_);
    cur_operator->Parse();

    if (cur_operator->operator_ == "++" || cur_operator->operator_ == "--") {
      auto ident_node = std::make_shared<TerminalIdentLiteral>(this->lexer_);
      ident_node->Parse();

      auto child_self_change_stat_node =
          std::make_shared<SelfChangeStatNode>(cur_operator, ident_node);

      this->children_.push_back(child_self_change_stat_node);
      this->stat_type_ = StatType::SELF_CHANGE_STAT;
    }

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
