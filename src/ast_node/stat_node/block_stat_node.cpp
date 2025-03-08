#include "ast_node/stat_node/block_stat_node.hpp"
#include "ast_node/stat_node/expression_stat_node.hpp"
#include "ast_node/stat_node/return_stat_node.hpp"
#include "ast_node/stat_node/if_stat_node.hpp"
#include "ast_node/stat_node/while_stat_node.hpp"
#include "ast_node/stat_node/for_stat_node.hpp"
#include "ast_node/stat_node/break_stat_node.hpp"
#include "ast_node/stat_node/continue_stat_node.hpp"
#include "ast_node/decl_node/variable_decl_node.hpp"
#include "token/token_helper_functions.hpp"
#include <sstream>

namespace mycompiler {

BlockStatNode::BlockStatNode(std::shared_ptr<Lexer> lexer) : StatNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::BLOCK_STAT;
  this->statType_ = StatType::BLOCK_STAT;
}

auto BlockStatNode::print_info() -> void {
  std::cout << "Node type: BLOCK_STAT" << std::endl;
  std::cout << "Statements: " << statements_.size() << std::endl;
  
  for (const auto& statement : statements_) {
    statement->print_info();
  }
  
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

std::string BlockStatNode::toString() const {
  std::stringstream ss;
  ss << "Block with " << statements_.size() << " statements";
  return ss.str();
}

auto BlockStatNode::Parse() -> void {
  // 解析块语句：{ statements }
  // 注意：左花括号已经被消费，我们只需要解析语句直到遇到右花括号
  
  // 解析语句直到遇到右花括号
  while (true) {
    Token token = lexer_->getCurrentToken();
    
    // 如果遇到右花括号，则结束解析
    if (token.getTokenType() == TokenType::SEPARATOR && 
        getSeparatorValueFromToken(token) == "}") {
      break;
    }
    
    // 如果遇到文件结束，则抛出异常
    if (token.getTokenType() == TokenType::ILLEGAL_OR_EOF) {
      throw std::runtime_error("Unexpected end of file");
    }
    
    // 根据标记类型决定解析哪种语句
    if (token.getTokenType() == TokenType::KEYWORD) {
      auto keywordType = getKeywordTypeFromToken(token);
      
      // 变量声明
      if (keywordType == KeywordType::LET) {
        auto varDecl = std::make_shared<VariableDeclNode>(lexer_);
        varDecl->Parse();
        addStatement(std::make_shared<ExpressionStatNode>(lexer_));
        add_child(varDecl);
      }
      // return语句
      else if (keywordType == KeywordType::RETURN) {
        auto returnStat = std::make_shared<ReturnStatNode>(lexer_);
        returnStat->Parse();
        addStatement(returnStat);
        add_child(returnStat);
      }
      // if语句
      else if (keywordType == KeywordType::IF) {
        auto ifStat = std::make_shared<IfStatNode>(lexer_);
        ifStat->Parse();
        addStatement(ifStat);
        add_child(ifStat);
      }
      // while语句
      else if (keywordType == KeywordType::WHILE) {
        auto whileStat = std::make_shared<WhileStatNode>(lexer_);
        whileStat->Parse();
        addStatement(whileStat);
        add_child(whileStat);
      }
      // for语句
      else if (keywordType == KeywordType::FOR) {
        auto forStat = std::make_shared<ForStatNode>(lexer_);
        forStat->Parse();
        addStatement(forStat);
        add_child(forStat);
      }
      // break语句
      else if (keywordType == KeywordType::BREAK) {
        auto breakStat = std::make_shared<BreakStatNode>(lexer_);
        breakStat->Parse();
        addStatement(breakStat);
        add_child(breakStat);
      }
      // continue语句
      else if (keywordType == KeywordType::CONTINUE) {
        auto continueStat = std::make_shared<ContinueStatNode>(lexer_);
        continueStat->Parse();
        addStatement(continueStat);
        add_child(continueStat);
      }
      // 其他关键字，作为表达式语句处理
      else {
        auto exprStat = std::make_shared<ExpressionStatNode>(lexer_);
        exprStat->Parse();
        addStatement(exprStat);
        add_child(exprStat);
      }
    }
    // 其他标记，作为表达式语句处理
    else {
      auto exprStat = std::make_shared<ExpressionStatNode>(lexer_);
      exprStat->Parse();
      addStatement(exprStat);
      add_child(exprStat);
    }
  }
}

void BlockStatNode::addStatement(std::shared_ptr<StatNode> statement) {
  statements_.push_back(statement);
}

const std::vector<std::shared_ptr<StatNode>>& BlockStatNode::getStatements() const {
  return statements_;
}

bool BlockStatNode::isTerminating() const {
  // 如果块为空，则不是终止语句
  if (statements_.empty()) {
    return false;
  }
  
  // 如果最后一个语句是终止语句，则块是终止语句
  return statements_.back()->isTerminating();
}

} // namespace mycompiler
