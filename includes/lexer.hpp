#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <iostream>
#include <cctype>


class lexer {

  public:
    lexer(std::string& source);

    void nextChar()

    char peek() const;

    void abort(const std::string& message) const;

    void skipWhitespace();

    void skipComment();

    std::string getToken();

  private:
    std::string sourceCode;
    char curChar;
    size_t curPos;
};

#endif
