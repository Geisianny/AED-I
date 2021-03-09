#include<stdio.h>
#include<stdlib.h>
struct lista{
    int info;
    struct lista* prox;
};typedef struct lista Lista;

/* fun��o de inicializa��o: retorna uma lista vazia */
 Lista* inicializa (void){
    return NULL;
 }

 /* inser��o no in�cio: retorna a lista atualizada */
Lista* insere (Lista* l,int i){
    Lista* novo = (Lista*)malloc (sizeof (Lista));
    novo -> info = i;
    novo -> prox = l;
    printf("\n");
    return novo;
}
/* imprime valores dos elementos*/
void imprime (Lista* l){
    Lista*p; //vari�vel auxiliar para percorrer a lista
    for (p = l; p != NULL; p = p->prox){
        printf("info = %d\n", p->info);
    }
}
/* busca um elemento na lista*/
Lista* busca (Lista* l,int v){
    Lista*p; //vari�vel auxiliar para percorrer a lista
    for (p = l; p != NULL; p = p-> prox){
        if(p -> info == v){
            return p;
        }
    }
    return NULL; //N�o achou o elemento
}
void libera (Lista* l){
    Lista* p = l;
    while(p != NULL){
        Lista* t = p->prox ; /* guarda refer�ncia para o pr�ximo elemento */
        free(p); /* libera a mem�ria apontada por p*/
        p = t; /* faz p apontar para o pr�ximo */
    }
}
/* fun��o retira: retira elemento da lista */
Lista* retira (Lista* l,int v) {
    Lista* ant = NULL;
    Lista* p = l; /* procura elemento na lista, guardando anterior */
    while(p != NULL && p-> info != v){
        ant = p;
        p = p -> prox;
    } /* verifica se achou elemento */
    if(p == NULL){
        return l; /* n�o achou: retorna lista original */
    }
    if (ant == NULL) { /* retira elemento
    /* retira elemento do inicio */
        l = p ->prox;
    }
    else{ /* retira elemento do meio da lista*/
        ant ->prox = p-> prox;
    }
    free(p);
    return l;
}

int main()
{
    int v = 9;
    Lista * lista;

    inicializa();
    insere(lista,v);
    imprime(lista);
    return 0;
}
