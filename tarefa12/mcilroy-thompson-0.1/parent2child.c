#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
  int pfd[2]; int r; //file descriptor
  // declarando e definindo inteiros; chamando pipe, fork e configurando erros
  r = pipe(pfd); if (r < 0) { perror("pipe"); exit(1); } 
  r = fork(); if (r < 0) { perror("fork"); exit(2); }

  if (r == 0) {
    close(pfd[1]); // sessão filho fechando a escrita
    r = dup2(pfd[0], STDIN_FILENO); if (r < 0) { perror("filho dup2"); exit(3); } //recebendo a leitura e configurando erro
    close(pfd[0]); //fechando o canal, n lerá mais nada vindo do pipe
    execl("/usr/bin/less","less",NULL); // filtrando a saida recebida com less
    fprintf(stderr,"%s: execl() failed - %s\n",argv[0],strerror(errno)); //configurando erro
  }
  close(pfd[0]); // sessão pai fechando a leitura de informações vindas do pipe para apenas escrever
  r = dup2(pfd[1], STDOUT_FILENO); if (r < 0) { perror("pai dup2"); exit(4); } // escrevendo e configurando erro
  close(pfd[1]); //fechando a conexão de escrita com o pipe
  // se deletarmos n conseguimos fechar o less no terminal, já que continuará aberto para enviar mais informações pro less, q ficará esperando
  for (int c = 0; c < 100; ++c) // apenas um loop para escrever linhas
    printf("Eis a linha %d\n",c);
  //qnd terminar de escrever, fechar a saida padrão -  para n ter mais ngm escrevendo pro pipe
  fclose(stdout); // se tirar esse: o less vai ficar aguardando este fechar, e este aguardará o fim do less, portanto ficará com a tela vazia. Ou seja, o less nem chega a imprimir nada n tela.
  wait(NULL); // wait para fazer a sessão pai esperar a sessão filho, ou seja, não fazê-los trabalhar paralelamente
  //se n tiver esse wait aq o less perderia acesso ao terminal por n ter um pai esperando por ele. se o pai morre o filho fica em segundo plano e perde acesso ao terminal
  exit(0); //finalização do programa
}
