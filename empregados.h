#ifndef EMPREGADOS_H_INCLUDED
#define EMPREGADOS_H_INCLUDED

#include "comum.h"
#include "empregado.h"

typedef struct Empregados
{
    Empregado *listaEmpregados;
    int tamanho;
} Empregados;

void mostrarEmpregados(Empregados empregados);

#endif