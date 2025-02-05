#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include "TokenType.h"

class Token {
public:
  std::string text;
  int kind;
  Token(char tokenText, TokenType tokenKind);
};

#endif

