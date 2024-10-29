#include "../../include/token/token_helper_functions.hpp"

namespace mycompiler {

auto get_keyword_type_from_token_class(Token token) -> Keyword_Type {
  return std::get<Keyword>(token.get_token_value()).Keyword_type_;
}

} // namespace mycompiler
