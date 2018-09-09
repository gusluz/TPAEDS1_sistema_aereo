#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadVoo.c"
#include "tadListaDeVoo.c"

int main() {
    tadVoo voo, *voo1 = NULL;
    tadListaVoo listaVoo, *plistaVoo = NULL;
    voo1 = &voo;
    plistaVoo = &listaVoo;
    char horaD[5];
    char horaP[5];
    inicializa(voo1);
    printf("VID: %d\n", getVid(voo1));
    printf("HD: %s\n", getHrDecolagem(voo1));
    printf("HP: %s\n", getHrPrevPouso(voo1));
    printf("AD: %s\n", getAeroportoDecolagem(voo1));
    printf("AP: %s\n", getAeroportoPrevPouso(voo1));
    printf("Pista: %d\n", getPistaDecolagem(voo1));
    fazListaVazia(&listaVoo);
    if(vazia(listaVoo)) printf("Lista Vazia!\n");
    setVid(voo1, rand());
    setHrDecolagem(voo1, "13:30\0");
    setHrPrevPouso(voo1, "15:30\0");
    setAeroportoDecolagem(voo1, "AEP\0");
    setAeroportoPrevPouso(voo1, "PEA\0");
    setPistaDecolagem(voo1, 1);
    if(!insereVoo(voo, &listaVoo)){
        printf("Inserido\n");
    }
    imprimeVoo(listaVoo);
    return 0;
}