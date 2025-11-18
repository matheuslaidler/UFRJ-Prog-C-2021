#include <stdio.h>
#include <inttypes.h> /* for PRIu64 and uint64_t */
#include <limits.h> /* for UINT64_MAX */
#include <stdlib.h> /* for exit() */
#include <math.h>

#define SUPPORTED "+ - * / %%"

void usage(int e) {
  printf("Usage: expr operand-1 operator operand-2\n");
  printf(" where operator must be exactly one of " SUPPORTED ".\n\n");

  printf("We do not support negative or rational numbers.\n\n");
  printf("But we do not suffer from integer overflow and\n");
  printf(" our numbers can go up to %" PRIuMAX ".\n\n", UINT64_MAX);

  printf("In other words, this program may have some limitations,\n"
         "like any other program, but it has no programming flaws.\n\n");

  printf("(*) C99, section 6.2.5.9\n\n"
      "``A computation involving unsigned operands can never overflow,\n"
      "because a result that cannot be represented by the resulting\n"
      "unsigned integer type is reduced modulo the number that is one\n"
      "greater than the largest value that can be represented by the\n"
      "resulting type.''\n\n");

  exit(e);
}

/*A redação será dessa função*/
/**'acho'-função abaixo serve para fazer com que o valor da string dos operandos sejam inteiros para fazer a operação*/
uint64_t array_to_uint64(char *s, uint64_t *u) 
{
  uint64_t pos;
  uint64_t r;
  uint64_t c;

  pos = 0; r = 0;

  for ( ;; ) {
    c = (uint64_t) (unsigned char) (s[pos] - '0'); /*o c ficará o primeiro valor da string do primeiro número do argumento*/
    printf("%lu \n",c);
    if (c < 10) { /*verifica se o c é menor q 10, pois so poderá ser maior q dez se for diferente de um numero, tipo espaço q valerá 208 */
      if( ((UINT64_MAX - c) / 10) >= r) /*Assegurar que o número não vai ser maior do que o limite máximo do tipo do int para não extrapolar a memória*/
        r = r * 10 + c; /*com r era zero, ele na primeira vez será igual a C; no próximo elemento do número */
      else return -1; /* doesn't fit */
      ++pos; continue;
    }
    break;
  }

  *u = r;
  return pos;/*retorna a posição onde parou, dps q achou o primeiro número inteiro, por exemplo*/
}

uint64_t power(uint64_t base, uint64_t n) {
  uint64_t p; p = 1;
  for (uint64_t i = 1; i <= n; ++i)
    p = p * base;
  return p;
}

int main(int argc, char *argv[]) { 
  if (argc != 4) usage(0);
  uint64_t op1;
  uint64_t op2;
  uint64_t r; 
  int okay;

  okay = array_to_uint64(argv[1], &op1);/*recebe a posição que chegou no for achando o primeiro nmr*/
  if (okay == -1) {
    printf("expr: %s is too large\n", argv[1]);
    exit(1);
  }
  if (okay == 0) {
    printf("expr: %s is an invalid natural number\n", argv[1]);
    exit(1);
  }

  okay = array_to_uint64(argv[3], &op2);
  if (okay < 0) {
    printf("expr: %s is too large\n", argv[2]); /*aqui vemos um errinho que no print esta printando o argv[2] e não o argv[3]*/
    exit(1);
  }
  if (okay == 0) {
    printf("expr: %s is an invalid natural number\n", argv[2]);
    exit(1);
  }

  int operator; 
  operator = argv[2][0];

  switch(operator) {

  case '-':
    if (op1 < op2) {
      printf("expr: illegal subtraction\n");
      exit(101);
    }
    r = op1 - op2;
    printf("%" PRIu64 "\n", r);
    break;

  case '+':
    r = op1 + op2;
    printf("%" PRIu64 "\n", r);
    break;

  case '%':
    r = op1 % op2;
    printf("%" PRIu64 "\n", r);
    break;
  
  case 'x':
    r = op1 * op2;
    printf("%" PRIu64 "\n", r);
    break;
  
  case '/':
    r = op1 / op2;
    printf("%" PRIu64 "\n", r);
    break;
  
  case '^':
    r = power(op1, op2);
    printf("%" PRIu64 "\n", r);
    break;

  default:
    printf("expr: unknown operator ``%c''\n", operator);
    exit(101);
    break;
  
  }

  return 0;
}
