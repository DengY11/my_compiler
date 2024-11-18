#include "ast_node/stat_node/stat_node.hpp"
#include "ast_node/expr_node/function_called_return_value_expr_node.hpp"
#include "ast_node/expr_node/literal_expr_node.hpp"
#include "ast_node/stat_node/change_variable_value_stat_node.hpp"
#include "ast_node/stat_node/expression_stat_node.hpp"
#include "ast_node/stat_node/self_change_stat_node.hpp"
#include "ast_node/terminal_symbols/terminal_ident_literal.hpp"
#include "ast_node/terminal_symbols/terminal_operator.hpp"
#include "ast_node/terminal_symbols/terminal_value_literal.hpp"
#include "token/token_type.hpp"
#include <functional>
#include <memory>
#include <stdexcept>

namespace mycompiler {

StatNode::StatNode(std::shared_ptr<Lexer> lexer) : BasicNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::STAT;
}

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

  case TokenType::IDENT:
    char next_ch = this->lexer_->lookNextChar();
    if (next_ch == '=') {
      auto child_change_var_stat_node =
          std::make_shared<ChangeVariableValueStatNodeHpp>(this->lexer_);
      child_change_var_stat_node->Parse();
      this->children_.push_back(child_change_var_stat_node);
    } else if (next_ch == '+' || next_ch == '-') {

      auto var_name = std::make_shared<TerminalIdentLiteral>(this->lexer_);
      var_name->Parse();

      auto op = std::make_shared<TerminalOperator>(this->lexer_);
      op->Parse();
      if (op->operator_ == "++" || op->operator_ == "--") {
        auto child_self_change_stat_node =
            std::make_shared<SelfChangeStatNode>(var_name, op);

        this->children_.push_back(child_self_change_stat_node);
      } else {
        auto op_value = std::make_shared<TerminalValueLiteral>(this->lexer_);
        op_value->Parse();

        auto child_literal_expr_node =
            std::make_shared<LiteralExprNode>(var_name, op, op_value);
        auto child_expression_stat =
            std::make_shared<ExpressionStatNode>(child_literal_expr_node);
        this->children_.push_back(child_expression_stat);
      }

    } else if (next_ch == '(') {
      auto child_func_name =
          std::make_shared<FunctionCalledReturnValueExprNode>(this->lexer_);
    }

    break;

  case TokenType::CONSTANT:
    break;

  case TokenType::KEYWORD:
    break;

  default:
    throw std::runtime_error("expect statment");
  }
}

} // namespace mycompiler
