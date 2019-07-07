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

	int topo;
	int capa;
	char *pElem;

}Pilha;

void CriaPilha( Pilha *p, int c ){
   p->topo = -1;
   p->capa = c;
   p->pElem = (char*) malloc (c * sizeof(char));
}

void Empilha ( Pilha *p, char v){
	p->topo++;
	p->pElem [p->topo] = v;
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
