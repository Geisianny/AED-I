#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void merge(char str[20][20], int inicio,int meio, int fim){ //aqui (receber array de strings e nao uma unica str)

    int i,j,k=0;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    /*NOVOS VETORES*/
    char str1[n1][20];  //aqui (array de strings e nao uma unica str)
    char str2[n2][20];  //aqui (array de strings e nao uma unica str)

    for(i=0;i<n1;i++){
        strcpy(str1[i], str[inicio+i]); //aqui (copia de strings em vez de atribuicao de caracteres)

    }
    for(j=0;j<n2;j++){
        strcpy(str2[j], str[meio+j+1]); //aqui (copia de strings em vez de atribuicao de caracteres)

    }
    j=0;
    i=0;
    k = inicio;
    while(i<n1 && j< n2){
        if(strcmp(str1[i],str2[j]) <= 0){ //aqui (comparacao de strings de um array e nao de strings individuais), (<= e nao <)
            strcpy(str[k], str1[i]); //aqui (copia de strings em vez de atribuicao de caracteres)
            i++;
        }else{
            strcpy(str[k], str2[j]); //aqui (copia de strings em vez de atribuicao de caracteres)
            j++;
        }
        k++;
    }
    while(i<n1){
        strcpy(str[k],str1[i]); //aqui (copia de strings em vez de atribuicao de caracteres)
        k++;
        i++;
    }
    while(j<n2){
       strcpy(str[k],str2[j]); //aqui (copia de strings em vez de atribuicao de caracteres)
        k++;
        j++;    //aqui (j++ e nao i++)
    }

}
void merge_sort(char str[20][20], int inicio, int fim){

    if(inicio < fim){

        int meio = inicio + (fim - inicio) / 2;

        merge_sort(str,inicio,meio);
        merge_sort(str,meio+1,fim);

        merge(str,inicio,meio,fim);
    }

}

void imprimir(char cidades[20][20], int n){ //criei um procedimento de impressao p ajudar a verificar a correcao
    int i;
    for(i=0; i<n; i++){
        printf(" %s ", cidades[i]);
    }
}

int main ()
{
     char cidade[20][20]; //aqui (array de strings e nao uma unica string)
    int j=0;
    while(1){

        if(j==20){  //aqui (evitando que o limite de memoria do array seja ultrapassado)
            break;
        }
        printf("Digite um nome de uma cidade: (-1 para sair)\n");
        scanf(" %[^\n]",&cidade[j++]);  //aqui (atribuindo a uma posicao do array e nao a uma unica string)

        if(strcmp(cidade[j-1], "-1")== 0){  //aqui (comparando posicao do array)
            break;
        }

        /*TRANSFORMAR A STRING INTEIRA EM MAIUSCULO*/
        for(int i=0;i<20;i++){
            if(cidade[j-1][i] >= 'a' && cidade[j-1][i] <= 'z'){ //aqui (comparando caracteres de uma determinada posicao do array)
                cidade[j-1][i]-=32;
            }
        }
        merge_sort(cidade,0,j-1);   //passando um array de strings e o tamanho atual do array ate o momento que foi lido
        imprimir(cidade,j); //criei esse procedimento

    }

    return 0;
}
