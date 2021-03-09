#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void bubble_sort (int vetor[], int n) {
    int k, j, aux,cont=0;

    for (k = 1; k < n; k++) {
        for (j = 0; j < n - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux  = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
                cont++;
            }
        }
    }


    for(int i=0;i<5;i++){
        printf("%d ",vetor[i]);
    }
    printf("\n%d",cont);

}
int main(){

    int dado[5]={16,18,15,37,13};
    bubble_sort(dado,5);

}
