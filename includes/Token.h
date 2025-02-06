#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include "TokenType.h"

class Token {
public:
  char text;
  TokenType kind;
  Token(char tokenText, TokenType tokenKind);
};

#endif

