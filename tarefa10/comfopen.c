/*++++Biblioteca++++*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
/*++++++++++++++++++*/
/*MatheusLaidlerUFRJ*/
/*++++FOPEN-Code++++*/

const char *str = "A melhor introdução à programação C/C + + por Daniel Bastos! - (UFRJ)\n";
int main(void) {
    const char* arquivo = "database.txt"; FILE* cta;
    cta = fopen(arquivo, "a+"); /*fopen(arquivo, "w+");*/
    if (!cta) {
        perror("fopen");
        exit(EXIT_FAILURE);/*return 1;*/
    }
    fprintf(cta, "%s", str);/*fwrite(str, 1, strlen(str), cta);*/
    printf("Escrita feita com sucesso!\n");
    /*fclose(cta);*/
    sleep(10);
    fclose(cta);
    return 0;
}

/*++++++++++++++++++*/

/*Comentários*/

/*
Comentando sobre o funcionamento do programa com sleep.
Análise - Tarefa;
Enquanto o programa está no SLEEP, nada ainda foi escrito realmente, apenas após a finalização.
É interessante comentar tbm que da forma que fizemos inicialmente (w+), ele apaga tudo q estava no arquivo antes e escreve o que pedimos, isso porque utilizamos o w+.
Então, durante a execução do sleep, o "database" da aula passada estava vazio e após o término do programa, ficou apenas a string que indicamos.
Se terminarmos o programa com ctrl-c a escrita não é finalizada, até porque ele só fecha o arquivo e conclui a ação após os 60 segundos.
Se colocarmos o fclose antes do sleep, o resultado muda e a escrita ocorre de 'imediato'.
(Claro, da para fazermos add o texto no final ou no início sem sobrescrever o arquivo, como colocando no final do arquivo com o a+ (ficando como com o open))
-Isso tudo foi testando com o fwrite. 
Agora, com o fprintf: Não teve nenhuma mudança, obviamente. O resultado seguiu sendo o mesmo.
Colocando 'a+'' no fopen ficamos com o arquivo intácto, porém com a adição da string ao final.
w+ -> abre o arq p leitura + escrita (se não existe: o arq é criado ; se não existe: é aberto p adição de caracteres no INICIO, sobrescrevendo o arq INTEIRO)
*/