#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadVoo.c"

int main() {
    tadVoo voo, *voo1 = NULL;
    voo1 = &voo;
    inicializa(voo1);
    printf("VID: %d\n", getVid(voo1));
    printf("HD: %s\n", getHrDecolagem(voo1));
    printf("HP: %s\n", getHrPrevPouso(voo1));
    printf("AD: %s\n", getAeroportoDecolagem(voo1));
    printf("AP: %s\n", getAeroportoPrevPouso(voo1));
    printf("Pista: %d\n", getPistaDecolagem(voo1));
    return 0;
}