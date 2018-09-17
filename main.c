#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "tadMatrizDeVoo.h"

int selecionaModo();
void menuSistema();
void modoInterativo();
void modoArquivo();

//Função para gerar números aleatórios

int geraVID() {
    return (rand() / 1000000);
}

void menuSistema() {
    printf("\n\n********************************\n");
    printf("***** BEM-VINDO AO SISTEMA *****\n");
    printf("********************************\n\n");
    printf("a) Inicializar Matriz\nb) Inserir Voo\nc) Remover Voo\nd) Procurar Voo\ne) Imprimir Voos (Decolagem e Pouso)\n");
    printf("f) Imprimir Voos(Decolagem)\ng) Imprimir Voos(Pouso)\nh) Imprimir Matriz\n");
    printf("i) Encontrar faixa de horário de decolagem e previsão de pouso\ncom maior número de voos cadastrados\n");
    printf("j) Encontrar faixa de horário de decolagem e previsão de pouso\ncom menor número de voos cadastrados\n");
    printf("k) Encontrar lista de voos mais recentemente alterada\n");
    printf("l) Encontrar lista de voos menos recentemente alterada\n");
    printf("m) Verificar se matriz é esparça\n");
}

//Função para selecionar opção de utilização do sistema

int selecionaModo() {
    int opcaoModo;
    printf("Selecione um modo de utilização do sistema (1 - interativo e 2 - arquivo): ");
    scanf("%d", &opcaoModo);
    if (opcaoModo == 1) {
        modoInterativo();
    } else if (opcaoModo == 2) {
        modoArquivo();
    } else {
        return 1;
    }
    return 0;
}

void modoInterativo() {
    tadMatrizDeVoo matrizDeVoo;
    char letra;
    menuSistema();
    printf("O que você deseja: ");
    scanf("%c", &letra);
    switch(letra){
        case 'a':
            inicializarTadMatrizDeVoo(&matrizDeVoo);
            break;
    }
    //    while(){
    //
    //    }
}

void modoArquivo() {
    tadMatrizDeVoo matrizDeVoo;
    FILE *arquivo;
    char frase[30];
    char opcao, caminho[50], hrDecolagem[6], hrPrevPouso[6], aeDecolagem[6], aePrevPouso[6];
    int pista;
    printf("Entre com o nome e caminho 2do arquivo: ");
    scanf("%s", &caminho);
    arquivo = fopen(caminho, "r");
    if (arquivo == NULL) {
        printf("Arquivo não encontrado!");
    }
    while (!feof(arquivo)) {
        fgets(frase, 30, arquivo);
        opcao = frase[0];
        switch(opcao){
            case 'a':
                inicializarTadMatrizDeVoo(&matrizDeVoo);
                break;
            case 'b':
                //inserir voo
                break;
        }
    }

    fclose(arquivo);
}

int main() {
    int erroModo;
    //MAIN SISTEMA DE TESTE
    printf("SISTEMA AÉREO UFV-CAF v1.0b\n****************\n");
    erroModo = selecionaModo();
    while (erroModo) {
        printf("Esse modo é inválido! Tente novamente!\n");
        erroModo = selecionaModo();
    }
//
//    //Inicializando 3 voos para inserção de exemplo.
//    //Exemplificando implementação de tadVoo e tadListaDeVoo
//    tadVoo voo1, voo2, voo3, voo4, voo5, voobusca, voobusca2;
//    tadListaVoo listaVoo;
//    tadItemMatriz itemMatriz;
//    tadMatrizDeVoo matrizDeVoo;
//    int erro1, erro2, erro3, erro4, errobusca; //Retorno de erros em inserção
//
//    //Inicializando Voos
//    inicializa(&voo1);
//    inicializa(&voo2);
//    inicializa(&voo3);
//    inicializa(&voo4);
//    inicializa(&voo5);
//    inicializa(&voobusca);
//    inicializa(&voobusca2);
//
//    fazListaVazia(&listaVoo); //Inicializando lista
//
//    //Verificando se a lista está vazia
//    if(vazia(listaVoo)) printf("Lista Vazia!\n\n");
//
//    //Todos os Set's abaixo estão setando informações nos 3 TADs de Voo.
//    //Voo1
//    setVid(&voo1, geraVID());
//    setHrDecolagem(&voo1, "08:30\0");
//    setHrPrevPouso(&voo1, "15:30\0");
//    setAeroportoDecolagem(&voo1, "AEP\0");
//    setAeroportoPrevPouso(&voo1, "PEA\0");
//    setPistaDecolagem(&voo1, 1);
//
//
//    //Voo2
//    setVid(&voo2, geraVID());
//    setHrDecolagem(&voo2, "14:00\0");
//    setHrPrevPouso(&voo2, "20:30\0");
//    setAeroportoDecolagem(&voo2, "PEA\0");
//    setAeroportoPrevPouso(&voo2, "ARE\0");
//    setPistaDecolagem(&voo2, 1);
//
//    //Voo3
//    setVid(&voo3, geraVID());
//    setHrDecolagem(&voo3, "12:00\0");
//    setHrPrevPouso(&voo3, "20:30\0");
//    setAeroportoDecolagem(&voo3, "PEA\0");
//    setAeroportoPrevPouso(&voo3, "ARE\0");
//    setPistaDecolagem(&voo3, 1);
//
//    //Voo4
//    setVid(&voo4, geraVID());
//    setHrDecolagem(&voo4, "12:00\0");
//    setHrPrevPouso(&voo4, "14:30\0");
//    setAeroportoDecolagem(&voo4, "PEA\0");
//    setAeroportoPrevPouso(&voo4, "ARE\0");
//    setPistaDecolagem(&voo4, 1);
//
//    erro1 = insereVoo(voo1, &listaVoo);
//    erro2 = insereVoo(voo2, &listaVoo);
//    erro3 = insereVoo(voo3, &listaVoo);
//    erro4 = insereVoo(voo4, &listaVoo);
//
//    if(!erro1) printf("Voo1 inserido\n");
//    if(!erro2) printf("Voo2 inserido\n");
//    if(!erro3) printf("Voo3 inserido\n");
//    if(!erro4) printf("Voo4 inserido\n\n");
//
//    //Imprimindo Voos da Lista
//    imprimeVoo(listaVoo);
//
//    //Armazeno o retorno da minha busca por um voo (Reitei da lista)
//    errobusca = retornaVoo(&listaVoo, 846, &voobusca);
//    voobusca2 = procuraVoo(&listaVoo, 1804);
//
//    printf("Item retirado da lista : -----------\n");
//    imprimeGets(&voobusca);
//
//    printf("Item encontrado da lista: -----------\n");
//    imprimeGets(&voobusca2);
//    //Imprimindo Voos da Lista
//    imprimeVoo(listaVoo);
//    //Matriz
//    inicializarTadMatrizDeVoo(&matrizDeVoo);
//    //Voo5
//    setVid(&voo5, geraVID());
//    setHrDecolagem(&voo5, "07:30\0");
//    setHrPrevPouso(&voo5, "15:30\0");
//    setAeroportoDecolagem(&voo5, "AEP\0");
//    setAeroportoPrevPouso(&voo5, "PEA\0");
//    setPistaDecolagem(&voo5, 1);
//    insereVooMatriz(&matrizDeVoo, voo5);
//    for(int i=0;i<24;i++){
//        for(int j=0;j<24;j++){
//            imprimeVoo(matrizDeVoo.matrizVoos[i][j].listaVoo);
//        }
//    }
    return 0;
}
