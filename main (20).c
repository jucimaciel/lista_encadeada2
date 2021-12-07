#include <stdio.h>
#include <stdlib.h>

struct lista {
int info;
struct lista* prox;
};

typedef struct lista Lista;
Lista *L1, *L2; 

Lista *addL1(){
Lista* novL1 = (Lista*) malloc(sizeof(Lista));
printf("informe o valor que deseja: ");
	scanf("%d", &novL1->info);
	
	novL1->prox = NULL;
	
	if(L1 == NULL) {
		L1 = novL1;
	} else{
		Lista *aux = L1;
    while(aux->prox != NULL) {
      aux = aux->prox;

		}
		aux->prox = L1;	
	}
  return L1;
}
Lista *addL2(){
Lista* novL2 = (Lista*) malloc(sizeof(Lista));
printf("informe o valor que deseja: ");
	scanf("%d", &novL2->info);
	
	novL2->prox = NULL;
	
	if(L2 == NULL) {
		L2 = novL2;
	} else{
		Lista *aux1 = L2;
    while(aux1->prox != NULL) {
      aux1 = aux1->prox;

		}
		aux1->prox = L2;	
	}
  return L2;
}
void lista_imprime(Lista *Listar) {
	if(Listar != NULL) {
		printf("%d ", Listar->info);
		lista_imprime(Listar->prox);
	}
}
Lista *concatena(Lista *L1, Lista *L2){
  	Lista *encad = L2;
while(encad->prox != NULL) {
		encad = encad->prox;
	
	encad->prox = L1;
}
	return encad;
}


int main() {
	int auxi = 0, opcao;
	char cond = 's';
Lista *L1, *L2, *L3;	
	do{
    printf("\tMenu\n");
		printf("(1) - Lista L1\n");
		printf("(2) - Lista L2\n");
		printf("(3) - listas L1 e L2\n");
		printf("(0) - finalizar programa!\n");
		printf("sua opcao: ");
		scanf("%d", &opcao);
    switch(opcao) {
			case 1:
				do{
					printf("(1) - informar os valores\n");
					printf("(2) - imprimior os valores\n");
					printf("(0) - inico\n");
					printf("sua opcao: ");
					scanf("%d", &opcao);
          switch(opcao) {
						case 1:
							cond = 's';
							while(cond != 'n') {
								L1=addL1();
								printf("deseja prossegir? [s / n] : ");
								scanf("%s", &cond);
							}
							break;
        case 2:
							lista_imprime(L1);
case 3:
							auxi = 2;
							break;
							
						default:
							printf("(erro) opcao nao encontrada\n");
					}
				} while(auxi != 2);
				
				break;
        case 2:
				do{
					
					printf("(1) - informar os valores\n");
					printf("(2) - imprimior os valores\n");
					printf("(0) - inico\n");
					printf("sua opcao: ");
					scanf("%d", &opcao);
          switch(opcao) {
						case 1:
							cond = 's';
							while(cond != 'n') {
								L2 =addL2();
								printf("voce quer continuar? [s / n] : ");
								scanf("%s", &cond);
							}
							break;
              default:
							printf("(erro) opcao nao encontrada\n");
					}
				} while(auxi != 3);
				
				break;
				
			case 3:
				L3 = concatena(L1, L2);
				break;
				
			case 4:
				printf("operacao finalizada: ");
				auxi = 1;
				break;
				
			default:
				printf("(error) opcao nao encontrada(\n");
		}
	} while(auxi != 1);


return 0;
}
