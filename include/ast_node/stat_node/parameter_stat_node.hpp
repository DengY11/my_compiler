#ifndef PARAMTER_STAT_NODE_HPP
#define PARAMTER_STAT_NODE_HPP
#include "ast_node/stat_node/stat_node.hpp"
#include <memory>

namespace mycompiler {

class ParameterStatNode : public StatNode {
public:
  ParameterStatNode(std::shared_ptr<Lexer> lexer);

  virtual auto print_info() -> void override;

  virtual auto Parse() -> void override;
};

} // namespace mycompiler

#endif
