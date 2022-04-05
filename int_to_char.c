#include <stdio.h>

int to_int(char x) {
  return (int) x - '0';
}
char to_char(int x) {
  return (char) x + '0';
}
int main(void) {
  char c = to_char(1);
  int d = to_int('1');
  printf("Char : %c, dan Int : %d\n", c, d);
  return 0;
}
