#include "../../include/lexer/lexer.hpp"

auto main() -> int {

  std::string code =
      "let a = 1 ; let func = function ( a , b ) { return a + b }";
  mycompiler::Lexer lexer(code);
  while (lexer.getNextToken().get_token_type() !=
         mycompiler::TokenType::ILLEGAL_OR_EOF) {
    lexer.getNextToken().print_info();
  }

  return 0;
}
