#include<stdio.h>
#include<stdlib.h>

struct livro{
    int num;
    int pag;
    float real;
    float dolar;
};
void cadastro(struct livro *Livro){

    Livro[0].num = 56890;
    Livro[0].pag = 500;
    Livro[0].real = 350.00;
    Livro[0].dolar =  Livro[0].real * 4.30;

    Livro[1].num = 3456;
    Livro[1].pag = 750;
    Livro[1].real = 450.00;
    Livro[1].dolar = Livro[1].real * 4.30;

    Livro[2].num =  234;
    Livro[2].pag = 150;
    Livro[2].real = 250.00;
    Livro[2].dolar = Livro[2].real * 4.30;

    Livro[3].num = 678;
    Livro[3].pag = 250;
    Livro[3].real = 158.99;
    Livro[3].dolar = Livro[3].real * 4.30;

    Livro[4].num = 67590;
    Livro[4].pag = 300;
    Livro[4].real = 99.99;
    Livro[4].dolar = Livro[4].real* 4.30;
}
void impressao (struct livro *Livro){
    printf("------------------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\tCADASTRO DE LIVROS\n");
    printf("------------------------------------------------------------------------------------------------------------------\n");
    for(int i=0;i<5;i++){
        printf("\tNumero:%d\t- Qnt de paginas:%d\t- Valor em Real:%.2f\t-Valor em Dolar: %.2f\n",Livro[i].num, Livro[i].pag,Livro[i].real,Livro[i].dolar);
    }
    printf("-------------------------------------------------------------------------------------------------------------------\n");
}
void muda_valor(struct livro *Livro){

    Livro[4].num = 67590;
    Livro[4].pag = 300;
    Livro[4].real = 184.00;
    Livro[4].dolar = Livro[4].real* 4.30;
    printf("\nATUALIZACAO...\n\n");
    impressao(Livro);

}
int main(){
    struct livro Livro[5];
    cadastro(Livro);
    impressao(Livro);
    muda_valor(Livro);
}
