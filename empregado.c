#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data.h"
#include "empregado.h"

Empregado criarEmpregado(int codigo, char nome[], char morada[], char genero, Data data_nascimento, Data ferias_inicio, Data ferias_fim)
{
    Empregado novoEmpregado;
    novoEmpregado.codigo = codigo;
    strcpy(novoEmpregado.nome, nome);
    strcpy(novoEmpregado.morada, morada);
    novoEmpregado.genero = genero;
    novoEmpregado.data_nascimento = data_nascimento;
    novoEmpregado.ferias_inicio = ferias_inicio;
    novoEmpregado.ferias_fim = ferias_fim;
    return novoEmpregado;
}

Empregado inserirDadosEmpregado()
{
    Empregado novoEmpregado;
    printf("Codigo: ");
    fflush(stdin);
    scanf("%d", &novoEmpregado.codigo);
    printf("Nome: ");
    fflush(stdin);
    scanf("%[^\n]", novoEmpregado.nome);
    printf("Morada: ");
    fflush(stdin);
    scanf("%[^\n]", novoEmpregado.morada);
    return novoEmpregado;
}