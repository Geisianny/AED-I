#include<stdio.h>
#include<stdlib.h>

 void ordenacao(int v[],int tam){ /*Funcao de ordenacao*/

     int i_maior = 0,i_menor = 0,i_atual,i,aux=0;

     for(i_atual=0;i_atual<(tam/2)+1;i_atual++){

        i_maior = i_atual;  /*Maior numero do vetor*/

        for(i=i_atual+1;i<tam-i_atual;i++){
            if(v[i]> v[i_maior]){
                i_maior = i;
            }
        }
        aux = v[i_atual];
        v[i_atual] = v[i_maior];
        v[i_maior] = aux;


        i_menor = i_atual; /*Menor numero do vetor*/

        for(i= i_atual+1;i<tam-i_atual;i++){
            if(v[i]< v[i_menor]){
                i_menor = i;
            }
        }
        aux = v[tam-1-i_atual];
        v[tam-1-i_atual] = v[i_menor];
        v[i_menor] = aux;
    }
}

void impressao(int vet[],int tam){ /*Funcao de impressao do vetor*/

    int i;

    printf("VETOR ORDENADO:\n\n");
    for(i=0;i<tam;i++){
        printf(" %d ",vet[i]);
    }
    printf("\n\n");
}

void remover (int tam,int v[],int pos){ /*Funcao de remover o numero e coloca 0 no seu lugar*/

    int i;

    v[pos] = 0;

    for(i=pos;i<tam;i++){
        if(i+1 < tam){
            v[i] = v[i+1];
        }
        else{
            v[i] = 0;
        }
    }


}

int menu(void){ /*Funcao menu de opcoes*/

    int op = 0;

    printf("--------------------------- MENU --------------------------------\n");
    printf("\nOPCAO:\n");
    printf("\t1 - Imprimir vetor ordenado\n");
    printf("\t2 - Remover elemento especifico do vetor\n");
    printf("\t3 - Sair do sistema\n");
    printf("\n\n-----------------------------------------------------------------\n");
    printf("Digite a opcao desejada: ");
    scanf("%d",&op);

    return op;
}

/*Funcao principal*/
int main ()
{
    int vet[10]={20,8,55,2,7,-2,1,9,3,17}; /*Vetor preenchido*/
    int op = 0,num=0,pos = 0,j, removidos = 0;

    ordenacao(vet,10-removidos);

    while(op != 3){

        op = menu(); /*Funcao menu*/
        system("cls"); /*Limpa a tela*/

        switch(op){ /*1 opcao*/

            case 1:
                impressao(vet,10); /*Impressao do vetor*/
                break;

            case 2: /*2 opcao*/
                printf("Digite o numero a ser removido do vetor: ");
                scanf("%d",&num);

                for(int i = 0; i<10;i++){
                    if(vet[i]== num){

                        pos = i;
                        printf("Numero encontrado!\n");
                        printf("Numero removido!\n");
                        removidos++;

                        remover(10,vet,pos); /*Funcao para remover o numero do vetor*/
                        break;

                    }else{

                        if(i== 9){ /*Para garantir que o vetor foi percorrido e o numero n encontrado*/
                            printf("Numero nao encontrado no vetor, tente novamente com outro numero!\n");
                        }
                    }
                }
                break;

            case 3: /* 3 opcao*/
                 printf("\nSaindo do sistema...\n\n"); /*SAIDA DO LOOP*/
                 break;

            default: /*OPÇÃO INVALIDA: CASO O NUMERO DIGITADO SEJA DIFERENTE DE 1-3*/
                printf("\nERRO!Digite uma opcao valida!\n\n"); /* MENSAGEM DE ERRO*/
                break;
        }


    }


}
