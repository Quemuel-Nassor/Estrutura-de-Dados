//declaração de bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<unistd.h>
#include<locale.h>

//variáveis globais
int opc;

//estrutura 
struct modelo{
	
	struct modelo *ant;
	struct modelo *prox;
	char nome[40];
	int numero;
	
};

typedef struct modelo pilha;

//empilhar(push)
void inserir(pilha *topo){
	
	//pilha *temp = topo->prox;
	pilha *novo = (pilha *)malloc(sizeof(pilha));
	novo->ant = NULL;
	novo->prox = NULL;
	topo->prox = novo;
	
	if(topo->ant!=NULL){
	
		topo->prox = novo->prox;
		novo->ant = topo->ant;
		topo->ant->prox = novo;
		topo->ant = novo;
		
	}else if(topo->ant == NULL){
				
		topo->prox = novo->prox;
		novo->ant = topo->ant;
		topo->ant = novo;
		novo->prox = topo;
	
	}
	
	//opção cancelar cadastro apertando ESC
	printf("\n\nInforme o nome: ");
	if((getch()) == 27){
		
	}else{
	
		fflush(stdin);
		gets(novo->nome);
		printf("Informe o número: ");
		scanf("%i", &novo->numero);
	}
}

//desempilhar(pop)
void retirar(pilha *topo){

	pilha *temp = topo->ant;

	if(temp == NULL){
		
		printf("\n\n\n\n\n\t\t\t\t\tPilha vazia");
		sleep(3);
		

	}else if(temp->ant != NULL){	
		
		printf("\n\nnome: %s\t",temp->nome);
		printf("número: %i\n",temp->numero);

		topo->ant = temp->ant;
		temp->ant->prox = topo;
		free(temp);
		fflush(stdin);
		getchar();
		
	}else if(temp->ant == NULL){	
		
		printf("\n\nnome: %s\t",temp->nome);
		printf("número: %i\n",temp->numero);

		temp->prox->ant = NULL;			
		free(temp);
		fflush(stdin);
		getchar();
		
	}
}

//consultar
void consulta(pilha *topo){
	
	pilha *temp = topo->ant;

	if (temp == NULL){
		
		printf("\n\n\n\n\n\t\t\t\t\tPilha vazia");
		sleep(3);
		
	}else{
	
		while(temp->ant != NULL){
		
			printf("\n\nnome: %s\t",temp->nome);
			printf("numero: %i\n",temp->numero);
		
			temp = temp->ant;
		}
		printf("\n\nnome: %s\t",temp->nome);
		printf("número: %i\n",temp->numero);
		fflush(stdin);
		getchar();
	
	}
}

int main(){
	
	setlocale (LC_ALL,"Portuguese");
	
	//estruturas
	pilha *topo = (pilha *)malloc(sizeof(pilha));
	
	topo->prox = NULL;
	topo->ant = NULL;
	
	//menu
	while(1==1){
		
		system("cls");
		printf("\n\n\n\t\t\t\t\tSelecione uma opção:\n\n\n1- empilhar\n2- desempilhar\n3- consultar\n0- sair\n");
		opc = (getch()-48);
		
		switch(opc){
			
			case 1:{
				
				system("cls");		
				inserir(topo);
				
				break;
				
			}
			
			case 2:{
				
				system("cls");
				retirar(topo); 
				
				break;
			}
			
			case 3:{
				
				system("cls");
				consulta(topo);
				
				break;
			}
			
			case 0:{
				
				exit(0);
				
				break;
			}
		}
	}
	return (0);
}

