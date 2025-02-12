#include <iostream>
#include "./includes/Token.h"
#include "./includes/TokenType.h"

Token::Token(std::string tokenText, TokenType tokenKind) {
  text = tokenText;
  kind = tokenKind;
}
