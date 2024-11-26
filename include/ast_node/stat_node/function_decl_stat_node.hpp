#ifndef FUNCTION_DECL_STAT_NODE_HPP
#define FUNCTION_DECL_STAT_NODE_HPP
#include "ast_node/stat_node/stat_node.hpp"
#include <memory>

namespace mycompiler {

class FunctionDeclStatNode : public StatNode {
public:
  FunctionDeclStatNode(std::shared_ptr<Lexer> lexer);

  virtual auto print_info() -> void override;

  virtual auto Parse() -> void override;

  virtual ~FunctionDeclStatNode() = default;
};

} // namespace mycompiler

#endif
