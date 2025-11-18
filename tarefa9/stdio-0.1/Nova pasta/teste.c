#include<stdio.h>
#include <stdlib.h>


#include <locale.h>
#include <stdlib.h>

#include <stdio.h>
#include <string.h>
#include "getline.h"

#define MAXLINE 1000


/*gcc teste.c -o teste*/

char *month(int m) {
  char *names[] = {
    "janeiro", "fevereiro", "março", "abril",
    "maio", "junho", "julho", "agosto",
    "setembro", "outubro", "novembro", "dezembro"
  };
  return names[m - 1];
}

void readEvents()
{
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


void archive()
{
    printf("\nSelecione seu arquivo\n");
    printf("\n  Favor, escreva o nome do arquivo abaixo.\n");
    printf("Certifique-se de ter o mesmo dentro do diretório deste programa."); /*quem sabe façamos a opção de indicar o diretório qnd tiver mais tempo*/
    printf("\n\n\n");
    
}

void database()
{
    printf("\nLendo evento da database padrão\n");
    printf("\n\n\n");
}

void help()
{
 printf("    Selecione a função adequada para sua necessidade.\n");
 printf("Este programa apenas organiza um exato tipo de arquivo como\n");
 printf("o database.txt que se encontra em seu diretório raiz.\n");
 printf("Ele coloca as datas em ordem e por extenso, além de organizar\n");
 printf("o evento pela data e colocando um limite de caracter para não\n");
 printf("passar de uma linha e ficar cada evento em cada linha.\n"); 

 printf("Caso queira selecionar seu próprio arquivo, selecione a opção\n");
 printf("número 1 do menu. Se quiser ver como fica com o do arquivo\n");
 printf("padrão selecione a função 2, e caso queira sair do programa,\n");
 printf("utilize a terceira opção ou mate-o com ctrl-c.\n");   
 printf("\n\n\n");
 
}

void leave()
{
    printf("\nObrigado pela preferência!\n");
}


int main()
{
    int continuar=1;

    do
    {
        printf("\n\tScript de leitura - Tarefa 9\n\n");
        printf("\t1. Indique o NOME do ARQUIVO.\n");
        printf("\t2. Usar 'database.txt' na raiz.\n");
        printf("\t2. Ajuda! Saiba como usar.\n");
        printf("\t0. Encerrar o programa.\n");

        scanf("%d", &continuar);
        system("cls || clear");

        switch(continuar)
        {
            case 1:
                archive();
                break;

            case 2:
                database();
                break;

            case 3:
                help();
                break;

            case 0:
                leave();
                break;

            default:
                printf("Digite uma opcao valida\n");
        }
    } while(continuar);
}

int my_getline(char *prmpt, char *buff, size_t sz) { /*vai ler a linha da entrada padrão e escrever em um buffer até num tamanho mázimo sz; prompt vamos usar mais como NULL, ent...*/
    int ch, extra; FILE *arq;
    setlocale(LC_ALL, "Portuguese");
    arq = fopen("database.txt","r+");
    if (prmpt != NULL) { 
    /*se vc n passar um NULL no primeiro argumento, vc pode colcoar um prompt lá... é util qnd se l~e direto do teclado, mas veremos de um arquivo)*/
        return 0;
    }
        // Get line with buffer overrun protection.
    if (fgets (buff, sz, arq) == NULL) /*fgets OBTÉM UMA STRING DO ARQUIVO*/ /*sz é MAXLINE do readevents ( o scanf n verifica pelo tamanho do buffer, gets foi uma forma cuidadosa )*/
        return NO_INPUT; /*lendo a linha até o limite ou até uma quebra de linha, se retornar nulo é pq n leu nada e assunto encerrado.
        -> explicação; o fgets lê bytes de um stream (como stdin) num array 's' não mais do que n-1 bytes ou até q uma nova linha seja lida.
                        Ou seja, ela lê a linha até o limite ou até encontrar uma quebra de linha**/

    if (arq == NULL) {
        printf("\nOcorreu um erro... O arquivo não pode ser aberto.\n");
        return NO_INPUT;
    } else {
        printf("\nSucesso na abertura!\n");
    }

    // If it was too long, there'll be no newline. In that case, we flush to end of line so that excess doesn't affect the next call.
    /*
    Quando a linha é muito grande,isto é, maior que o limite do buffer, a leitura da mesma é terminada no limite. 
    Após voltar a leitura, começará de onde parou e essa linha (continuação da anterior) será desconsiderada.
    O codigo abaixo é basicamente para fazer essa funcionalidade.
    */
    if (buff[strlen(buff)-1] != '\n') {
        extra = 0;
        while (((ch = getchar()) != '\n') && (ch != EOF))
            extra = 1;
        return (extra == 1) ? TOO_LONG : OK;    
    }

    // Otherwise remove newline and give string back to caller.
    /*pra finalizar fecha com o nulo \0 e retorna um OK.*/
    buff[strlen(buff)-1] = '\0';
    return OK;
}