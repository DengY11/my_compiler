#include "ast_node/root_node.hpp"
#include "ast_node/decl_node/function_decl_node.hpp"
#include "ast_node/decl_node/variable_decl_node.hpp"
#include "ast_node/stat_node/expression_stat_node.hpp"
#include <ostream>
#include <sstream>

namespace mycompiler {

RootNode::RootNode(std::shared_ptr<Lexer> lexer) : BasicNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::ROOT;
}

void RootNode::print_info() {
  std::cout << "Node type: ROOT" << std::endl;
  std::cout << "Declarations: " << declarations_.size() << std::endl;
  for (const auto& decl : declarations_) {
    decl->print_info();
  }
  
  std::cout << "Statements: " << statements_.size() << std::endl;
  for (const auto& stat : statements_) {
    stat->print_info();
  }
  
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

std::string RootNode::toString() const {
  std::stringstream ss;
  ss << "RootNode with " << declarations_.size() << " declarations and "
     << statements_.size() << " statements";
  return ss.str();
}

void RootNode::Parse() {
  // 解析整个程序，直到遇到文件结束
  while (true) {
    Token token = lexer_->peekNextToken();
    
    // 如果遇到文件结束，则停止解析
    if (token.getTokenType() == TokenType::ILLEGAL_OR_EOF) {
      break;
    }
    
    // 根据标记类型决定解析声明还是语句
    if (token.getTokenType() == TokenType::KEYWORD) {
      auto keywordType = getKeywordTypeFromToken(token);
      
      // 函数声明
      if (keywordType == KeywordType::FUNC) {
        auto funcDecl = std::make_shared<FuncDeclNode>(lexer_);
        funcDecl->Parse();
        addDeclaration(funcDecl);
        add_child(funcDecl);
      }
      // 变量声明
      else if (keywordType == KeywordType::LET) {
        auto varDecl = std::make_shared<VariableDeclNode>(lexer_);
        varDecl->Parse();
        addDeclaration(varDecl);
        add_child(varDecl);
      }
      // 其他语句
      else {
        auto exprStat = std::make_shared<ExpressionStatNode>(lexer_);
        exprStat->Parse();
        addStatement(exprStat);
        add_child(exprStat);
      }
    }
    // 默认作为表达式语句处理
    else {
      auto exprStat = std::make_shared<ExpressionStatNode>(lexer_);
      exprStat->Parse();
      addStatement(exprStat);
      add_child(exprStat);
    }
  }
}

void RootNode::addDeclaration(std::shared_ptr<DeclNode> decl) {
  declarations_.push_back(decl);
}

void RootNode::addStatement(std::shared_ptr<StatNode> stat) {
  statements_.push_back(stat);
}

const std::vector<std::shared_ptr<DeclNode>>& RootNode::getDeclarations() const {
  return declarations_;
}

const std::vector<std::shared_ptr<StatNode>>& RootNode::getStatements() const {
  return statements_;
}

} // namespace mycompiler
