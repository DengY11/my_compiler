#include "ast_node/decl_node/function_decl_node.hpp"
#include "ast_node/stat_node/parameter_list_stat_node.hpp"
#include "ast_node/terminal_symbols/terminal_func.hpp"
#include "ast_node/terminal_symbols/terminal_ident_literal.hpp"
#include <memory>

namespace mycompiler {

FuncDeclNode::FuncDeclNode(std::shared_ptr<Lexer> lexer) : DeclNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::FUNCTION_DECL;
}

void FuncDeclNode::print_info() {
  std::cout << "Node type:: FUNCTION_DECL" << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

void FuncDeclNode::Parse() {
  // func ident+parameter_list{stmt_list}
  Token &&token = this->lexer_->getCurrentToken();
  if (token.get_token_type() == TokenType::ILLEGAL_OR_EOF) {
    throw std::runtime_error("illegal token or end of file");
  }

  this->lexer_->getNextToken();

  auto child_func = std::make_shared<TerminalFunc>(this->lexer_);
  child_func->Parse();
  this->children_.push_back(child_func);

  this->lexer_->getNextToken();

  auto child_ident = std::make_shared<TerminalIdentLiteral>(this->lexer_);
  child_ident->Parse();
  this->children_.push_back(child_ident);

  this->lexer_->getNextToken();

  auto child_parameter_list = std::make_shared<ParameterListStatNode>(
      this->lexer_, ParameterListType::FUNC_DECL);
  child_parameter_list->Parse();

  // TODO: func_body;
}

} // namespace mycompiler
