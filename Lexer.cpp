#include <iostream>
#include "./includes/Lexer.hpp"
#include "./includes/Token.h"

Lexer::Lexer(std::string &source) {
  this->source = source + '\n';
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

Token Lexer::getToken() {
  skipWhitespace();
  skipComment();
  Token token = Token(' ', TokenType::DEF);
  switch(curChar) {
    case '+':
      token = Token(curChar, TokenType::PLUS);
      std::cout << "+";
      break;
    case '-':
      token = Token(curChar, TokenType::MINUS);
      std::cout << "-";
      break;
    case '*':
      token = Token(curChar, TokenType::ASTERISK);
      std::cout << "*";
      break;
    case '/':
      token = Token(curChar, TokenType::SLASH);
      std::cout << "/";
      break;
    case '\n':
      token = Token(curChar, TokenType::NEWLINE);
      std::cout << "\\n";
      break;
    case '\0':
      token = Token(' ', TokenType::EOFT);
      std::cout << "\0";
      break;
    case '=':
      if (peek() == '='){
        char lastChar = curChar;
        nextChar();
        token = Token(lastChar + curChar, TokenType::EQEQ);
        std::cout << "==";
      } else {
        token = Token(curChar, TokenType::EQ);
        std::cout << "=";
      }
      break;
    case '>':
      if (peek() == '=') {
        char lastChar = curChar;
        nextChar();
        token = Token(lastChar + curChar, TokenType::GTEQ);
        std::cout << ">=";
      } else {
        token = Token(curChar, TokenType::GT);
        std::cout << ">";
      }
      break;
    case '<':
      if (peek() == '=') {
        char lastChar = curChar;
        nextChar();
        token = Token(lastChar + curChar, TokenType::LTEQ);
        std::cout << "<=";
      } else {
        token = Token(curChar, TokenType::LT);
        std::cout << "<";
      }
      break;
    case '!':
      if (peek() == '=') {
        char lastChar = curChar;
        nextChar();
        token = Token(lastChar + curChar, TokenType::NOTEQ);
        std::cout << "!=";
      } else {
        std::cout << "Expected !=, got !";
      }
      break;
    default:
      std::cout << "No idea";
      break;
  };

  nextChar();
  return token;
}

void Lexer::skipWhitespace() {
  while (curChar == ' ' || curChar == '\t' || curChar == '\r') {
    nextChar();
  }
}

void Lexer::skipComment() {
  if (curChar == '#') {
    while (curChar != '\n') {
      nextChar();
    }
  }
}





