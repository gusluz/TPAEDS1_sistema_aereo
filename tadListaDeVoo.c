#include <stdlib.h>
#include <stdio.h>
#include "tadListaDeVoo.h"

//inicializa a lista encadeada(recebida como parâmetro) vazia
void fazListaVazia(tadListaVoo* listaVoo){
    listaVoo->primeiro = (tipoApontador) malloc(sizeof(tipoCelula)); //Aloca um espaço do tamanho de uma célula para
    // receber a célula cabeça e armazena no ponteiro que aponta para o primeiro elemento da lista
    listaVoo->ultimo = listaVoo->primeiro; //Faz o ponteiro último apontar para o primeiro elemento
    listaVoo->primeiro->prox = NULL; //Faz o ponteiro próx(próximo) da minha célula cabeça apontar para NULL
}
//Verifica se minha lista encadeada(recebida como parâmetro) está vazia
int vazia(tadListaVoo listaVoo){
    return (listaVoo.primeiro == listaVoo.ultimo); //retorna 1 caso a igualdade seja verdadeira
}

//Imprime todos os voos da lista encadeada (recebida como parâmetro)
void imprimeVoo(tadListaVoo listaVoo){
    tipoApontador aux; //Crio um ponteiro auxiliar para percorrer a lista
    aux = listaVoo.primeiro->prox; //Faço o ponteiro ser igual ao ponteiro prox do primeiro elemento da lista(célula cabeça)
    while(aux != NULL){ //Enquanto o ponteiro próx(próximo) não apontar para NULL
        printf("VID: %d\n", getVid(&aux->voo)); //
        printf("Hora Decolagem: %s\n", getHrDecolagem(&aux->voo));
        printf("Hora Prevista para Pouso: %s\n", getHrPrevPouso(&aux->voo));
        printf("Aeroporto Decolagem: %s\n", getAeroportoDecolagem(&aux->voo));
        printf("Aeroporto Previsto para Pouso: %s\n", getAeroportoPrevPouso(&aux->voo));
        printf("Pista de Decolagem: %d\n\n", getPistaDecolagem(&aux->voo));
        aux = aux->prox; //Incrementa meu ponteiro para o próximo elemento da lista
    }
}

//Insere um item(voo) de lista linear na minha lista encadeada(recebida como parâmetro) e retorna 0 caso operação tenha sucesso
int insereVoo(tadVoo voo, tadListaVoo* listaVoo){
    tipoApontador posicao, novo; //Crio um ponteiro para posição em que deve ser inserido e um ponteiro para o novo item
    posicao = listaVoo->primeiro; //Posição começa do primeiro elemento(célula cabeça)
    while(posicao->prox != NULL){
            comp = strcmp(posicao->prox->voo.hrDecolagem, voo.hrDecolagem);
            if(comp<=0){
                novo = (tipoApontador) malloc(sizeof(tipoCelula)); //Aloco um espaço para minha nova célula para nova informação
                novo->voo = voo; //Minha informação contida na célula será o voo recebido como parâmetro
                novo->prox = posicao->prox; //Aponto meu ponteiro de prox(próximo) para o mesmo local em que meu antigo ponteiro
                // da posição em que devo colocar apontava
                posicao->prox = novo; //Aponto meu antigo ponteiro da posição em que devo colocar apontava, para o novo item da lista
            }
    //Enquanto meu ponteiro prox(próximo) não apontar para NULL E minha comparação de string(hora de decolagem
        // do voo contido na lista encadeada e do voo recebido como parâmetro) for menor do que 0, percorra a lista
        posicao = posicao->prox; //Incrementa meu ponteiro para o próximo elemento da lista
    }
    return 0;
}

//Retira o item da lista e retorna o item (TADVoo) para uso no programa
tadVoo retornaVoo(tadListaVoo* listaVoo, int vid){
    tipoApontador posicao, aux; //Crio um ponteiro posicao para percorrer a lista e um ponteiro auxiliar para
    // receber meu novo ponteiro
    tadVoo voo, *voo1 = NULL; //Crio um TADVoo e um ponteiro para o mesmo
    voo1 = &voo; //Aponto para o endereço do meu TAD
    posicao = listaVoo->primeiro; //Posição começa do primeiro elemento(célula cabeça)
    while(posicao->prox != NULL && posicao->prox->voo.vid != vid){
        //Enquanto meu ponteiro prox(próximo) não apontar para NULL E meu VID do item (TADVoo) for diferente do que
        //eu recebi como parâmetro, percorra a lista
        posicao = posicao->prox; //Incrementa meu ponteiro para o próximo elemento da lista
    }
    aux = posicao->prox; //Meu ponteiro auxiliar vai receber o ponteiro prox da posição encontrada
    *voo1 = aux->voo; //Meu item(TADVoo) dessa posicao vai ser armazenado no TADVoo criado anteriormente
    posicao->prox = aux->prox; //A posição do próximo vai ser a mesma do próximo do ponteiro auxiliar
    if(posicao->prox == NULL) listaVoo->ultimo = posicao; //Se a próxima posição for NULL meu ponteiro para o último
    //recebe essa posição
    free(aux); //Libero a célula do HEAP
    return voo; //Retorno o item encontrado
}

//Procuro o item da lista e retorno o item(TADVoo) para o uso no programa
tadVoo procuraVoo(tadListaVoo* listaVoo, int vid){
    tipoApontador posicao; //Crio um ponteiro posicao para percorrer a lista e armazenar a posição encontrada
    posicao = listaVoo->primeiro; //Posição começa do primeiro elemento da lista(célula cabeça)
    while(posicao->prox != NULL && posicao->prox->voo.vid != vid){
        //Enquanto meu ponteiro prox(próximo) não apontar para NULL E meu VID do item (TADVoo) for diferente do que
        //eu recebi como parâmetro, percorra a lista
        posicao = posicao->prox; //Incrementa meu ponteiro para o próximo elemento da lista
    }
    return posicao->prox->voo; //Retorno o item encontrado sem retirá-lo da lista encadeada
}