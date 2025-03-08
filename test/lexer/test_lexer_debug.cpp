#include "lexer/lexer.hpp"
#include "lexer/lexer_helper_functions.hpp"
#include "token/token_type.hpp"
#include <iostream>
#include <string>

int main() {
  // 测试分号
  {
    std::string code = ";";
    mycompiler::Lexer lexer(code);
    
    std::cout << "Testing semicolon ';':" << std::endl;
    std::cout << "Is ';' a separator type? " << (mycompiler::isSeparatorType(';') ? "Yes" : "No") << std::endl;
    
    std::string semicolonStr = ";";
    std::cout << "Is ';' in separator pool? " << (lexer.isSeparator(semicolonStr) ? "Yes" : "No") << std::endl;
    
    std::cout << "Calling getNextToken()..." << std::endl;
    lexer.getNextToken();
    
    std::cout << "Token type: " << static_cast<int>(lexer.getCurrentToken().getTokenType()) << std::endl;
    std::cout << "Expected type: " << static_cast<int>(mycompiler::TokenType::SEPARATOR) << std::endl;
    
    lexer.getCurrentToken().printInfo();
  }
  
  // 测试操作符
  {
    std::string code = "+";
    mycompiler::Lexer lexer(code);
    
    std::cout << "\nTesting operator '+':" << std::endl;
    std::cout << "Is '+' an operator type? " << (mycompiler::isOperatorType('+') ? "Yes" : "No") << std::endl;
    
    std::string plusStr = "+";
    std::cout << "Is '+' in operator pool? " << (lexer.isOperator(plusStr) ? "Yes" : "No") << std::endl;
    
    std::cout << "Calling getNextToken()..." << std::endl;
    lexer.getNextToken();
    
    std::cout << "Token type: " << static_cast<int>(lexer.getCurrentToken().getTokenType()) << std::endl;
    std::cout << "Expected type: " << static_cast<int>(mycompiler::TokenType::OPERATOR) << std::endl;
    
    lexer.getCurrentToken().printInfo();
  }
  
  // 测试关键字
  {
    std::string code = "let";
    mycompiler::Lexer lexer(code);
    
    std::cout << "\nTesting keyword 'let':" << std::endl;
    
    std::string letStr = "let";
    std::cout << "Is 'let' in keyword pool? " << (lexer.isKeyword(letStr) ? "Yes" : "No") << std::endl;
    
    std::cout << "Calling getNextToken()..." << std::endl;
    lexer.getNextToken();
    
    std::cout << "Token type: " << static_cast<int>(lexer.getCurrentToken().getTokenType()) << std::endl;
    std::cout << "Expected type: " << static_cast<int>(mycompiler::TokenType::KEYWORD) << std::endl;
    
    lexer.getCurrentToken().printInfo();
  }
  
  return 0;
} 