#include "../../../include/ast_node/expr_node/function_called_return_value_expr_node.hpp"
#include "../../../include/ast_node/expr_node/ident_expr_node.hpp"
#include "../../../include/ast_node/expr_node/literal_expr_node.hpp"
#include "../../../include/ast_node/terminal_symbols/terminal_ident_literal.hpp"
#include "../../../include/ast_node/terminal_symbols/terminal_separator.hpp"
#include "../../../include/ast_node/terminal_symbols/terminal_value_literal.hpp"
#include <memory>
#include <stdexcept>

namespace mycompiler {

FunctionCalledReturnValueExprNode::FunctionCalledReturnValueExprNode(
    std::shared_ptr<Lexer> lexer)
    : ExprNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::FUNCTION_CALL_EXPR;
}

void FunctionCalledReturnValueExprNode::print_info() {
  std::cout << "Node type: FUNCTION_CALL_EXPR" << std::endl;
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

void FunctionCalledReturnValueExprNode::Parse() {
  // TODO:
  Token token = this->lexer_->getCurrentToken();
  auto child_ident = std::make_shared<TerminalIdentLiteral>(this->lexer_);
  child_ident->Parse();
  this->children_.push_back(child_ident);

  this->lexer_->getNextToken();
  auto child_left = std::make_shared<TerminalSeparator>(this->lexer_);
  child_left->Parse();
  if (child_left->separator_ != "(") {
    throw std::runtime_error("expect a (");
  } else {
    this->children_.push_back(child_left);
  }

  this->lexer_->getNextToken();
  // TODO:
}

} // namespace mycompiler
