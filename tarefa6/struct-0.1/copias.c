#include <stdio.h>

struct point {
  int x;
  int y;
};

struct point add1(struct point p) {
  struct point ret;
  ret.x = p.x + 1;
  ret.y = p.y + 2;
  return ret;
}

int main(void) {
  
  struct point p;
  struct point q;

  p.x = 0; p.y = 0;
  q = add1(p); /* a copy of p is passed to add1() */
  /* q is totally different from p */

  printf("p = (%d, %d)\n", p.x, p.y);
  printf("q = (%d, %d)\n", q.x, q.y);

  /*
    You can see p was not changed by the procedure add1().
  */

  return 0;
}
