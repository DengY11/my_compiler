#include "../../../include/ast_node/decl_node/variable_decl_node.hpp"
#include "../../../include/ast_node/expr_node/ident_expr_node.hpp"
#include "../../../include/ast_node/expr_node/literal_expr_node.hpp"
#include "../../../include/ast_node/terminal_symbols/terminal_equal.hpp"
#include "../../../include/ast_node/terminal_symbols/terminal_ident_literal.hpp"
#include "../../../include/ast_node/terminal_symbols/terminal_let.hpp"
#include "../../../include/ast_node/terminal_symbols/terminal_separator.hpp"
#include "../terminal_symbols/terminal_let.cpp"
#include <memory>
#include <stdexcept>

namespace mycompiler {

VarDeclNode::VarDeclNode(std::shared_ptr<Lexer> lexer) : DeclNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::VARIABLE_DECL;
}

void VarDeclNode::print_info() {
  std::cout << "Node type: VARIABLE_DECL" << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

void VarDeclNode::Parse() {
  // let ident = expr;
  Token &&token = this->lexer_->getCurrentToken();
  if (token.get_token_type() == TokenType::ILLEGAL_OR_EOF) {
    throw std::runtime_error("illegal token or end of file");
  }
  auto child_let = std::make_shared<TerminalLet>(this->lexer_);
  child_let->Parse();
  this->children_.push_back(child_let);

  this->lexer_->getNextToken();

  auto child_identifier = std::make_shared<TerminalIdentLiteral>(this->lexer_);
  child_identifier->Parse();
  this->children_.push_back(child_identifier);

  this->lexer_->getNextToken();

  auto child_equal = std::make_shared<TerminalEqual>(this->lexer_);
  child_equal->Parse();
  this->children_.push_back(child_equal);

  this->lexer_->getNextToken();

  auto child_value = std::make_shared<LiteralExprNode>(this->lexer_);
  child_value->Parse();
  this->children_.push_back(child_value);

  this->lexer_->getNextToken();

  auto child_semicolon = std::make_shared<TerminalSeparator>(this->lexer_);
  child_semicolon->Parse();
  if (child_semicolon->separator_ != ";") {
    throw std::runtime_error("expect ;");
  }
  this->children_.push_back(child_semicolon);

  // 卧槽，写了一周终于写完了
}

} // namespace mycompiler
