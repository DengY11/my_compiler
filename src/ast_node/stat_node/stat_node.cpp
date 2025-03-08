#include "ast_node/stat_node/stat_node.hpp"
#include "magic_enum/magic_enum.hpp"
#include <memory>
#include <sstream>

namespace mycompiler {

StatNode::StatNode(std::shared_ptr<Lexer> lexer) : BasicNode(lexer) {
  this->ast_node_type_ = AST_NODE_TYPE::STAT;
  this->statType_ = StatType::VOID_STAT; // 默认为空语句
}

auto StatNode::print_info() -> void {
  std::cout << "Node type: STAT" << std::endl;
  std::cout << "Stat type: " << std::string(magic_enum::enum_name(this->statType_)) << std::endl;
  std::cout << "Is terminating: " << (isTerminating() ? "true" : "false") << std::endl;
  
  std::cout << "Children: " << std::endl;
  std::for_each(std::begin(children_), std::end(children_),
                [](ChildPtr child) { child->print_info(); });
}

std::string StatNode::toString() const {
  std::stringstream ss;
  ss << "Statement of type " << std::string(magic_enum::enum_name(this->statType_));
  return ss.str();
}

StatType StatNode::getStatType() const {
  return statType_;
}

bool StatNode::isTerminating() const {
  // 只有return, break, continue语句是终止语句
  return statType_ == StatType::RETURN_STAT || 
         statType_ == StatType::BREAK_STAT || 
         statType_ == StatType::CONTINUE_STAT;
}

void StatNode::Parse() {}

} // namespace mycompiler
