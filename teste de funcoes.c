#include<stdio.h>
#include<stdlib.h>
#include "funcoes.h"

int main ()
{
    char string[100],carac;
    int tam = 0;

    printf("Digite uma string: "); //SOLICITACAO DA STRING
    scanf("%[^\n]",string);       // LENDO A STRING INGNORANDO OS ESPAÇOS

    printf("Digite um caractere: "); //SOLICITACAO DO CARACTERE
    scanf(" %c",&carac);             // LENDO O CARACTERE

    tam = tamanho(string); //FUNCAO TAMANHO DA STRING

    if(carac >= 97 && carac <= 122){ //TRANSFORMANDO O CARACTERE DIGITADO EM MAIUSCULO
        carac -=32;
    }

    for(int i=0; i<tam;i++){  //TRANSFORMANDO A STRING DIGITADO EM MAIUSCULA(TABELA ASCII)
        if(string[i] >= 97 && string[i] <= 122){
            string[i] -=32;
        }
    }

    printf("Contagem de %c em %s: %d\n",carac,string,conta_char(string,carac)); // RESULTADO DE QUANTAS VEZES O CARACTERE APARECE NA STRING
    printf("Contagem de vogais(A,E,I,O,U) em %s: %d\n",string,conta_vogais(string)); // RESULTADO DE QUANTAS VOGAIS TEM NA STRING

    return 0;
}
