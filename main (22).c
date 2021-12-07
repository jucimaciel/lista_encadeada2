#include <stdio.h>
#include <stdlib.h>
struct num{
  int numero;
  struct num*proximo;
};
typedef struct num TipoLista;
TipoLista *inicio;

void iniciolista(){
  	TipoLista *lista = malloc(sizeof(TipoLista));
printf("informe o valor que deseja: ");
	scanf("%d", &lista->numero);
	
	lista->proximo = NULL;
	
	if(inicio == NULL) {
		inicio = lista;
	} else{
		TipoLista *auxi= inicio;
    while(auxi->proximo != NULL) {
			auxi = auxi->proximo;
		}
		
		auxi->proximo = lista;
		
	}
}

void inverter(TipoLista*lista){
  if(lista != NULL) {
		inverter(lista->proximo);
		printf("%d ", lista->numero);
}
}
void imprimir(TipoLista *lista) {
	if(lista != NULL) {
		printf("%d ", lista->numero);
		imprimir(lista->proximo);
	}
}
int main() {
	int aux = 0;
  int opcao;
	char cond = 's';
	
	do{
		printf("menu\n");
		printf("(1) - informar os numeros\n");
		printf("(2) - listar \n");
		printf("(3) - ordem inversa dos num\n");
		printf("(0) - voltar\n");
		printf("\n outra opcao: \n");
		scanf("%d", &opcao);
    switch(opcao) {
						case 1:	
							cond = 's';
							while(cond != 'n'){
								iniciolista();
								printf("voce desejaria continuar? (s / n) : ");
								scanf("%s", &cond);
							} 
							
							break;
							
						case 2:	
							imprimir(inicio);
							break;
						
						case 3:
							inverter(inicio);
							break;
							
						case 4:
							printf("operacao finalizada: ");
              aux = 1;

							break;
							
			default:
				printf("(erro) Opcao n existente \n");
		}
	} while(aux != 1);
	
	return 0;
}
        

      
    


      






		




