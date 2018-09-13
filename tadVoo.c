#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadVoo.h"

//Inicializa o TADVoo com valores 0 em campos INT e valores NULL('\0') em campos char
void inicializa(tadVoo* voo){
    voo->vid = 0;
    voo->hrDecolagem[0] = '\0';
    voo->hrPrevPouso[0] = '\0';
    voo->aeroportoDecolagem[0] = '\0';
    voo->aeroportoPrevPouso[0] = '\0';
    voo->pistaDecolagem = 0;
}

//GETs do TADVoo
//Retorna um INT contendo o número VID do Voo
int getVid(tadVoo* voo){
    return voo->vid;
}
//Retorna um ponteiro (início) da cadeia de caracteres que contém a hora de decolagem do Voo
char* getHrDecolagem(tadVoo* voo){
    return voo->hrDecolagem;
}
//Retorna um ponteiro (início) da cadeia de caracteres que contém a hora prevista de pouso do Voo
char* getHrPrevPouso(tadVoo* voo){
    return voo->hrPrevPouso;
}
//Retorna um INT contendo o número da pista de decolagem do Voo
int getPistaDecolagem(tadVoo* voo){
    return voo->pistaDecolagem;
}
//Retorna um ponteiro (início) da cadeia de caracteres que contém o aeroporto de decolagem do Voo
char* getAeroportoDecolagem(tadVoo* voo){
    return voo->aeroportoDecolagem;
}
//Retorna um ponteiro (início) da cadeia de caracteres que contém o aeroporto previsto de pouso do Voo
char* getAeroportoPrevPouso(tadVoo* voo){
    return voo->aeroportoPrevPouso;
}

//SETs do TADVoo
//Seta a informação(INT) VID do Voo recebida como parâmetro e retorna 0 caso execute a operação com sucesso
int setVid(tadVoo* voo, int vid){
    voo->vid = vid;
    return 0;
}
//Seta a informação (CHAR) hora de decolagem como parâmetro e retorna 0 caso execute a operação com sucesso
int setHrDecolagem(tadVoo* voo, char hrDecolagem[]){
    strcpy(voo->hrDecolagem, hrDecolagem);
    return 0;
}
//Seta a informação (CHAR) hora prevista de pouso como parâmetro e retorna 0 caso execute a operação com sucesso
int setHrPrevPouso(tadVoo* voo, char hrPrevPouso[]){
    strcpy(voo->hrPrevPouso, hrPrevPouso);
    return 0;
}
//Seta a informação (CHAR) aeroporto de decolagem como parâmetro e retorna 0 caso execute a operação com sucesso
int setAeroportoDecolagem(tadVoo* voo, char aeroportoDecolagem[]){
    strcpy(voo->aeroportoDecolagem, aeroportoDecolagem);
    return 0;
}
//Seta a informação (CHAR) aeroporto previsto de pousco como parâmetro e retorna 0 caso execute a operação com sucesso
int setAeroportoPrevPouso(tadVoo* voo, char aeroportoPrevPouso[]){
    strcpy(voo->aeroportoPrevPouso, aeroportoPrevPouso);
    return 0;
}
//Seta a informação(INT) pista de decolagem do Voo recebida como parâmetro e retorna 0 caso execute a operação com sucesso
int setPistaDecolagem(tadVoo* voo, int pistaDecolagem){
    voo->pistaDecolagem = pistaDecolagem;
    return 0;
}