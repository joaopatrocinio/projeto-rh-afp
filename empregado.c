#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "comum.h"
#include "data.h"
#include "empregado.h"
#include "categoria.h"

Empregado criarEmpregado(int codigo, char nome[], char morada[], char genero, Data data_nascimento, Data ferias_inicio, Data ferias_fim, float salario, char categoria)
{
    Empregado novoEmpregado;
    novoEmpregado.codigo = codigo;
    strcpy(novoEmpregado.nome, nome);
    strcpy(novoEmpregado.morada, morada);
    novoEmpregado.genero = genero;
    novoEmpregado.data_nascimento = data_nascimento;
    novoEmpregado.ferias_inicio = ferias_inicio;
    novoEmpregado.ferias_fim = ferias_fim;
    novoEmpregado.salario = salario;
    novoEmpregado.categoria = categoria;
    return novoEmpregado;
}

Empregado inserirDadosEmpregado()
{
    Empregado novoEmpregado;

    printf("\n");

    // Pedir codigo (deve ser maior que 0)
    do
    {
        novoEmpregado.codigo = devolverNumero("Codigo");
        if (novoEmpregado.codigo <= 0)
        {
            printf("\n\t!! O codigo introduzido nao e valido.\n\n");
        }
    }
    while (novoEmpregado.codigo <= 0);

    // Nome e morada
    devolverString("Nome", novoEmpregado.nome);
    devolverString("Morada", novoEmpregado.morada);

    // Pedir genero (M ou F)
    do
    {
        novoEmpregado.genero = devolverCaracter("Genero (M/F)");
        novoEmpregado.genero = toupper(novoEmpregado.genero);
        if (novoEmpregado.genero != 'M' && novoEmpregado.genero != 'F')
        {
            printf("\n\t!! O genero introduzido nao e valido.\n\n");
        }
    }
    while (novoEmpregado.genero != 'M' && novoEmpregado.genero != 'F');

    // Pedir salario (deve ser maior que 0)
    do
    {
        novoEmpregado.salario = devolverFloat("Salario");
        if (novoEmpregado.salario <= 0)
        {
            printf("\n\t!! O salario introduzido nao e valido.\n\n");
        }
    }
    while (novoEmpregado.salario <= 0);

    // Categoria
    do
    {
        novoEmpregado.categoria = devolverCaracter("Categoria (M - Motorista / F - Fabril / A - Administrativo)");
        novoEmpregado.categoria = toupper(novoEmpregado.categoria);
        if (novoEmpregado.categoria != 'M' && novoEmpregado.categoria != 'F' && novoEmpregado.categoria != 'A')
        {
            printf("\n\t!! A categoria introduzida nao e valida.\n\n");
        }
    }
    while (novoEmpregado.categoria != 'M' && novoEmpregado.categoria != 'F' && novoEmpregado.categoria != 'A');

    // Datas
    printf("\n\tData de nascimento:\n\n");
    novoEmpregado.data_nascimento = lerData();
    printf("\n\tData de inicio de ferias:\n\n");
    novoEmpregado.ferias_inicio = lerData();
    printf("\n\tData de fim de ferias:\n\n");
    novoEmpregado.ferias_fim = lerData();

    return novoEmpregado;
}

void mostrarEmpregado(Empregado empregado)
{
    printf("\n-> Codigo: %d\n", empregado.codigo);
    printf("-> Nome: %s\n", empregado.nome);
    printf("-> Morada: %s\n", empregado.morada);
    printf("-> Genero: %c\n", empregado.genero);
    printf("-> Salario: %.2f\n", empregado.salario);
    printf("-> Categoria: %s\n", devolveCategoria(empregado.categoria));
    printf("-> Data de nascimento: ");
    imprimirData(empregado.data_nascimento);
    printf("-> Data de inicio de ferias: ");
    imprimirData(empregado.ferias_inicio);
    printf("-> Data de fim de ferias: ");
    imprimirData(empregado.ferias_fim);
}
