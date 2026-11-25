#include <stdio.h>

/* Declaração antecipada das funções necessárias para o cálculo */
int diasNoMes(int mes, int ano);
int ehBissexto(int ano);
int validarData(int dia, int mes, int ano);
long dataParaDias(int dia, int mes, int ano);

/* Converte um número absoluto de dias de volta para o formato de data (dia, mes, ano) */
void diasParaData(long totalDias, int *dia, int *mes, int *ano){
    int a = 1;
    int m = 1;
    long diasNoAno;
    
    /* Descobre o ano */
    while (1) {
        diasNoAno = ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0)) ? 366 : 365;
        if (totalDias <= diasNoAno) break;
        totalDias -= diasNoAno;
        a++;
    }
    *ano = a;
    
    /* Descobre o mês */
    while (1) {
        long diasMes = diasNoMes(m, *ano);
        if (totalDias <= diasMes) break;
        totalDias -= diasMes;
        m++;
    }
    *mes = m;
    
    /* O que sobra são os dias */
    *dia = (int)totalDias;
}

/* 
 * TRECHO DO CASE 5 (Para colocar dentro do switch na main):
 * 
        case 5: {
            int d1, m1, a1, qtdDias;
            
            printf("\n--- DIGITE A DATA INICIAL ---\n");
            printf("Digite o dia: ");
            scanf("%d", &d1);
            printf("Digite o mes: ");
            scanf("%d", &m1);
            printf("Digite o ano: ");
            scanf("%d", &a1);
            
            if (!validarData(d1, m1, a1)) {
                printf("\n[ERRO] Data inicial invalida!\n");
                break;
            }
            
            printf("Digite a quantidade de dias a somar: ");
            scanf("%d", &qtdDias);
            
            {
                long dias1 = dataParaDias(d1, m1, a1) + qtdDias;
                diasParaData(dias1, &d1, &m1, &a1);
            }
            
            printf("\n=> A data final do periodo e: %02d/%02d/%d\n", d1, m1, a1);
            break;
        }
*/
