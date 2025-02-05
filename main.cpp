#include <iostream>

#include "./includes/Lexer.hpp"

int main(int argc, char *argv[])
{
  std::string source = "LET foobar = 123";
  std::cout << source << std::endl;
  Lexer lexer = Lexer(source);
  std::cout << lexer.source << std::endl;
  while(lexer.peek() != '\0') {
    std::cout << lexer.curChar << std::endl;
    lexer.nextChar();
  }
}
