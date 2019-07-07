#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//Algoritmo que gera e soluciona entradas do tipo:
//A+B^C
//A=4
//B=3
//C=2
//Posfixa: ABC^+
//Valor: 13

typedef struct Pilha {
	int topo;
	int capa;
	char *pElem;

}Pilha;

char posFixa[510];
int resolve[510];
int s = 0, topoPilha = 0;

int Prioridade(char c, char t);
void CriaPilha( Pilha *p, int c );
void Empilha( Pilha *p, char v);
char Desempilha(Pilha *p );
void PosFixa(char expr[]);
int checaParentese(char *aux);
int potenciacao(int a, int b);

int main(){
	char aux[510];
	int alfabeto[27];
	scanf("%s",aux);
	getchar();
	char letra;
	int valor;
	while(scanf(" %c=%d", &letra, &valor) != EOF){
	    alfabeto[letra-'A'] = valor;
	}
	if(checaParentese(aux)){
		PosFixa(aux);
		printf("Posfixa: %s\n", posFixa);	
		for(int i = 0; i<s; i++){
		    char x = posFixa[i];
		    if(x >= 65 && x <= 90){
		        resolve[topoPilha++] = alfabeto[x-'A'];
		    }
		    else if(x == '+' || x == '-' || 
			    x == '*' || x == '/' ||
			    x == '^' ){
		        int valor2 = resolve[--topoPilha];
		        int valor1 = resolve[--topoPilha]; 
		        int total;
		        if(x == '+') total = valor1 + valor2;
		        else if(x == '-') total = valor1 - valor2;
		        else if(x == '/') total = valor1 / valor2;
		        else if(x == '*') total = valor1 * valor2;
		        else if(x == '^') total = pow(valor1, valor2);
		        resolve[topoPilha++] = total;
		    }
		}
		printf("Valor: %d\n", resolve[0]);
	}else{
		printf("emf\n");
	}
	return 0;
}

int potenciacao(int a, int b){
    int total = a;
    int boleano = 0;
    if(b<0) {b *= -1;boleano=1;}
    b--;
    while(b--){
        total *= a;
    }
    if(boleano) total = 1/total;
    return total;
}

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

void PosFixa(char expr[]){
  Pilha p;
  int i = 0;
  char c,t;
 
  CriaPilha(&p,510);
  Empilha(&p, '(');
 
  do{
    c = expr[i];
    i++;
    if(c >= 'A' && c <= 'Z'){
      posFixa[s++] = c;
    }
    else if(c == '('){
      Empilha(&p, '(');
    }
    else if(c == ')' || c == '\0'){
      do{
        t = Desempilha(&p);
        if(t != '(')
          posFixa[s++] = t;
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
          posFixa[s++] = t;
        }
      }
    }
  }while(c != '\0');
}
int checaParentese(char *aux){
	int p=0;
	for(int i = 0;i<strlen(aux);i++){
		if(aux[i]=='(') p++;
        else if(aux[i]==')') p--;
	}
	if(p==0)
		return 1;
	return 0;
}
