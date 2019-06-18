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
int N;

void cria_fila(){
    fila = mallocc(sizeof(Fila));
    //célula cabeça
    fila->valor = -1;
    fila->prox = fila;
    N = 0;
}

void imprime_fila(){
    //printando primeira linha da tabela
    printf("\t _____");
    for(int i = 1;i<N;i++){
        printf(" _____");
    }
    printf("\n\t|");
    //printando valores da tabela
    Fila *imprime_elemento_fila = fila->prox;
    for(int i = 0;i<N;i++){
        imprime_elemento_fila = imprime_elemento_fila->prox;
        printf(" %03d |", imprime_elemento_fila->valor);
    }
    //printando última linha da tabela
    printf("\n\t ‾‾‾‾‾");
    for(int i = 1;i<N;i++){
        printf(" ‾‾‾‾‾");
    }
    //printando u e p
    //Na lista encadeada eles sempre estão em posições fixasS
    printf("\n\t   p");
    int ja_veio_aqui = 0;
    for(int i = 0; i>=0; i++){
        if(i) printf("     ");
        if(N == i+1) {
            printf("     u\n");
        }
        printf(" ");
    }
   
}

int remove_fila(){
    if(fila_vazia) return 0;
    Fila *lixo = fila->prox;
    fila->prox = lixo->prox;
    free(lixo);
    return 1;
}
int entra_fila(int elemento){
    //para economizar tempo sempre a célula cabeça é recriada
    Fila *nova, *realiza_troca;

    //fazendo nova virar a célula cabeça
    nova = mallocc(sizeof(Fila));
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
int primeiro_da_fila(){
    return fila->prox->valor;
}
int fila_vazia(){
    if(fila->prox->valor == -1) return 1;
    else return 0;
}
int fila_cheia(){
    //Nunca fica cheia
    return 0;
}