//bibliotecas
#include<stdio.h>
#include<windows.h>
#include<string.h>

int u=0,i=0,tempo_total = 1000;  // tempo em milisegundos
float progresso = 0;	//contador
char p[8],desenho[40];	//vari�veis de desenhos ou s�mbolos

int main(){
 	
	 while(progresso<100){	//la�o de repeti��o do menu
	 	
	 	if(i>=6 or (progresso>=95)){	//reseta os pontinhos a cada 6 ciclos
			i=0;
			strcpy(p,"");
		}
		system("cls");	//limpa a tela(atualiza)

		printf("Carregando");
		printf("%s",p);
		strcat(p,".");	//adiciona um ponto a cada ciclo
		
		strcat(desenho,"\xB2");	//adiciona uma figura a string a cada 5%	
		printf("\n\n\n%s",desenho);
		
		progresso = progresso + 5; //A cada 5% a barra de progresso ser� atualizada
		Sleep(tempo_total);	//temporizador
		i++;
	}
}
