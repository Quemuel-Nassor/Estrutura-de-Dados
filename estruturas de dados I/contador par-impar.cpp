#include<stdio.h>
#include<stdlib.h>

int num,i=0,par=0,impar=0,a;


main(){
	
	
	
	while(i<8){
		
		system("cls");
		printf("\n\nInforme um valor inteiro:\n");
		scanf("%i",&num);
	
		
		if (num%2 == 0){
			par ++;
		
		}else{
			impar ++;
		
		}
		system("cls");
		i++;
		
	}
	printf("\n\t Pares %i \n\t Impares %i",par,impar);
	
	exit(0);
}
