#include<stdio.h>
#include<stdlib.h>

typedef struct Lista{
    int num;
    struct Lista*prox;
}Lista;

/*INICIALIZA A LISTA*/
Lista* cria_lista () {
    return NULL;
}

/*FUNÇÃO INSERIR INTEIROS NA LISTA*/
Lista* inserir(int val, Lista*L1){

   Lista* novo = (Lista*)malloc(sizeof(Lista));
   novo->num = val;
   novo->prox = L1;

    return novo;

}
/*NUMEROS SOLICITADOS E ADICIONADOS NAS LISTAS*/
Lista* solicitacao_dos_num(Lista*L1){
	
    int num = 0;
    
    while(1){
        printf("Digite um numero: (-1 para sair)\n");
        scanf("%d", &num);
        if(num == -1){
            break;
        }
        L1 = inserir(num,L1);
    }
    return L1;

}

/*FUNÇÃO PARA LIBERAR A MEMORIA*/
void lst_libera (Lista*L1)
{
    Lista* p = L1;
    Lista* t=NULL;
    while (p != NULL) {
        t = p->prox; /* guarda referência p/ próx. elemento */
        free(p); /* libera a memória apontada por p */
        p = t; /* faz p apontar para o próximo */
    }
}

/*INVERSO E CONCATENÇÃO DAS LISTAS*/
Lista* concatena(Lista* L1,Lista*L2){

    /*LISTA 1 INVERSA*/
    Lista *nova = cria_lista();
    Lista *p = L1; /*LISTA AUXILIAR*/
    while(p != NULL){
        nova = inserir(p->num,nova); /*FUNÇÃO CRIAR E INSERIR LISTA INVERSA*/
        p = p -> prox; 
    }

	lst_libera(p); 
	
    /*LISTA INVERSA 2*/
    Lista *nova2 = cria_lista();
    Lista *p2 = L2; /*LISTA AUXILIAR*/
    while(p2 != NULL){
        nova2 = inserir(p2->num,nova2); /*FUNÇÃO CRIAR E INSERIR LISTA INVERSA*/
        p2 = p2 -> prox;
    }
     
	lst_libera(p2);
	
	
    Lista* aux1=cria_lista(); /*LISTA AUXILIAR 1*/
    Lista* aux2=cria_lista(); /*lISTA AUXILIAR 2*/

    if(nova2 == NULL){
        return nova;
	}
    aux1 = nova2;
    do{
        aux2 = aux1;
        aux1 = aux1->prox;
        
    }while(aux1 != NULL);
	
    aux2 ->prox = nova;
    
	return nova2;
	
	lst_libera(nova);
	lst_libera(nova2);
	lst_libera(aux1);
	lst_libera(aux2);
	
}

 /*IMPRESSAO DAS LISTAS*/
 void imprimir_lista(Lista* L1){
    Lista* aux = L1;
    while(aux != NULL){
        printf("%d ", aux->num);
        aux = aux -> prox;
    }
}

/*FUNÇÃO PRINCIPAL*/

int main()
{
    Lista * L1 = cria_lista();   /*LISTA 1*/
    Lista *L2 = cria_lista();   /*LISTA 2*/
    Lista * L3 = cria_lista(); /*LISTA 3*/


    printf("LISTA 1:\n\n");
    L1=solicitacao_dos_num(L1);

    printf("\nLISTA 2: \n\n");
    L2=solicitacao_dos_num(L2);

    printf("\nLista 1: \n");
    imprimir_lista(L1);
    printf("\n");

    printf("\nLista 2: \n");
    imprimir_lista(L2);
    printf("\n");

    printf("\nLista 1 concatenada c/ a lista 2: \n");
    L3 = concatena(L1,L2);
    imprimir_lista(L3);
    printf("\n");

    lst_libera(L1);
    lst_libera(L2);
    lst_libera(L3);


    return 0;

}
