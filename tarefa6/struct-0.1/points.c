#include <stdio.h>

int main(void) {

  struct point {
    short int x;
    short int y;
  };

  struct point p1; p1.x = 0; p1.y = 0;
  struct point p2; p2.x = 1; p2.y = 1;
  printf("A origem do plano: (%d, %d).\n", p1.x, p1.y);
  printf("Um ponto no plano: (%d, %d).\n", p2.x, p2.y);

  printf("O tamanho de /struct point/: %ld.\n", sizeof p1);
  printf("O tamanho de /struct point/: %ld.\n", sizeof p2);
  printf("O tamanho de /struct point/: %ld.\n", sizeof (struct point));
  printf("O tamanho de /struct point */: %ld.\n", sizeof (struct point *));
  
  return 0;
}
