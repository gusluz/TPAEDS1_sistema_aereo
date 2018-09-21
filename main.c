#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "tadMatrizDeVoo.h"

//Protótipos dos subprogramdas contidos no programa principal
void selecionaModo();
void menuSistema();
void modoInterativo();
void modoArquivo();
int geraVID();

/**
 * Função para gerar números aleatórios entre 0 e 100
 * @return int número aleatório
 */
int geraVID() {
    return (0 + rand() % (100 + 1 - 0));
}

/**
 * Função que imprime o menu do sistema
 */
void menuSistema() {
    printf("\n\n****************************************  MENU  ******************************************\n\n");
    printf("a) Inicializar Matriz\nb) Inserir Voo\nc) Remover Voo\nd) Procurar Voo\ne) Imprimir Voos (Decolagem e Pouso)\n");
    printf("f) Imprimir Voos(Decolagem)\ng) Imprimir Voos(Pouso)\nh) Imprimir Matriz\n");
    printf("i) Encontrar faixa de horário de decolagem e previsão de pouso\ncom maior número de voos cadastrados\n");
    printf("j) Encontrar faixa de horário de decolagem e previsão de pouso\ncom menor número  voos cadastrados\n");
    printf("k) Encontrar lista de voos mais recentemente alterada\n");
    printf("l) Encontrar lista de voos menos recentemente alterada\n");
    printf("m) Verificar se matriz é esparça\n");
}

/**
 * Função para selecionar o modo de utilização do sistema (1 para interativo e 2 para arquivo)
 * @return int
 */
void selecionaModo() {
    printf("------------------------------------------------------------------------------------------\n");
    printf("|                                 SISTEMA AEREO UFV-CAF                                  |\n");
    printf("------------------------------------------------------------------------------------------\n");
    int opcaoModo = 0;
    while (opcaoModo != 1 || opcaoModo != 2) {
        printf("Selecione um modo de utilização do sistema (1 - interativo e 2 - arquivo): ");
        scanf("%d", &opcaoModo);
        switch (opcaoModo) {
            case 1:
                printf("------------------------------------------------------------------------------------------\n");
                printf("|                                  BEM-VINDO AO SISTEMA                                  |\n");
                printf("------------------------------------------------------------------------------------------");
                modoInterativo();
                break;
            case 2:
                modoArquivo();
                break;
            default:
                printf("Inválido\n");
                break;
        }
    }
}

/**
 * Função do modo interativo. Se s for digitado o programa é encerrado.
 * Um switch é responsável pela execução de função dependendo da escolha no menu
 */
