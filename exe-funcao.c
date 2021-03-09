#include<stdio.h>
#include<stdlib.h>
#include "funcoesm.h"

int main()
{
    int a,b,c;

    scanf("%d %d %d",&a,&b,&c);
    printf("Em ordem descrescente: %d %d %d\n",maior(a,b,c),medio(a,b,c), menor(a,b,c));
    printf("Soma: %d\n",soma(a,b,c));
    printf("Multiplicacao: %d\n", mult(a,b,c));
    printf("Multiplicacao * max: %d\n",multmax(a,b,c));
}
