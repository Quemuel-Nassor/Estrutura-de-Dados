//declara��o de bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>

//declara��o da estrutura de cadastro
struct valores{
	struct valores*prox;//apontamento de valores para o cadastro seguinte
	int numero;
	char letra;
};

typedef struct valores cadastro;

//fun��o adicionar ao come�o
void adiciona_comeco(cadastro *alocacao){
	cadastro*novo=(cadastro *)malloc(sizeof(cadastro));//aloca��o de um novo espa�o do tipo registro em um espa�o do tamanho de cadastro
	
	if(!novo){
		printf("Mem�ria Insuficiente");
		exit(1);
	}
	
	printf("Informe um numero:\n");
	novo->numero = (getch() -48);
	system("cls");
	printf("Informe uma letra:\n\n");
	novo->letra = getch();
	novo->prox=NULL;
	
	if(alocacao->prox != NULL){
		novo->prox = alocacao->prox;
		alocacao->prox = novo;
		
	}else{
		alocacao->prox = novo;
	}
 	

}
				      
//fun��o para exibir tudo
void imprime(cadastro *alocacao){
	
	cadastro*exibe = alocacao->prox;//variavel tempor�ria para percorrer e comparar a lista
	if(alocacao->prox == NULL){
	printf("Lista vazia");
	}else{	
		while(exibe->prox != NULL){
				printf("%i\t",exibe->numero);
				printf("%c\n\n",exibe->letra);
				exibe = exibe->prox;
			}
			printf("%i\t",exibe->numero);
			printf("%c\n\n",exibe->letra);
			
	}
	system("pause>>null");
}
			 
//fun��o para exibir espec�fico
void imprime_especifico(cadastro *alocacao){
	
	
	cadastro *vlr = alocacao->prox;//variavel para exibir os valores
	cadastro *aux =(cadastro *)malloc(sizeof(cadastro));//variavel para pesquisar 
	cadastro *temp = alocacao->prox;//variavel tempor�ria para percorrer e comparar a lista
	
	printf("Informe o n�mero que deseja consultar\n\n");
	aux->numero = (getch()-48);
	printf("Informe a letra que deseja consultar\n\n");
	aux->letra = getch();
	system("cls");
	cadastro*exibe = alocacao->prox;//variavel tempor�ria para percorrer e comparar a lista
	
	if(alocacao->prox == NULL){
		printf("Lista vazia");
	}else{
	while(temp->prox != NULL){
			if(temp->numero == aux->numero and temp->letra == aux->letra){
				vlr = temp;
			}
			temp = temp->prox;
			
			if(temp->prox == NULL and temp->numero == aux->numero and temp->letra == aux->letra){
				vlr = temp;	
			}
	}}
	printf("%i\t",vlr->numero);
	printf("%c\n\n",vlr->letra);
	system("pause>>null");
}

//fun��o adicionar ao fim
void adiciona_fim(cadastro *alocacao){
	
	cadastro *temp = alocacao->prox;//variavel tempor�ria para percorrer e comparar a lista
	cadastro *novo=(cadastro *)malloc(sizeof(cadastro));//aloca��o de um novo espa�o do tipo registro em um espa�o do tamanho de cadastro
	
	if(!novo){
		printf("Mem�ria Insuficiente!!!");
		exit(1);}
	if(temp == NULL){
		alocacao->prox = novo;		
	}else{
		alocacao->prox = temp;		
		while(temp->prox != NULL){//la�o para percorrer a lista at� encontrar o fim
			temp=temp->prox;
		}
		temp->prox = novo;
	}
	novo->prox = NULL;
	
	printf("Informe um numero:\n");
	novo->numero = (getch() -48);
	system("cls");
	printf("Informe uma letra:\n");
	novo->letra = getch();
}
				  
//fun��o remover o primeiro elemento
void remove_primeiro(cadastro *alocacao){
	
	cadastro*exibe = alocacao->prox;//variavel tempor�ria para percorrer e comparar a lista
	if(alocacao->prox == NULL){
		printf("Lista vazia");
		system("pause>>null");
	}else{
		cadastro *aux = alocacao->prox;//vari�vel a ser excluida
		alocacao->prox = aux->prox;
		aux = NULL;
		free(aux);
	}
}

//fun��o remove tudo
void remove_tudo(cadastro *alocacao){
	if(alocacao->prox == NULL){
		printf("Lista vazia");
		system("pause>>null");
	}else{
	while(alocacao->prox != NULL){
		
		cadastro *aux = alocacao->prox;
		alocacao->prox = aux->prox;
		aux = NULL;
		free(aux);
	}}
	
}

//fun��o remove espec�fico
void remove_especifico(cadastro *alocacao){
	
	cadastro *aux = alocacao->prox;
	cadastro *temp = alocacao->prox;
	cadastro *especifico = (cadastro *)malloc(sizeof(cadastro));//variavel para pesquisar 
	
	printf("Informe o n�mero que deseja remover\n\n");
	especifico->numero = (getch()-48);
	printf("Informe a letra que deseja remover\n\n");
	especifico->letra = getch();
	system("cls");
	
	temp = alocacao->prox;
	aux = alocacao;
	
	while(temp->prox != NULL){
		
		if(temp->numero == especifico->numero and temp->letra == especifico->letra){
				aux->prox = temp->prox;
				temp = NULL;
				free(temp);
				break;
		}
		temp = temp->prox;
		aux = aux->prox;
		
		if(temp->prox == NULL and temp->numero == especifico->numero and temp->letra == especifico->letra){
			aux->prox = temp->prox;
			free(temp);
		} 
	}
}
		  
int opc;

//fun��o principal
main(){

	setlocale(LC_ALL,"portuguese");//habilita a acentua��o
	
	cadastro *alocacao = (cadastro *)malloc(sizeof(cadastro));//teste de aloca��o de mem�ria e defini��o da origem do ponteiro
	
		if(not alocacao){
			printf("N�o h� mem�ria dispon�vel!!");
			exit(1);
		}
		alocacao->prox = NULL;//aponta o in�cio para nulo
		
	while(1==1){
	
	 system("cls");	
	 
		printf("\t\tSelecione uma op��o:\n\n\n1- Adicionar ao fim da lista\n2- Exibir todos os valores\n3- Exibir valor espec�fico\n4- Adicionar ao come�o da lista\n5- Remover o primeiro elemento\n6- Remover tudo\n7- Remover elemento espec�fico\n8- Sair\n\n");
	
		opc = (getch() -48);
		system("cls");
		
		switch(opc){
			
			case 1:{
				adiciona_fim(alocacao);
				break;}
				
			case 2:{
				imprime(alocacao);
				break;}
	
			case 3:{
				imprime_especifico(alocacao);
				break;
			}

			case 4:{
				adiciona_comeco(alocacao);
				break;
			}
	
			case 5:{
				remove_primeiro(alocacao);
				break;
			}
	
			case 6:{
				remove_tudo(alocacao);
				break;
			}

			case 7:{
				remove_especifico(alocacao);
				break;
			}
				
			case 8:{
				system("cls");
				return(0);
				break;
			}
		
			default:
				printf("Valor inv�lido!");
		}
	}

	return (0);
	
}



