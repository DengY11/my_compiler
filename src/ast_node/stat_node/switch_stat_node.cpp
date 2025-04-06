#include "ast_node/stat_node/switch_stat_node.hpp"
#include "ast_node/stat_node/case_stat_node.hpp"
#include "ast_node/stat_node/default_stat_node.hpp"
#include "ast_node/stat_node/expression_stat_node.hpp"
#include "ast_node/stat_node/stat_list_node.hpp"
#include "ast_node/terminal_symbols/terminal_separator.hpp"
#include "ast_node/terminal_symbols/terminal_switch.hpp"
#include "magic_enum/magic_enum.hpp"
#include <memory>
#include <sstream>
#include <stdexcept>

namespace mycompiler {

SwitchStatNode::SwitchStatNode(std::shared_ptr<Lexer> lexer) : StatNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::SWITCH_STAT;
  defaultCase_ = nullptr;
}

void SwitchStatNode::print_info() {
  std::cout << "Node type: " << std::endl;
  std::cout << std::string(magic_enum::enum_name(this->ast_node_type_))
            << std::endl;

  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

std::string SwitchStatNode::toString() const {
  std::stringstream ss;
  ss << "SwitchStatement(" << expression_->toString() << ", [";
  
  bool first = true;
  for (const auto& caseItem : cases_) {
    if (!first) {
      ss << ", ";
    }
    ss << "Case(" << caseItem.first->toString() << ", " 
       << caseItem.second->toString() << ")";
    first = false;
  }
  
  if (defaultCase_) {
    if (!first) {
      ss << ", ";
    }
    ss << "Default(" << defaultCase_->toString() << ")";
  }
  
  ss << "])";
  return ss.str();
}

void SwitchStatNode::Parse() {
  Token &&token = this->lexer_->getCurrentToken();
  if (token.getTokenType() == TokenType::ILLEGAL_OR_EOF) {
    throw std::runtime_error("illegal token or end of file");
  }

  // 解析switch关键字
  auto child_terminal_switch_stat = std::make_shared<TerminalSwitch>(this->lexer_);
  child_terminal_switch_stat->Parse();
  this->children_.push_back(child_terminal_switch_stat);

  // 解析左括号
  auto child_left_parentheses = std::make_shared<TerminalSeparator>(this->lexer_);
  child_left_parentheses->Parse();
  if (child_left_parentheses->separator_ != "(") {
    throw std::runtime_error("expect (");
  } else {
    this->children_.push_back(child_left_parentheses);
  }

  this->lexer_->getNextToken();

  // 解析条件表达式
  auto child_expr = std::make_shared<ExpressionStatNode>(this->lexer_);
  child_expr->Parse();
  this->children_.push_back(child_expr);
  expression_ = child_expr->getExpression();  // 存储表达式

  this->lexer_->getNextToken();

  // 解析右括号
  auto child_right_parentheses = std::make_shared<TerminalSeparator>(this->lexer_);
  child_right_parentheses->Parse();
  if (child_right_parentheses->separator_ != ")") {
    throw std::runtime_error("expect )");
  } else {
    this->children_.push_back(child_right_parentheses);
  }

  // 解析左大括号
  auto child_left_big = std::make_shared<TerminalSeparator>(this->lexer_);
  child_left_big->Parse();
  if (child_left_big->separator_ != "{") {
    throw std::runtime_error("expect {");
  } else {
    this->children_.push_back(child_left_big);
  }

  this->lexer_->getNextToken();

  // 解析case和default语句
  while (true) {
    Token current = this->lexer_->getCurrentToken();
    
    // 如果遇到右大括号，说明switch语句结束
    if (current.getTokenType() == TokenType::SEPARATOR && 
        current.getValue() == "}") {
      break;
    }
    
    // 解析case语句
    if (current.getTokenType() == TokenType::KEYWORD && 
        current.getKeywordType() == KeywordType::CASE) {
      auto caseNode = std::make_shared<CaseStatNode>(this->lexer_);
      caseNode->Parse();
      this->children_.push_back(caseNode);
      
      // 添加到cases列表
      addCase(caseNode->getExpression(), caseNode->getBlock());
      continue;
    }
    
    // 解析default语句
    if (current.getTokenType() == TokenType::KEYWORD && 
        current.getKeywordType() == KeywordType::DEFAULT) {
      auto defaultNode = std::make_shared<DefaultStatNode>(this->lexer_);
      defaultNode->Parse();
      this->children_.push_back(defaultNode);
      
      // 设置default块
      setDefaultCase(defaultNode->getBlock());
      continue;
    }
    
    // 如果既不是case也不是default，则抛出异常
    throw std::runtime_error("expect case or default in switch statement");
  }

  // 解析右大括号
  auto child_right_big = std::make_shared<TerminalSeparator>(this->lexer_);
  child_right_big->Parse();
  if (child_right_big->separator_ != "}") {
    throw std::runtime_error("expect }");
  } else {
    this->children_.push_back(child_right_big);
  }

  this->lexer_->getNextToken();
}

std::shared_ptr<ExprNode> SwitchStatNode::getExpression() const {
  return expression_;
}

const std::vector<std::pair<std::shared_ptr<ExprNode>, std::shared_ptr<BlockStatNode>>>& 
SwitchStatNode::getCases() const {
  return cases_;
}

std::shared_ptr<BlockStatNode> SwitchStatNode::getDefaultCase() const {
  return defaultCase_;
}

void SwitchStatNode::addCase(std::shared_ptr<ExprNode> caseExpr, 
                            std::shared_ptr<BlockStatNode> caseBlock) {
  cases_.push_back(std::make_pair(caseExpr, caseBlock));
}

void SwitchStatNode::setDefaultCase(std::shared_ptr<BlockStatNode> defaultBlock) {
  defaultCase_ = defaultBlock;
}

bool SwitchStatNode::isTerminating() const {
  // 如果没有default子句并且case列表为空，则不是终止语句
  if (!defaultCase_ && cases_.empty()) {
    return false;
  }
  
  // 检查所有case子句是否都是终止语句
  bool allCasesTerminating = true;
  for (const auto& caseItem : cases_) {
    if (!caseItem.second->isTerminating()) {
      allCasesTerminating = false;
      break;
    }
  }
  
  // 如果有default子句，检查它是否是终止语句
  bool defaultTerminating = defaultCase_ ? defaultCase_->isTerminating() : false;
  
  // 只有当所有case都是终止语句且default也是终止语句（或没有default）时，整个switch才是终止语句
  return allCasesTerminating && (defaultTerminating || !defaultCase_);
}

} // namespace mycompiler
