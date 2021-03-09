#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *vetor,num=0,i=0;

    printf("Digite o tam do vetor: "); // tamanho do vetor
    scanf("%d", &num);

    vetor = malloc(num*sizeof(int)); //numeros do vetor

    for(i=0;i<num;i++){
        scanf("%d",&vetor[i]);
    }

    for(i=num-1;i>=0;i--){ // impressao do vetor
        printf("%d ",vetor[i]);
    }
    free(vetor); //liberando a memoria alocada
    return 0;
}
