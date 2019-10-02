/*
Esta biblioteca possui as fun��es:

carregar -> permite ler dados de um arquivo de texto para a mem�ria
descarregar -> permite escrever dados da mem�ria em arquivo de texto
desaloca -> libera mem�ria utilizada ap�s grava��o em arquivo de texto 

estrutura para receber dados do arquivo*/
typedef struct cad{
	
	char nome[30];
	int numero;
	
}cad;

//fun��o para ler do arquivo para a struct
void carregar(FILE *livros,lista *acervo){
	
	//abre o arquivo livros
	livros = fopen("pre-lista.txt","r");
	
	//ponteiro tempor�rio para percorrer a lista
	lista *temp;
	
	//struct para receber os dados do arquivo
	cad recebe;
	
	//passa struct do arquivo para a lista
	while((fread(&recebe,sizeof(recebe),1,livros))==1){
	
		//cria uma nova aloca��o/
		lista *novo = (lista *)malloc(sizeof(lista));
		novo->prox = NULL;
		novo->ant = NULL;
		
		//transp�e os dados para a lista
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
			
			//printf("\n\ncondi��o2\n\n");
			
		//adiciona ao fim
		}else{
			
			//percorre a lista at� encontrar o final
			while(temp->prox!= NULL){
				
				temp= temp->prox;
				
			}
			
			//inser��o ao fim da lista
			temp->prox = novo;
			novo->ant = temp;	
			//printf("\n\ncondi��o3\n\n");			
		}		
	}
	
	fclose(livros);
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------

//fun��o para liberar mem�ria alocada
void desaloca(lista *acervo){
	
	//la�o que percorre e libera a lista
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

//fun��o para reescrever struct no arquivo
void descarregar(lista *acervo,FILE *livros){
	
	//ponteiro temporario
	lista *temp = acervo->prox;
	
	//struct para guardar em arquivo
	cad recebe;
	
	//abre arquivo em modo escrita
	livros = fopen("log.txt","w");		
			
	while(temp->prox != NULL){
		
		//transp�e os dados para armazenamento
		strcpy(recebe.nome,temp->nome);
	 	recebe.numero = temp->numero;
		
		//escreve a struct no arquivo
		fwrite(&recebe,sizeof(recebe),1,livros);
		temp = temp->prox;
	}
	
	//armazena a ultima struct
	if(temp->prox == NULL){
	
	//transp�e os dados para armazenamento
		strcpy(recebe.nome,temp->nome);
	 	recebe.numero = temp->numero;
		
		//escreve a struct no arquivo
		fwrite(&recebe,sizeof(recebe),1,livros);
	}
	
	//fecha o arquivo
	fclose(livros);
}
