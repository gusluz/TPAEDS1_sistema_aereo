#include <stdio.h>
#include <stdlib.h>
#define TAMCHAR 6
//Estrutura responsável pelo Tipo Abstrado de Dados Voo
typedef struct {
    int vid;
    char hrDecolagem[TAMCHAR], hrPrevPouso[TAMCHAR], aeroportoDecolagem[TAMCHAR], aeroportoPrevPouso[TAMCHAR];
    int pistaDecolagem;
} tadVoo;

//Protótipos de funções
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
