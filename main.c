#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stack.h"

int main(int argc, char **argv){
  
  int i, N, j;
  int x,y;
  Stack s;
  s.top = NULL;
  s.size = 0;

  for (i = 1; i < argc; i++)
  {
    N = 0; 
    x = 0;
    y= 0;

    for (j = 0; j < strlen(argv[i]); j++) {
      switch (argv[i][j]) {
      case '{': push(&s, argv[i][j]); x++;
                break;
      case '[': push(&s, argv[i][j]); x++;
                break;
      case '}': y++; if (pop(&s) != '{') N = 1;
                break;
      case ']': y++; if (pop(&s) != '[') N = 1;
                break;
      }
    }
    if (s.size > 0) {
      N = 1;
    }
    if (N == 0)
      printf("argv %d : correct\n", i);
    else if (x>y)
      printf("argv %d : incorrect: too many open parenthesis\n", i);
    else if (y>x)
      printf("argv %d : incorrect: too many closed parenthesis\n", i);
    else if (y==x&&N==1)
      printf("argv %d : incorrect: mismatch\n", i);
    pop_all(&s);

  }

  return 0;
}
