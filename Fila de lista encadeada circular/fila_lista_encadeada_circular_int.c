#include <stdio.h>
#include <stdlib.h>
#include "fila_lista_encadeada_circular_int.h"

typedef struct lista_encadeada_circular {
   int posicao;
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
    fila->posicao = 0;
    fila->valor = 0;
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

void remove_fila(){
    Fila *lixo = fila->prox;
    fila->prox = lixo->prox;
    free(lixo);
}
void entra_fila(int elemento){
    Fila *nova;
    nova = mallocc(sizeof(Fila));
    nova->valor = elemento;
    Fila *ultimo_elemento = ultimo_da_fila();
    nova->prox = ultimo_elemento->prox;
    ultimo_elemento->prox = nova;
    N++;
}
Fila* ultimo_da_fila(){
    Fila *ultimo_elemento = fila;
    while(ultimo_elemento->prox->posicao != 0){
        ultimo_elemento = ultimo_elemento->prox;
    }
    return ultimo_elemento;
}
int fila_vazia(){
    if(fila->prox->posicao == 0) return 1;
    else return 0;
}
int fila_cheia(){
    //Nunca fica cheia
    return 0;
}