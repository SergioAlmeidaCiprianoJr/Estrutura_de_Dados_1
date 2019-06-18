#include <stdio.h>
#include <stdlib.h>
#include "fila_continua_int.h"

static int *fila;
static int p, u;
int N;

void cria_fila(){
    p = 0;
    u = 0;
    N = 10;
    fila = malloc(N*sizeof(int));
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
int remove_fila(){
    if(fila_vazia) return 0;
    int elemento_removido = fila[p];
    fila[p++] = 0;
    if(p==N) p = 0;
    return elemento_removido;
}
int entra_fila(int elemento){
    if(fila_cheia()) realoca_elementos();
    fila[u++] = elemento;
    if(u==N) u = 0;
    return 1;
}
int primeiro_da_fila(){
    return fila[p];
}
int fila_vazia(){
    return u==p;
}
int fila_cheia(){
    if((u+1)%N==p) return 1;
    else return 0;
}
void realoca_elementos(){
    int novoN = 10 + N;
    int *vetor;
    vetor = malloc(novoN*sizeof(int));
    if(p<u){
        for(int i=p; i<u; i++){
            vetor[i-p] = fila[i];
        }
        p = 0;
    }
    else{
        int j,i;
        for(j=p; j<N; j++){
            vetor[j-p] = fila[j];
        }
        j-=p;
        for(i=0; i<u; i++){
            vetor[i+j] = fila[i];
        }
        p = 0;
        u = j+i;
    }
    N = novoN;
    free(fila);
    fila = vetor;
}