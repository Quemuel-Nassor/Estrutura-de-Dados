/*
Esta biblioteca possui as funções:

carregar -> permite ler dados de um arquivo de texto para a memória
descarregar -> permite escrever dados da memória em arquivo de texto
desaloca -> libera memória utilizada após gravação em arquivo de texto 

estrutura para receber dados do arquivo*/
typedef struct cad{
	
	char nome[30];
	int numero;
	
}cad;

//função para ler do arquivo para a struct
void carregar(FILE *livros,lista *acervo){
	
	//abre o arquivo livros
	livros = fopen("pre-lista.txt","r");
	
	//ponteiro temporário para percorrer a lista
	lista *temp;
	
	//struct para receber os dados do arquivo
	cad recebe;
	
	//passa struct do arquivo para a lista
	while((fread(&recebe,sizeof(recebe),1,livros))==1){
	
		//cria uma nova alocação/
		lista *novo = (lista *)malloc(sizeof(lista));
		novo->prox = NULL;
		novo->ant = NULL;
		
		//transpõe os dados para a lista
		strcpy(novo->nome,recebe.nome);
		novo->numero = recebe.numero;
		
		//verifica o inicio da lista
		if(acervo->prox == NULL){
		
			acervo->prox = novo;
			novo->ant = acervo;
			temp = acervo->prox;
			
			//printf("\n\ncondicao1\n\n");
			
		//verifica o segundo item da lista
		}else if(temp->prox == NULL){
			
			temp->prox = novo;
			novo->ant = temp;
			
			//printf("\n\ncondição2\n\n");
			
		//adiciona ao fim
		}else{
			
			//percorre a lista até encontrar o final
			while(temp->prox!= NULL){
				
				temp= temp->prox;
				
			}
			
			//inserção ao fim da lista
			temp->prox = novo;
			novo->ant = temp;	
			//printf("\n\ncondição3\n\n");			
		}		
	}
	
	fclose(livros);
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------

//função para liberar memória alocada
void desaloca(lista *acervo){
	
	//laço que percorre e libera a lista
	while(acervo->prox!= NULL){
		
		lista *temp = acervo->prox;
		acervo->prox = temp->prox;
		
		if(temp->prox == NULL){
		
			free(temp);
			break;
			
		}
		
		temp->prox->ant = acervo;
		free(temp);
		
	}
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------

//função para reescrever struct no arquivo
void descarregar(lista *acervo,FILE *livros){
	
	//ponteiro temporario
	lista *temp = acervo->prox;
	
	//struct para guardar em arquivo
	cad recebe;
	
	//abre arquivo em modo escrita
	livros = fopen("log.txt","w");		
			
	while(temp->prox != NULL){
		
		//transpõe os dados para armazenamento
		strcpy(recebe.nome,temp->nome);
	 	recebe.numero = temp->numero;
		
		//escreve a struct no arquivo
		fwrite(&recebe,sizeof(recebe),1,livros);
		temp = temp->prox;
	}
	
	//armazena a ultima struct
	if(temp->prox == NULL){
	
	//transpõe os dados para armazenamento
		strcpy(recebe.nome,temp->nome);
	 	recebe.numero = temp->numero;
		
		//escreve a struct no arquivo
		fwrite(&recebe,sizeof(recebe),1,livros);
	}
	
	//fecha o arquivo
	fclose(livros);
}
