#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main() {
  char str[] = "1111\n2222\n3333\n4444";
  char str2[] = "5555\n6666\n7777\n";
  printf("\033[2J");
  printf("\033[%d;%dH", 0, 0);
  
  printf("%s", str);
  sleep(1);
  printf("\033[2J");
  printf("\033[%d;%dH", 0, 0);

  printf("%s", str2);
  sleep(1);
  printf("\033[2J");
  printf("\033[%d;%dH", 0, 0);
  printf("%s", str);

  printf("\033[2J");
  printf("\033[%d;%dH", 0, 0);
  
  return 0;
}