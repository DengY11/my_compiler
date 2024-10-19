#include "../../include/lexer/lexer.hpp"
#include <string>

auto main() -> int {

  std::string code =
      "let a = 100 ; let func = function ( a , b ) { return a + b + 53.4 } ?";
  std::cout << "source length:";
  std::cout << code.length() << std::endl;
  mycompiler::Lexer lexer(code);
  int cnt = 0;
  lexer.print_source();
  lexer.getNextToken();
  while (lexer.getCurrentToken().get_token_type() !=
         mycompiler::TokenType::ILLEGAL_OR_EOF) {
    lexer.getCurrentToken().print_info();
    ++cnt;
    lexer.getNextToken();
  }
  std::cout << "token amount:" + std::to_string(cnt) << std::endl;

  return 0;
}
