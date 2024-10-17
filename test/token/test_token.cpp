#include "../../include/token/token.hpp"
#include <iostream>

int main() {
  mycompiler::Token t1 =
      mycompiler::make_operator_token(mycompiler::Operator_Type::DIV);
  mycompiler::Token t2 = mycompiler::make_separator_token(";");
  mycompiler::Token t3 = mycompiler::make_constant_token(1);
  mycompiler::Token t4 = mycompiler::make_constant_token(1.1);
  mycompiler::Token t5 =
      mycompiler::make_operator_token(mycompiler::Operator_Type::SUB);
  mycompiler::Token t6 = mycompiler::make_constant_token("hachimi");
  mycompiler::Token t7 =
      mycompiler::make_keyword_token(mycompiler::Keyword_Type::ELSE);
  mycompiler::Token t8 = mycompiler::make_identifier_token("asd");
  t1.print_info();
  t2.print_info();
  t3.print_info();
  t4.print_info();
  t5.print_info();
  t6.print_info();
  t7.print_info();
  t8.print_info();

  return 0;
}
