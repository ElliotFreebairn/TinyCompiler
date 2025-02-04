#includes <iostream>


class lexer {
public:
  lexer(std::string& source) {
    this.source = source + '\n';
    this.curChar = '';
    this.curPos = -1';
    this.nextChar();
  }

  void nextChar() {
    this.curPos += 1;
    if (this.curPos >= this.source.length()) {
      this.curChar = '\0';
    } else {
      this.curChar = this.source[this.curPos];
    }
  }

  char peek() {
    if (this.curPOs + 1 >= this.source.length()) {
      return '\0';
    }
    return this.source[this.curPos + 1];
  }
}
