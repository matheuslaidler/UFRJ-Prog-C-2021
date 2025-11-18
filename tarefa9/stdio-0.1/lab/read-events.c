/*
Trabalho: 
Fazer read-events funcionar sem usar stdin (entrada padrão), com fopen, fclose e fgets, gerando, assim, modificação do getline no processo. 


**Sua tarefa é re-escrever o read-events.c - que usa a stdio para ler a base de dados - sem usar os serviços de 
redirecionamento de arquivo do shell, ou seja, você vai usar fopen(), fclose() e fgets().  
Você vai ter que ajustar o procedimento my_getline() em getline.c.  

OU SEJA: Sua tarefa é fazer a mesma coisa que read-events.c sem usar a stdin. 

[Elegante será se você permitir ao usuário a especificar o arquivo 
da base de dados pela linha de comando, ou seja, usando 
/main(int argc, char *argv[])/, permitindo seu usuário a
trabalhar com várias bases de dados de conteúdo diferentes]

Responda as seguintes perguntas a si mesmo.  O que acontece se
removermos as chamadas a memset() em read-events.c?  Por que não
usamos scanf() sem fgets() se scanf() é capaz de ler diretamente da
entrada padrão ou de algum arquivo aberto por fopen()?  Em outras
palavras, por que estamos delegando o trabalho pra fgets() primeiro?
A resposta mais importante é o fato de que fgets() consome um
argumento chamado /n/ fazendo com que ela leia não mais que n - 1
bytes.  Por que isso é importante pra gente?  (Você não tem que
entregar suas respostas.  Use essas perguntas como guia para seu
entendimento, se você se importar com o assunto.)

Quando terminar a tarefa com sucesso, pergunte-se o que você prefere
--- escrever seu programa usando as facilidades do shell ou ignorando
as facilidades do shell e usando fopen(), fclose() et cetera. 
 -> para tempo e teste de compatibilidade de partes do código, prefiro shell, 
mas para finalizar um programa para ser portátil entre sistemas e mais sólido
ou seguro, melhor usar o que o C tem a nos oferecer que faça a função do shell.


*/
#include <locale.h>
#include <stdlib.h>

#include <stdio.h>
#include <string.h>
#include "getline.h"

#define MAXLINE 1000



/*nossa lista dos meses para a formatação*/
char *month(int m) {
  char *names[] = {
    "janeiro", "fevereiro", "março", "abril",
    "maio", "junho", "julho", "agosto",
    "setembro", "outubro", "novembro", "dezembro"
  };
  return names[m - 1]; 
}

int main(int argc, char *argv[]) {
  int d, m, y; int r; char ln[MAXLINE]; /*buffer do getline - maxline: 1k*/
  /*
  FILE *arq;
  setlocale(LC_ALL, "Portuguese");
  if (argc < 1) {
    printf("Use o programa com argumentos");
    return 0;
  }*/

  for (;;) {
    r = my_getline(NULL, ln, sizeof ln); /*leio a linha nesse array*/
    if (r == TOO_LONG) { /*se for muito longo*/
      printf("too long: [%s]\n", ln); /*digo ser longo, repitdo a iteração e passo pra próxima linha (como se terminasse de ler a linha mas sem considerar ela por ter passado do limite)*/
      continue;
    }
    if (r == NO_INPUT) { /* we reached the end of the file */ /*se get line chegar a NO_INPUT significa q chegamos em EOF*/
      break;                        /*portanto enterrompo o loop aq - terminando o programa */ /*podia ser return ou exit*/
    }
    
    char event[MAXLINE]; memset(event, '\0', sizeof event); /*declaro um array EVENTO do msm tamanho, a ideia é colocar a descrição do evento nela; memset zerando o array por completo, para bastar apenas escrever os bytes nele, sem zerar mais - ou seja, apenas sobrescreverei os zeros com os próximos conteúdos que pegaremos no loop. Em outras palavras, a lista fica toda preenchida de zero para serem substituidas pelo conteúdo, para n ter q ficar criando zero a cada vez. Por aq tbm fechamos a string com \0*/
    r = sscanf(ln, "%d/%d/%d %[^\n]", &d, &m, &y, event); /*usando string scanf p fzr a leitura dessas strings desse array lido pelo mygetline e "formatando" o que queremos. É reconhecemos a datae a descrição, colocando a variável do que vai ser cada coisa (dia, mês, ano e evento) - n eh uma variável local ao scanf ent usa ponteiro p escrever direto nela. - Para evento usa uma expressão regular com classe de caracteres, nele diz que não pode haver uma quebra de linha, e "pega tudo q restar" da formatação até a quebra de linha, como se dissesse: continue lendo a linha e gravando o trecho em 'event' até achar uma quebra de linha. Ao fim, Scanf retorna o nmr de coisas q ela leu.*/
    if (r < 3) { /* Invalid line for some reason. */ /*Aq vemos o resultado do scan. Se achou 4, ótimo; Se achou 3, legal... significa que pegou a data mas sem evento. Se for menor que isso, ent n é válido. Ou seja, se vc n der 3 inteiros, a data n é válida e é ignorado, voltando pro inicio do loop*/
      continue;
    }
    /*agr iremos falar da formatação realmente;  é nessa hora que tem a estrutura da seta e os espaçamentos.*/
    char date[MAXLINE]; memset(date, '\0', sizeof date);
    snprintf(date, sizeof date, "Dia %d de %s de %d", d, month(m), y); /*o sprinf é usado como snprintf para colocarmos o tamanho da array e evitar buffer overflow. A array agr é toda essa tada por extenso. Ou seja, ao invés de imprimir na tela estou imprimindo dentro de um array.*/
    printf("%-30s --> %-.30s%s\n", date, event, 
           strlen(event) > 30 ? "..." : ""); /*A formatação com o espaçamentop é dado pelo %s. Nesse caso, da data escrita por extenso até o inicio da "-->"" terão 30 caracteres, e isso dps da seta também, se a desc for maior que isso, parar e colocar "...". O - antes do 30 é pra mostrar q é pra esquerda (se n botar nada fica pra direita), e o . é pra mostrar que é o limite/máximo que da pra ir. Por exemplo, poderemos colocar pra procurar ocupar 25 caracteres mas nunca passar de 30 -> %-25.30s%s. No nosso caso estamos colocando pra ocupar o quanto quiser, mas sem passar do 30. No fim, pras reticências, estamos usando um operador ternário, pra n ter q ter duas chamadas a printf, ai colocamos pra sempre imprimir alguma string dps, ou será ... ou será uma string vazia.*/
    
    }
}
