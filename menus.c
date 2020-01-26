#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "empregado.h"
#include "empregados.h"
#include "estatisticas.h"

void desenharMenu()
{
    limparEcra();

    printf("## Projeto AFP - Gestao de Recursos Humanos\n\n");
    printf("* MENU INICIAL *\n\n");
    printf("(1) Gerir empregados\n");
    printf("(2) Estatisticas\n");
    printf("(3) Conjunto atual de fichas de empregados (A-Z)\n");
    printf("(4) Matriz com numero de empregados por genero e categoria\n");
    printf("(5) Empregados de ferias numa determinada data\n");
    printf("(6) Importar empregados\n");
    printf("(7) Exportar empregados\n");
    printf("\n(0) Sair\n\n");
}

void menuGerirEmpregados(Empregados *empregados)
{
    int menu;
    do
    {
        limparEcra();

        printf("## Projeto AFP - Gestao de Recursos Humanos\n\n");
        printf("* GERIR EMPREGADOS *\n\n");
        printf("(1) Inserir empregados\n");
        printf("(2) Mostrar todos os empregados\n");
        printf("(3) Mostrar empregado por codigo\n");
        printf("(4) Atualizar empregados\n");
        printf("(5) Eliminar empregados\n");
        printf("\n(0) <- Voltar\n\n");

        menu = devolverNumero("Introduza uma opcao");

        switch (menu)
        {
            case 1:
            {
                Empregado novoEmpregado = inserirDadosEmpregado(*empregados);
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

void menuEstatisticas(Empregados empregados)
{
    int menu;
    do
    {
        limparEcra();

        printf("## Projeto AFP - Gestao de Recursos Humanos\n\n");
        printf("* ESTATISTICAS *\n\n");
        printf("(1) Numero atual de empregados por categoria\n");
        printf("(2) Total de salarios a pagar\n");
        printf("(3) Media de salarios a pagar\n");
        printf("(4) Empregado mais novo\n");
        printf("(5) Empregado mais velho\n");
        printf("\n(0) <- Voltar\n\n");

        menu = devolverNumero("Introduza uma opcao");

        switch (menu)
        {
            case 1:
                mostrarNumeroDeEmpregadosPorCategoria(empregados);
                break;
            case 2:
                totalSalariosAPagar(empregados);
                break;
            case 3:
                mediaSalariosAPagar(empregados);
                break;
            case 4:
                empregadoMaisNovo(empregados);
                break;
            case 5:
                empregadoMaisVelho(empregados);
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
}

void importarEmpregadosDefault(Empregados *empregados)
{
    char importar;

    do
    {
        importar = devolverCaracter("Importar \"empregados.csv\" (S/N)");
        importar = toupper(importar);

        if (importar != 'S' && importar != 'N')
            printf("\n\t## Opcao invalida.\n\n");
    }
    while (importar != 'S' && importar != 'N');

    if (importar == 'S')
    {
        if (importarEmpregados("empregados.csv", empregados) == 1)
            printf("Importado com sucesso.\n");
        else
            printf("Erro ao importar empregados.\n");

        pausa();
    }
}
