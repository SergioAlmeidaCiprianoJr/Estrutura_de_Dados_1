#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int Prioridade(char c, char t){
  int pc,pt;
 
  if(c == '^')
    pc = 4;
  else if(c == '*' || c == '/')
    pc = 2;
  else if(c == '+' || c == '-')
    pc = 1;
  else if(c == '(')
    pc = 4;
 
  if(t == '^')
    pt = 3;
  else if(t == '*' || t == '/')
    pt = 2;
  else if(t == '+' || t == '-')
    pt = 1;
  else if(t == '(')
    pt = 0;
 
  return (pc > pt);
}
typedef struct Pilha {

<<<<<<< HEAD
	int topo;
	int capa;
	char *pElem;

}Pilha;
=======
void remove_pilha(char elemento);
void entra_pilha(char elemento);
int pilha_nao_vazia();
void criaPosFixa();
void prioridade();

char pilha[510] = {};//todas as funções
char expressao[510] = {};
char posfixa[510] = {};
int t = 0, j = 0;
>>>>>>> 6625f54a62d01703c86d7108311e2e2f920316eb

void CriaPilha( Pilha *p, int c ){
   p->topo = -1;
   p->capa = c;
   p->pElem = (char*) malloc (c * sizeof(char));
}

<<<<<<< HEAD
void Empilha ( Pilha *p, char v){
	p->topo++;
	p->pElem [p->topo] = v;
=======
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
>>>>>>> 6625f54a62d01703c86d7108311e2e2f920316eb
}

char Desempilha (Pilha *p ){
   char aux = p->pElem [p->topo];
   p->topo--;
   return aux;
}

void Conversor(char expr[]){
  Pilha p;
  int i = 0;
  char c,t;
 
  CriaPilha(&p,510);
  Empilha(&p, '(');
 
  do{
    c = expr[i];
    i++;
    if(c >= 'A' && c <= 'Z'){
      printf("%c", c);
    }
    else if(c == '('){
      Empilha(&p, '(');
    }
    else if(c == ')' || c == '\0'){
      do{
        t = Desempilha(&p);
        if(t != '(')
          printf("%c", t);
      }while(t != '(');
    }
    else if(c == '+' || c == '-' || 
            c == '*' || c == '/' ||
            c == '^' ){
      while(1){
        t = Desempilha(&p);
        if(Prioridade(c,t)){
          Empilha(&p, t);
          Empilha(&p, c);
          break;
        }
        else{
          printf("%c", t);
        }
      }
    }
  }while(c != '\0');
  printf("\n");
}
int checaParentese(char aux[]){
	int p=0,c=0,x=0;
	for(int i = 0;i<strlen(aux);i++){
		if(aux[i]=='('){
			p++;
		}else if(aux[i]==')'){
			p--;
		}if(aux[i]=='['){
			c++;
		}else if(aux[i]==']'){
			c--;
		}if(aux[i]=='{'){
			x++;
		}else if(aux[i]=='}'){
			x--;
		} 
	}
	if(p==0&&x==0&&c==0)
		return 1;
	return 0;
}
int main(){
	char aux[510];
	scanf("%s",aux);
	if(checaParentese(aux)){
		Conversor(aux);	
	}else{
		printf("incorretamente parentizada\n");
	}
	return 0;
}
<<<<<<< HEAD
=======

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




    
    
    
    
>>>>>>> 6625f54a62d01703c86d7108311e2e2f920316eb
