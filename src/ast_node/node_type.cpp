#include "ast_node/node_type.hpp"
#include <string>

namespace mycompiler {

std::string getNodeTypeString(NodeType type) {
  switch (type) {
    case NodeType::EXPR_NODE:
      return "Expression Node";
    case NodeType::STAT_NODE:
      return "Statement Node";
    case NodeType::DECL_NODE:
      return "Declaration Node";
    case NodeType::TERMINAL_NODE:
      return "Terminal Node";
    case NodeType::ROOT_NODE:
      return "Root Node";
    default:
      return "Unknown Node Type";
  }
}

} // namespace mycompiler 