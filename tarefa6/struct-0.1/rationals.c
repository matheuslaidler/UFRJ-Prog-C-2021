#include <stdio.h>

typedef struct rational racional

struct rational {
  int num;
  int den; /* Notice den should never be zero because there's no such
              rational number with [den]ominator zero. */
};

racional mul(racional r1, racional r2) {
  racional ret;
  ret.num = r1.num * r2.num;
  ret.den = r1.den * r2.den;
  return ret;
}

/*

testes 

a/b + c/d = ad+cb/bd = (l.den*k.num) + (k.den*l.num) / (k.den * l.den)
 fração -> k.num = a k.den = b // l.num = c l.den = d
 
 

racional soma(racional k, racional l) {

  racional conta;
  conta.num = (l.den * k.num) + (k.den * l.num);
  conta.den = (k.den * l.den);

  return conta;
}
*/

/*mmc*/


int mmc0(int m, int n, int mcopy, int ncopy) { /*salvando valores originais tbm*/

/*achando o mínimo múltiplo comum de dois inteiros a e b - menor inteiro positivo e multiplo de a e b

se a = 2 e b = 5
a = ##
b = #####

se a + a:
####
#####

se a + a(original):
######
#####

se b + b:
######
##########

se a + a(original):
########
##########

se a + a(original):
##########
##########
=10

Pronto
O programa deverá funcionar desse jeito

como usamos 4 arguentos para salvar o valor original dos números, iremos criar uma funçãoa mmc que usa essa para o cálculo e deixar essa como 'mmc0'
então poderemos verificar os erros por essa outra função, como verificar se o usuário colocou o m menor ou igual a zero e coisas do tipo.
*/ 
	if (m == n) return m;
	if (m < n) return mmc0(m + mcopy,n, mcopy, ncopy);
	if (n < m) return mmc0(m, n + ncopy, mcopy, ncopy);
	return -1 /*podemos colocar esse return para evitar o aviso do compilador, pois os if's já irão cobrir todos os casos, ou simplesmente desligar o aviso do compilador*/
/*Ou seja, esse return -1 nunca ocorrerá*/
}

int mmc(int m, int n) { 
	/*aq tbm podemos verificar por erros de uso, como se tiver nmr negativo ou igual a zero e se o tamanho do inteiro é compatível*/
	return mmc0(m, n, m, n);
}

int main(void) {
  racional a;
  racional b;
  a.num = 4; a.den = 3; /* 4/3 */
  b.num = 3; b.den = 4; /* 3/4 */

  racional c; c = mul(a, b);

  printf("%d/%d * %d/%d = %d/%d\n", a.num, a.den, b.num, b.den, c.num, c.den);
  
  printf("mmc(%d, %d) == %d\n", 2, 5, mmc(2,5));
  
  printf("mmc(%d, %d) == %d == %d\n", 2, 5, mmc(2,5), 10); /*verificações*/
  printf("mmc(%d, %d) == %d == %d\n", 3, 6, mmc(3,6), 6); /*verificações*/
  printf("mmc(%d, %d) == %d == %d\n", 1, 1, mmc(1,1), 1); /*verificações*/
  printf("mmc(%d, %d) == %d == %d\n", 1, 11001, mmc(1,11001), 11001); /*verificações*/
  
  
  return 0;
}
