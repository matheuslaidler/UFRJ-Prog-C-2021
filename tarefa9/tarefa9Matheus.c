/*
Primeiramente, obrigado por tudo Daniel, você foi o melhor professor que eu tive da área (sem brincadeiras).
Agora, partindo pro recado, eu acabei fazendo os programas "do zero" em um e não apenas editando getline e read-events.
Na hora de fzr o programa optei fzr tudo junto, sem ser apenas modificações do getline e read-events na entrada. 
Achei assim mais prático e interessante colocar um loop pra ler as linhas enquanto aplica o filtro e a estrutua que foi mostrada, me pareceu uma ideia boa. 
Optei por fzr o usuário escrever o arquivo sem argumento, apenas com interação direto do usuário, fznd ele colocar
o nome do arquivo e iniciando o processo da leitura de linha a linha sem precisar de "outro programa" pra isso.
Espero que goste.*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXLINE 1000


char *month(int m) {
  char *names[] = {
    "janeiro", "fevereiro", "março", "abril",
    "maio", "junho", "julho", "agosto",
    "setembro", "outubro", "novembro", "dezembro"
  };
  return names[m - 1]; 
}

int main(void)
{
	/*Declarando as variáveis*/
	FILE *arquivo;
	char buff[MAXLINE];
	size_t sz;
	char continuar;
	int d, m, y; int r; 
	/*Menu de interação com usuário*/
	printf("\n______________________________________________________________________\n\n");
	printf("\n\t\tDigite o nome do arquivo com extensão\n");
	printf("\n\t\tCertifique-se de estar na mesma pasta\n\n");
	printf("\n\t\t\t(Exemplo: database.txt)\n\n");
	printf("\n______________________________________________________________________\n\n");
	scanf("%s", &continuar);
	printf("\n\n");
	/*Capturando a resposta do usuário -> pegando o nome do arquivo*/
	arquivo = fopen(&continuar,"r");

	/*Verificando se o arquivo digitado pelo usuário existe (biblioteca unistd.h)*/
	if( access( &continuar, F_OK ) != -1)
    {
        printf("Arquivo encontrado...\n\n");
    }
    else
    {
    	printf("Arquivo não encontrado...\n\n");
    	return 0;
    }

    /*Loop da verificação linha por linha do arquivo*/
	while(fgets(buff, sz, arquivo) != NULL)
	{
		
																/*Sem o memset o evento q ficar vazio será repetido pelo último, deixando a saida errada*/
    	char event[MAXLINE]; memset(event, '\0', sizeof event); /*declaro um array EVENTO do msm tamanho, a ideia é colocar a descrição do evento nela; memset zerando o array por completo, para bastar apenas escrever os bytes nele, sem zerar mais - ou seja, apenas sobrescreverei os zeros com os próximos conteúdos que pegaremos no loop. Em outras palavras, a lista fica toda preenchida de zero para serem substituidas pelo conteúdo, para n ter q ficar criando zero a cada vez. Por aq tbm fechamos a string com \0*/
		r = sscanf(buff, "%d/%d/%d %[^\n]", &d, &m, &y, event); /*usando string scanf p fzr a leitura dessas strings desse array lido pelo mygetline e "formatando" o que queremos. É reconhecemos a datae a descrição, colocando a variável do que vai ser cada coisa (dia, mês, ano e evento) - n eh uma variável local ao scanf ent usa ponteiro p escrever direto nela. - Para evento usa uma expressão regular com classe de caracteres, nele diz que não pode haver uma quebra de linha, e "pega tudo q restar" da formatação até a quebra de linha, como se dissesse: continue lendo a linha e gravando o trecho em 'event' até achar uma quebra de linha. Ao fim, Scanf retorna o nmr de coisas q ela leu.*/
		if (r < 3) { 											 /*Aq vemos o resultado do scan. Se achou 4, ótimo; Se achou 3, legal... significa que pegou a data mas sem evento. Se for menor que isso, ent n é válido. Ou seja, se vc n der 3 inteiros, a data n é válida e é ignorado, voltando pro inicio do loop*/
			continue;
		}
		   /*Formatação dos campos do arquivo*/
		char date[MAXLINE]; memset(date, '\0', sizeof date);
		snprintf(date, sizeof date, "Dia %d de %s de %d", d, month(m), y); 		/*o sprinf é usado como snprintf para colocarmos o tamanho da array e evitar buffer overflow. A array agr é toda essa tada por extenso. Ou seja, ao invés de imprimir na tela estou imprimindo dentro de um array.*/
		printf("%-30s --> %-.30s%s\n", date, event, 
		        strlen(event) > 30 ? "..." : ""); 								/*A formatação com o espaçamentop é dado pelo %s. Nesse caso, da data escrita por extenso até o inicio da "-->"" terão 30 caracteres, e isso dps da seta também, se a desc for maior que isso, parar e colocar "...". O - antes do 30 é pra mostrar q é pra esquerda (se n botar nada fica pra direita), e o . é pra mostrar que é o limite/máximo que da pra ir. Por exemplo, poderemos colocar pra procurar ocupar 25 caracteres mas nunca passar de 30 -> %-25.30s%s. No nosso caso estamos colocando pra ocupar o quanto quiser, mas sem passar do 30. No fim, pras reticências, estamos usando um operador ternário, pra n ter q ter duas chamadas a printf, ai colocamos pra sempre imprimir alguma string dps, ou será ... ou será uma string vazia.*/
		    

		/*para ver o resultado padrão: printf("%s",buff);*/
	}

	/*Para ver o arquivo original:/
	while(fgets(buff, sz, arquivo) != NULL)
	{
		printf("%s",buff);
	}
	*/

	if(fgets(buff, sz, arquivo) == NULL){
		return 1;
	}
	fclose(arquivo);
	printf("\n\n");
	getchar();
	return(0);

}
