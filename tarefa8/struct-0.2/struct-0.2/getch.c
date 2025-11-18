#include <stdio.h>
#define BUFSIZE 100

char buf[BUFSIZE]; /* a buffer for ungetch() */
int p = 0; /* the next free position in buf */

int getch(void) { /* get a (possibly pushed-back) character */
  if (p > 0) 
    return buf[--p];
  else 
    return getchar();
}

void ungetch(int c) {
  if (p >= BUFSIZE)
    printf("ungetch: too many characters; buffer full\n");
  else
    buf[p++] = c;
}

#ifdef TEST
int main(void) {
  int c;
  ungetch('a'); ungetch('b'); ungetch('c');
  c = getch(); printf("c = %c, p = %d\n", c, p);
  c = getch(); printf("c = %c, p = %d\n", c, p);
  c = getch(); printf("c = %c, p = %d\n", c, p);
  return 0;
}
#endif
