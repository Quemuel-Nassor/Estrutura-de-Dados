/*
Esta biblioteca possui uma fun��o de ordena��o do tipo Insertion-Sort
que permite ordena��o num�rica crescente. 

fun��o de ordena��o numerica*/
void insertion(lista *inicio){
	
	//contadores
	int i = 1;
	
	//cria os comparadores
	lista *ref;
	lista *aux, *aux2;

	//verifica se a lista possui itens
	if(inicio->prox != NULL){
			
		//loop para verificar a ordena��o
		while(i != 0){
			
			//inicializa o contador
			i = 0;
			
			//posiciona os comparadores
			ref = inicio->prox;
			
			//loop de ordena��o da entrada 
			while(ref->prox != NULL){
				
				//posiciona o auxiliar
				aux = ref->prox;
				
/*==================================================================================================
condicionais para receber e ordenar os itens que s�o inseridos na lista com rela��o ao item anterior
*/					
				//verifica se o aux � menor que o ref
				if((aux->numero < ref->numero) and aux->prox != NULL){
					
					printf("trocando o %i com o %i\n",aux->numero,ref->numero);
					aux->prox->ant = ref;
					ref->ant->prox = aux;
					ref->prox = aux->prox;
					aux->ant = ref->ant;
					aux->prox = ref;
					ref->ant = aux;
					i++;
					
				}
						
				//verifica se o aux � menor que o ref na �ltima posi��o
				if((aux->numero < ref->numero) and aux->prox == NULL){
					
					printf("trocando o %i com o %i\n",aux->numero,ref->numero);
					ref->prox = aux->prox;
					aux->ant = ref->ant;
					ref->ant = aux;
					aux->prox = ref;
					aux->ant->prox = aux;
					i++;
				
				}
				
				printf("reposicionando comparadores fora da lista %i com %i\n\n",ref->numero, ref->prox->numero);
				//muda para a pr�xima posi��o na lista
				ref = ref->prox;
					
//==================================================================================================
					
				//loop de ordena��o dentro da lista
				while(aux->ant != NULL){
						
					//reposicionando os comparadores
					aux2 = aux->ant;
						
					//verificar e reposiciona o ultimo item da lista
					if(aux->numero < aux2->numero and aux2 == NULL){
						
						printf("trocando o %i com o %i\n",aux->numero,aux2->numero);
						
						aux2->prox = aux->prox;
						aux->ant = aux2->ant;
						aux->prox = aux2;
						aux2->prox->ant = aux2;
						aux2->ant = aux;
						i++;
						
					}
					
					//verificar e reposiciona os itens da lista
					if(aux->numero < aux2->numero and aux2 != NULL){
							
						printf("trocando o %i com o %i\n",aux->numero,aux2->numero);	
							
						aux2->prox = aux->prox;
						aux->ant = aux2->ant;
						aux->prox = aux2;
						aux2->prox->ant = aux2;
						aux2->ant = aux;
						aux->ant->prox = aux;
						i++;
						
					}
						
						printf("reposicionando comparadores dentro da lista%i com %i\n\n", aux->numero, aux2->numero);
					
						//muda para a posi��o anterior na lista
						aux = aux2;
				
				}
			}
		}
	}
}
