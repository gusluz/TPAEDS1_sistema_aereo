#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadListaDeVoo.h"

int main() {
    //Inicializando 3 voos para inserção de exemplo.
    //Exemplificando implementação de tadVoo e tadListaDeVoo
    tadVoo voo1, voo2, voo3;
    tadListaVoo listaVoo;

    int erro1, erro2, erro3; //Retorno de erros em inserção

    //Inicializando Voos
    inicializa(&voo1);
    inicializa(&voo2);
    inicializa(&voo3);

    fazListaVazia(&listaVoo); //Inicializando lista

    //Verificando se a lista está vazia
    if(vazia(listaVoo)) printf("Lista Vazia!\n\n");

    //Todos os Set's abaixo estão setando informações nos 3 TADs de Voo.
    //Voo1
    setVid(&voo1, rand());
    setHrDecolagem(&voo1, "13:30\0");
    setHrPrevPouso(&voo1, "15:30\0");
    setAeroportoDecolagem(&voo1, "AEP\0");
    setAeroportoPrevPouso(&voo1, "PEA\0");
    setPistaDecolagem(&voo1, 1);

    //Voo2
    setVid(&voo2, rand());
    setHrDecolagem(&voo2, "14:00\0");
    setHrPrevPouso(&voo2, "20:30\0");
    setAeroportoDecolagem(&voo2, "PEA\0");
    setAeroportoPrevPouso(&voo2, "ARE\0");
    setPistaDecolagem(&voo2, 1);

    //Voo3
    setVid(&voo3, rand());
    setHrDecolagem(&voo3, "12:00\0");
    setHrPrevPouso(&voo3, "20:30\0");
    setAeroportoDecolagem(&voo3, "PEA\0");
    setAeroportoPrevPouso(&voo3, "ARE\0");
    setPistaDecolagem(&voo3, 1);
    erro1 = insereVoo(voo1, &listaVoo);
    erro2 = insereVoo(voo2, &listaVoo);
    erro3 = insereVoo(voo3, &listaVoo);
    if(!erro1) printf("Voo1 inserido\n");
    if(!erro2) printf("Voo2 inserido\n");
    if(!erro3) printf("Voo3 inserido\n\n");

    //Imprimindo Voos da Lista
    imprimeVoo(listaVoo);
    return 0;
}
