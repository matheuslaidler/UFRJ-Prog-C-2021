#include <ctype.h>
#include <string.h>
#include <stdio.h>

#define NKEYS ((sizeof table) / (sizeof table[0]))
#define MAXWORD 100

struct kw {
  char *word; 
  int count;
};

struct kw table[] = {
  {"break", 0},
  {"case", 0},
  {"char", 0},
  {"const", 0},
  {"int", 0},
  {"continue", 0},
  {"default", 0},
  {"unsigned", 0},
  {"void", 0},
  {"volatile", 0},
  {"while", 0}
};

int main() {
  printf("sizeof table[0] = %ld\n", sizeof table[0]);
  printf("sizeof (struct kw) = %ld\n", sizeof (struct kw));
  return 0;
}
