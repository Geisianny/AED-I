#include<stdio.h>
#include<stdlib.h>

/*Considerando o vetor com os seguintes valores {78, 12, 35, 1, 17, 4, 43, 11, 17, 1} e
o algoritmo Insertion sort, como estará o vetor na terceira iteração? **/

void insertionSort(int*v,int n){
    int i,j,aux,cont=0;
    for(i=1;i<n;i++){
        aux = v[i]; // MOVE AS CARTAS MAIORES PARA FRENTE
        for(j=i;(j>0) && (aux< v[j-1]); j--){
            v[j]= v[j-1];
        }
        v[j]= aux;
        cont++;
        if(cont == 3){ // garantir a terceira iteração
            break;
        }
    }
    for(i=0;i<10;i++){
        printf("%d ",v[i]);
    }
    printf("\n");
}

int main()
{
    int v[]={78, 12, 35, 1, 17, 4, 43, 11, 17, 1};
    insertionSort(v,10);
    return 0;
}
