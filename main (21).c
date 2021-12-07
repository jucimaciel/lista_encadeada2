#include <stdio.h>
#include <stdlib.h>


struct listadenumero{
	int v;
	struct listadenumero *proximo;
};

typedef struct listadenumero num;
num *inicio;




void infonumero() {
	num *va = malloc(sizeof(num));
	
	printf("Digite o valor: ");
	scanf("%d", &va->v);
	
	va->proximo = NULL;
	
	if(inicio == NULL) {
		inicio = va;
	} else {
		num *auxiliar = inicio;
		
		while(auxiliar->proximo != NULL) {
			auxiliar = auxiliar->proximo;
		}
		
		auxiliar->proximo = va;
	}
}

void imprimir(num *va) {
	if(va != NULL) {
		printf("%2d ", va->v);
		imprimir(va->proximo);
	}
}

num *remover(num *va){
	num *novo = va;
	num *remover;
	
	if(novo != NULL) {
		
		if(novo->proximo->v <= 0) {
			printf("novo: %d ", novo->v);	
			novo->proximo = novo->proximo->proximo;	
		}
		
		printf("remover:%d", novo->v);
		remover(novo->proximo);
	}
	return novo;
}

int main() {
	int auxi = 0, opcao;
	char cond = 'S';
	num *novonum;
	
	do{
		printf("menu\n");
		
	        printf("(1) - informar os valores\n");
					printf("(2) - imprimior os valores\n");
          printf("(2) - informar negativos\n");
					printf("(0) - inico\n");
					printf("sua opcao: ");
					scanf("%d", &opcao);
		
		switch(opcao) {
			case 1:
				opcao = 'S';
				while(opcao != 'N') {
					infonumero();
					printf("Desejar continuar? [S / N]: ");
					scanf("%d", &opcao);
				}
				break;
			case 2:
				imprimir(inicio);
				break;
			case 3:
				novonum = remover(inicio);
								break;
			case 4:
				printf("operacao finalizada;)\n");
				auxi = 1;
				break;
			default:
							printf("(erro) opcao nao encontrada\n");
		}
	} while(auxi != 1);
	
	return 0;
}