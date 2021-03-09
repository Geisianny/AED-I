#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void merge(char str[20], int inicio,int meio, int fim){

    int i,j,k=0;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    /*NOVOS VETORES*/
    char str1[n1];
    char str2[n2];

    for(i=0;i<n1;i++){
        str1[i]= str[inicio+i];
        strcpy(str1[i],str[i+inicio]);

    }
    for(j=0;j<n2;j++){
        str2[j] = str[meio+j+1];

    }
    j=0;
    i=0;
    k = inicio;
    while(i<n1 && j< n2){
        if(strcmp(str1,str2) <0){
            str[k]= str1[i];
            i++;
            }else{
                str[k]= str2[j];
                j++;
        }
        k++;
    }
    while(i<n1){
        str[k]=str1[i];
        k++;
        i++;
    }
    while(j<n2){
       str[k]=str2[j];
        k++;
        i++;
    }

}
void merge_sort(char* str, int inicio, int fim){

    if(inicio < fim){

        int meio = inicio + (fim - inicio) / 2;

        merge_sort(str,inicio,meio);
        merge_sort(str,meio+1,fim);

        merge(str,inicio,meio,fim);
    }

}

int main ()
{
     char cidade[20];

    while(1){

        printf("Digite um nome de uma cidade: (-1 para sair)\n");
        scanf(" %[^\n]",&cidade);

        if(strcmp(cidade, "-1")== 0){
            break;
        }

        /*TRANSFORMAR A STRING INTEIRA EM MAIUSCULO*/
        for(int i=0;i<20;i++){
            if(cidade[i] >= 'a' && cidade[i] <= 'z'){
                cidade[i]-=32;
            }
        }
        merge_sort(cidade,0,19);

    }

    return 0;
}
