#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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