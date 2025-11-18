#include <stdio.h>

struct ip_address {
  unsigned char bs[4];
};

int main(void) {

  struct ip_address ip1;
  ip1.bs[0] = 65;
  ip1.bs[1] = 21;
  ip1.bs[2] = 52;
  ip1.bs[3] = 178;

  struct ip_address ip2;
  ip2 = ip1; /* beautiful: we just copied an array using the /=/
                operator */

  printf("ip1 is %d.%d.%d.%d\n", ip1.bs[0], ip1.bs[1], ip1.bs[2], ip1.bs[3]);
  printf("ip2 is %d.%d.%d.%d\n", ip2.bs[0], ip2.bs[1], ip2.bs[2], ip2.bs[3]);
  return 0;
}
