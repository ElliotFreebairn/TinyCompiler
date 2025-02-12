#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include "TokenType.h"

class Token {
public:
  std::string text;
  TokenType kind;
  Token(std::string tokenText, TokenType tokenKind);
};

#endif

