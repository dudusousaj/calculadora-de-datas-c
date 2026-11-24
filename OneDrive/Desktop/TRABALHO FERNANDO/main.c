#include <stdio.h>

/* FUNÇÕES */
 
int menu();
int ehBissexto(int ano);
int diasNoMes(int mes, int ano);
int validarData(int dia, int mes, int ano);
long dataParaDias(int dia, int mes, int ano);
void diasParaData(long totalDias, int *dia, int *mes, int *ano);

int main(void){
	int opcao;
	
	do{
		opcao = menu();
		switch(opcao)
		{
		case 1:
			printf("Voce escolheu a opcao 1");
			break;
		case 2:
			printf("Voce escolheu a opcao 2");
			break;
		case 3:
			printf("Voce escolheu a opcao 3");
			break;
		case 4:
			printf("Voce escolheu a opcao 4");
			break;
		case 5:
			printf("Voce escolheu a opcao 5");
			break;
		case 0:
			printf("O PROGRAMA SERA ENCERRADO");
			break; 
		default:
			printf("Opcao Invalida");
		}
	}
	while(opcao != 0);
	
	return 0;
}

int menu(){
	int opcao;
	
	printf("\n CALCULADORA DE DATAS \n");
	
	printf("\n1- Datas no mesmo mes");
	printf("\n2- Datas no mesmo ano");
	printf("\n3- Datas em anos consecutivos");
	printf("\n4- Datas em quaisquer anos");
	printf("\n5- Calcular data final");
	printf("\n0- Sair");
	
	printf("\n\nEscolha uma opcao:");
	scanf("%d", &opcao);
	
	return opcao;
}

