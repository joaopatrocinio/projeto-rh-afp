#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "comum.h"
#include "empregados.h"

int numeroDeEmpregadosPorCategoria(Empregados empregados, char cat)
{
    int contar = 0;

    for (int i = 0; i < empregados.tamanho; i++)
        if (empregados.listaEmpregados[i].categoria == cat)
            contar++;

    return contar;
}

void mostrarNumeroDeEmpregadosPorCategoria(Empregados empregados)
{
    char cat;

    // Validar categoria
    do
    {
        cat = devolverCaracter("Categoria (M - Motorista / F - Fabril / A - Administrativo)");
        cat = toupper(cat);
        if (cat != 'M' && cat != 'F' && cat != 'A')
        {
            printf("\n\t!! A categoria introduzida nao e valida.\n\n");
        }
    }
    while (cat != 'M' && cat != 'F' && cat != 'A');

    int num = numeroDeEmpregadosPorCategoria(empregados, cat);
    printf("\n-> Exist%s %d empregad%s na categoria %s.\n\n", (num == 1 ? "e" : "em"), num, (num == 1 ? "o" : "os"), devolveCategoria(cat));

    pausa();
}

float calcularSalariosAPagar(Empregados empregados, char categoria, char genero)
{
    float somaSalarios = 0;

    for (int i = 0; i < empregados.tamanho; i++)
    {
        if (empregados.listaEmpregados[i].categoria == categoria || categoria == 'T')
        {
            if (empregados.listaEmpregados[i].genero == genero || genero == 'T')
            {
                somaSalarios += empregados.listaEmpregados[i].salario;
            }
        }
    }

    return somaSalarios;
}

void totalSalariosAPagar(Empregados empregados)
{
    char categoria;

    // Validar categoria
    do
    {
        categoria = devolverCaracter("\nFiltrar por categoria (T - Todas | F - Fabril | M - Motorista | A - Administrativo)");
        categoria = toupper(categoria);

        if (categoria != 'T' && categoria != 'F' && categoria != 'M' && categoria != 'A')
        {
            printf("\n\t!! Categoria introduzida nao e valida.\n");
        }
    }
    while (categoria != 'T' && categoria != 'F' && categoria != 'M' && categoria != 'A');

    // Validar genero
    char genero;
    do
    {
        genero = devolverCaracter("\nFiltrar por genero (T - Todos | M - Masculino | F - Feminino)");
        genero = toupper(genero);

        if (genero != 'T' && genero != 'M' && genero != 'F')
        {
            printf("\n\t!! Genero introduzida nao e valido.\n");
        }
    }
    while (genero != 'T' && genero != 'M' && genero != 'F');

    float salarioTotal = calcularSalariosAPagar(empregados, categoria, genero);

    printf("\n-> Total de salario a pagar: %.2f EUR\n\n", salarioTotal);

    pausa();
}

void mediaSalariosAPagar(Empregados empregados)
{
    char categoria;

    // Validar categoria
    do
    {
        categoria = devolverCaracter("\nFiltrar por categoria (T - Todas | F - Fabril | M - Motorista | A - Administrativo)");
        categoria = toupper(categoria);

        if (categoria != 'T' && categoria != 'F' && categoria != 'M' && categoria != 'A')
        {
            printf("\n\t!! Categoria introduzida nao e valida.\n");
        }
    }
    while (categoria != 'T' && categoria != 'F' && categoria != 'M' && categoria != 'A');

    // A função de calcular o total de salários a pagar é reutilizada, mas o parâmetro de género
    // é sempre 'T', ou seja, o resultado não tende em conta o genero do empregado.
    float salarioTotal = calcularSalariosAPagar(empregados, categoria, 'T');

    // Contar numero de empregados na categoria escolhida para calcular a media aritmetica.
    int contar = 0;

    if (categoria != 'T')
    {
         for (int i = 0; i < empregados.tamanho; i++)
        {
            if (empregados.listaEmpregados[i].categoria == categoria)
            {
                contar++;
            }
        }
    }
    else contar = empregados.tamanho;

    if (contar == 0) contar = 1; // evitar divisao por zero se nao houver empregados
    float media = salarioTotal / contar;

    printf("\n-> Media de salarios a pagar: %.2f EUR\n\n", media);

    pausa();
}

void empregadoMaisNovo(Empregados empregados)
{
    Empregado empregadoMaisNovo = obterEmpregadoMaisNovo(empregados);
    if (empregadoMaisNovo.codigo != -1)
    {
        mostrarEmpregado(empregadoMaisNovo);
    }
    else
    {
        printf("\n## Nao existem empregados.\n\n");
    }

    pausa();
}

void empregadoMaisVelho(Empregados empregados)
{
    Empregado empregadoMaisVelho = obterEmpregadoMaisVelho(empregados);
    if (empregadoMaisVelho.codigo != -1)
    {
        mostrarEmpregado(empregadoMaisVelho);
    }
    else
    {
        printf("\n## Nao existem empregados.\n\n");
    }
    pausa();
}
