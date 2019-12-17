#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

typedef struct Data
{
    int dia, mes, ano;
} Data;

Data criarData(int dia, int mes, int ano);
Data lerData();
void imprimirData(Data data);
void imprimirDataExtenso(Data data);

#endif