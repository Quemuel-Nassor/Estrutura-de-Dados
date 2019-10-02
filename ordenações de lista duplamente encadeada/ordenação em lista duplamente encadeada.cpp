//bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<unistd.h>


//estrutura de dados 
struct modelo{
	
	struct modelo *prox;
	struct modelo *ant;
	char nome[30];
	int numero;
	
};

typedef struct modelo lista;

//ponteiro para arquivo de cadastros
FILE *pontcad;

//bibliotecas exclusivas
#include"loadlibrary.h"
#include"buble_sort.h"
#include"insertion_sort2.h"



//função para receber os dados
void recebe(lista *usuario){
	
	lista *entrada = (lista*)malloc(sizeof(lista));
	
	printf("Informe o nome: ");
	
		fflush(stdin);
		gets(entrada->nome);
		
		printf("\nInforme o numero: ");
		scanf("%i",&entrada->numero);
		
		entrada->prox = usuario->prox;
		usuario->prox = entrada;
		entrada->ant = usuario;

}

//função para exibir os dados
void exibe(lista* usuario){
	
	lista *temp = usuario->prox;
	
	if(temp == NULL){
		
		system("cls");
		printf("\n\n\n\n\t\t\t\t\tLista vazia!");
		sleep(1);
	
	}else{
	
		while(temp->prox != NULL){
			
			printf("%i\t\t",temp->numero);
			printf("%s\n------------------------------------------\n",temp->nome);
			temp = temp->prox;
		}
		printf("%i\t\t",temp->numero);
		printf("%s\n------------------------------------------\n",temp->nome);
		
		fflush(stdin);
		getchar();		
	}
	
	
}

//declaração da função principal
int main(){
	
	//variaveis locais
	int opc,sel;
	lista *inicio = (lista*)malloc(sizeof(lista));
	inicio->prox = NULL;
	inicio->ant = NULL;
	
	while(1){
		
		system("cls");
		printf("\t\t\t\tSelecione uma opcao: \n\n\n1 - adicionar ao inicio\n2 - exibir lista \n3 - ordenacao\n4 - Carregar lista\n0 - sair\n\n");
		opc = getch() -48;
		system("cls");
		
		switch(opc){
			
			case 1:{
				
				recebe(inicio);
				break;
			}
			
			case 2:{
				
				exibe(inicio);
				//descarregar(inicio,pontcad);
				break;
			}
			
			case 3:{
				
				printf("\t\t\t\tSelecione o metodo de ordenacao:\n\n\n1 - Buble sort\n2 - Selection sort\n3 - Quick sort\n4 - Insertion sort\n\n");
				sel = getch() -48;
				system("cls");
					
					
				
				switch(sel){
					
					case 1:{
					
						buble(inicio);
						break;
			
					}
					
					case 2:{
						
						
						break;
					}
					
					case 3:{
					
						break;
					}
					
					case 4:{
						exibe(inicio);
						insertion(inicio);
						//system("pause");
						break;
					}
				
					default:
						
					system("cls");
					printf("\n\n\n\n\t\t\t\t\tInvalido");
					sleep(2);
				
				}
				
				break;
			}
			
			case 4:{
				desaloca(inicio);
				carregar(pontcad,inicio);
				
				break;
			}
			
			case 0:{
				
				exit(0);
				break;
			}
			
			default:
				system("cls");
				printf("\n\n\n\n\t\t\t\t\tInvalido");
				sleep(2);
		}
	}
		
	return(0);
}
