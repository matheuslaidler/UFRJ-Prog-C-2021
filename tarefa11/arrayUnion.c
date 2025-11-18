#include <stdio.h>
#include <string.h>

union value {
    int credito;
    char lista[5];
  } u;

void main () {
  u.credito = 5; // inicializando credito
  printf ("O valor de credito é: %d\n", u.credito);
  strcpy (u.lista, "abelha");
  printf ("O valor do elemento 0 da lista é: '%c' -> %d\n", u.lista[0],u.lista[0]);
  printf("\t Elementos da lista:  [%c,%c,%c,%c,%c,%c]\n",u.lista[0],u.lista[1],u.lista[2],u.lista[3],u.lista[4],u.lista[5]);
  printf("\ncomo ta o credito agr?  %c | %d\n",u.credito,u.credito);
}