#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <math.h>
#include <time.h>

int main(int argc, char *argv[]) {

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
    	exit(1); /* processo-filho morre aqui de qualquer forma */
  	}
  	
  	if (r > 0) {
  		printf("processo-pai\n");
  	}
  /* 
     Adicione uma chamada a wait() de forma que o processo-pai consiga
     esperar pelo filho terminar antes do processo-pai morrer.  Use a
     macro WEXITSTATUS() --- veja documentação de wait() --- pra obter
     o fator encontrado pelo processo-filho, entregue a wait() por via
     de exit().  Quem faz essa comunicação entre processos é o
     sistema; por isso esses procedimentos são /system calls/.
  */

  	printf("processo-pai: fim\n");
  	return 0;
}