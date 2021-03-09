/*LAB 2*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


 struct tipopessoas{ // DEFINIÇÃO DE STRUCT PESSOAS
    char genero[5];
    char nome[40];
    float altura;
 };

  void cadastro(struct tipopessoas * pe){ //CADASTRO DE PESSOAS

    pe[0].altura = 1.70;             //DADOS DA PESSOA 0
    strcpy(pe[0].nome, "Todd");
    strcpy(pe[0].genero,"M");

    pe[1].altura = 1.72;           //DADOS DA PESSOA 1
    strcpy(pe[1].nome, "Carolyn");
    strcpy(pe[1].genero,"F");

    pe[2].altura = 1.80;          // DADOS DA PESSOA 2
    strcpy(pe[2].nome, "Beatrice");
    strcpy(pe[2].genero,"F");

    pe[3].altura = 1.78;        // DADOS DA PESSOA 3
    strcpy(pe[3].nome, "Diane");
    strcpy(pe[3].genero,"F");

    pe[4].altura = 1.88;       //DADOS DA PESSOA 4
    strcpy(pe[4].nome, "Judah");
    strcpy(pe[4].genero,"M");

  }

  void impressao (struct tipopessoas *pe){ //IMPRESSAO DAS PESSOAS
    printf("--------------------------------------------------\n");
    printf("\t\tCADASTRO DE PESSOAS\n");
    printf("--------------------------------------------------\n");
    for(int i=0;i<5;i++){
        printf("Pessoa:%s\t- Altura:%.2f\t- genero:%s\n",pe[i].nome,pe[i].altura,pe[i].genero);
    }
    printf("--------------------------------------------------\n");
  }

  void mediaAltura (struct tipopessoas *pe){  //MEDIA DAS ALTURAS

      float mediaAltura;
      for(int i=0; i<5;i++){
         mediaAltura += pe[i].altura;
      }
      mediaAltura = mediaAltura/5;
      printf("A) A altura media das 5 pessoas: %.2f;\n",mediaAltura);

  }

 void maiorAltura(struct tipopessoas *pe){ //MAIOR ALTURA
     float maior=0.0;
     for(int i=0;i<5;i++){
        if(pe[i].altura> maior){
            maior = pe[i].altura;
        }
     }
     printf("B) A maior altura encontrada: %.2f;\n",maior);
    }

 void mediasPorGenero(struct tipopessoas *pe){ //MEDIA POR GENERO
    float mediaMulher = 0.0, mediaHomem=0.0;
    for(int i=0;i<5;i++){
        if(strcmp(pe[i].genero,"F") == 0){
            mediaMulher += pe[i].altura;
        }else{
            mediaHomem += pe[i].altura;
        }
    }
    mediaMulher = mediaMulher/3;
    mediaHomem = mediaHomem/2;
    printf("C) A altura media das mulheres: %.2f\n   E a altura media dos homens: %.2f;\n",mediaMulher,mediaHomem);
 }

 void qntHomens(struct tipopessoas *pe){ //QUANTIDADE DE HOMENS
    int contH = 0;
    for(int i =0; i<5;i++){
        if(strcmp(pe[i].genero,"M")== 0){
            contH += 1;
        }
    }
    printf("D) A quantidade de homens: %d;\n\n",contH);
 }

 void altera(struct tipopessoas *pe){ // ALTERA A ALTURA DE UMA DAS PESSOAS

    pe[0].altura = 1.70; // PESSOA 0 P/ ALTERA
    strcpy(pe[0].nome, "Todd");
    strcpy(pe[0].genero,"M");

    pe[1].altura = 1.72; // PESSOA 1 P/ ALTERAR
    strcpy(pe[1].nome, "Carolyn");
    strcpy(pe[1].genero,"F");

    pe[2].altura = 1.80; // PESSOA 2 P/ ALTERAR
    strcpy(pe[2].nome, "Beatrice");
    strcpy(pe[2].genero,"F");

    pe[3].altura = 1.78; // PESSOA 3 P/ ALTERAR
    strcpy(pe[3].nome, "Diane");
    strcpy(pe[3].genero,"F");

    pe[4].altura = 1.88; // PESSOA 4 P/ ALTERAR
    strcpy(pe[4].nome, "Judah");
    strcpy(pe[4].genero,"M");

    impressao(pe); // FUNÇAO IMPRESSAO
    printf("\n");
    printf("DADOS:\n\n");
    mediaAltura(pe); // FUNCAO MEDIA DAS ALTURAS
    maiorAltura(pe); // FUNÇÃO MAIOR ALTURA
    mediasPorGenero(pe); // FUNÇÃO MEDIAS POR GENEROS
    printf("\n");

 }

//PROGRAMA PRINCIPAL
int main (){

    struct tipopessoas pe[5]; // PESSSOAS

    cadastro(pe); // CADASTRO DE PESSOAS
    impressao(pe); // FUNÇÃO IMPRESSAO
    printf("\n");
    printf("DADOS:\n\n");
    mediaAltura(pe); // FUNCAO MEDIA DAS ALTURAS
    maiorAltura(pe); // FUNÇAO MAIOR ALTURA
    mediasPorGenero(pe); // FUNCAO MEDIA POR GENERO
    qntHomens (pe); // FUNCAO QUANTIDADE DO GENERO MASCULINO
    printf("\n\nDADOS ALTERADOS\n\n"); // ALTERA DADOS
    altera(pe); // FUNÇÃO ALTERA A ALTURA DE UMA DAS PESSOAS


    system("pause");
    return 0;
}
