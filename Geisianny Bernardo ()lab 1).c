/*LAB 1*/

#include<stdio.h>
#include<stdlib.h>
int menu(void){ //FUN��O MENU DE OP��ES//
    int op;

    printf("-----------Menu-----------\n");
    printf("1 - Somar\n");
    printf("2 - Subtrair\n");
    printf("3 - Multiplicar\n");
    printf("4 - Dividir\n");
    printf("5 - Sair\n");
    printf("--------------------------\n");
    printf("Digite sua opcao: ");
    scanf("%d",&op);

    return op;
}


int main() //FUN��O PRINCIPAL//
{
   float n1,n2,maior=0.0, menor=0.0;
   int op;

   while(op!= 5){ //COME�O DO LOOP//

        op = menu(); //FUN��O MENU DE OP�OES//
        system("cls"); // LIMPAR A TELA//

        switch(op){
           case 1: //OP��O SOMAR//

              printf("\nDigite 2 valores: "); //NUMEROS SOLICITADOS PELO TECLADO//
              scanf("%f %f",&n1,&n2);
              printf("\nResultado da soma: %.0f\n\n",n1 + n2); //RESULTADO DA SOMA DOS 2 NUMEROS//
              break;

           case 2: //OP��O SUBTRAIR//

                printf("\nDigite 2 valores: "); //NUMEROS SOLICITADOS PELO TECLADO//
                scanf("%f %f",&n1,&n2);
                if(n1 > n2){ //OBTENDO O MAIOR E O MENOR NUMERO PARA REALIZAR A SUBTRA��O//
                    maior = n1;
                    menor = n2;
                }else{
                    maior = n2;
                    menor = n1;
                }
                printf("\nResultado da substracao: %.0f\n\n",maior - menor); //RESULTADO DA SUBTRA��O DOS 2 NUMEROS//
                break;

          case 3://OP��O MULTIPLICAR//

                printf("\nDigite 2 valores: "); //NUMEROS SOLICITADOS PELO TECLADO//
                scanf("%f %f",&n1,&n2);
                printf("\nResultado da multiplicacao: %.0f\n\n",n1*n2); //RESULTADO DA MULTIPLICA��O DOS 2 NUMEROS//
                break;

          case 4://OP��O DIVIDIR//

                printf("\nDigite 2 valores: "); //NUMEROS SOLICITADOS PELO TECLADO//
                scanf("%f %f",&n1,&n2);

                if(n1 == 0 || n2 == 0){ //VERIFICA��O DA EXISTENCIA DO NUMERO ZERO NA DIVISAO//
                    printf("ERRO! nao eh possivel dividir um numero por zero / ou zero dividir um numero.\n"); //MENSAGEM DE ERRO//
                    printf("Por favor, digite 2 numeros novamente: ");// SOLICITA��O DE MAIS DOIS NUMEROS//
                    scanf("%f %f",&n1,&n2);
                }
                printf("\nResultado da divisao: %.2f\n\n",n1/n2);// RESULTADO DA DIVIS�O DOS 2 NUMEROS QUE N�O S�O ZERO//
                break;

          case 5: //OP��O SAIR//

                printf("\nSaindo do sistema...\n\n"); //SAIDA DO LOOP//
                break;

        default: //OP��O INVALIDA: CASO O NUMERO DIGITADO SEJA DIFERENTE DE 1-5//

            printf("\nERRO!Digite uma opcao valida!\n\n"); // MENSAGEM DE ERRO//
            break;
     }
   }

    return 0;
}
