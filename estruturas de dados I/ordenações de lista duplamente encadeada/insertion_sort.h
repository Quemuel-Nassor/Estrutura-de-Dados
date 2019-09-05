//função de ordenação numérica
void insertion(lista *inicio){
	
	//contadores
	int count,count1 = 1;
	
	//laço de verificação se está ordenado
	while(count1 != 0){
		/*printf(" linha 9 laço do count1 contador que verifica se esstá ordenado\n\n\n");
		system("pause");
		system("cls");*/
		count1 = 0;
		
		//verificação de itens na lista
		if(inicio->prox == NULL){
			
			printf("Lista vazia!");
			sleep(2);
		
		}else{
			
			//ponteiros e variáveis
			lista *ref = inicio->prox;
			lista *aux = ref->prox;
			lista *ord;
			
			
//--------------------------------------------------------------------------------	
			//laço de ordenação
			while(ref->prox != NULL){
				/*printf("linha 29 laço de ordenação primario passa o ref para frente\n");
				system("pause");
				system("cls");*/
				count = 1;
				
				if(aux->numero < ref->numero){
					
					
					/*printf("linha 37 condicao1, troca efetivamente o ref %i de posição com o aux %i\n",ref->numero,aux->numero);
					system("pause");
					system("cls");*/
					//troca o ref de posição com o valor seguinte
					aux->prox->ant = ref;
					ref->ant->prox = aux;
					ref->prox = aux->prox;
					aux->ant = ref->ant;
					aux->prox = ref;
					ref->ant = aux;
					/*exibe(inicio);
					printf("linha49");system("pause");*/
					count1++;
				
					
				}else if(aux->numero > ref->numero){
					
					
					/*printf("linha 55 condicao2, atribui ref %i ao valor seguinte, no caso o %i\n",ref->numero,aux->numero);
					system("pause");
					system("cls");*/
					//ref recebe o valor seguinte
					ref = aux;
					/*exibe(inicio);
					printf("linha 61");system("pause");*/
					count1++;
				
					
				}
				
//=============================================================================================================================================================				
				//laço de ordenação anterior ao ref
				while(count != 0){
					/*printf("linha 68, laço de ordenação da parte de trás da lista\n\n\n\n");
					system("pause");
					system("cls");
					printf("linha 72 valor do ord %i\n",aux->ant->numero);*/
					ord  = aux->ant;
					count  = 0; 
						
					//laço de ordenação da lista 
					while(aux->ant != NULL){
						/*printf("linha 81 entrou no laço de troca do aux %i com o de trás %i\n\n\n",aux->numero,aux->ant->numero);
						system("pause");
						system("cls");*/
						
			
						//se o numero anterior ao aux for maior	
						if((ord->ant != NULL) and ((ord->numero) > (aux->numero))){
									
							/*printf("linha 87 trocou o aux %i de posição com o anterior %i\n",aux->numero,ord->numero);
							system("pause");
							system("cls");*/
							ord->ant->prox = aux;
							aux->prox->ant = ord;
							ord->prox = aux->prox;
							aux->ant = ord->ant;
							aux->prox = ord;
							ord->ant = aux;
							count++;
							/*printf("linha 99");system("pause");
							exibe(inicio);
							printf("linha 101");system("pause");*/
							//ord  = ord->ant;
						
						//se o anterior ao ORD for nulo	
						}else if((ord->ant == NULL) and ((ord->numero) > (aux->numero))){
							
							/*printf("linha 103 trocou o aux %i de posição com o anterior %i\n",aux->numero,ord->numero);
							system("pause");
							system("cls");*/
							ord->prox = aux->prox;
							aux->prox= ord;
							aux->ant = ord->ant;
							ord->ant = aux;
							count++;
							/*exibe(inicio);
							printf("linha 115");system("pause");*/
							//ord  = ord->ant;
							
						}/*else {
							printf("\n\nexcessão das duas primeiras condicoes, aux %i, ord %i count %i",aux->numero,ord->numero,count);
							system("pause>>null");system("cls");
						}*/
						ord  = ord->ant;
						aux = aux->ant;
						//printf("\n\nexcessão das 3 condicoes, aux %i, ord %i count %i",aux->numero,ord->numero,count);system("pause>>null");system("cls");
						//printf("\n\ncontinua no loop \n\n");system("pause>>null");system("cls");
					}//if(aux->ant == NULL){printf("saiu do loop interno de ordenação para trás do ref"),system("pause>>null");system("cls");}
					aux = ref->prox;
					
				}//if(count != 0){printf("saiu do loop externo de verificação de ordenação para trás do ref"),system("pause>>null");system("cls");}
//=============================================================================================================================================================				
				
				ref = ref->prox;
				aux = ref->prox;

//--------------------------------------------------------------------------------				
			}
			
		}
	}
}
