#ifndef PARAMTER_LIST_STAT_NODE_HPP
#define PARAMTER_LIST_STAT_NODE_HPP
#include "./stat_node.hpp"
#include <memory>

namespace mycompiler {

class ParameterListStatNode : public StatNode {
public:
  ParameterListStatNode(std::shared_ptr<Lexer> lexer);

  virtual auto print_info() -> void override;

  virtual auto Parse() -> void override;

  auto is_parameter_list_type(const Token &token) -> bool;
};

} // namespace mycompiler

#endif
