#include "../../include/lexer/lexer.hpp"
#include <string>

auto main() -> int {

  std::string code =
      "let a = 1 ; let func = function ( a , b ) { return a + b }";
  mycompiler::Lexer lexer(code);
  int cnt = 0;
  lexer.print_source();
  while (lexer.getNextToken().get_token_type() !=
         mycompiler::TokenType::ILLEGAL_OR_EOF) {
    ++cnt;
    lexer.getNextToken().print_info();
  }
  std::cout << "token amount:" + std::to_string(cnt) << std::endl;

  return 0;
}
