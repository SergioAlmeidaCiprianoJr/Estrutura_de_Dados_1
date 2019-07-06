#include <stdio.h>
#include <stdlib.h>

void remove_pilha(char elemento);
void entra_pilha(char elemento);
int pilha_nao_vazia();
void criaPosFixa();
void prioridade();

char pilha[510] = {};//todas as funções
char expressao[510] = {};
char posfixa[510] = {};
int t = 0, j = 0;

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
    
    t = 0
    criaPosFixa();
    
    for(int i = 0; i<j; i++){
        printf("%c", posfixa[i]);
    }
    printf("\n");

    
    
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

void criaPosFixa(){

	for(int i = 1; expressao[i] != '\0'; ++i) {
        if(expressao[i] >= 'A' && expressao[i] <= 'Z'){
	        posfixa[j] = expressao[i];
	        j++;
        }
        else{
	        if(expressao[i] == '('){
	            entra_pilha(expressao[i]);
		    }
		    else{
		        if(expressao[i] == ')'{
		            char op = desempilha();
		            while(op!='('){ 
		                posfixa[j] = op;
		                j++;
		                op = desempilha();
		            }
	            }
	            else{
		            char t = desempilha();
		            if(prioridade(c)>prioridade(t)){
		                entra_pilha(t);
		                entra_pilha(c);
		            else{
		                while(prioridade(c)<=prioridade(t)){
		                    posfixa[j]=t;
		                    j++;
		                    t = desempilha();
		                }
		                entra_pilha(t);
		                entra_pilha(c);
		            }
		        }
		    }
	    }
	}

	while(pilha_nao_vazia() == true){
	    posfixa[j] = desempilha();
	    j++;
	}

}

void prioridade(){

}




    
    
    
    
