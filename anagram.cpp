#include <iostream>
#include <cctype>
#include <cstring>

bool anagram(char *s1, char *s2);

int main(int argc, char *argv[]) {
  char *s1 = argv[1];
  char *s2 = argv[2];

  bool result = anagram(s1, s2);
  std::cout << result << '\n';

  return 0;
}

bool anagram(char *s1, char *s2) {
  int arr[26] = {0};

  if(strlen(s1) != strlen(s2)) {
    return false;
  }

  char c;
  int index;

  for(int i = 0; i; i++) {
    c = tolower(s1[i]);
    index = c - 97;
    arr[index]++;
    c = tolower(s2[i]);
    index = c - 97;
    arr[index]--;
  }

  for(int i = 0; i < 26; i++) {
    if(arr[i] != 0) {
      return false;
    }
    return true;
  }
}

