#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <math.h>
#include <time.h>

int main(int argc, char *argv[]) {
  int status = 0;
  unsigned long N = 1763; /* o composto que queremos fatorar*/
 
  pid_t r = fork();
  if (r < 0) { perror("fork"); exit(1); }

  if (r == 0) {
    printf("processo-filho: rodando...\n");
    time_t t = time(NULL);
    if (0 == t % 2) {
      for (int i = 2; i < sqrt(N); ++i) {
        if (0 == N % i) {
          printf("processo-filho: fator encontrado\n");
          exit(i);
        }
      }
    }
    else {
      for (int i = N - 1; i >= 2; --i) {
        if (0 == N % i) {
          printf("processo-filho: fator encontrado\n");
          exit(i);
        }
      }
    }
    printf("processo-filho: fator não encontrado\n");
    exit(1);
/*first test - n consigo testar por problemas no compilador, ent nem sei se isso aqui faz sentido kkkk*/
    if (waitpid(r, &status, WUNTRACED | WCONTINUED) == -1) {
      perror("wpid");
      exit(EXIT_FAILURE);
    }
    if (WIFEXITED(status)) {
      printf("exit status; %d\n", WEXITSTATUS(status));
    } 

    printf("processo-pai: fim\n");
  return 0;
  }
/*}*/
