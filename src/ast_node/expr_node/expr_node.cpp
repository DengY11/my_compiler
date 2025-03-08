#include "ast_node/expr_node/expr_node.hpp"
#include "magic_enum/magic_enum.hpp"
#include <sstream>

namespace mycompiler {

ExprNode::ExprNode(std::shared_ptr<Lexer> lexer) : BasicNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::EXPR;
}

void ExprNode::print_info() {
  std::cout << "Node type: EXPR" << std::endl;
  std::cout << "Expression type: " << getExpressionType() << std::endl;
  std::cout << "Is constant: " << (isConstant() ? "true" : "false") << std::endl;
  std::cout << "Is lvalue: " << (isLValue() ? "true" : "false") << std::endl;
  
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

std::string ExprNode::toString() const {
  std::stringstream ss;
  ss << "Expression of type " << getExpressionType();
  return ss.str();
}

std::string ExprNode::getExpressionType() const {
  // 默认实现返回"unknown"，派生类应该覆盖此方法
  return "unknown";
}

bool ExprNode::isConstant() const {
  // 默认实现返回false，派生类应该覆盖此方法
  return false;
}

bool ExprNode::isLValue() const {
  // 默认实现返回false，派生类应该覆盖此方法
  return false;
}

} // namespace mycompiler
