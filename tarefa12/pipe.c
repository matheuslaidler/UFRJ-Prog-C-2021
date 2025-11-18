#include <stdio.h>
#include <unistd.h> 
#include <sys/wait.h>

#define MAXLINE 1000

int main(){
	int n, fd[2];  	// fd[0] - leitura X fd[1] - escrita    
	if (pipe(fd) == -1){ // chamando pipe e configurando erro
		fprintf(stderr, "ERRO com PIPE\n"); // se não der para usar pipe parar o programa
		return 1;
	}
	printf("\n\t*Sessão do Game*\t"); // parte visual do codigo
	printf("\n - Adivinhe qual o número da sorte do pai - \n\n");
	int id = fork(); // fznd o fork
	//se os prints de cima tivesse abaixo do fork eles seriam duplicados, um de cada sessão
	if (id == -1){ //configurando erro 
		fprintf(stderr, "ERRO com FORK\n"); // se o fork não for feito parar o programa
		return 4;
	}
	if (id == 0){ // configurando sessão do filho
		close(fd[0]); // fechando a porta de leitura que não será utilizada
		int x; // declarando e definindo um inteiro X que será usado para armazenar a resposta
		printf("\n\t*Sessão do Filho*\t");
		printf("\n:- Pai, acho que seu número da sorte é ");
		scanf("%d",&x); // resposta armazenada
		if (write(fd[1],&x,sizeof(int)) == -1) { // escrevendo o que queremos passar pro pai via pipe em x
			fprintf(stderr, "ERRO com a ESCRITA\n"); // se não der para fzr isso parar o programa - configurando erro
			return 2;
		}
		close(fd[1]); // fechando conexão de escrita
	} else {
		close(fd[1]); // fechando conexão de escrita inutilizada
		int y; // declarando inteiro para armazenar o recebimento
		printf("\n\t*Sessão do Pai*\t");
		n = read(fd[0],&y,sizeof(int)); // leitura do recebimento
		close(fd[0]); // fechando porta de recebimento
		if (n == -1) { // aqui fiz separado com a var 'n', mas poderia ser junto como no 'if'
			fprintf(stderr, "ERRO com a LEITURA\n"); // se não der para ler o que foi passado parar o programa
			return 3;
		}
		if (y == 2){ // fizemos uma condição dps dos primeiros testes para ter o certo e errado.
		printf("\n:- Acertou, filho! O número da sorte é %d\n\n", y); // A informação que será printada aq é a recebida pelo pai via pipe
		} else{
			printf("\n:- Errou, filho. O meu número da sorte não é %d\n\n", y); // Aqui é só um print com a cola pra testar se funfa o pipe e fork
		}
		wait(NULL); /* Ainda é ideal usar para q eles n fiquem funcionando paralelamente.
		Geralmente é importante para não deixar o pai morrer antes do filho, 
		porém nesse caso nao muda muito pois usamos o filho para passar a informação, 
		logo o pai morre dps pois ele que receberá a informação. */
	}
	return 0;
}