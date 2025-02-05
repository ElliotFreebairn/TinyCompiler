#include <iostream>
#include "./includes/Token.h"
#include "./includes/TokenType.h"

Token::Token(char tokenText, TokenType tokenKind) {
  text = tokenText;
  kind = tokenKind;
}
