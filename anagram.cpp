#include <cctype>
#include <cstring>
#include <stdexcept>

bool anagram(char *s1, char *s2) {
  if(!s1 || !s2) {
    throw std::invalid_argument("Anagram() requires 2 arguments.\n");
  }

  int arr[26] = {0};

  if(strlen(s1) != strlen(s2)) {
    return false;
  }

  char c;
  int index;

  for(int i = 0; s1[i] && s2[i]; i++) {
    c = tolower(s1[i]);
    index = c - 97;
    arr[index]++;
    c = tolower(s2[i]);
    index = c - 97;
    arr[index]--;
  }

  for(auto i : arr) {
    if(arr[i] != 0) {
      return false;
    }
  }
  return true;
}

