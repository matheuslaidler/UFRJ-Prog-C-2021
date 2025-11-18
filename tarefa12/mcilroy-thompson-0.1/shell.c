#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
  int p[2];
  pid_t c1 = -1, c2 = -1;

  pipe(p);

  switch (c1 = fork()) {
  case -1:
    perror("fork"); exit(1);
    break;
  case 0:
    close(p[0]);
    dup2(p[1], STDOUT_FILENO);
    close(p[1]);
    execl("/bin/cat", "cat", "shell.c", NULL);
    perror("execl"); 
    exit(1);
    break;
  default:
    ;
  }

  switch (c2 = fork()) {
  case -1:
    perror("fork"); exit(1);
    break;
  case 0:
    close(p[1]);
    dup2(p[0], STDIN_FILENO);
    close(p[0]);
    execl("/usr/bin/less", "less", NULL);
    perror("execl"); exit(1);
  default:
    ;
  }

  close(p[0]); close(p[1]);
  wait(NULL); // primeiro filho a morrer
  wait(NULL); // segundo filho a morrer
}
