#include<stdio.h>
#include<stdlib.h>


int aux,vlr[5]= {7,3,8,1,6};
int i,m=4;
 
main(){
	
	for(i=0;i<5;i++){
	printf("%i",vlr[i]);
	}
	printf("\n");
	for(m=4;m>=0;m--){
		printf("%i",vlr[m]);
	}
	
	return(0);
}
