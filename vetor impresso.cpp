#include<stdio.h>
#include<stdlib.h>


int i=0,m,list[5];

main(){
	while(i<5){
	
	system("cls");
	printf("Informe um numero:\n");
	scanf("%i",&list[i]);
	i++;}
	
	printf("\n\n\n");
	for(i=0;i<5;i++){
		printf("%i",list[i]);
		
	}
	printf("\n");
	for(m=4;m>=0;m--){
		printf("%i",list[m]);
	}
	

	exit(0);
}