void modoInterativo() {
    tadMatrizDeVoo matrizDeVoo;
    tadVoo voo, vooBusca;
    inicializa(&voo);
    inicializa(&vooBusca);
    inicializarTadMatrizDeVoo(&matrizDeVoo);
    int pistaD, sair = 0, erroInsere, erroRemove, erroBusca, vidRemove, vidBusca, mEsparca;
    char letra, horaD[6], horaP[6], aeroportoD[6], aeroportoP[6];
    menuSistema();
    while (sair == 0) {
        getchar();
        printf("O que você deseja: ");
        scanf("%c", &letra);
        switch (letra) {
            case 'a':
                inicializarTadMatrizDeVoo(&matrizDeVoo);
                printf("Matriz inicializada com sucesso!");
                menuSistema();
                break;
            case 'b':
                printf("Entre com os dados do vôo: \nHora de Decolagem: ");
                scanf("%s", horaD);
                printf("Hora de previsão de pouso: ");
                scanf("%s", horaP);
                printf("Aeroporto de decolagem: ");
                scanf("%s", aeroportoD);
                printf("Aeroporto de previsão de pouso: ");
                scanf("%s", aeroportoP);
                printf("Pista de Decolagem: ");
                scanf("%d", &pistaD);
                setVid(&voo, geraVID());
                setHrDecolagem(&voo, horaD);
                setHrPrevPouso(&voo, horaP);
                setAeroportoDecolagem(&voo, aeroportoD);
                setAeroportoPrevPouso(&voo, aeroportoP);
                setPistaDecolagem(&voo, pistaD);
                erroInsere = insereVooMatriz(&matrizDeVoo, voo);
                if (!erroInsere) printf("Voo %d inserido!\n", getVid(&voo));
                menuSistema();
                break;
            case 'c':
                printf("Entre com o VID a ser removido: ");
                scanf("%d", &vidRemove);
                erroRemove = removeVooMatriz(&matrizDeVoo, vidRemove);
                if (erroRemove) printf("Voo %d Removido\n", vidRemove);
                else printf("Voo %d não encontrado!\n", vidRemove);
                menuSistema();
                break;
            case 'd':
                printf("Entre com o VID a ser procurado: ");
                scanf("%d", &vidBusca);
                erroBusca = procuraVooMatriz(&matrizDeVoo, vidBusca, &vooBusca);
                if (erroBusca) printf("Voo não encontrado!\n");
                menuSistema();
                break;
            case 'e':
                printf("Entre com a hora de decolagem: ");
                scanf("%s", horaD);
                printf("Entre com a hora de previsão de pouso: ");
                scanf("%s", horaP);
                imprimeVoosHrDHrP(&matrizDeVoo, horaD, horaP);
                menuSistema();
                break;
            case 'f':
                printf("Entre com a hora de decolagem: ");
                scanf("%s", horaD);
                imprimeVoosHrD(&matrizDeVoo, horaD);
                menuSistema();
                break;
            case 'g':
                printf("Entre com a hora de previsão de pouso: ");
                scanf("%s", horaP);
                imprimeVoosHrP(&matrizDeVoo, horaP);
                menuSistema();
                break;
            case 'h':
                imprimeMatriz(&matrizDeVoo);
                menuSistema();
                break;
            case 'i':
                maiorNumVoos(&matrizDeVoo);
                menuSistema();
                break;
            case 'j':
                menorNumVoos(&matrizDeVoo);
                menuSistema();
                break;
            case 'k':
                lAlteradaRecente(&matrizDeVoo);
                menuSistema();
                break;
            case 'l':
                lAlteradaNRecente(&matrizDeVoo);
                menuSistema();
                break;
            case 'm':
                mEsparca = esparca(&matrizDeVoo);
                if (mEsparca) printf("É esparça!\n");
                else printf("Não é esparça!\n");
                menuSistema();
                break;
            case 's':
                sair = 1;
                exit(0);
                break;
            default:
                printf("Inválido!");
                menuSistema();
                break;
        }
    }
}

/**
 * Função do modo arquivo. Se s for encontrado no arquivo, o programa é encerrado.
 * Um switch é responsável pela execução de função dependendo da escolha no menu
 */
