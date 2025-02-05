#include <iostream>
#include "./includes/Lexer.hpp"

Lexer::Lexer(std::string &source) {
  source = source + '\n';
  curChar = ' ';
  curPos = -1;
  nextChar();
}

void Lexer::nextChar() {
  curPos += 1;
  if (curPos >= source.length()) {
    curChar = '\0';
  } else {
    curChar = source[curPos];
  }
}

char Lexer::peek() {
  if (curPos + 1 >= source.length()) {
    return '\0';
  }
  return source[curPos + 1];
}

