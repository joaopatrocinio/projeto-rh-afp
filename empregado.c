#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "comum.h"
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
    printf("\nCodigo: ");
    fflush(stdin);
    scanf("%d", &novoEmpregado.codigo);
    printf("Nome: ");
    fflush(stdin);
    scanf("%[^\n]", novoEmpregado.nome);
    printf("Morada: ");
    fflush(stdin);
    scanf("%[^\n]", novoEmpregado.morada);
    printf("Genero: ");
    scanf(" %c", &novoEmpregado.genero);
    printf("Data de nascimento:\n");
    novoEmpregado.data_nascimento = lerData();
    printf("\nData de inicio de ferias:\n");
    novoEmpregado.ferias_inicio = lerData();
    printf("\nData de fim de ferias:\n");
    novoEmpregado.ferias_fim = lerData();

    return novoEmpregado;
}

void mostrarEmpregado(Empregado empregado)
{
    printf("\n-> Codigo: %d\n", empregado.codigo);
    printf("-> Nome: %s\n", empregado.nome);
    printf("-> Morada: %s\n", empregado.morada);
    printf("-> Data de Nascimento: ");
    imprimirData(empregado.data_nascimento);
    printf("-> Data de inicio de ferias: ");
    imprimirData(empregado.ferias_inicio);
    printf("-> Data de fim de ferias: ");
    imprimirData(empregado.ferias_fim);
}
