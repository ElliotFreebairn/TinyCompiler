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
  Token token = Token(" ", TokenType::DEF);
  switch(curChar) {
    case '+':
      token = Token(std::string(1, curChar), TokenType::PLUS);
      std::cout << "PLUS";
      break;
    case '-':
      token = Token(std::string(1, curChar), TokenType::MINUS);
      std::cout << "MINUS";
      break;
    case '*':
      token = Token(std::string(1, curChar), TokenType::ASTERISK);
      std::cout << "ASTERISK";
      break;
    case '/':
      token = Token(std::string(1, curChar), TokenType::SLASH);
      std::cout << "SLASH";
      break;
    case '\n':
      token = Token(std::string(1, curChar), TokenType::NEWLINE);
      std::cout << "NEWLINE";
      break;
    case '\0':
      token = Token(" ", TokenType::EOFT);
      std::cout << "EOFT";
      break;
    case '=':
      if (peek() == '='){
        char lastChar = curChar;
        nextChar();
        token = Token(std::string(1, lastChar + curChar), TokenType::EQEQ);
        std::cout << "EQEQ";
      } else {
        token = Token(std::string(1, curChar), TokenType::EQ);
        std::cout << "EQ";
      }
      break;
    case '>':
      if (peek() == '=') {
        char lastChar = curChar;
        nextChar();
        token = Token(std::string(1, lastChar + curChar), TokenType::GTEQ);
        std::cout << "GTEQ";
      } else {
        token = Token(std::string(1, curChar), TokenType::GT);
        std::cout << "GT";
      }
      break;
    case '<':
      if (peek() == '=') {
        char lastChar = curChar;
        nextChar();
        token = Token(std::string(1, lastChar + curChar), TokenType::LTEQ);
        std::cout << "LTEQ";
      } else {
        token = Token(std::string(1, curChar), TokenType::LT);
        std::cout << "LT";
      }
      break;
    case '!':
      if (peek() == '=') {
        char lastChar = curChar;
        nextChar();
        token = Token(std::string(1, lastChar + curChar), TokenType::NOTEQ);
        std::cout << "NOTEQ";
      } else {
        std::cout << "Expected !=, got !";
      }
      break;
    case '\"': {
      nextChar();
      int startPos = curPos;
      
      while(curChar != '\"') {
        if(curChar == '\r' || curChar == '\n' || curChar == '\t' || curChar == '\\' || curChar == '&') {
          std::cout << "You're cooked, illegal string"; 
        }
        nextChar();
      }
      std::string tokenText = source.substr(startPos, curPos - startPos);
      token = Token(tokenText, TokenType::STRING);
      std::cout << "STRING";
      break;

    }
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





