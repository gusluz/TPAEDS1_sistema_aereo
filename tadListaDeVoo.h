typedef struct tipoCelula *tipoApontador;

typedef struct tipoCelula{
    tadVoo voo;
    tipoApontador prox;
} tipoCelula;

typedef struct {
    tipoApontador primeiro, ultimo;
} tadListaVoo;

void fazListaVazia(tadListaVoo* listaVoo);
int vazia(tadListaVoo listaVoo);
int insereVoo(tadVoo voo, tadListaVoo* listaVoo);
tadVoo retornaVoo(tadListaVoo* listaVoo, int vid);
tadVoo procuraVoo(tadListaVoo* listaVoo, int vid);
void imprimeVoo(tadListaVoo listaVoo);

