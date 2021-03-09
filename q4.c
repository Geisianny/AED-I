#include<stdio.h>
#include<stdlib.h>

void selectionSort(int*v, int n){
    int i,j,menor, troca,cont=0;
    for(i=0;i<n-1; i++){
        menor = i;
        for(j=i+1; j< n;j++){ // PROCURA O MENOR ELEMENTO EM RELAÇÃO A 'I'
            if(v[j]>v[menor]){
                menor = j;
            }
        }
        if(i != menor){ // TROCA OS VALORES DA POSIÇÃO ATUAL COM A 'MENOR'
            troca = v[i];
            v[i] = v[menor];
            v[menor] = troca;

        }
        cont++;
            if(i == 5){
                break;
            }

    }

    for(i=0;i<10;i++){
        printf("%d ",v[i]);
    }
    printf("\n");
}

int main ()
{
    int v[10]={15,11,16,18,23,5,10,22,21,12};

    selectionSort(v,10);
    return 0;
}

