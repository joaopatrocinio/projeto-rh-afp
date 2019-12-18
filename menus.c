#include <stdio.h>
#include <stdlib.h>

#include "empregado.h"
#include "empregados.h"

void desenharMenu()
{
    limparEcra();

    printf("## Projeto AFP - Gestao de Recursos Humanos\n\n");
    printf("1) Gerir empregados\n");
    printf("2) Estatisticas\n");
    printf("\n0) Sair\n\n");
}

void menuGerirEmpregados(Empregados *empregados)
{
    int menu;
    do
    {
        limparEcra();

        printf("* GERIR EMPREGADOS *\n\n");
        printf("1) Inserir empregados\n");
        printf("2) Mostrar empregados\n");
        printf("3) Atualizar empregados\n");
        printf("\n0) <- Voltar\n\n");

        menu = devolverNumero("Introduza uma opcao");

        switch (menu)
        {
            case 1:
            {
                Empregado novoEmpregado = inserirDadosEmpregado();
                adicionarEmpregado(empregados, novoEmpregado);
                break;
            }
            case 2:
            {
                mostrarEmpregados(*empregados);
                break;
            }
            case 3:
            {
                atualizarEmpregado(empregados);
                break;
            }
        }
    }
    while (menu != 0);
}
