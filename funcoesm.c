#include<stdio.h>
#include<stdlib.h>

int maior(int a, int b, int c){
    int maior = 0;

    if(a > b && a >c){
        maior = a;
    }else if(b>a && b>c){
        maior = b;
    }else{
        maior = c;
    }
    return maior;
}
int medio (int a, int b, int c){
    int medio = 0;

    if(a>b && a < c){
        medio = a;
    }else if(b > a && b<c){
        medio = b;
    }else{
        medio = c;
    }

    return medio;

}
int menor(int a, int b, int c){

   int menor = 0;

   if(a < b && a< c){ // menor numero
        menor = a;
    }else if(b < a && b < c){
        menor = b;
    }else if (c<a && c < b){
        menor = c;
    }
    return menor;
}
int soma(int a, int b, int c){
    return a + b + c;
}
int mult(int a, int b, int c){
    return a*b*c;
}
int multmax(int a, int b, int c)
{
    return (a*b*c)*maior(a,b,c);
}
int main()
{
    return 0;
}
