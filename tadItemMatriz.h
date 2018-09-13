#include <stdio.h>
#include <stdlib.h>
#include "tadListaDeVoo.h"

typedef struct {
    tadListaVoo listaVoo;
    int numVoos;
    char horarioAtualizacao[6];
} tadItemMatriz;

void inicializarTadItemMatriz(tadItemMatriz *itemMatriz);

//GETs
//Retorna a lista de Voo
tadListaVoo getListaVoo(tadItemMatriz *itemMatriz);
//Retorna o número de voos
int getNumVoos(tadItemMatriz *itemMatriz);
//Retorna o horário da última atualização
char* getHorarioAtualizacao(tadItemMatriz *itemMatriz);

//SETs
//Seta a lista de voo e retorna 0 caso obteve sucesso
int setListaVoo(tadItemMatriz *itemMatriz, tadListaVoo listaVoo);
//Seta número de voos e retorna 0 caso obteve sucesso
int setNumVoos(tadItemMatriz *itemMatriz, int numVoos);
//Seta o horário da atualização de voo e retorna 0 caso obteve sucesso
int setHorarioAtualizacao(tadItemMatriz *itemMatriz, char horaAtualizacao[]);
