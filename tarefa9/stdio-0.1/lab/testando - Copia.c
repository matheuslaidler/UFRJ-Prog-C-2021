#include <stdio.h>


int main(void)
{
	FILE *pont_arq;
	char texto_str[20];
	char continuar;

	printf("\n\tDigite o nome do arquivo e sua extensão:\n");
	scanf("\t%s", &continuar);
	printf("\n\n");

	pont_arq = fopen(&continuar,"r");

	while(fgets(texto_str, 20, pont_arq) != NULL)
	{
		printf("%s",texto_str);
	}
	fclose(pont_arq);
	printf("\n\n");
	getchar();
	return(0);

}