#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int vid;
    char hrDecolagem[5], hrPrevPouso[5], aeroportoDecolagem[5], aeroportoPrevPouso[5];
    int pistaDecolagem;
} tadVoo;

void inicializa(tadVoo* voo);
int getVid(tadVoo* voo);
int setVid(tadVoo* voo, int vid);
char* getHrDecolagem(tadVoo* voo);
int setHrDecolagem(tadVoo* voo, char hrDecolagem[]);
char* getHrPrevPouso(tadVoo* voo);
int setHrPrevPouso(tadVoo* voo, char hrPrevPouso[]);
char* getAeroportoDecolagem(tadVoo* voo);
int setAeroportoDecolagem(tadVoo* voo, char aeroportoDecolagem[]);
char* getAeroportoPrevPouso(tadVoo* voo);
int setAeroportoPrevPouso(tadVoo* voo, char aeroportoPrevPouso[]);
int getPistaDecolagem(tadVoo* voo);
int setPistaDecolagem(tadVoo* voo, int pistaDecolagem);

