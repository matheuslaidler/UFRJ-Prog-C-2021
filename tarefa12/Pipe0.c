#include <unistd.h> 
#include <stdlib.h> 
#include <stdio.h>
#include <sys/types.h> 

#define MAX 1000

int main(void) 
{ 
      int n, fd[2];      
      pid_t pid;      
      char listabraba[MAX];      
      if (pipe(fd) < 0) { 
            fprintf(stderr, "pipe deu merda\n");      
            exit(1);      
      }      
      if ( (pid = fork()) < 0) { 
            fprintf(stderr, "fork deu merda\n");      
            exit(2);      
      }      
      else if (pid > 0) { /* pai */ 
            close(fd[0]); /* fecha lado receptor do pipe */ 
            printf("\t*Sessão Pai*\t");
            write(fd[1], "TOMA ESSA STRING", 16); 
      }     else { /* filho */      
            close(fd[1]); /* fecha lado emissor do pipe */ 
            printf("\t*Sessão Filho*\t");
            n = read(fd[0], listabraba, MAX); 
            write(STDOUT_FILENO, listabraba, n);
            printf("\t String Recebida\n");     
      }      
      exit(0);      
} 
