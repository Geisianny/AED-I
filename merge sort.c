#include<stdio.h>
#include<Stdlib.h>
#include<math.h>

void merge(int * v,int inicio,int meio,int fim){

    int i,j,k;
    int n1 = meio-inicio+1;
    int n2 = fim-meio;

    /*NOVOS VETORES*/
    int v1[n1], v2[n2];

    for(i=0;i<n1;i++){
        v1[i] = v[inicio+i];
    }
    for( j=0;j<n2;j++){
        v2[j] = v[meio+j+1];
    }

    i = 0;
    j = 0;
    k = inicio;
    while (i<n1 && j< n2){
        if(v1[i] >= v2[j]){
            v[k] = v1[i];
            i = i + 1;
        }else{
            v[k] =  v2[j];
            j = j +1;
        }
        k++;
    }
    while (i< n1){
        v[k]= v1[i];
        i++;
        k++;
    }
    while(j< n2){
        v[k]= v2[j];
        j++;
        k++;
    }
}
void merge_Sort(int *v, int inicio,int fim){

    if(inicio < fim){

        int meio = inicio + (fim - inicio) / 2;

        merge_Sort(v,inicio,meio);
        merge_Sort(v,meio+1,fim);

        merge(v,inicio,meio,fim);
    }
}

int main()
{
    int v[5]={10, 7,3, 2,-1};
    merge_Sort(v,0,4);

    for(int i = 0; i<5; i++){
        printf("%d ",v[i]);
    }
    printf("\n");
    return 0;
}
