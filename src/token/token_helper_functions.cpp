#include "token/token_helper_functions.hpp"
#include "token/token_type.hpp"

namespace mycompiler {

auto get_keyword_type_from_token_class(const Token &token)
    -> Keyword_Type const {
  return std::get<Keyword>(token.get_token_value()).Keyword_type_;
}

auto get_operator_type_from_token_class(const Token &token)
    -> Operator_Type const {
  return std::get<Operator>(token.get_token_value()).operator_type_;
}

auto get_ident_literal_type_from_token_class(const Token &token)
    -> std::string const {
  return std::get<Identifier>(token.get_token_value()).value_;
}

auto get_value_literal_type_from_token_class(const Token &token)
    -> std::string const {
  return std::get<Identifier>(token.get_token_value()).value_;
}

auto get_separator_type_from_token_class(const Token &token)
    -> std::string const {
  return std::get<Separator>(token.get_token_value()).value_;
}

auto is_identifier_type(const Token &token) -> bool {
  return token.get_token_type() == TokenType::IDENT;
}

} // namespace mycompiler
