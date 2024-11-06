#ifndef PARAMTER_LIST_STAT_NODE_HPP
#define PARAMTER_LIST_STAT_NODE_HPP
#include "ast_node/stat_node/stat_node.hpp"
#include <memory>

namespace mycompiler {

enum class ParameterListType { FUNC_DECL, FUNC_CALL };

class ParameterListStatNode : public StatNode {
public:
  ParameterListStatNode(std::shared_ptr<Lexer> lexer,
                        ParameterListType para_type);

  virtual auto print_info() -> void override;

  virtual auto Parse() -> void override;

  virtual ~ParameterListStatNode() = default;

  auto is_parameter_list_type(const Token &token) -> bool;

  auto is_decl_func_parameter_list_type(const Token &token) -> bool;

private:
  ParameterListType para_type_;
};

} // namespace mycompiler

#endif
