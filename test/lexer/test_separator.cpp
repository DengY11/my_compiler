#include "lexer/lexer_helper_functions.hpp"
#include "lexer/separator_pool.hpp"
#include <iostream>
#include <string>

int main() {
  // 测试isSeparatorType函数
  char semicolon = ';';
  std::cout << "Is ';' a separator type? " << (mycompiler::isSeparatorType(semicolon) ? "Yes" : "No") << std::endl;
  
  // 测试SeparatorPool类
  mycompiler::SeparatorPool separatorPool;
  std::string semicolonStr = ";";
  std::cout << "Is ';' in separator pool? " << (separatorPool.find(semicolonStr) ? "Yes" : "No") << std::endl;
  
  return 0;
} 