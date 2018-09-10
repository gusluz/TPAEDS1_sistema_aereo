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

void imprimeVoo(tadListaVoo listaVoo){
    tipoApontador aux;
    aux = listaVoo.primeiro->prox;
    while(aux != NULL){
        printf("%d\n", getVid(&aux->voo));
        printf("%s\n", getHrDecolagem(&aux->voo));
        printf("%s\n", getHrPrevPouso(&aux->voo));
        printf("%s\n", getAeroportoDecolagem(&aux->voo));
        printf("%s\n", getAeroportoPrevPouso(&aux->voo));
        printf("%d\n", getPistaDecolagem(&aux->voo));
        aux = aux->prox;
    }
}

int insereVoo(tadVoo voo, tadListaVoo* listaVoo){
    tipoApontador aux, i;
    aux = listaVoo->primeiro;
    while(aux->prox != NULL && strcmp(aux->prox->voo.hrDecolagem, voo.hrDecolagem) < 0)
    {
        aux = aux->prox;
    }
    i = (tipoApontador) malloc(sizeof(tipoCelula));
    i->voo = voo;
    i->prox = aux->prox;
    aux->prox = i;
    return 0;
}

tadVoo retornaVoo(tadListaVoo* listaVoo, int vid){
    tipoApontador i, aux;
    tadVoo voo, *voo1 = NULL;
    voo1 = &voo;
    aux = listaVoo->primeiro;
    while(aux->prox != NULL && aux->prox->voo.vid != vid){
        aux = aux->prox;
    }
    i = aux->prox;
    *voo1 = i->voo;
    aux->prox = i->prox;
    if(aux->prox == NULL) listaVoo->ultimo = aux;
    free(i);
    return voo;
}

tadVoo procuraVoo(tadListaVoo* listaVoo, int vid){
    tipoApontador i, aux;
    aux = listaVoo->primeiro;
    while(aux->prox != NULL && aux->prox->voo.vid != vid){
        aux = aux->prox;
    }
    return aux->prox->voo;
}