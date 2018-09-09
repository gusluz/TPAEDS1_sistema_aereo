#include <stdio.h>
#include <string.h>
#include "tadVoo.h"

void inicializa(tadVoo* voo){
    voo->vid = 0;
    char stringNull[5];
    stringNull[0] = '\0';
    strcpy(voo->hrDecolagem, stringNull);
    strcpy(voo->hrPrevPouso, stringNull);
    strcpy(voo->aeroportoDecolagem, stringNull);
    strcpy(voo->aeroportoPrevPouso, stringNull);
    voo->pistaDecolagem = 0;
}
int getVid(tadVoo* voo){
    return voo->vid;
}
int setVid(tadVoo* voo, int vid){
    voo->vid = vid;
    return 0;
}
char* getHrDecolagem(tadVoo* voo){
    return voo->hrDecolagem;
}
int setHrDecolagem(tadVoo* voo, char hrDecolagem[]){
    strcpy(voo->hrDecolagem, hrDecolagem);
    return 0;
}
char* getHrPrevPouso(tadVoo* voo){
     return voo->hrPrevPouso;
}
int setHrPrevPouso(tadVoo* voo, char hrPrevPouso[]){
    strcpy(voo->hrPrevPouso, hrPrevPouso);
    return 0;
}
char* getAeroportoDecolagem(tadVoo* voo){
    return voo->aeroportoDecolagem;
}
int setAeroportoDecolagem(tadVoo* voo, char aeroportoDecolagem[]){
    strcpy(voo->aeroportoDecolagem, aeroportoDecolagem);
    return 0;
}
char* getAeroportoPrevPouso(tadVoo* voo){
    return voo->aeroportoPrevPouso;
}
int setAeroportoPrevPouso(tadVoo* voo, char aeroportoPrevPouso[]){
    strcpy(voo->aeroportoPrevPouso, aeroportoPrevPouso);
    return 0;
}
int getPistaDecolagem(tadVoo* voo){
    return voo->pistaDecolagem;
}
int setPistaDecolagem(tadVoo* voo, int pistaDecolagem){
    voo->pistaDecolagem = pistaDecolagem;
    return 0;
}
int horasParaMinutos(char *horario){
    int i,minutosTotal = 0;
    for(i=0;i<5;i++){
        horario[i] = horario[i] - 48;
    }
    minutosTotal += (horario[0] * 10) * 60;
    minutosTotal += horario[1] * 60;
    minutosTotal += horario[3] * 10;
    minutosTotal += horario[4];
    return minutosTotal;
}