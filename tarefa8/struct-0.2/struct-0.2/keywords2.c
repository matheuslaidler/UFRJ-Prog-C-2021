#include <ctype.h>
#include <string.h>
#include <stdio.h>

#define NKEYS ((sizeof table) / (sizeof table[0]))
#define MAXWORD 100

int getword(char *, int);
struct kw * lookup(char *, struct kw *, int n);

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
  int n; char word[MAXWORD]; struct kw * p;

  while (getword(word, MAXWORD) != EOF)
    if (isalpha(word[0]))
      if ((p = lookup(word, table, NKEYS)) != NULL)
        p->count++;

  for (p = table; p < table + NKEYS; p++)
    if (table[n].count > 0)
      printf("%4d %s\n", p->count, p->word);

  return 0;
}

struct kw * lookup(char *word, struct kw * table, int n) {
  struct kw *p;
  for (p = table; p < table + n; p++) {
    if (strcmp(word, p->word) == 0)
      return p;
  }

  return NULL; /* not found */
}

int getword(char *word, int lim) {
  int getch(void);
  void ungetch(int);

  int c; char *w;
  
  w = word;

  while (isspace(c = getch()))
    ;

  if (c != EOF)
    *w++ = c;

  if (!isalpha(c)) {
    *w = '\0';
    return c;
  }

  for ( ; --lim > 0; w++)
    if (!isalnum(*w = getch())) {
      ungetch(*w);
      break;
    }

  *w = '\0';
  return word[0];
}
