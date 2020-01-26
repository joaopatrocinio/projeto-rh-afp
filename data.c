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
    int bissexto;
    int i = 0;

    // Validação da data. Continua no loop se não passar as verificações todas.
    do
    {
        if (i != 0) printf("\nData invalida.\n");
        i++;

        do
        {
            data.dia = devolverNumero("\nIntroduza o dia");
            if (data.dia <= 0)
            {
                printf("\n\t!! O dia introduzido nao e valido.\n\n");
            }
        }
        while (data.dia <= 0);

        do
        {
            data.mes = devolverNumero("Introduza o mes");
            if (data.mes <= 0)
            {
                printf("\n\t!! O mes introduzido nao e valido.\n\n");
            }
        }
        while (data.mes <= 0);

        do
        {
            data.ano = devolverNumero("Introduza o ano");
            if (data.ano <= 0)
            {
                printf("\n\t!! O ano introduzido nao e valido.\n\n");
            }
        }
        while (data.ano <= 0);

        if (data.ano % 400 == 0) {
            bissexto = 1;
        }
        else if ((data.ano % 4 == 0) && (data.ano % 100 != 0)) {
            bissexto = 1;
        }
        else {
            bissexto = 0;
        }

        if (data.mes > 12 || data.mes < 0) continue;

        if (bissexto == 0 && data.mes == 2 && (data.dia > 28 || data.dia < 0)) continue;
        if (bissexto == 1 && data.mes == 2 && (data.dia > 29 || data.dia < 0)) continue;

        if (data.mes == 1 || data.mes == 3 || data.mes == 5 || data.mes == 7 || data.mes == 8 || data.mes == 10 || data.mes == 12)
        {
            if (data.dia > 31 || data.dia < 0) continue;
        }
        if (data.mes == 4 || data.mes == 6 || data.mes == 9 || data.mes == 11)
        {
            if (data.dia > 30 || data.dia < 0) continue;
        }

        break;
    }
    while (1);

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
    mes = local->tm_mon + 1;
    ano = local->tm_year + 1900;

    Data data = criarData(dia, mes, ano);
    return data;
}

int calcularIdade(Data data_nasc)
{
    Data data_atual = dataAtual();

    int month[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int bissexto;

    // Ver se ano é bissexto, se não for muda fevereiro para 28 dias.
    if (data_atual.ano % 400 == 0)
    {
        bissexto = 1;
    }
    else if ((data_atual.ano % 4 == 0) && (data_atual.ano % 100 != 0))
    {
        bissexto = 1;
    }
    else
    {
        bissexto = 0;
    }
    if (bissexto == 0) month[1] = 28;

    // calcular idade
    if (data_nasc.dia > data_atual.dia)
    {
        data_atual.dia = data_atual.dia + month[data_nasc.mes - 1];
        data_atual.mes = data_atual.mes - 1;
    }
    if (data_nasc.mes > data_atual.mes)
    {
        data_atual.ano = data_atual.ano - 1;
        data_atual.mes = data_atual.mes + 12;
    }

    int idade = data_atual.ano - data_nasc.ano;

    return idade;
}
