#include "../../include/token/token_helper_functions.hpp"

namespace mycompiler {

auto get_keyword_type_from_token_class(Token token) -> Keyword_Type {
  return std::get<Keyword>(token.get_token_value()).Keyword_type_;
}

auto get_operator_type_from_token_class(Token token) -> Operator_Type {
  return std::get<Operator>(token.get_token_value()).operator_type_;
}

auto get_ident_literal_type_from_token_class(Token token) -> std::string {
  return std::get<Identifier>(token.get_token_value()).value_;
}

auto get_value_literal_type_from_token_class(Token token) -> std::string {
  return std::get<Identifier>(token.get_token_value()).value_;
}

} // namespace mycompiler
