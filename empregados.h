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
void adicionarEmpregado(Empregados *empregados, Empregado novoEmpregado);
void atualizarEmpregado(Empregados *empregados);
Empregado devolveEmpregadoPorCodigo(int codigo, Empregados *empregados, int *index);
void eliminarEmpregados(Empregados *empregados);

#endif
