#include <stdio.h>
#include <stdlib.h>

#include "comum.c"
#include "data.c"
#include "empregado.c"
#include "empregados.c"
#include "menus.c"

Empregados empregados;

int main()
{
    int menu;

    // Começar lista de empregados com espaço para 1 empregado,
    // irá ser aumentado quando for preciso.
    empregados.listaEmpregados = (Empregado*) malloc(1 * sizeof(Empregado));

    do
    {
        desenharMenu();
        menu = devolverNumero("Introduza uma opcao");
        switch (menu)
        {
        case 1:
            menuGerirEmpregados(&empregados);
            break;
        default:
            break;
        }
    }
    while (menu != 0);

    return 0;
}
