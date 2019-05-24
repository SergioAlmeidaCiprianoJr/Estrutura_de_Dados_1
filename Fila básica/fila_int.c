#include <stdio.h>
#include <stdlib.h>
#include "fila_int.h"
#define N 10

static int fila[N];
static int p, u;

void cria_fila(){
    p = 0;
    u = 0;
    for(int i = 0;i<N;i++){
        fila[i] = 0;
    }
}
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
    int ja_veio_aqui = 0;
    for(int i = 0; i>=0; i++){
        if(p==u && p==0) {printf("pu\n");break;}
        if(i) printf("     ");
        if(p == i || !p) {
            if(!ja_veio_aqui) printf("p");
            ja_veio_aqui = 1;
        }
        if(u == i+1) {
            if(p==u) printf("      pu\n");
            else printf("     u\n");
            break;
        }
        printf(" ");
    }
   
}
void remove_fila(){
    fila[p++] = 0;
}
void entra_fila(int elemento){
    fila[u++] = elemento;
}
int primeiro_da_fila(){
    return fila[p];
}
int ultimo_da_fila(){
    return fila[u-1];
}
int fila_vazia(){
    return u==p;
}
int fila_cheia(){
    if(u >= N) return 1;
    else return 0;
}