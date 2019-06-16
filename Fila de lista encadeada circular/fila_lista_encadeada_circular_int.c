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

void cria_fila(){
    fila = malloc(sizeof(Fila));
    //célula cabeça
    fila->posicao = -1;
    fila->valor = -1;
    fila->prox = fila;
}

/*
void imprime_fila(){
    //printando primeira linha da tabela
    printf("\t _____");
    for(int i = 1;i<N;i++){
        printf(" _____");
    }
    printf("\n\t|");
    //printando valores da tabela
    for(int i = 0;i<N;i++){
        printf(" %03d |", fila[i]);
    }
    //printando última linha da tabela
    printf("\n\t ‾‾‾‾‾");
    for(int i = 1;i<N;i++){
        printf(" ‾‾‾‾‾");
    }
    //printando u e p
    printf("\n\t   ");
    int ja_veio_aqui_p = 0, ja_veio_aqui_u = 0, consertando_espaco_inadequado = 0;
    for(int i = 0; i>=0; i++){
        consertando_espaco_inadequado = 0;
        if(p==u && p==0) {printf("pu\n");break;}
        if(i) printf("     ");
        if(p == i || !p) {
            if(!ja_veio_aqui_p) {printf("p"),consertando_espaco_inadequado = 1;}
            ja_veio_aqui_p = 1;
        }
        if(u == i) {
            if(!ja_veio_aqui_u) {printf("u"),consertando_espaco_inadequado = 1;}
            ja_veio_aqui_u = 1;
        }
        if(ja_veio_aqui_u && ja_veio_aqui_p) {printf("\n");break;}
        if(!consertando_espaco_inadequado) printf(" ");
    }
   
}
*/

void remove_fila(){
    Fila *lixo = fila->prox;
    fila->prox = lixo->prox;
    free(lixo);
}
void entra_fila(int elemento){
    Fila *nova;
    nova = malloc(sizeof(Fila));
    nova->valor = elemento;
    Fila *ultimo_elemento = ultimo_da_fila();
    nova->prox = ultimo_elemento->prox;
    ultimo_elemento->prox = nova;
}
Fila* ultimo_da_fila(){
    Fila *ultimo_elemento = fila;
    while(ultimo_elemento->prox->posicao != -1){
        ultimo_elemento = ultimo_elemento->prox;
    }
    return ultimo_elemento;
}
int fila_vazia(){
    if(fila->prox->posicao == -1) return 1;
    else return 0;
}
int fila_cheia(){
    //Nunca fica cheia
    return 0;
}