#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include "getline.h"

int my_getline(char *prmpt, char *buff, size_t sz) {/*vai ler a linha da entrada padrão e escrever em um buffer até num tamanho mázimo sz; prompt vamos usar mais como NULL, ent...*/
    int ch, extra; 
    if (prmpt != NULL) { 
    /*se vc n passar um NULL no primeiro argumento, vc pode colcoar um prompt lá... é util qnd se l~e direto do teclado, mas veremos de um arquivo)*/
        printf ("%s", prmpt);
        fflush (stdout); /*fflush DESCARREGA O BUFFER*/
    }
        // Get line with buffer overrun protection.
    if (fgets (buff, sz, stdin) == NULL) /*fgets OBTÉM UMA STRING DO ARQUIVO*/ /*sz é MAXLINE do readevents ( o scanf n verifica pelo tamanho do buffer, gets foi uma forma cuidadosa )*/
        return NO_INPUT; /*lendo a linha até o limite ou até uma quebra de linha, se retornar nulo é pq n leu nada e assunto encerrado.
        -> explicação; o fgets lê bytes de um stream (como stdin) num array 's' não mais do que n-1 bytes ou até q uma nova linha seja lida.
                        Ou seja, ela lê a linha até o limite ou até encontrar uma quebra de linha**/

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


/*Coisas como o 'TOO_LONG'e'NO_INPUT' podem ser verificada em getline.h*/