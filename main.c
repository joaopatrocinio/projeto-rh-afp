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
    empregados.tamanho = 0;

    // Empregado de teste, remover na build final
    Empregado empregadoTeste = criarEmpregado(1, "Joao Patrocinio", "Rua da Uniao, N. 4, Moita", 'M', criarData(25, 1, 2001), criarData(23, 12, 2019), criarData(6, 1, 2020), 1543, 'A');
    adicionarEmpregado(&empregados, empregadoTeste);
    Empregado empregadoTeste2 = criarEmpregado(2, "Angela Ferreira", "Rua das Oliveiras, N. 8, Pinhal Novo", 'F', criarData(12, 6, 2003), criarData(6, 1, 2020), criarData(17, 1, 2020), 1454, 'F');
    adicionarEmpregado(&empregados, empregadoTeste2);
    Empregado empregadoTeste3 = criarEmpregado(3, "Bruno Marques", "Rua da Paz, N. 32, Barreiro", 'M', criarData(22, 7, 2002), criarData(17, 1, 2020), criarData(5, 2, 2020), 1654, 'M');
    adicionarEmpregado(&empregados, empregadoTeste3);

    do
    {
        desenharMenu();
        menu = devolverNumero("Introduza uma opcao");
        switch (menu)
        {
        case 1:
            // Neste caso a lista de empregados é enviada para a função por referência porque esta pode
            // ser alterada, no caso das estatisticas e da ficha dos empregados não são enviadas por referência
            // porque vão ser executadas operações read-only, não necessitando de alterar a lista original.
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
