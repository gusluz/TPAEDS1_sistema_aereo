#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include "tadItemMatriz.h"

void inicializarTadItemMatriz(tadItemMatriz *itemMatriz){
    fazListaVazia(&itemMatriz->listaVoo);
    itemMatriz->numVoos = 0;
    itemMatriz->horarioAtualizacao[0] = '\0';
}

//GETs
//Retorna a lista de Voo
tadListaVoo getListaVoo(tadItemMatriz *itemMatriz){
    return itemMatriz->listaVoo;
}
//Retorna o número de voos
int getNumVoos(tadItemMatriz *itemMatriz){
    return itemMatriz->numVoos;
}
//Retorna o horário da última atualização
char* getHorarioAtualizacao(tadItemMatriz *itemMatriz){
    return itemMatriz->horarioAtualizacao;
}

//SETs
//Seta a lista de voo e retorna 0 caso obteve sucesso
int setListaVoo(tadItemMatriz *itemMatriz, tadListaVoo listaVoo){
    itemMatriz->listaVoo = listaVoo;
    return 0;
}
//Seta número de voos e retorna 0 caso obteve sucesso
int setNumVoos(tadItemMatriz *itemMatriz, int numVoos){
    itemMatriz->numVoos = numVoos;
    return 0;
}
//Seta o horário da atualização de voo e retorna 0 caso obteve sucesso
int setHorarioAtualizacao(tadItemMatriz *itemMatriz, char horaAtualizacao[]){
    strcpy(itemMatriz->horarioAtualizacao, horaAtualizacao);
    return 0;
}