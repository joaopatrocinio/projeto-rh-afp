#include <stdio.h>
#include <stdlib.h>

#include "comum.h"
#include "data.h"
#include "empregado.h"
#include "empregados.h"
#include "menus.h"

Empregados empregados;

int main()
{
    int menu;

    // Começar lista de empregados com espaço para 1 empregado,
    // irá ser aumentado quando for preciso.
    empregados.listaEmpregados = (Empregado*) malloc(1 * sizeof(Empregado));
    if (!empregados.listaEmpregados) exit(0);

    // Empregado de teste, remover na build final
    Empregado empregadoTeste = criarEmpregado(1, "Joao Patrocinio", "Rua da Uniao, N. 4, Gaio", 'M', criarData(25, 1, 2001), criarData(23, 12, 2019), criarData(6, 1, 2020), 1543, 'A');
    adicionarEmpregado(&empregados, empregadoTeste);

    do
    {
        desenharMenu();
        menu = devolverNumero("Introduza uma opcao");
        switch (menu)
        {
        case 1:
            menuGerirEmpregados(&empregados);
            break;
        case 2:
            menuEstatisticas(empregados);
            break;
        case 3:
            conjuntoAtualFichasEmpregados(empregados);
            break;
        case 0:
            break;
        default:
            printf("\n\t!! Opcao invalida.\n\n");
            pausa();
            break;
        }
    }
    while (menu != 0);

    return 0;
}
