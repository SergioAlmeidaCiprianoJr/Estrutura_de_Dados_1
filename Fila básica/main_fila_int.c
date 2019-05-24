#include <stdio.h>
#include <stdlib.h>
#include "fila_continua_int.h"

int fim = 0;//finaliza o programa

int menu();
void opcao1();
void opcao2();
void opcao3();
void opcao4();
void opcao5();

int main(){

    cria_fila();
    void (*opcao[])() = { opcao1, opcao2, opcao3, opcao4, opcao5};
    while(!fim) opcao[menu()-1]();
    system("clear");
    return 0;
}

int menu(){
    int opcao;
    system("clear");
    printf("Crie sua fila personalizada:\n\n");
    printf("Opções:\n\n");
    printf("(1) Inserir elementos na fila\n");
    printf("(2) Retirar elementos da fila\n");
    printf("(3) Reiniciar fila\n");
    printf("(4) Imprimir a fila\n");
    printf("(5) Sair\n\n");
    printf("Escolha: ");
    scanf("%d", &opcao);
    return opcao;
}

void opcao1(){
    //Inserir elementos na fila
    system("clear");
    int elementos;
    char volta_menu;
    int operacao_finalizada = 0;
    printf("Número de elementos para inserir na fila: ");
    scanf("%d", &elementos);
    while(elementos<0 || elementos>999){
        printf("Número de elementos inválidos!!\n");
        printf("Digite número de elementos entre 0 e 999, inclusos: ");
        scanf("%d", &elementos);
    }
    if(fila_vazia()) cria_fila();
    for(int i = 0; i<elementos; ++i){
        int elementoi;
        if(fila_cheia()) {
            printf("\nNão é possível colocar mais nenhum elemento, pois a fila está cheia.\n");
            printf("\nDeseja voltar ao menu[S/N]: ");
            scanf(" %c", &volta_menu);
            operacao_finalizada = 1;
            if(volta_menu == 'N' || volta_menu == 'n') fim++;
        }
        else{
            printf("informe o elemento número %d: ", i+1);
            scanf("%d", &elementoi);
            entra_fila(elementoi);
        }
    }
    if(!operacao_finalizada) {
        printf("\nOperação finalizada com sucesso!!\n");
        printf("Deseja voltar ao menu[S/N]: ");
        scanf(" %c", &volta_menu);
        if(volta_menu == 'N' || volta_menu == 'n') fim++;
    }
}
void opcao2(){
    //Retirar elementos da fila
    system("clear");
    int elementos;
    char volta_menu;
    printf("Número de elementos para retirar da fila: ");
    scanf("%d", &elementos);
    int contador = 1;
    while(!fila_vazia()){
        printf("Removendo %d, que é o %d° elemento da fila.\n", primeiro_da_fila(), contador);
        remove_fila();
        elementos--;
        if(!elementos) break;    
        contador++;
    }
    if(!elementos) {
        printf("\nOperação finalizada com sucesso!!\n");
    }
    else{
        printf("\nNão foi possível remover %d elemento(s)!!\nA fila já está completamente vazia!!\n", elementos);
    }
    printf("Deseja voltar ao menu[S/N]: ");
    scanf(" %c", &volta_menu);
    if(volta_menu == 'N' || volta_menu == 'n') fim++;
}
void opcao3(){
    //Reiniciar fila
    system("clear");
    cria_fila();
    printf("Fila reiniciada com sucesso!!\n");
    printf("Deseja voltar ao menu[S/N]: ");
    char volta_menu;
    scanf(" %c", &volta_menu);
    if(volta_menu == 'N' || volta_menu == 'n') fim++;
}
void opcao4(){
    //Imprimir a fila
    system("clear");
    imprime_fila();
    printf("\nDeseja voltar ao menu[S/N]: ");
    char volta_menu;
    scanf(" %c", &volta_menu);
    if(volta_menu == 'N' || volta_menu == 'n') fim++;
}
void opcao5(){
    //Sair
    fim++;
}