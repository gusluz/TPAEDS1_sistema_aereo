#include <stdio.h>
#include <stdlib.h>
#include "tadMatrizDeVoo.h"

void inicializarTadMatrizDeVoo(tadMatrizDeVoo* matrizDeVoo) {
    for (int k = 0; k < 24; k++) {
        for (int l = 0; l < 24; l++) {
            inicializarTadItemMatriz(&(matrizDeVoo->matrizVoos[k][l]));
        }
    }
    matrizDeVoo->numTotVoos = 0;
    matrizDeVoo->atualizacaoHorario[0] = '\0';
    matrizDeVoo->data[0] = '\0';
}

int insereVooMatriz(tadMatrizDeVoo* matrizDeVoo, tadVoo voo) {
    int erroInsere, horaDecolagem, horaPrevPouso;
    tadListaVoo listaVoo;
    fazListaVazia(&listaVoo);
    erroInsere = insereVoo(voo, &listaVoo);
    if (!erroInsere) {
        horaDecolagem = converteHoras(voo.hrDecolagem);
        horaPrevPouso = converteHoras(voo.hrPrevPouso);
        matrizDeVoo->matrizVoos[horaDecolagem][horaPrevPouso].listaVoo = listaVoo;
        matrizDeVoo->matrizVoos[horaDecolagem][horaPrevPouso].numVoos++;
        matrizDeVoo->numTotVoos++;
    }
    return 0;
}

int converteHoras(char horario[]) {
    int horas;
    for (int i = 0; i < 6; i++) {
        horario[i] = horario[i] - 48;
    }
    horas = (horario[0] * 10) + horario[1];
    return horas;
}