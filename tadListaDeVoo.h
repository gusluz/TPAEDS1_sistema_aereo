#include <stdio.h>
#include <stdlib.h>
#include "tadVoo.h"

//Ponteiro apontador
typedef struct tipoCelula *tipoApontador;

//ED para célula da lista encadeada
typedef struct tipoCelula{
    tadVoo voo; //Lista Linear - TADVoo (info)
    tipoApontador prox; //Apontamento para próxima célula (prox)
} tipoCelula;

//ED para células cabeça da lista encadeada
typedef struct {
    tipoApontador primeiro, ultimo; //Apontamento para primeiro e último elemento da lista
} tadListaVoo;

void fazListaVazia(tadListaVoo* listaVoo); //Inicializar lista vazia
int vazia(tadListaVoo listaVoo); //Verificar se a lista está vazia
int insereVoo(tadVoo voo, tadListaVoo* listaVoo); //Inserir Voo na lista
tadVoo retornaVoo(tadListaVoo* listaVoo, int vid); //Retirar voo da lista e retornar para o programa
tadVoo procuraVoo(tadListaVoo* listaVoo, int vid); //Procurar voo em lista
void imprimeVoo(tadListaVoo listaVoo); //Imprimir voos da lista

