//Design an algorithm and write code to remove the duplicate 
//characters in a string without using any additional buffer.
//NOTE: One or two additional variables are fine. An extra 
//copy of the array is not.

#include <iostream>
#include <string>

char *removeDups(char *str);

int main(int argc, char *argv[]) {

  std::string str = argv[1];
  std::string noDups = removeDups(str);
  std::cout << noDups << '\n';
  return 0;
}

std::string removeDups(std::string str) {
  for(int i = 0; i < str.length(); i++) {
    if(str[i]) {
      for(int j = i + 1; j < str.length(); j++) {
        if(str[j]) {
          if(str[i] == str[j]) {
            str[j] = NULL;
          }
        }
      }
    }
  }
  for(int i = 0; i < str.length(); i++) {
    
  }
}