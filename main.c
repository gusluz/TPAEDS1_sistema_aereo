#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "tadMatrizDeVoo.h"

//Função para gerar números aleatórios
int geraVID(){
    return (rand()/1000000);
}

int main() {
    //Inicializando 3 voos para inserção de exemplo.
    //Exemplificando implementação de tadVoo e tadListaDeVoo
    tadVoo voo1, voo2, voo3, voo4, voobusca, voobusca2;
    tadListaVoo listaVoo;

    int erro1, erro2, erro3, erro4, errobusca; //Retorno de erros em inserção

    //Inicializando Voos
    inicializa(&voo1);
    inicializa(&voo2);
    inicializa(&voo3);
    inicializa(&voo4);
    inicializa(&voobusca);
    inicializa(&voobusca2);

    fazListaVazia(&listaVoo); //Inicializando lista

    //Verificando se a lista está vazia
    if(vazia(listaVoo)) printf("Lista Vazia!\n\n");

    //Todos os Set's abaixo estão setando informações nos 3 TADs de Voo.
    //Voo1
    setVid(&voo1, geraVID());
    setHrDecolagem(&voo1, "08:30\0");
    setHrPrevPouso(&voo1, "15:30\0");
    setAeroportoDecolagem(&voo1, "AEP\0");
    setAeroportoPrevPouso(&voo1, "PEA\0");
    setPistaDecolagem(&voo1, 1);


    //Voo2
    setVid(&voo2, geraVID());
    setHrDecolagem(&voo2, "14:00\0");
    setHrPrevPouso(&voo2, "20:30\0");
    setAeroportoDecolagem(&voo2, "PEA\0");
    setAeroportoPrevPouso(&voo2, "ARE\0");
    setPistaDecolagem(&voo2, 1);

    //Voo3
    setVid(&voo3, geraVID());
    setHrDecolagem(&voo3, "12:00\0");
    setHrPrevPouso(&voo3, "20:30\0");
    setAeroportoDecolagem(&voo3, "PEA\0");
    setAeroportoPrevPouso(&voo3, "ARE\0");
    setPistaDecolagem(&voo3, 1);

    //Voo4
    setVid(&voo4, geraVID());
    setHrDecolagem(&voo4, "12:00\0");
    setHrPrevPouso(&voo4, "14:30\0");
    setAeroportoDecolagem(&voo4, "PEA\0");
    setAeroportoPrevPouso(&voo4, "ARE\0");
    setPistaDecolagem(&voo4, 1);

    erro1 = insereVoo(voo1, &listaVoo);
    erro2 = insereVoo(voo2, &listaVoo);
    erro3 = insereVoo(voo3, &listaVoo);
    erro4 = insereVoo(voo4, &listaVoo);

    if(!erro1) printf("Voo1 inserido\n");
    if(!erro2) printf("Voo2 inserido\n");
    if(!erro3) printf("Voo3 inserido\n");
    if(!erro4) printf("Voo4 inserido\n\n");

    //Imprimindo Voos da Lista
    imprimeVoo(listaVoo);

    //Armazeno o retorno da minha busca por um voo (Reitei da lista)
    errobusca = retornaVoo(&listaVoo, 846, &voobusca);
    voobusca2 = procuraVoo(&listaVoo, 1804);

    printf("Item retirado da lista : -----------\n");
    printGets(&voobusca);

    printf("Item encontrado da lista: -----------\n");
    printGets(&voobusca2);
    //Imprimindo Voos da Lista
    imprimeVoo(listaVoo);

    return 0;
}
