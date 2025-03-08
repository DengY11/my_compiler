#include "ast_node/expr_node/unary_expr_node.hpp"
#include "ast_node/expr_node/literal_expr_node.hpp"
#include "ast_node/expr_node/pratt_parser.hpp"
#include "token/token_helper_functions.hpp"
#include <sstream>

namespace mycompiler {

UnaryExprNode::UnaryExprNode(std::shared_ptr<Lexer> lexer) : ExprNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::UNARY_EXPR;
}

UnaryExprNode::UnaryExprNode(std::shared_ptr<TerminalOperator> op,
                             std::shared_ptr<ExprNode> operand)
    : ExprNode(operand->getLexer()), operator_(op), operand_(operand) {
  this->ast_node_type_ = AST_NODE_TYPE::UNARY_EXPR;
  add_child(op);
  add_child(operand);
}

auto UnaryExprNode::add_child(std::shared_ptr<TerminalOperator> op,
                              std::shared_ptr<TerminalValueLiteral> right)
    -> void {
  this->children_.push_back(op);
  this->children_.push_back(right);
}

void UnaryExprNode::print_info() {
  std::cout << "Node type: UNARY_EXPR" << std::endl;
  std::cout << "Operator: " << operator_->operator_ << std::endl;
  
  std::cout << "Operand: " << std::endl;
  operand_->print_info();
  
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

std::string UnaryExprNode::toString() const {
  std::stringstream ss;
  ss << operator_->operator_ << operand_->toString();
  return ss.str();
}

void UnaryExprNode::Parse() {
  // 使用Pratt解析器解析表达式
  PrattParser parser(lexer_);
  auto expr = parser.parseExpression(Precedence::UNARY);
  
  // 如果解析结果不是一元表达式，则抛出异常
  auto unaryExpr = std::dynamic_pointer_cast<UnaryExprNode>(expr);
  if (!unaryExpr) {
    throw std::runtime_error("Expected unary expression");
  }
  
  // 复制解析结果
  operator_ = unaryExpr->operator_;
  operand_ = unaryExpr->operand_;
  
  // 添加子节点
  add_child(operator_);
  add_child(operand_);
}

std::string UnaryExprNode::getExpressionType() const {
  // 根据操作符和操作数的类型确定表达式的类型
  std::string operandType = operand_->getExpressionType();
  
  // 如果操作符是逻辑非，则返回布尔类型
  if (operator_->operator_ == "!") {
    return "bool";
  }
  
  // 如果操作符是自增或自减，则返回操作数的类型
  if (operator_->operator_ == "++" || operator_->operator_ == "--") {
    return operandType;
  }
  
  // 如果操作符是正负号，则返回操作数的类型
  if (operator_->operator_ == "+" || operator_->operator_ == "-") {
    return operandType;
  }
  
  // 默认返回未知类型
  return "unknown";
}

bool UnaryExprNode::isConstant() const {
  // 如果操作数是常量，且操作符是纯函数（如正负号），则表达式是常量
  if (operand_->isConstant()) {
    if (operator_->operator_ == "+" || operator_->operator_ == "-" || 
        operator_->operator_ == "!") {
      return true;
    }
  }
  
  // 自增自减操作符总是有副作用的，所以不是常量
  return false;
}

bool UnaryExprNode::isLValue() const {
  // 一元表达式通常不是左值，除非是解引用操作符（在这个语言中可能没有）
  return false;
}

std::shared_ptr<TerminalOperator> UnaryExprNode::getOperator() const {
  return operator_;
}

std::shared_ptr<ExprNode> UnaryExprNode::getOperand() const {
  return operand_;
}

} // namespace mycompiler
