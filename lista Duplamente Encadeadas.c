#include<Stdio.h>
#include<stdlib.h>

struct lista{
    int info;
    struct lista* ant;
    struct lista* prox;
};typedef struct lista Lista;

Lista*lst_insere (Lista* l, int i){
    Lista* novo = (Lista*)malloc (sizeof (Lista));
    novo -> info = i;
    novo -> prox = l;
    novo -> ant = NULL;
    if(l != NULL) //Verifica se a lista estava vazia
        l ->ant = novo;
    return novo;
}

Lista*lst_retira (Lista* l, int i){
    Lista* p = lst_busca (l, i); //procura o elemento; //procura o elemento
    if(p == NULL) //não encontrou o elemento
        return l;
    if(l == p)
        l = p -> prox ; // testa se é o primeiro elemento
    else
        p -> ant -> prox = p-> prox;
    if(p -> prox != NULL) //verifica se é o último elemento
       p -> prox -> ant = p-> ant;
    free(p);
    return l;
}
int main()
{
    int v = 9;
    Lista * lista;
    lst_insere(lista,v);
    return 0;
}
