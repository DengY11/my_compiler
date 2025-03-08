#include "lexer/lexer_helper_functions.hpp"
#include <cctype>

namespace mycompiler {

auto isConstantNumberType(char ch) -> bool {
  return (std::isdigit(ch) || ch == '.');
}

auto isConstantStringType(char ch) -> bool { return ch != '\0'; }

auto isIdentType(char ch) -> bool {
  return (std::isdigit(ch) || std::isalpha(ch) || ch == '_');
}

auto isKeywordType(char ch) -> bool { return std::isalpha(ch); }

auto isOperatorType(char ch) -> bool {
  return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' ||
          ch == '!' || ch == '^');
}

auto maybeBinaryOperator(char ch) -> bool {
  return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' ||
          ch == '=');
}

auto maybeUnaryOperator(char ch) -> bool { return ch == '!'; }

auto isSeparatorType(char ch) -> bool {
  return (ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == '[' ||
          ch == ']' || ch == ',' || ch == ';' || ch == '"');
}

auto separatorCanCombine(std::string &pre, char cur) -> bool {
  if (pre[pre.length() - 1] == '[' && cur == '[') {
    return true;
  }
  if (pre[pre.length() - 1] == ']' && cur == ']') {
    return true;
  }
  return false;
}

} // namespace mycompiler
