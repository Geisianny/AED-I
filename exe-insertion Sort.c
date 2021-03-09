#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    struct no* prox;
    struct no* ant;
    int valor;
} no;

void insertion_sort(no* l){
    no* aux;
    no* aux_i;
    int key;
    if(l!=NULL){
        for(aux=l->prox; aux!=NULL; aux=aux->prox){ //começando do segundo elem ate o ultimo
            key = aux->valor;
            aux_i = aux->ant;
            while((aux_i != NULL) && (aux_i->valor > key)){
                aux_i->prox->valor = aux_i->valor;
                aux_i = aux_i->ant;
            }
            if(aux_i == NULL){
                l->valor = key;
            }
            else{
                aux_i->prox->valor = key;
            }
        }
    }
}

no* inserir_ini(no* l, int valor){
    no* novo = (no*)malloc(sizeof(no));
    novo->valor = valor;
    novo->ant = NULL;
    novo->prox = l;
    if(l!=NULL){
        l->ant = novo;
    }
    return novo;
}

void liberar_memoria(no* l){
    no* aux;
    while(l!=NULL){
        aux = l->prox;
        free(l);
        l = aux;
    }
}

void imprimir(no* l){
    no* aux;
    printf("\n");
    for(aux=l; aux!=NULL; aux=aux->prox){
        printf("%d ", aux->valor);
    }
}

int main(){
    int v;
    no* lista = NULL;
    do{
       printf("proximo valor:\n");
       scanf("%d", &v);
       lista = inserir_ini(lista, v);
       imprimir(lista);
       insertion_sort(lista);
       imprimir(lista);
    }while(v!=-1);
    liberar_memoria(lista);
}
