#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <iostream>
#include <cctype>
#include "Token.h"



class Lexer {

  public:
    Lexer(std::string &source);

    void nextChar();

    char peek();
  
    void abort(const std::string& message) const;

    void skipWhitespace();

    void skipComment();

    Token getToken();

    std::string source;
    char curChar;
    size_t curPos;
};

#endif
