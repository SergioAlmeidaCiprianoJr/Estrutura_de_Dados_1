#include <stdio.h>
#include <stdlib.h>
#include "fila_estatica_int.h"
#define N 10

int fila[N];
int p, u;

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
int remove_fila(){
    if(fila_vazia) return -1;
    int elemento_removido = fila[p];
    fila[p++] = 0;
    return elemento_removido;
}
int entra_fila(int elemento){
    if(fila_cheia) return 0;
    fila[u++] = elemento;
    return 1;
}
int fila_vazia(){
    return u==p;
}
int fila_cheia(){
    if(u >= N) return 1;
    else return 0;
}
