#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "comum.h"
#include "data.h"
#include "empregado.h"
#include "empregados.h"
#include "menus.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");

    // Come�ar lista de empregados com espa�o para 1 empregado,
    // ir� ser aumentado quando for preciso.
    Empregados empregados;
    empregados.listaEmpregados = (Empregado*) malloc(1 * sizeof(Empregado));
    if (!empregados.listaEmpregados) exit(0);
    empregados.tamanho = 0;

    // Pergunta ao utilizador se quer importar os empregados no ficheiro "empregados.csv"
    importarEmpregadosDefault(&empregados);

    int menu;
    do
    {
        desenharMenu();
        menu = devolverNumero("Introduza uma opcao");
        switch (menu)
        {
        case 1:
            // Neste caso a lista de empregados � enviada para a fun��o por refer�ncia porque esta pode
            // ser alterada, no caso das estatisticas e da ficha dos empregados n�o s�o enviadas por refer�ncia
            // porque v�o ser executadas opera��es read-only, n�o necessitando de alterar a lista original.
            menuGerirEmpregados(&empregados);
            break;
        case 2:
            menuEstatisticas(empregados);
            break;
        case 3:
            conjuntoAtualFichasEmpregados(empregados);
            break;
        case 4:
            matrizNumeroEmpregados(empregados);
            break;
        case 5:
            empregadosDeFeriasNumaData(empregados, lerData());
            break;
        case 6:
            pedirImportarEmpregados(&empregados);
            break;
        case 7:
            pedirExportarEmpregados(empregados);
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
