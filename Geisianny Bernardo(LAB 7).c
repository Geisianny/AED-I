#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void merge(char str[20][20], int inicio,int meio, int fim){ /*FUNÇÃO MERGE*/

    int i,j,k=0;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    /*Novos vetores auxiliares*/
    char str1[n1][20];
    char str2[n2][20];

    /*Copia o vetor de strings para vetores auxiliares*/
    for(i=0;i<n1;i++){
        strcpy(str1[i], str[inicio+i]);
    }
    for(j=0;j<n2;j++){
        strcpy(str2[j], str[meio+j+1]);

    }
    /*Variaveis inicializadas*/
    j=0;
    i=0;
    k = inicio;

    while(i<n1 && j< n2){
        if(strcmp(str1[i],str2[j]) >= 0){ /*Ordem decrescente do vetor de strings*/
            strcpy(str[k], str1[i]);
            i++;
        }else{
            strcpy(str[k], str2[j]);
            j++;
        }
        k++;
    }
    /* Copie os elementos restantes de str1, se houver
     alguns */
    while(i<n1){
        strcpy(str[k],str1[i]);
        k++;
        i++;
    }

    /* Copie os elementos restantes de str2, se houver
     alguns */
    while(j<n2){
       strcpy(str[k],str2[j]);
        k++;
        j++;
    }

}
void merge_sort(char str[20][20], int inicio, int fim){ /*FUNÇÃO MERGE SORT*/

    int meio = 0;

    if(inicio < fim){

        meio = inicio + (fim - inicio) / 2;

        merge_sort(str,inicio,meio);
        merge_sort(str,meio+1,fim);

        merge(str,inicio,meio,fim);
    }

}

void imprimir(char cidades[20][20], int n){ /*FUNÇÃO DE IMPRESSAO*/

    int i;

    printf("\nCIDADES: \n\n");

    for(i=0; i<n; i++){
        printf(" %s - ", cidades[i]);
    }
    printf("\n");
}

/*FUNÇÃO PRINCIPAL*/

int main ()
{
     char cidade[20][20]; /*Vetor de strings*/
     int j = 0;

     while(1){

        if(j==20){ /* Verificação para que o limite da memoria do vetor não seja ultrapassado*/
            break;
        }
        printf("\nDigite um nome de uma cidade: (-1 para sair)\n");
        scanf(" %[^\n]",&cidade[j++]);

        if(strcmp(cidade[j-1], "-1")== 0){ /*Saída do while */
            break;
        }

        /*TRANSFORMAR O VETOR DE STRING INTEIRO EM MAIUSCULO*/
        for(int i=0;i<20;i++){
            if(cidade[j-1][i] >= 'a' && cidade[j-1][i] <= 'z'){
                cidade[j-1][i]-=32;
            }
        }
        merge_sort(cidade,0,j-1); /*FUNÇÃO MERGE SORT*/
        imprimir(cidade,j); /*FUNÇÃO IMPRESSAO*/

    }

    return 0;
}
