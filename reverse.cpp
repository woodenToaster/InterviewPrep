//Write code to reverse a C-Style String. 

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

char* reverse(char *str);

int main(int argc, char* argv[]) {
  char *str = argv[1];
  char *rStr = reverse(str);
  printf("%s\n", rStr);
  return 0;
}

char* reverse(char *str) {
  if(str == NULL) {
    printf("Error\n");
    exit(-1);
  }
  char *rStr;
  int end = strlen(str) - 1;
  char *begin = str;

  rStr = &str[end];

  while(str != rStr && str < rStr) {
    char tmp = *str;
    *str = *rStr;
    *rStr = tmp;
    str++;
    rStr--;
  }
  return begin;
}