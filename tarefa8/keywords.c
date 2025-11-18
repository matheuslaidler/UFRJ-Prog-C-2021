#include <ctype.h>
#include <string.h>
#include <stdio.h>



struct key {
  char *word; 
  int count;
};

struct key table[] = {
  {"break", 0},
  {"case", 0},
  {"char", 0},
  {"for", 0},
  {"const", 0},
  {"int", 0},
  {"continue", 0},
  {"default", 0},
  {"unsigned", 0},
  {"void", 0},
  {"volatile", 0},
  {"while", 0}
};



#define NKEYS ((sizeof table) / (sizeof table[0]) )

int getword(char *, int);
int lookup(char *, struct key *);


#define MAXWORD 100

int main(int argc, char *argv[]) {
  int n; char word[MAXWORD];

  while (getword(word, MAXWORD) != EOF)
    if (isalpha(word[0]))
      if ((n = lookup(word, table)) >= 0)
        table[n].count++;
  
  
  for (n = 0; n < NKEYS; n++) 
    if (argc == 1)
      printf("%4d %s\n",table[n].count, table[n].word);
    if (argc == 2)
      if ((n = lookup(argv[1], table)) != 0)
        printf("%4d %s\n",table[n].count, argv[1]);

  

  return 0;
}


int lookup(char *word, struct key tab[]) {
  for (int i = 0; i < NKEYS; ++i)  {
    if (!strcmp(word, table[i].word))
      return i;
  }
  return -1; 
}



int getword(char *word, int lim) {
  int getch(void);
  void ungetch(int);

  int c; 
  char *w = word;

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
