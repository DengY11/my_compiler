#include "lexer/lexer_helper_functions.hpp"
#include <cctype>

namespace mycompiler {

auto is_constant_number_type(char ch) -> bool {
  return (std::isdigit(ch) || ch == '.');
}

auto is_constant_string_type(char ch) -> bool { return ch != '\0'; }

auto is_indent_type(char ch) -> bool {
  return (std::isdigit(ch) || std::isalpha(ch) || ch == '_');
}

auto is_keyword_type(char ch) -> bool { return std::isalpha(ch); }

auto is_operator_type(char ch) -> bool {
  return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' ||
          ch == '!' || ch == '^');
}

auto is_separator_type(char ch) -> bool {
  return (ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == '[' ||
          ch == ']' || ch == ',' || ch == ';' || ch == '"');
}

auto separator_can_combine(std::string &pre, char cur) -> bool {
  if (pre[pre.length() - 1] == '[' && cur == '[') {
    return true;
  }
  if (pre[pre.length() - 1] == ']' && cur == ']') {
    return true;
  }
  return false;
}

} // namespace mycompiler
