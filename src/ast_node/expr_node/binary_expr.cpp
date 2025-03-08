#include "ast_node/expr_node/binary_expr.hpp"
#include "ast_node/expr_node/expr_node.hpp"
#include "ast_node/expr_node/literal_expr_node.hpp"
#include "ast_node/expr_node/tenary_expr_node.hpp"
#include "ast_node/node_type.hpp"
#include "ast_node/terminal_symbols/terminal_operator.hpp"
#include "ast_node/expr_node/pratt_parser.hpp"
#include "token/token_helper_functions.hpp"
#include <sstream>

namespace mycompiler {

BinaryExprNode::BinaryExprNode(std::shared_ptr<Lexer> lexer) : ExprNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::BINNARY_EXPR;
}

BinaryExprNode::BinaryExprNode(std::shared_ptr<ExprNode> left,
                               std::shared_ptr<TerminalOperator> op,
                               std::shared_ptr<ExprNode> right)
    : ExprNode(left->getLexer()), left_(left), operator_(op), right_(right) {
  this->ast_node_type_ = AST_NODE_TYPE::BINNARY_EXPR;
  add_child(left);
  add_child(op);
  add_child(right);
}

void BinaryExprNode::print_info() {
  std::cout << "Node type: BINARY_EXPR" << std::endl;
  std::cout << "Operator: " << operator_->operator_ << std::endl;
  
  std::cout << "Left operand: " << std::endl;
  left_->print_info();
  
  std::cout << "Right operand: " << std::endl;
  right_->print_info();
  
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

std::string BinaryExprNode::toString() const {
  std::stringstream ss;
  ss << "(" << left_->toString() << " " << operator_->operator_ << " " << right_->toString() << ")";
  return ss.str();
}

void BinaryExprNode::Parse() {
  // 使用Pratt解析器解析表达式
  PrattParser parser(lexer_);
  auto expr = parser.parseExpression();
  
  // 如果解析结果不是二元表达式，则抛出异常
  auto binaryExpr = std::dynamic_pointer_cast<BinaryExprNode>(expr);
  if (!binaryExpr) {
    throw std::runtime_error("Expected binary expression");
  }
  
  // 复制解析结果
  left_ = binaryExpr->left_;
  operator_ = binaryExpr->operator_;
  right_ = binaryExpr->right_;
  
  // 添加子节点
  add_child(left_);
  add_child(operator_);
  add_child(right_);
}

std::string BinaryExprNode::getExpressionType() const {
  // 根据操作符和操作数的类型确定表达式的类型
  std::string leftType = left_->getExpressionType();
  std::string rightType = right_->getExpressionType();
  
  // 如果操作符是比较操作符，则返回布尔类型
  if (operator_->operator_ == "==" || operator_->operator_ == "!=" ||
      operator_->operator_ == "<" || operator_->operator_ == "<=" ||
      operator_->operator_ == ">" || operator_->operator_ == ">=") {
    return "bool";
  }
  
  // 如果操作符是算术操作符，则根据操作数的类型确定
  if (leftType == "int" && rightType == "int") {
    return "int";
  } else if (leftType == "float" || rightType == "float") {
    return "float";
  } else if (leftType == "string" && operator_->operator_ == "+") {
    return "string";
  }
  
  // 默认返回未知类型
  return "unknown";
}

bool BinaryExprNode::isConstant() const {
  // 如果左右操作数都是常量，则表达式是常量
  return left_->isConstant() && right_->isConstant();
}

void BinaryExprNode::add_child(std::shared_ptr<ExprNode> left,
                               std::shared_ptr<TerminalOperator> op,
                               std::shared_ptr<ExprNode> right) {
  left_ = left;
  operator_ = op;
  right_ = right;
  
  add_child(left);
  add_child(op);
  add_child(right);
}

std::shared_ptr<ExprNode> BinaryExprNode::getLeft() const {
  return left_;
}

std::shared_ptr<TerminalOperator> BinaryExprNode::getOperator() const {
  return operator_;
}

std::shared_ptr<ExprNode> BinaryExprNode::getRight() const {
  return right_;
}

} // namespace mycompiler
