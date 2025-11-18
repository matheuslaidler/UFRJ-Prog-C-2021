#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void){
	pid_t pid;

	pid = fork();

	if (pid == -1){
		printf("Essa não! Um erro foi encontrado!\n\n");
		printf("O programa está sendo encerrando...\n");
		sleep(10);
		printf("Tente novamente.\n");
		return 1;
	}

	if (pid > 0) {
		printf("\tP0 - ID do Processo: %d\n",getpid());
		while(1);
	} else {
		printf("\tP1 - ID do Processo: %d\n",getpid());
		while(1);
	}
	
	return 0;
}