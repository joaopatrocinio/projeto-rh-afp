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
    printf("\n-> Exist%s %d empregados na categoria %s.\n\n", (num == 1 ? "e" : "em"), num, devolveCategoria(cat));

    pausa();
}
