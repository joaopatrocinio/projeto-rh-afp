#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "comum.h"
#include "empregados.h"

int numeroDeEmpregadosPorCategoria(Empregados *empregados, char cat)
{
    int contar = 0;

    for (int i = 0; i < empregados->tamanho; i++)
        if (empregados->listaEmpregados[i].categoria == cat)
            contar++;

    return contar;
}

void mostrarNumeroDeEmpregadosPorCategoria(Empregados *empregados)
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

float calcularSalariosAPagar(Empregados *empregados, char categoria, char genero)
{
    float somaSalarios = 0;

    for (int i = 0; i < empregados->tamanho; i++)
    {
        if (empregados->listaEmpregados[i].categoria == categoria || categoria == 'T')
        {
            if (empregados->listaEmpregados[i].genero == genero || genero == 'T')
            {
                somaSalarios += empregados->listaEmpregados[i].salario;
            }
        }
    }

    return somaSalarios;
}

void totalSalariosAPagar(Empregados *empregados)
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
