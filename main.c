#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadVoo.c"
#include "tadListaDeVoo.c"

int main() {
    tadVoo voo1, voo2, voo3, retorno;
    tadListaVoo listaVoo;
    int erro1, erro2, erro3;
    inicializa(&voo1);
    inicializa(&voo2);
    inicializa(&voo3);
    fazListaVazia(&listaVoo);
    if(vazia(listaVoo)) printf("Lista Vazia!\n");
    setVid(&voo1, rand());
    setHrDecolagem(&voo1, "13:30\0");
    setHrPrevPouso(&voo1, "15:30\0");
    setAeroportoDecolagem(&voo1, "AEP\0");
    setAeroportoPrevPouso(&voo1, "PEA\0");
    setPistaDecolagem(&voo1, 1);
    setVid(&voo2, rand());
    setHrDecolagem(&voo2, "14:00\0");
    setHrPrevPouso(&voo2, "20:30\0");
    setAeroportoDecolagem(&voo2, "PEA\0");
    setAeroportoPrevPouso(&voo2, "ARE\0");
    setPistaDecolagem(&voo2, 1);
    setVid(&voo3, rand());
    setHrDecolagem(&voo3, "12:00\0");
    setHrPrevPouso(&voo3, "20:30\0");
    setAeroportoDecolagem(&voo3, "PEA\0");
    setAeroportoPrevPouso(&voo3, "ARE\0");
    setPistaDecolagem(&voo3, 1);
    erro1 = insereVoo(voo1, &listaVoo);
    erro2 = insereVoo(voo2, &listaVoo);
    erro3 = insereVoo(voo3, &listaVoo);
    imprimeVoo(listaVoo);
    printf("\n\n\n\n\n");
    retorno = retornaVoo(&listaVoo, 1681692777);
    printf("%d\n", retorno.vid);
    printf("\n\n\n\n\n");
    imprimeVoo(listaVoo);
    retorno = procuraVoo(&listaVoo, 846930886);
    printf("\n\n\n\n\n");
    printf("%d\n", retorno.vid);
    printf("\n\n\n\n\n");
    imprimeVoo(listaVoo);
    return 0;
}