#include <stdio.h>
#include <string.h>
#include "getline.h"

#define MAXLINE 1000

char *month(int m) {
  char *names[] = {
    "janeiro", "fevereiro", "março", "abril",
    "maio", "junho", "julho", "agosto",
    "setembro", "outubro", "novembro", "dezembro"
  };
  return names[m - 1];
}

int main() {
  int d, m, y; int r;
  char ln[MAXLINE];

  for (;;) {
    r = my_getline(NULL, ln, sizeof ln);
    if (r == TOO_LONG) {
      printf("too long: [%s]\n", ln);
      continue;
    }
    if (r == NO_INPUT) { /* we reached the end of the file */
      break;
    }
    
    char event[MAXLINE]; memset(event, '\0', sizeof event);
    r = sscanf(ln, "%d/%d/%d %[^\n]", &d, &m, &y, event);
    if (r < 3) { /* Invalid line for some reason. */
      continue;
    }

    char date[MAXLINE]; memset(date, '\0', sizeof date);
    snprintf(date, sizeof date, "Dia %d de %s de %d", d, month(m), y);
    printf("%-30s --> %-.30s%s\n", date, event, 
           strlen(event) > 30 ? "..." : "");
  }
}
