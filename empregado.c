#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "comum.h"
#include "data.h"
#include "empregado.h"
#include "empregados.h"
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

Empregado inserirDadosEmpregado(Empregados empregados)
{
    Empregado novoEmpregado;

    printf("\n");

    int codigo;
    // Pedir codigo (deve ser maior que 0)
    do
    {
        codigo = devolverNumero("Codigo");
        if (codigo <= 0)
        {
            printf("\n\tO codigo introduzido nao e valido!!\n");
        }
        if (validarCodigoExistente(empregados, codigo) == 1)
        {
            codigo = -1;
            printf("\n\t!! O codigo introduzido esta ocupado por outro empregado.\n\n");
        }
    }
    while (codigo <= 0);

    novoEmpregado.codigo = codigo;

    // Nome - Não deve aceitar numeros
    devolverString("Nome", novoEmpregado.nome);
    printf("\n");


    // Morada
    devolverString("Morada", novoEmpregado.morada);
    printf("\n");


    // Pede Género (M - Masculino ou F - Feminino)
    do
    {
        novoEmpregado.genero = devolverCaracter("Genero (M/F)");
        novoEmpregado.genero = toupper(novoEmpregado.genero);
        printf("\n");
        if (novoEmpregado.genero != 'M' && novoEmpregado.genero != 'F')
        {
            printf("\tO genero introduzido nao e valido!!\n\n");
        }
    }
    while (novoEmpregado.genero != 'M' && novoEmpregado.genero != 'F');


    // Pede o salário (deve ser maior que 0)
    //Nao deve aceitar letras
    do
    {
        novoEmpregado.salario = devolverFloat("Salario");
        if (novoEmpregado.salario <= 0)
        {
            printf("\nO salario introduzido nao e valido!!\n\n");
        }
        printf("\n");
    }
    while (novoEmpregado.salario <= 0);

    // Pede uma das categorias
    do
    {
        novoEmpregado.categoria = devolverCaracter("Categoria (M - Motorista / F - Fabril / A - Administrativo)");
        novoEmpregado.categoria = toupper(novoEmpregado.categoria);
        if (novoEmpregado.categoria != 'M' && novoEmpregado.categoria != 'F' && novoEmpregado.categoria != 'A')
        {
            printf("\n\tA categoria introduzida nao e valida!!\n\n");
        }
    }
    while (novoEmpregado.categoria != 'M' && novoEmpregado.categoria != 'F' && novoEmpregado.categoria != 'A');

    printf("\n");


    // Pede a data de nascimento
    printf("Data de nascimento:\n");
    novoEmpregado.data_nascimento = lerData();

    printf("\n");

    // Pede a data do inicio das férias
    printf("Data de inicio de ferias:\n");
    novoEmpregado.ferias_inicio = lerData();

    printf("\n");

    int contar_data_fim = 0;

    do
    {
        if (contar_data_fim != 0) printf("\n\t## Data fim menor que data inicio!\n");
        contar_data_fim++;
        printf("\n");
        printf("Data de fim de ferias:\n");
        novoEmpregado.ferias_fim = lerData();

        if (novoEmpregado.ferias_fim.ano < novoEmpregado.ferias_inicio.ano)
           continue;

        else if (novoEmpregado.ferias_fim.ano > novoEmpregado.ferias_inicio.ano)
            break;

        if (novoEmpregado.ferias_fim.ano == novoEmpregado.ferias_inicio.ano)
        {
             if (novoEmpregado.ferias_fim.mes<novoEmpregado.ferias_inicio.mes)
                continue;
             else if (novoEmpregado.ferias_fim.mes>novoEmpregado.ferias_inicio.mes)
                break;
             else if (novoEmpregado.ferias_fim.dia<novoEmpregado.ferias_inicio.dia)
                continue;
             else if(novoEmpregado.ferias_fim.dia>novoEmpregado.ferias_inicio.dia)
                break;
        }

        break;
    }
    while (1);

    return novoEmpregado;
}

void mostrarEmpregado(Empregado empregado)
{
    printf("\n-> %-10s: %d\n", "Codigo", empregado.codigo);
    printf("-> %-10s: %s\n", "Nome", empregado.nome);
    printf("-> %-10s: %s\n", "Morada", empregado.morada);
    printf("-> %-10s: %c\n", "Genero", empregado.genero);
    printf("-> %-10s: %.2f EUR\n", "Salario", empregado.salario);
    printf("-> %-10s: %s\n", "Categoria", devolveCategoria(empregado.categoria));
    printf("-> %-10s: %d an%s\n", "Idade", calcularIdade(empregado.data_nascimento), (calcularIdade(empregado.data_nascimento) != 1 ? "os" : "o"));
    printf("-> %-25s: ", "Data de nascimento");
    imprimirData(empregado.data_nascimento);
    printf("-> %-25s: ", "Data de inicio de ferias");
    imprimirData(empregado.ferias_inicio);
    printf("-> %-25s: ", "Data de fim de ferias");
    imprimirData(empregado.ferias_fim);
}
