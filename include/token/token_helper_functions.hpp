#ifndef TOKEN_HELPER_FUNCTIONS
#define TOKEN_HELPER_FUNCTIONS
#include "eof_or_illegal_type.hpp"
#include "token/comment_type.hpp"
#include "token/constant_type.hpp"
#include "token/ident_type.hpp"
#include "token/keyword_type.hpp"
#include "token/operator_type.hpp"
#include "token/preprocessor.hpp"
#include "token/separator_type.hpp"
#include "token/token.hpp"
#include "token/token_type.hpp"
#include <iostream>
#include <string>
#include <variant>

namespace mycompiler {

auto get_keyword_type_from_token_class(const Token &token)
    -> Keyword_Type const;

auto get_operator_type_from_token_class(const Token &token)
    -> Operator_Type const;

auto get_ident_literal_type_from_token_class(const Token &token)
    -> std::string const;

auto get_value_literal_type_from_token_class(const Token &token)
    -> std::string const;

auto get_separator_type_from_token_class(const Token &token)
    -> std::string const;

auto is_identifier_type(const Token &token) -> bool;

auto is_unary_operator_token(const Token &token) -> bool;

auto is_binary_operator_token(const Token &token) -> bool;

auto get_operator_priority(const std::string &op) -> int;

auto get_operator_priority(const Token &token) -> int;

// TODO:

} // namespace mycompiler

#endif
