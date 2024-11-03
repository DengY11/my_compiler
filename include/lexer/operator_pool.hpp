#ifndef OPERATOR_POOL_HPP
#define OPERATOR_POOL_HPP

#include "token/operator_type.hpp"
#include <string>
#include <unordered_set>

namespace mycompiler {

class OperatorPool {
public:
  OperatorPool();
  auto find(std::string &op) -> bool;

private:
  const std::unordered_set<std::string> operators_;
};

auto get_operator_type_from_string(std::string &str) -> Operator_Type;

} // namespace mycompiler

#endif
