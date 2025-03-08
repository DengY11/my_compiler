#include "ast_node/ast_node.hpp"
#include <iostream>

namespace mycompiler {

ASTNode::ASTNode(std::shared_ptr<Lexer> lexer)
    : lexer_(lexer), lineNumber_(0), columnNumber_(0) {
  if (lexer_) {
    lineNumber_ = lexer_->getCurrentToken().getLineNumber();
    columnNumber_ = lexer_->getCurrentToken().getColumnNumber();
  }
}

std::shared_ptr<Lexer> ASTNode::getLexer() const {
  return lexer_;
}

void ASTNode::setLexer(std::shared_ptr<Lexer> lexer) {
  lexer_ = lexer;
}

int ASTNode::getLineNumber() const {
  return lineNumber_;
}

void ASTNode::setLineNumber(int lineNumber) {
  lineNumber_ = lineNumber;
}

int ASTNode::getColumnNumber() const {
  return columnNumber_;
}

void ASTNode::setColumnNumber(int columnNumber) {
  columnNumber_ = columnNumber;
}

std::string ASTNode::getNodeType() const {
  return "ASTNode";
}

} // namespace mycompiler 