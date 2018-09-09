#include <stdio.h>
#include <stdlib.h>
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

}
char* getAeroportoDecolagem(tadVoo* voo){
    return voo->aeroportoDecolagem;
}
int setAeroportoDecolagem(tadVoo* voo, char aeroportoDecolagem[]){

}
char* getAeroportoPrevPouso(tadVoo* voo){
    return voo->aeroportoPrevPouso;
}
int setAeroportoPrevPouso(tadVoo* voo, char aeroportoPrevPouso[]){

}
int getPistaDecolagem(tadVoo* voo){
    return voo->pistaDecolagem;
}
int setPistaDecolagem(tadVoo* voo, int pistaDecolagem){
    voo->pistaDecolagem = pistaDecolagem;
    return 0;
}