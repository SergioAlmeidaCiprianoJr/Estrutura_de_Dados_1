#include <stdio.h>
#include <stdlib.h>
#include "fila_lista_encadeada_circular_int.h"

typedef struct lista_encadeada_circular {
   int valor;
   struct lista_encadeada_circular *prox;
} Fila;

// p sempre será zero
Fila *fila;
// considerando N tamanho da fila
int N = 0;

void cria_fila(){
    //chamada quando a fila é reiniciada
    if(N>0) limpa_fila();
    //célula cabeça
    fila = malloc(sizeof(Fila));
    fila->valor = -1;
    fila->prox = fila;
    N = 0;
}

void imprime_fila(){
    //printando primeira linha da tabela
    printf("\t _____");
    for(int i = 1;i<=N;i++){
        printf(" _____");
    }
    printf("\n\t|");
    //printando célula cabeça
    printf(" --- |");
    //printando valores da tabela
    Fila *imprime_elemento_fila = fila->prox;
    for(int i = 0;i<N;i++){
        printf(" %03d |", imprime_elemento_fila->valor);
        imprime_elemento_fila = imprime_elemento_fila->prox;
    }
    //printando última linha da tabela
    printf("\n\t ‾‾‾‾‾");
    for(int i = 1;i<=N;i++){
        printf(" ‾‾‾‾‾");
    }
    //printando célula cabeça
    printf("\n\t head\n");
}

int remove_fila(){
    if(fila_vazia()) return -1;
    Fila *lixo = fila->prox;
    int elemento_removido = fila->prox->valor;
    fila->prox = lixo->prox;
    free(lixo);
    N--;
    return elemento_removido;
}
int entra_fila(int elemento){
    //para economizar tempo sempre a célula cabeça é recriada
    Fila *nova, *realiza_troca;

    //fazendo nova virar a célula cabeça
    nova = malloc(sizeof(Fila));
    nova->valor = -1;
    nova->prox = fila->prox;

    fila->prox = nova;
    fila->valor = elemento;

    //fazendo fila voltar a ser a célula cabeça
    realiza_troca = fila;
    fila = nova;
    nova = realiza_troca;

    N++;

    return 1;
}
int fila_vazia(){
    if(fila->prox->valor == -1) return 1;
    else return 0;
}
int fila_cheia(){
    //Nunca fica cheia
    return 0;
}
void limpa_fila(){
    while(!fila_vazia){
        remove_fila();
    }
}