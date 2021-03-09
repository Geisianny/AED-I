#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int valor;
    struct no*prox;
}no;

/*Funcao inserir inteiros na lista*/

no* inserir(int val, no* lista){
    no* aux = lista; /*inicializa aux com o primeiro da lista*/
    no* ant = NULL; /*inicializa ant com NULL*/
    no* novo = (no*)malloc(sizeof(no));
    novo-> valor = val;

    while(aux != NULL && (aux->valor < novo->valor)){
        ant = aux;
        aux = aux->prox;
    }
    novo->prox = aux;
    if(ant != NULL){
        ant->prox = novo;
    } else{
        lista = novo;
    }
    return lista;


}
void imprimir_lista(no* lista){
    no* aux = lista;
    while(aux != NULL){
        printf("%d ", aux->valor);
        aux = aux -> prox;
    }
}

void lst_libera (no*lista)
{
    no* p = lista;
    no* t;
    while (p != NULL) {
        t = p->prox; /* guarda referência p/ próx. elemento */
        free(p); /* libera a memória apontada por p */
        p = t; /* faz p apontar para o próximo */
    }
}
int main ()
{
    int val;
    no* lista = NULL;
    while(1){
        scanf("%d",&val);
        lista = inserir(val,lista);
        imprimir_lista (lista);

   }
   lst_libera(lista);

   return 0;
}
