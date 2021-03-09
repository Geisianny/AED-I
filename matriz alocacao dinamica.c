#include<stdio.h>
#include<stdlib.h>

void ler_elementos (int ** matriz, int x, int y){ // funcao de leitura dos elementos
    int i,j;
    for(i=0;i<x;i++){
        for(j=0;j<y;j++){
            scanf("%d", &matriz[i][j]);
        }
    }
}
int soma(int** matriz,int**matriz2, int x, int y){ // soma das 2 matrizes
    int soma = 0,i,j;

    for(i=0;i<x;i++){
        for(j=0;j<y;j++){
            soma += matriz[i][j] + matriz2[i][j];
        }
    }
    return soma;
}

void impressao(int**matriz,int x,int y){ // impressao das matrizes
    int i,j,m = y*x;

    for(i=0;i<x;i++){
        for(j=0;j<y;j++){
            printf("%10d",matriz[i][j]);
        }
        printf("\n");
    }

}
int main ()
{
    int **m_p, **m_p2;
    int n=0,m=0,i,j;

    printf("Digite a qnt de colunas e linhas das matrizes: ");
    scanf("%d %d",&n,&m);

    m_p = (int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++){
        m_p[i] = (int*)malloc(n*sizeof(int));
    }

    m_p2 = (int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++){
        m_p2[i] = (int*)malloc(n*sizeof(int));
    }

    printf("\nDigite os elementos da matriz 1:"); // matriz 1
    ler_elementos(m_p,n,m);
    printf("\nMATRIZ 1:\n");
    impressao(m_p,n,m);
    printf("\n");

    printf("\nDigite os elementos da matriz 2: "); //matriz 2
    ler_elementos(m_p2,n,m);
    printf("\nMATRIZ 2:\n");
    impressao(m_p2,n,m);

    printf("\nSoma dos elementos das 2 matrizes: %d\n",soma(m_p,m_p2,n,m));
    return 0;
}
