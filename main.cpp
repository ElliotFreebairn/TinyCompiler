#include <iostream>

#include "./includes/Lexer.hpp"
#include "./includes/Token.h"
#include "./includes/TokenType.h"

int main(int argc, char *argv[])
{
//  std::string source = "LET foobar = 123"; 
//  std::cout << source << std::endl;
//  Lexer lexer = Lexer(source);
//  std::cout << lexer.source << std::endl;
//  while(lexer.peek() != '\0') {
//    std::cout << lexer.curChar << std::endl;
//    lexer.nextChar();
//  }
//
  std::string source = "+-*/>>= #This is a comment\n=!=";
    Lexer lexer = Lexer(source);
  
  Token token = lexer.getToken();
  while (token.kind != TokenType::EOFT) {
    std::cout << token.kind << " " << std::endl;
    token = lexer.getToken();
}
}
