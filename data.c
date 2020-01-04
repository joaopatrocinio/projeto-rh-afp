#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "data.h"

Data criarData(int dia, int mes, int ano)
{
    Data data;
    data.dia = dia;
    data.mes = mes;
    data.ano = ano;
    return data;
}

Data lerData()
{
    Data data;
    printf("Introduza o dia: ");
    scanf("%d", &data.dia);
    printf("Introduza o mes: ");
    scanf("%d", &data.mes);
    printf("Introduza o ano: ");
    scanf("%d", &data.ano);
    return data;
}

void imprimirData(Data data)
{
    printf("%02d/%02d/%04d\n", data.dia, data.mes, data.ano);
}

void imprimirDataExtenso(Data data)
{
    char mes_extenso[12];
    switch (data.mes)
    {
        case 1:
        {
            strcpy(mes_extenso, "Janeiro");
            break;
        }
        case 2:
        {
            strcpy(mes_extenso, "Fevereiro");
            break;
        }
        case 3:
        {
            strcpy(mes_extenso, "Marco");
            break;
        }
        case 4:
        {
            strcpy(mes_extenso, "Abril");
            break;
        }
        case 5:
        {
            strcpy(mes_extenso, "Maio");
            break;
        }
        case 6:
        {
            strcpy(mes_extenso, "Junho");
            break;
        }
        case 7:
        {
            strcpy(mes_extenso, "Julho");
            break;
        }
        case 8:
        {
            strcpy(mes_extenso, "Agosto");
            break;
        }
        case 9:
        {
            strcpy(mes_extenso, "Setembro");
            break;
        }
        case 10:
        {
            strcpy(mes_extenso, "Outubro");
            break;
        }
        case 11:
        {
            strcpy(mes_extenso, "Novembro");
            break;
        }
        case 12:
        {
            strcpy(mes_extenso, "Dezembro");
            break;
        }
    }

    printf("%02d de %s de %04d\n", data.dia, mes_extenso, data.ano);
}

Data dataAtual()
{
    int dia, mes, ano;

	time_t now;
	time(&now);

	struct tm *local = localtime(&now);

    dia = local->tm_mday;
    mes = local->tm_mon + 1;   	    // get month of year (0 to 11)
    ano = local->tm_year + 1900;	// get year since 1900

    Data data = criarData(dia, mes, ano);
    return data;
}

int calcularIdade(Data data_nasc)
{
    Data data_atual = dataAtual();

    int idade = data_atual.ano - data_nasc.ano;

    // verificar se ja fez anos no ano corrente
    if (data_atual.mes <= data_nasc.mes && data_atual.dia <= data_nasc.dia)
    {
        // retirar um ano se ainda não fez
        idade--;
    }

    return idade;
}
