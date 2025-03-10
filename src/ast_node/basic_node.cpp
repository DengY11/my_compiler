#include "ast_node/basic_node.hpp"
#include "magic_enum/magic_enum.hpp"
#include <algorithm>
#include <memory>
#include <stdexcept>
#include <sstream>

namespace mycompiler {

BasicNode::BasicNode(std::shared_ptr<Lexer> lexer)
    : ast_node_type_(mycompiler::AST_NODE_TYPE::BASIC), lexer_(lexer) {}

void BasicNode::print_info() {
  std::cout << "Node type: " << std::endl;
  std::cout << std::string(magic_enum::enum_name(this->ast_node_type_))
            << std::endl;

  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

std::string BasicNode::toString() const {
  std::stringstream ss;
  ss << "Node type: " << std::string(magic_enum::enum_name(this->ast_node_type_));
  return ss.str();
}

void BasicNode::add_child(std::shared_ptr<BasicNode> childptr) {
  this->children_.emplace_back(childptr);
}

bool BasicNode::expectNextToken(TokenType type) {
  Token nextToken = lexer_->peekNextToken();
  return nextToken.getTokenType() == type;
}

Token BasicNode::consumeToken(TokenType type) {
  Token nextToken = lexer_->peekNextToken();
  if (nextToken.getTokenType() != type) {
    std::stringstream ss;
    ss << "Expected token type " << static_cast<int>(type) 
       << " but got " << static_cast<int>(nextToken.getTokenType())
       << " at line " << nextToken.getLineNumber() 
       << ", column " << nextToken.getColumnNumber();
    throw std::runtime_error(ss.str());
  }
  lexer_->getNextToken();
  return lexer_->getCurrentToken();
}

} // namespace mycompiler
