#include <stdio.h>
#include <stdlib.h>
#include "tadItemMatriz.h"
#define TAMMATRIZ 24

typedef struct {
    tadItemMatriz matrizVoos[TAMMATRIZ][TAMMATRIZ];
    char data[11];
    int numTotVoos;
    char atualizacaoHorario[6];
} tadMatrizDeVoo;

void inicializarTadMatrizDeVoo(tadMatrizDeVoo* matrizDeVoo);
int insereVooMatriz(tadMatrizDeVoo* matrizDeVoo, tadVoo voo);
int converteHoras(char horario[]);
