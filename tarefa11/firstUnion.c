#include<stdio.h>
union lab{
    int x;
    short int y;
};
int main(){
    int a = sizeof(union lab);
    printf("%d\n", a);
    return 0;
};
