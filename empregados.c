#include <stdio.h>
#include <stdlib.h>

#include "comum.h"
#include "empregado.h"
#include "empregados.h"

void mostrarEmpregados(Empregados empregados)
{
    if (empregados.tamanho > 0)
    {
        printf("\n| LISTA DE EMPREGADOS |\n");
        for (int i = 0; i < empregados.tamanho; i++)
        {
            printf("\n-> Codigo: %d\n", empregados.listaEmpregados[i].codigo);
            printf("-> Nome: %s\n", empregados.listaEmpregados[i].nome);
            printf("-> Morada: %s\n", empregados.listaEmpregados[i].morada);
        }    
    }
    else
    {
        printf("\n!! Nao existem empregados armazenados no programa.\n\n");
    }
    
    pausa();
}

void adicionarEmpregado(Empregados *empregados, Empregado novoEmpregado)
{
    // Alocar espaço para um novo empregado.
    empregados->listaEmpregados[empregados->tamanho] = novoEmpregado;
    empregados->tamanho++;
    empregados->listaEmpregados = realloc(empregados->listaEmpregados, (empregados->tamanho * sizeof(Empregado) + sizeof(Empregado)));
}