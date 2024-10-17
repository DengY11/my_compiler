#include "../../include/lexer/lexer.hpp"
#include "../../include/lexer/lexer_helper_functions.hpp"
#include <cctype>
#include <cstddef>
#include <stdexcept>

namespace mycompiler {

Lexer::Lexer(const std::string &input) : input_(input), index_(0) {}

auto Lexer::is_end() -> bool { return this->index_ >= input_.length(); }

void Lexer::skipWhitespace() {
  while (!this->is_end() && std::isspace(this->input_[index_])) {
    ++index_;
  }
}

auto Lexer::peekChar() -> char {
  if (!is_end()) {
    return input_[index_];
  }
  return '\0';
}

auto Lexer::advanceChar() -> char {
  if (!is_end()) {
    return input_[index_++];
  }
  return '\0';
}

auto Lexer::is_keyword(std::string &word) -> bool {
  return this->keyword_pool_.find(word);
}

auto Lexer::getNextToken() -> mycompiler::Token {
  this->skipWhitespace();

  if (is_end()) {
    return make_eof_or_illegal_token(mycompiler::EOF_OR_ILLEGAL_TYPE::EOF_);
  }

  char current = this->advanceChar();

  if (std::isdigit(current)) {
    std::string numberStr(1, current);
    size_t number_of_dot = 0;
    while (!this->is_end() && is_constant_number_type(this->peekChar())) {
      if (peekChar() == '.') {
        number_of_dot++;
        if (number_of_dot > 1) {
          throw std::runtime_error(
              "the amount of dot of the number should be 0 or 1");
        }
      }
      numberStr += this->advanceChar();
    }
    if (number_of_dot != 0) {
      return make_constant_token(std::stoi(numberStr));
    } else if (number_of_dot == 1) {
      return make_constant_token(std::stod(numberStr));
    }
    return make_eof_or_illegal_token(EOF_OR_ILLEGAL_TYPE::ILLEGAL);
  }

  if (std::isalpha(current)) {
    // 字母开头，有可能是关键字，IDENT,
    bool have_underline = false;
    std::string alphaStr(1, current);
    while (!this->is_end() && (is_keyword_type(this->peekChar()) ||
                               is_indent_type(this->peekChar()))) {

      if (peekChar() == '_') {
        have_underline = true;
      }
      alphaStr += peekChar();
    }
    if (have_underline) {
      return make_identifier_token(alphaStr);
    } else if (is_keyword(alphaStr)) {
      return make_keyword_token(get_keyword_type_from_string(alphaStr));
    }
    return make_eof_or_illegal_token(EOF_OR_ILLEGAL_TYPE::ILLEGAL);
  }
  // TODO:还有啥分隔符，符号开头之类的
}

} // namespace mycompiler
