#include <stdio.h>
#include <stdlib.h>

#include "empregado.h"
#include "empregados.h"
#include "estatisticas.h"

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
        printf("2) Mostrar todos os empregados\n");
        printf("3) Mostrar empregado por codigo\n");
        printf("4) Atualizar empregados\n");
        printf("5) Eliminar empregados\n");
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
                obterFichaDeEmpregadoPorCodigo(empregados);
                break;
            }
            case 4:
            {
                atualizarEmpregado(empregados);
                break;
            }
            case 5:
            {
                eliminarEmpregados(empregados);
                break;
            }
            case 0:
            {
                break;
            }
            default:
            {
                printf("\n\t!! Opcao invalida.\n\n");
                pausa();
                break;
            }
        }
    }
    while (menu != 0);
}

void menuEstatisticas(Empregados *empregados)
{
    int menu;
    do
    {
        limparEcra();

        printf("* ESTATISTICAS *\n\n");
        printf("1) Numero atual de empregados por categoria\n");
        printf("\n0) <- Voltar\n\n");

        menu = devolverNumero("Introduza uma opcao");

        switch (menu)
        {
            case 1:
            {
                mostrarNumeroDeEmpregadosPorCategoria(empregados);
                break;
            }
            case 0:
            {
                break;
            }
            default:
            {
                printf("\n\t!! Opcao invalida.\n\n");
                pausa();
                break;
            }
        }
    }
    while (menu != 0);
}
