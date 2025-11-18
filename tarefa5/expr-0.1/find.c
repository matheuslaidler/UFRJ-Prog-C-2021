#include <stdio.h>
#include <string.h>

#define MAXLINE 1000
int getln(char *line, int max);

int main(int argc, char *argv[]) {
  char line[MAXLINE];
  int found = 0;
  if (argc != 2)
    printf("Usage: find pattern\n");
  else
    while (getln(line, MAXLINE) > 0)
      if (strstr(line, argv[1]) != NULL) {
        /*  How to use strstr?  Say ``man 3p strstr'' to your
            shell. */
        printf("%s", line);
        found++;
      }
  return found;
}
