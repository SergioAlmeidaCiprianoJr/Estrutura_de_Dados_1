#include <stdio.h>
#include <stdlib.h>
//#include "fila_estatica_int.h"
//#include "fila_continua_int.h"
#include "fila_lista_encadeada_circular_int.h"

int fim = 0;//finaliza o programa
char volta_menu;

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
    int operacao_finalizada = 0;
    printf("Número de elementos para inserir na fila: ");
    scanf("%d", &elementos);
    if(fila_vazia()) cria_fila();//resetando p e u para zero
    for(int i = 0; i<elementos; ++i){
        int elementoi;
        printf("informe o elemento número %d: ", i+1);
        scanf("%d", &elementoi);
        while(elementoi<0 || elementoi>999){
            printf("Elemento inválido!!\n");
            printf("Digite um elemento entre 0 e 999, inclusos: ");
            scanf("%d", &elementoi);
        }
        if(!entra_fila(elementoi)){
            printf("\nNão é possível colocar mais nenhum elemento, pois a fila está cheia.\n");
            printf("\nDeseja voltar ao menu[S/N]: ");
            scanf(" %c", &volta_menu);
            operacao_finalizada = 1;
            if(volta_menu == 'N' || volta_menu == 'n') fim++;
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
    printf("Número de elementos para retirar da fila: ");
    scanf("%d", &elementos);
    int contador = 1;
    while(fila_vazia()){
        int elemento_removido = remove_fila();
        if(!elemento_removido){
            printf("\nNão foi possível remover %d elemento(s)!!\nA fila já está completamente vazia!!\n", elementos);
        }
        else{
            printf("Removendo %d, que é o %d° elemento da fila.\n", elemento_removido, contador);
            elementos--;
            if(!elementos) break;    
            contador++;
        }
    }
    if(!elementos) {
        printf("\nOperação finalizada com sucesso!!\n");
    }
    else{
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
    scanf(" %c", &volta_menu);
    if(volta_menu == 'N' || volta_menu == 'n') fim++;
}
void opcao4(){
    //Imprimir a fila
    system("clear");
    imprime_fila();
    printf("\nDeseja voltar ao menu[S/N]: ");
    scanf(" %c", &volta_menu);
    if(volta_menu == 'N' || volta_menu == 'n') fim++;
}
void opcao5(){
    //Sair
    fim++;
}