#include "../../../include/ast_node/expr_node/literal_expr_node.hpp"
#include "../../../include/ast_node/expr_node/function_called_return_value_expr_node.hpp"
#include "../../../include/ast_node/expr_node/ident_expr_node.hpp"
#include "../../../include/ast_node/terminal_symbols/terminal_value_literal.hpp"
#include <memory>
#include <stdexcept>

namespace mycompiler {

LiteralExprNode::LiteralExprNode(std::shared_ptr<Lexer> lexer)
    : ExprNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::LITERAL_EXPR;
}

void LiteralExprNode::print_info() {
  std::cout << "Node type: LITERAL_EXPR" << std::endl;
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

void LiteralExprNode::Parse() {
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
  }
}
} // namespace mycompiler
