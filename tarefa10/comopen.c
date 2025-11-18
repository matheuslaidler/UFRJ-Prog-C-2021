/*++++Biblioteca++++*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
/*++++++++++++++++++*/
/*MatheusLaidlerUFRJ*/
/*+++++OPEN-Code++++*/

const char *str = "A melhor introdução à programação C/C + + por Daniel Bastos! - (UFRJ)\n";

int main(void) {
    const char* arquivo = "database.txt"; int cta;
    cta = open(arquivo, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU); 
    if (cta == -1) {
        perror("open");
        return 1;/*exit(EXIT_FAILURE);*/ 
    }
    write(cta, str, strlen(str));
    printf("Escrita feita com sucesso!\n");
    sleep(10);
    close(cta);
    return 0;/*exit(EXIT_SUCCESS);*/
}

/*++++++++++++++++++*/
/*comentários:*/
/*testar dps: open(arquivo, O_RDWR | O_CREAT)*/
/*cta = open(arquivo, O_RDWR | O_CREAT); */
/*cta = call to action*/
/*Análise: Tarefa 1*/
/*
Podemos visualizar que enquanto o programa está em ação, isto é, ainda no timming do sleep(60), a ação de escrever a string já foi feita com sucesso.
Foi feita, inclusive, sem sobrescrever o arquivo todo. Ela foi apenas adicionada ao final do arquivo em uma nova linha.
(Isso usando o write para escrever)

*/