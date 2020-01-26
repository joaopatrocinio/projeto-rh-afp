#ifndef EMPREGADO_H_INCLUDED
#define EMPREGADO_H_INCLUDED

#include "data.h"
#include "categoria.h"

typedef struct Empregado
{
    int codigo;
    char nome[51], morada[151];
    char genero, categoria;
    float salario;
    Data data_nascimento, ferias_inicio, ferias_fim;
} Empregado;

Empregado criarEmpregado(int codigo, char nome[], char morada[], char genero, Data data_nascimento, Data ferias_inicio, Data ferias_fim, float salario, char categoria);
Empregado inserirDadosEmpregado();
void mostrarEmpregado(Empregado empregado);

#endif
