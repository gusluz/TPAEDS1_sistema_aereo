#include <stdlib.h>
#include <stdio.h>
#include "tadListaDeVoo.h"

void fazListaVazia(tadListaVoo* listaVoo){
    listaVoo->primeiro = (tipoApontador) malloc(sizeof(tipoCelula));
    listaVoo->ultimo = listaVoo->primeiro;
    listaVoo->primeiro->prox = NULL;
}
int vazia(tadListaVoo listaVoo){
    return (listaVoo.primeiro == listaVoo.ultimo);
}
int insereVoo(tadVoo voo, tadListaVoo *listaVoo){
    listaVoo->ultimo->prox = (tipoApontador) malloc(sizeof(tipoCelula));
    listaVoo->ultimo = listaVoo->ultimo->prox;
    listaVoo->ultimo->voo = voo;
    listaVoo->ultimo->prox = NULL;
    return 0;
}
void imprimeVoo(tadListaVoo listaVoo){
    tipoApontador aux;
    aux = listaVoo.primeiro->prox;
    while(aux != NULL){
        printf("%d\n", aux->voo.vid);
        printf("%s\n", aux->voo.hrDecolagem);
        printf("%s\n", aux->voo.hrPrevPouso);
        printf("%s\n", aux->voo.aeroportoDecolagem);
        printf("%s\n", aux->voo.aeroportoPrevPouso);
        printf("%d\n", aux->voo.pistaDecolagem);
        aux = aux->prox;
    }
}