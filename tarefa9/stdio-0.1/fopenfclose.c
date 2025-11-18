#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

/*  
->tabela de funções - relembrando e resumindo<-

fopen() -. ABRE UM ARQUIVO
fclose() -. FECHA O ARQ GARANTINDO A TRANSFERENCIA DO BUFFER (texto na memoria)
fgets() -. OBTÉM UMA STRING DO ARQUIVO
fgetc() -. OBTÉM UM CARACTER DO ARQUIVO
fread() -. LE UM BLOCO DE DADOS DO ARQUIVO
fwrite() -. ESCREVE UM BLOCO DE DADOS NO ARQUIVO
fscanf() -. LEITURA DE ENTRADA FORMATADA - SCANF
fprintf() -. ESCRITA DE SAIDA FORMATADA - PRINTF
fflush() -. DESCARREGA O BUFFER
fputs() -. INSERE UMA STRING NO ARQUIVO
fputc() -. INSERE UM CARACTER NO ARQUIVO
fseek() -. REPOSICIONA O PONTEIRO
rewind() -. REPOSICIONA O PONTEIRO PARA O INICIO DO ARQ
ftell() -. RETORNA A POSIÇÃO DO PONTEIRO


->basico do q vms utilizar para abrir e fechar o arquivo<-

fopen -> FILE *fopen(const char *filename, const char *mode)
-> modos de fopen;
	r  -> abre arq pra leitura (se não existe: retorna NULL)
	w  -> abre o arq para escrita (se não existe: o arq é criado; se existe: é apagado sem aviso e um novo é criado)
	a  -> abre o arq pra add novos caracteres (se não existe: o arq é criado; se existe: é aberto p ADIÇÃO de caracteres NO FIM)
	r+ -> abre o arq para leitura e escrita (se não existe retorna NULL: ; se não existe: é aberto p adição de caracteres no INICIO, sobrescrevendo as existentes)
	w+ -> abre o arq p leitura + escrita (se não existe: o arq é criado ; se não existe: é aberto p adição de caracteres no INICIO, sobrescrevendo o arq INTEIRO)
	a+ -> abre o arq p leitura e p add novos caracteres (se não existe o arq é criado: ; se não existe: é aberto p EDIÇÃO de caracteres no FIM)
   (wb -> criando arq binário)
fclose -> int fclose(FILE *FP) -> fp: ponteiro de arquivo associado a stream

*/

int main() {

	FILE *arq;
	int resposta;

	setlocale(LC_ALL, "Portuguese");
	arq = fopen("testando.txt","wb");
	if (arq == NULL) {
		printf("\nOcorreu um erro... O arquivo não pode ser aberto.\n");
	} else {
		printf("\nSucesso na abertura!\n");
	}


	/*Por aq podemos agr fzr a escrita no arquivo ou leitura de outro, além de escrever neste que abrimos inicialmente? 
																									tente e responda*/


	resposta = fclose(arq);
	if (resposta == 0) {
		printf("\nSucesso no fechamento\n");
	} else {
		printf("\nErro no fechamento\n");
	}

	printf("\nPressione ENTER para sair\n");
	getchar();
	return 0;
}