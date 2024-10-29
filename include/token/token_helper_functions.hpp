#ifndef TOKEN_HELPER_FUNCTIONS
#define TOKEN_HELPER_FUNCTIONS
#include "./comment_type.hpp"
#include "./constant_type.hpp"
#include "./ident_type.hpp"
#include "./keyword_type.hpp"
#include "./operator_type.hpp"
#include "./preprocessor.hpp"
#include "./separator_type.hpp"
#include "./token.hpp"
#include "./token_type.hpp"
#include "eof_or_illegal_type.hpp"
#include <iostream>
#include <string>
#include <variant>

namespace mycompiler {

auto get_keyword_type_from_token_class(Token token) -> Keyword_Type;

// TODO:

} // namespace mycompiler

#endif
