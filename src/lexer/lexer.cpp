#include "../../include/lexer/lexer.hpp"
#include "../../include/lexer/lexer_helper_functions.hpp"
#include <cctype>
#include <cstddef>
#include <stdexcept>

namespace mycompiler {

Lexer::Lexer(const std::string &input)
    : input_(input), index_(0),
      curToken_(mycompiler::Token(
          make_eof_or_illegal_token(EOF_OR_ILLEGAL_TYPE::ILLEGAL))) {}

auto Lexer::is_end() -> bool { return this->index_ >= input_.length(); }

void Lexer::print_source() {
  std::cout << "source: " + this->input_ << std::endl;
}

auto Lexer::getCurrentIndex() const -> size_t { return this->index_; }

auto Lexer::lookNextChar() -> char {
  int nextIndex = ++index_;
  if (nextIndex >= this->input_.length()) {
    return '\0';
  }
  return input_[nextIndex];
}

void Lexer::skipWhitespace() {
  if (this->index_ >= this->input_.length() - 1) {
    ++index_;
    return;
  }
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

auto Lexer::is_operator(std::string &word) -> bool {
  return this->operator_pool_.find(word);
}

auto Lexer::is_separator(std::string &word) -> bool {
  return this->separator_pool_.find(word);
}

auto Lexer::getNextToken() -> mycompiler::Token {
  this->skipWhitespace();
  // std::cout << "current index: ";
  // std::cout << this->getCurrentIndex() << std::endl;

  if (is_end() || peekChar() == '\0') {
    return make_eof_or_illegal_token(mycompiler::EOF_OR_ILLEGAL_TYPE::EOF_);
  }

  char current = this->advanceChar();

  if (std::isdigit(current)) {
    std::cout << "getNextToken digit" << std::endl;
    std::string numberStr(1, current);
    size_t number_of_dot = 0;
    while (!this->is_end() && is_constant_number_type(this->peekChar())) {
      if (peekChar() == '.') {
        // std::cout << "cur char: ";
        // std::cout << peekChar() << std::endl;
        number_of_dot++;
        if (number_of_dot > 1) {
          throw std::runtime_error(
              "the amount of dot of the number should be 0 or 1");
        }
      }
      numberStr += this->advanceChar();
    }
    if (number_of_dot == 0) {
      curToken_ = make_constant_token(std::stoi(numberStr));
      return curToken_;
    } else if (number_of_dot == 1) {
      curToken_ = make_constant_token(std::stod(numberStr));
      return curToken_;
    }
    curToken_ = make_eof_or_illegal_token(EOF_OR_ILLEGAL_TYPE::ILLEGAL);
    return curToken_;
  }

  if (std::isalpha(current)) {
    std::cout << "getNextToken alpha" << std::endl;
    //  字母开头，有可能是关键字，IDENT,
    bool have_underline = false;
    std::string alphaStr(1, current);
    while (!this->is_end() && (is_keyword_type(this->peekChar()) ||
                               is_indent_type(this->peekChar()))) {

      if (peekChar() == '_') {
        have_underline = true;
      }
      alphaStr += this->advanceChar();
    }
    if (have_underline) {
      this->curToken_ = make_identifier_token(alphaStr);
      return curToken_;
    } else if (is_keyword(alphaStr)) {
      curToken_ = make_keyword_token(get_keyword_type_from_string(alphaStr));
      return curToken_;
    }
    curToken_ = make_identifier_token(alphaStr);
    return curToken_;
  }

  if (mycompiler::is_operator_type(current)) {
    std::cout << "getNextToken operator" << std::endl;
    std::string operatorStr(1, current);
    while (!this->is_end() && is_operator_type(this->peekChar())) {
      operatorStr += this->advanceChar();
    }
    if (this->is_operator(operatorStr)) {
      curToken_ =
          make_operator_token(get_operator_type_from_string(operatorStr));
      return curToken_;
    }
    throw std::runtime_error("operator: " + operatorStr + " illegal!");
  }

  if (mycompiler::is_separator_type(current)) {
    std::cout << "getNextToken separator" << std::endl;
    std::string separatorStr(1, current);
    while (!this->is_end() && is_separator_type(this->peekChar()) &&
           separator_can_combine(separatorStr, this->peekChar())) {
      separatorStr += this->advanceChar();
    }
    if (this->is_separator(separatorStr)) {
      curToken_ = make_separator_token(separatorStr);
      return curToken_;
    }
    throw std::runtime_error("separator " + separatorStr + " illegal!");
  }
  // TODO:我不确定这里是否把token的种类全部枚举完了

  curToken_ =
      mycompiler::make_eof_or_illegal_token(EOF_OR_ILLEGAL_TYPE::ILLEGAL);
  return curToken_;
}

auto Lexer::getCurrentToken() const -> Token { return this->curToken_; }

} // namespace mycompiler
