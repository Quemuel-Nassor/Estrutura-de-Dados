/*
Esta biblioteca possui uma função de ordenação do tipo Bubble-Sort
que permite ordenação numérica crescente.

função de ordenação numerica*/
void buble(lista *ordena){
	
	//indicadores de passagem do loop
	int marcador = -5;
	
	if(ordena->prox == NULL){
		
		printf("Lista vazia!");
		sleep(2);
	
	}else{
	
		lista *temp1, *temp2;
		
		//loop secundário de verificação de ordenação 
		while(marcador !=0){
		
			temp1 = ordena->prox;
			temp2 = temp1->prox;
		
			marcador = 0;
			
			//loop primário de ordenação 
		 	while(temp2->prox != NULL){
	
				if((temp2->numero) < (temp1->numero)){
			 		
					temp1->prox = temp2->prox;
					temp2->prox->ant = temp1;
					temp2->ant = temp1->ant;
					temp1->ant->prox = temp2;
					temp1->ant = temp2;
					temp2->prox = temp1;
					
					marcador++;
				 	//printf(" LOOP1\n ");
				}
				temp1 = temp2;
				temp2 = temp2->prox;
				//printf(" MUDANÇA DE CAIXAS\n ");
			}
			
			//verificação de termos desordenados ao fim da lista
			if((temp2->prox == NULL ) and (temp2->numero < temp1->numero)){
				 
				 	temp1->prox = temp2->prox;
				 	temp2->prox = temp1;
				 	temp2->ant = temp1->ant;
				 	temp1->ant = temp2;
				 	temp2->ant->prox = temp2;
				 	marcador++;
				 	//printf(" marcador%i\n ",marcador);
				
			 }
		}
		//getchar();
	}
}
