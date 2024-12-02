#ifndef LEXER_HELPER_FUNCTIONS_HPP
#define LEXER_HELPER_FUNCTIONS_HPP

#include "lexer/lexer.hpp"
namespace mycompiler {

auto is_constant_number_type(char ch) -> bool;

auto is_constant_string_type(char ch) -> bool;

auto is_ident_type(char ch) -> bool;

auto is_keyword_type(char ch) -> bool;

auto is_operator_type(char ch) -> bool;

auto is_separator_type(char ch) -> bool;

auto maybe_binary_operator(char ch) -> bool;

auto maybe_unary_operator(char ch) -> bool;

auto separator_can_combine(std::string &pre, char cur) -> bool;
} // namespace mycompiler
#endif // !LEXER_HELPER_FUNCTIONS_HPP
