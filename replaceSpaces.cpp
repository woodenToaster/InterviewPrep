#include <string>
#include <iostream>

void replaceSpaces(std::string& str);

int main(int argc, char *argv[]) {
  std::string str = " a string with spaces  ";

  replaceSpaces(str);

  std::cout << str << '\n';

  return 0;
}

void replaceSpaces(std::string& str) {
  std::string insert = "%%20";

  for(int i = 0; i < str.length(); i++) {
    if(str[i] == ' ') {
      str.insert(i, insert);
    }
  }
}