void modoArquivo() {
    tadMatrizDeVoo matrizVoo;
    tadVoo voo, vooBusca;
    inicializa(&voo);
    inicializa(&vooBusca);
    inicializarTadMatrizDeVoo(&matrizVoo);
    char horaD[6], horaP[6], aeroportoD[6], aeroportoP[6];
    int pistaD, sair = 0, erroInsere, erroRemove, erroBusca, vidRemove, vidBusca, mEsparca;
    char opcao;
    char nomeArquivo[50];
    char buffer[255];
    FILE *arquivo = NULL; // Arquivo TXT lido
    printf("Entre o caminho do arquivo, com extensão: ");
    scanf(" %s", nomeArquivo);
    arquivo = fopen(nomeArquivo, "rt");
    if (arquivo == NULL) {
        printf("O arquivo %s não existe. Encerrando a execução. \n", nomeArquivo);
        exit(0);
    }
    while ((fscanf(arquivo, "%s", buffer)) != EOF) {
        fflush(arquivo);
        if (!feof(arquivo)) {
            fflush(arquivo);
            opcao = buffer[0];
            switch (opcao) {
                case 'a':
                    inicializarTadMatrizDeVoo(&matrizVoo);
                    printf("Matriz inicializada com sucesso!\n");
                    break;
                case 'b':
                    fscanf(arquivo, "%s", horaD);
                    fscanf(arquivo, "%s", horaP);
                    fscanf(arquivo, "%s", aeroportoD);
                    fscanf(arquivo, "%s", aeroportoP);
                    fscanf(arquivo, "%d", &pistaD);
                    setVid(&voo, geraVID());
                    setHrDecolagem(&voo, horaD);
                    setHrPrevPouso(&voo, horaP);
                    setAeroportoDecolagem(&voo, aeroportoD);
                    setAeroportoPrevPouso(&voo, aeroportoP);
                    setPistaDecolagem(&voo, pistaD);
                    erroInsere = insereVooMatriz(&matrizVoo, voo);
                    if (!erroInsere) printf("Voo %d inserido!\n", getVid(&voo));
                    break;
                case 'c':
                    fscanf(arquivo, "%d", &vidRemove);
                    erroRemove = removeVooMatriz(&matrizVoo, vidRemove);
                    if (!erroRemove) printf("Voo %d Removido\n", vidRemove);
                    else printf("Voo %d não encontrado!\n", vidRemove);
                    break;
                case 'd':
                    fscanf(arquivo, "%d", &vidBusca);
                    erroBusca = procuraVooMatriz(&matrizVoo, vidBusca, &vooBusca);
                    if (erroBusca) printf("Voo %d não encontrado!\n", vidBusca);
                    break;
                case 'e':
                    fscanf(arquivo, "%s", horaD);
                    fscanf(arquivo, "%s", horaP);
                    printf("\n********** VOOS COM HORÁRIO DE DECOLAGEM %s E HORÁRIO DE POUSO %s **********\n", horaD, horaP);
                    imprimeVoosHrDHrP(&matrizVoo, horaD, horaP);
                    printf("\n");
                    break;
                case 'f':
                    fscanf(arquivo, "%s", horaD);
                    printf("\n*************** VOOS COM HORÁRIO DE DECOLAGEM %s ***************\n", horaD);
                    imprimeVoosHrD(&matrizVoo, horaD);
                    printf("\n\n\n");
                    break;
                case 'g':
                    fscanf(arquivo, "%s", horaP);
                    printf("\n*************** VOOS COM HORÁRIO DE POUSO %s ***************\n", horaP);
                    imprimeVoosHrP(&matrizVoo, horaP);
                    break;
                case 'h':
                    printf("\n********** IMPRIMINDO MATRIZ DE VOOS **********\n");
                    imprimeMatriz(&matrizVoo);
                    break;
                case 'i':
                    printf("\n********** INFORMAÇÕES DA MATRIZ COM MAIOR NÚMERO DE VOOS **********\n");
                    maiorNumVoos(&matrizVoo);
                    break;
                case 'j':
                    printf("\n********** INFORMAÇÕES DA MATRIZ COM MENOR NÚMERO DE VOOS **********\n");
                    menorNumVoos(&matrizVoo);
                    break;
                case 'k':
                    printf("\n********** INFORMAÇÕES DA MATRIZ RECENTEMENTE ALTERADA **********\n");
                    lAlteradaRecente(&matrizVoo);
                    break;
                case 'l':
                    printf("\n********** INFORMAÇÕES DA MATRIZ MENOS RECENTEMENTE ALTERADA **********\n");
                    lAlteradaNRecente(&matrizVoo);
                    break;
                case 'm':
                    printf("\n********** VERIFICANDO SE A MATRIZ É ESPARÇA **********\n");
                    mEsparca = esparca(&matrizVoo);
                    if (mEsparca) printf("É esparça!\n");
                    else printf("Não é esparça!\n");
                    break;
                case 's':
                    sair = 1;
                    exit(0);
                    break;
            }
        }

    }
    fclose(arquivo);
}

int main() {
    srand(time(NULL));
    selecionaModo();
    return 0;
}