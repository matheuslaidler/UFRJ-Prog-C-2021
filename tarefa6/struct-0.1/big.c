#include <stdio.h>

struct big {
  char bs1[1000];
  char bs2[1000];
  char bs3[1000];
  char c;
};

int main(void) {
  struct big b; /* Dear compiler, please allocate me some space. */
  printf("How big is /b/? It's %ld bytes big.\n", sizeof b);
}
