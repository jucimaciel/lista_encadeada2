#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodalista{
char titulo[51];
char autor[51];
int ano;
int quantidade;
struct nodalista *prox;
};
typedef struct nodalista editora;
editora *inicio;
int estq=0;



void iniciodlista(){
  editora *livro=malloc(sizeof(editora));

printf("Insira o titulo:\n");
scanf("%s", livro->titulo);
printf("\n");
printf("Insira o autor:\n");
scanf("%s", livro->autor);
printf("\n");
printf("Insira o ano:\n");
scanf("%d", &livro->ano);
printf("\n");
printf("Insira a quantidade:\n");
scanf("%d", &livro->quantidade);

if(inicio==NULL){
  inicio=livro;
}
else{
  editora *livross=inicio;
  while(livross->prox != NULL) {
			livross = livross->prox;
		}
		
		livross->prox = livro;
	}
}
void imprimir(editora*livro){
  if(livro==NULL){
    printf("o titulo e: %s\n", livro->titulo);
    printf("o autor e: %s\n", livro->autor);
    printf("o ano e: %d\n", livro->ano);
    printf("a quantidade e: %d\n", livro->quantidade);
    imprimir(livro->prox);

}

}
int quant(editora*livro){
  if (livro!=NULL){
    estq +=livro->quantidade;
    quant(livro-> prox);
  }
  return estq;
}
void livros_ano(editora *livro, int ano){
  if(livro!=NULL){
    if(livro->ano==ano){
        printf(" o titulo e: %s\n", livro->titulo);
        printf("o autor e: %s\n", livro->autor);
        printf("o ano e: %d\n", livro->ano);
        printf("a quantidade e: %d\n", livro->quantidade);
    }

		livros_ano(livro->prox, ano);

  }
  
}
int main (){
  	int aux = 0;
    int opcao;
    int quandlivros;
    int anopublicacao;
    char cond='s';

    do {
      printf("\nmenu");
      printf("(1)-livros\n");
      printf("(2)-fechar\n");
      printf("outra opcao: \n");
      scanf("%d", &opcao);

      switch (opcao){
        case 1:
        do{
          printf("(1) - inserir livros desejado\n");
					printf("(2) - listar \n");
					printf("(3) - quantidade de livros desejado\n");
					printf("(4) - procurar o livro por ano\n");
					printf("[0] - inicio\n");
					printf("outra opcao: ");
					scanf("%d", &opcao);
          switch(opcao) {
						case 1:	
							cond = 's';
							while(cond != 'n'){
								iniciodlista();
								printf("voce desejaria continuar? (s / n) : ");
								scanf("%s", &cond);
							} 
							
							break;
							
						case 2:	
							imprimir(inicio);
							break;
						
						case 3:
							quandlivros = quant(inicio);
							printf("Estoque: %d\n", quandlivros);
							break;
							
						case 4:
							printf("informr o ano de publicacao: ");
							scanf("%d", &anopublicacao);
							livros_ano(inicio, anopublicacao);
							break;
							
						case 5:
							aux = 2;
							break;
							
						default:
							printf("(erro) Opcao nao existente\n");
					}
				} while(aux != 2);
				break;
			case 2:
				aux = 1;
        break;
			default:
				printf("(erro) Opcao n existente \n");
		}
	} while(aux != 1);
	
	return 0;
}
        

      
    


      



