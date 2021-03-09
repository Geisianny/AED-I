#include<stdio.h>
#include<stdlib.h>


int tamanho(char* str){   //FUNCAO QUE RETORNA O TAMANHO DA STRING

    int tam = 0;

    for(int i=0; str[i] != '\0'; i++){ //CONTAGEM DO TAMANHO DA STRING
        tam ++;
    }

    return tam;
}


int conta_char (char* str, char c){  //FUNCAO 1: CONTAGEM DO CARACTERE NA STRING

    int tam = 0, cont_c = 0;

    tam = tamanho(str); //FUNCAO: TAMANHO DA STRING


    for(int i=0; i<tam; i++){ // CONTAGEM DO CARACTERE NA STRING DIGITADA
        if(str[i]== c){
            cont_c ++;
        }
    }
    return cont_c;
}

int conta_vogais (char* str){ //FUNCAO 2: CONTAGEM DA VOGAIS NA STRING

    int cont_v = 0,tam = 0;

    tam = tamanho(str); //FUNCAO TAMANHO DA STRING

    for(int i=0;i<tam;i++){  //CONTAGEM DAS VOGAIS(A,E,I,O,U)
        if(str[i] == 'A'  || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'){
            cont_v ++;
        }
    }
    return cont_v;
}

// FUNCAO PRINCIPAL //
int main ()
{
    char string[100],carac;
    int tam = 0;

    printf("Digite uma string: "); //SOLICITACAO DA STRING
    scanf("%[^\n]",string);       // LENDO A STRING IGNORANDO OS ESPAÇOS

    printf("Digite um caractere: "); //SOLICITACAO DO CARACTERE
    scanf(" %c",&carac);             // LENDO O CARACTERE

    tam = tamanho(string); //FUNCAO TAMANHO DA STRING

    if(carac >= 97 && carac <= 122){ //TRANSFORMANDO O CARACTERE DIGITADO EM MAIUSCULO
        carac -=32;
    }

    for(int i=0; i<tam;i++){  //TRANSFORMANDO A STRING DIGITADO EM MAIUSCULA
        if(string[i] >= 97 && string[i] <= 122){
            string[i] -=32;
        }
    }

    printf("Contagem de %c em %s: %d\n",carac,string,conta_char(string,carac)); // RESULTADO DE QUANTAS VEZES O CARACTERE APARECE NA STRING
    printf("Contagem de vogais(A,E,I,O,U) em %s: %d\n",string,conta_vogais(string)); // RESULTADO DE QUANTAS VOGAIS TEM NA STRING

    return 0;
}
