#include <stdio.h>
#include <stdlib.h>

void remove_pilha(char elemento);
void entra_pilha(char elemento);
int pilha_nao_vazia();

char pilha[510] = {};//todas as funções
char posfixa[510] = {};
int t;

int main(){

    int i = 1;
    char escaneia;
    scanf("%c", &escaneia);
    expressao[0] = '(';
    while(escaneia!='\n'){
        expressao[i++] = escaneia;
        if(escaneia == '{') entra_pilha('}');
        else if(escaneia == '(') entra_pilha(')');
        else if(escaneia == '[') entra_pilha(']');
        else if(escaneia == '}') remove_pilha('}');
        else if(escaneia == ']') remove_pilha(']');
        else if(escaneia == ')') remove_pilha(')');
        scanf("%c", &escaneia);
    }
    expressao[i++] = ')';
    expressao[i] = '\0';
    
    if(!resultado || pilha_nao_vazia()) {printf("incorretamente parentizada\n");return 0;}
    
    
    
    
    return 0;
}

void remove_pilha(char elemento){
    char retirado;
    if(!resultado);
    else if(!pilha_nao_vazia()) resultado = 0;
    else{    
        retirado = pilha[--t];
        if(retirado!=elemento) resultado = 0;
    }
}
void entra_pilha(char elemento){
    pilha[t++] = elemento;
}
char desempilha(){
    return pilha[--t];
}
int pilha_nao_vazia(){
    return t>0;
}

Entrada:Uma expressao matemematica exp[1..n]

para cada caracter c em exp[1..n] faca
    se c estiver entre A e Z entao
        posfixa[j]←c
        j←j+ 1
    senao
        sec = ‘(’entao
            empilha(c)
        senao
            sec = ‘)’entao
                op←desempilha()
                enquanto op!=‘(’ faca
                    posfixa[j]←op
                    j←j+ 1
                    op←desempilha()
                fim
            senao
                t←desempilha()
                se prioridade(c)>prioridade(t) entao
                    empilha(t)
                    empilha(c)
                senao
                    enquanto prioridade(c)≤prioridade(t) faca
                        posfixa[j]←t
                        j←j+ 1
                        t←desempilha()
                    fim
                    empilha(t)
                    empilha(c)
                fim
            fim
        fim
    fim
fim

enquanto pilhavazia() = false faca
    posfixa[j]←desempilha()
    j←j+ 1
fim
    
    
    
    
    
