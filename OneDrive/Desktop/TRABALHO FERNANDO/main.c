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
/*Função para avaliar se a data digitada pelo usuário existe no calendário, com return 1 sendo verdadeiro e return 0 falso*/
int validarData(int dia, int mes, int ano){
	/*teste para saber a viabilidade de anos,considerando seu começo como 1*/
	if(ano < 1){
		return 0;
	}
	/*Teste para saber a viabilidade de meses no interválo de 1 a 12*/
	if(mes <1 || mes > 12){
		return 0;
	}
	/*Teste para saber se a data não ultrapassa o limite do mês ou ano*/
	if(dia < 1 || dia > diasNoMes(mes,ano)){
		return 0;
	}
	return 1;
}
/*Função que converte os dias decorridos de 01/01/0001 até a data válida em questão*/
long dataParaDias(int dia, int mes, int ano){
	long total = 0;
	int i;
	
	/*Soma os dias totais de cada ano anterior,incluindo os bissextos,até o atual,sendo que o atual não é contado da mesma forma que os seus antecessores*/
	for(i = 1;i < ano; i++){
		if(ehBissexto(i) == 1){
			total = total + 366;
		}else{
			total = total + 365;
		}
	}
	/*Soma os dias de cada mês passado do ano atual,com o atual fora dessa conta*/
	for(i = 1;i < mes;i++){
		total = total+ diasNoMes(i, ano);
	}
	/*Soma os dias do mês atual,que não foram considerados anteriormente*/
	total = total + dia;
	return total;
}

