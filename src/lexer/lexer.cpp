#include "lexer/lexer.hpp"
#include "lexer/lexer_helper_functions.hpp"
#include <cctype>
#include <cstddef>
#include <stdexcept>

namespace mycompiler {

Lexer::Lexer(const std::string &input)
    : input_(input), index_(0), line_(1), column_(1),
      curToken_(mycompiler::makeEofOrIllegalToken(EofOrIllegalType::ILLEGAL, line_, column_)) {}

auto Lexer::isEnd() -> bool { 
  return this->index_ >= input_.length(); 
}

auto Lexer::printSource() -> void {
  std::cout << "source: " + this->input_ << std::endl;
}

auto Lexer::getCurrentIndex() const -> size_t { 
  return this->index_; 
}

auto Lexer::getCurrentLine() const -> std::size_t {
  return this->line_;
}

auto Lexer::getCurrentColumn() const -> std::size_t {
  return this->column_;
}

auto Lexer::updatePosition(char ch) -> void {
  if (ch == '\n') {
    this->line_++;
    this->column_ = 1;
  } else {
    this->column_++;
  }
}

auto Lexer::lookNextChar() -> char {
  int nextIndex = index_ + 1;
  if (nextIndex >= this->input_.length()) {
    return '\0';
  }
  return input_[nextIndex];
}

auto Lexer::peekNextToken() -> Token {
  // 保存当前状态
  size_t savedIndex = index_;
  Token savedToken = curToken_;
  std::size_t savedLine = line_;
  std::size_t savedColumn = column_;
  
  // 获取下一个Token
  Token nextToken = getNextToken();
  
  // 恢复状态
  index_ = savedIndex;
  curToken_ = savedToken;
  line_ = savedLine;
  column_ = savedColumn;
  
  return nextToken;
}

auto Lexer::skipSingleLineComment() -> void {
  // 跳过"//"
  advanceChar(); // 跳过第一个'/'
  advanceChar(); // 跳过第二个'/'
  
  // 跳过直到行尾或文件结束
  while (!isEnd() && peekChar() != '\n') {
    advanceChar();
  }
}

auto Lexer::skipMultiLineComment() -> void {
  // 跳过"/*"
  advanceChar(); // 跳过'/'
  advanceChar(); // 跳过'*'
  
  // 跳过直到找到"*/"或文件结束
  while (!isEnd()) {
    if (peekChar() == '*' && lookNextChar() == '/') {
      advanceChar(); // 跳过'*'
      advanceChar(); // 跳过'/'
      return;
    }
    advanceChar();
  }
}

auto Lexer::skipComment() -> bool {
  if (peekChar() == '/' && lookNextChar() == '/') {
    skipSingleLineComment();
    return true;
  } else if (peekChar() == '/' && lookNextChar() == '*') {
    skipMultiLineComment();
    return true;
  }
  return false;
}

auto Lexer::skipWhitespace() -> void {
  // 如果已经到达输入结束，直接返回
  if (this->index_ >= this->input_.length()) {
    return;
  }
  
  // 跳过空白字符和注释
  bool skippedSomething;
  do {
    skippedSomething = false;
    
    // 跳过空白字符
    while (!this->isEnd() && std::isspace(this->input_[index_])) {
      updatePosition(this->input_[index_]);
      ++index_;
      skippedSomething = true;
    }
    
    // 跳过注释
    if (!isEnd() && skipComment()) {
      skippedSomething = true;
    }
  } while (skippedSomething);
}

auto Lexer::peekChar() -> char {
  if (!isEnd()) {
    return input_[index_];
  }
  return '\0';
}

auto Lexer::advanceChar() -> char {
  if (!isEnd()) {
    char ch = input_[index_++];
    updatePosition(ch);
    return ch;
  }
  return '\0';
}

auto Lexer::isKeyword(std::string &word) -> bool {
  return this->keywordPool_.find(word);
}

auto Lexer::isOperator(std::string &word) -> bool {
  return this->operatorPool_.find(word);
}

auto Lexer::isSeparator(std::string &word) -> bool {
  return this->separatorPool_.find(word);
}

auto Lexer::getNextToken() -> mycompiler::Token {
  this->skipWhitespace();

  // 保存当前位置，用于创建Token
  std::size_t startLine = line_;
  std::size_t startColumn = column_;

  // 检查是否到达输入结束
  if (isEnd() || peekChar() == '\0') {
    curToken_ = makeEofOrIllegalToken(mycompiler::EofOrIllegalType::EOF_, startLine, startColumn);
    return curToken_;
  }

  char current = this->advanceChar();

  // 处理数字
  if (std::isdigit(current)) {
    std::string numberStr(1, current);
    size_t number_of_dot = 0;
    
    // 读取完整的数字
    while (!this->isEnd() && isConstantNumberType(this->peekChar())) {
      if (peekChar() == '.') {
        number_of_dot++;
        if (number_of_dot > 1) {
          throw std::runtime_error("数字中小数点数量不能超过1个");
        }
      }
      numberStr += this->advanceChar();
    }
    
    // 根据是否有小数点创建不同类型的常量Token
    if (number_of_dot == 0) {
      curToken_ = makeConstantToken(std::stoi(numberStr), startLine, startColumn);
      return curToken_;
    } else if (number_of_dot == 1) {
      curToken_ = makeConstantToken(std::stod(numberStr), startLine, startColumn);
      return curToken_;
    }
    
    // 如果出现异常情况，返回非法Token
    curToken_ = makeEofOrIllegalToken(EofOrIllegalType::ILLEGAL, startLine, startColumn);
    return curToken_;
  }

  // 处理标识符和关键字
  if (std::isalpha(current)) {
    bool have_underline = false;
    std::string alphaStr(1, current);
    
    // 读取完整的标识符或关键字
    while (!this->isEnd() && (isKeywordType(this->peekChar()) ||
                             isIdentType(this->peekChar()))) {
      if (peekChar() == '_') {
        have_underline = true;
      }
      alphaStr += this->advanceChar();
    }
    
    // 如果包含下划线，一定是标识符
    if (have_underline) {
      this->curToken_ = makeIdentifierToken(alphaStr, startLine, startColumn);
      return curToken_;
    } 
    // 检查是否是关键字
    else if (isKeyword(alphaStr)) {
      curToken_ = makeKeywordToken(getKeywordTypeFromString(alphaStr), startLine, startColumn);
      return curToken_;
    }
    // 否则是普通标识符
    curToken_ = makeIdentifierToken(alphaStr, startLine, startColumn);
    return curToken_;
  }

  // 处理操作符
  if (mycompiler::isOperatorType(current)) {
    std::string operatorStr(1, current);
    
    // 检查是否是注释开始
    if (current == '/' && (peekChar() == '/' || peekChar() == '*')) {
      // 恢复位置
      --index_;
      --column_;
      
      // 跳过注释并获取下一个Token
      skipComment();
      return getNextToken();
    }
    
    // 读取可能的多字符操作符
    while (!this->isEnd() && isOperatorType(this->peekChar())) {
      operatorStr += this->advanceChar();
    }
    
    // 检查是否是有效的操作符
    if (this->isOperator(operatorStr)) {
      curToken_ = makeOperatorToken(getOperatorTypeFromString(operatorStr), startLine, startColumn);
      return curToken_;
    }
    throw std::runtime_error("非法操作符: " + operatorStr);
  }

  // 处理分隔符
  if (mycompiler::isSeparatorType(current)) {
    std::string separatorStr(1, current);
    
    // 读取可能的多字符分隔符
    while (!this->isEnd() && isSeparatorType(this->peekChar()) &&
           separatorCanCombine(separatorStr, this->peekChar())) {
      separatorStr += this->advanceChar();
    }
    
    // 检查是否是有效的分隔符
    if (this->isSeparator(separatorStr)) {
      curToken_ = makeSeparatorToken(separatorStr, startLine, startColumn);
      return curToken_;
    }
    throw std::runtime_error("非法分隔符: " + separatorStr);
  }

  // 处理其他未识别的字符
  curToken_ = makeEofOrIllegalToken(EofOrIllegalType::ILLEGAL, startLine, startColumn);
  return curToken_;
}

auto Lexer::getCurrentToken() const -> Token { 
  return this->curToken_; 
}

} // namespace mycompiler
