#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct labA{ /*Total 3bytes - 24bits*/
	short int x; /*short int = 2bytes = 16bits / int = 4bytes = 32bits*/
	unsigned char z; /*1byte = 8bits*/
} n;
/*VS*/
union labB{ /*Total: 2bytes - 16bits*/
	short int x; /*2bytes - 16bits*/
	unsigned char z; /*1byte - 8bits*/
} m;
/*Economia de espaço - porém só se pode usar um de cada vez*/
/*Veja o porque no teste abaixo:*/
int main(){
	/*union labB m;struct labA n;*/
	int a = 0;int b = 0;
	m.x = 5;m.z = 'a';
	a = sizeof(m);b = sizeof(n);
	printf("\n\t-----------\n\n");
	printf("\tx = %d\n",m.x); /*dará o valor decimal de 'a' = 97*/
	printf("\tz = %c\n",m.z);
	/*Darão o mesmo resultado, 
	já que primeiro escrevemos o 5 na memória, 
	e dps sobrescrevemos com o 'a'.
	Se usarmos o 5 antes de sobrescrevermos com a string,
	como colocando o print antes de m.z receber qlqr valor,
	então o resultado sairia perfeitamente como deveria.*/
	printf("\t-----------\n\n");
	m.x = 8;
	printf("\tx = %d\n",m.x);
	m.z = 'z';
	printf("\tz = %c\n",m.z);
	printf("\t-----------\n");
	printf("\n\tUnion>%dbytes \n\tStruct>%dbytes\n\n",a,b);

	/*vendo o tamanho total de struct e union + de cada elemento dele*/
	int a1 = sizeof(m.x);int a2 = sizeof(m.z);int b1 = sizeof(n.x);int b2 = sizeof(n.z);
	printf("\n\n\tBytes de Union:%d\t \n.Sendo eles: %d de (x) e %d de (z) \n\tBytes de Struct:%d\t \n.Sendo eles: %d de (x) e %d de (z) \n\n",a,a1,a2,b,b1,b2);
	return 0;
};
