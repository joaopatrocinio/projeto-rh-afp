#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
            mostrarEmpregado(empregados.listaEmpregados[i]);
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

void atualizarEmpregado(Empregados *empregados)
{
    int num = devolverNumero("Insira o codigo do empregado que quer atualizar");
    int index;
    Empregado empregadoParaAtualizar = devolveEmpregadoPorCodigo(num, empregados, &index);
    printf("%d", index);
    if (empregadoParaAtualizar.codigo != -1)
    {
        mostrarEmpregado(empregadoParaAtualizar);

        int codigo = devolverNumero("Novo codigo");
        char nome[50];
        devolverString("Novo nome", nome);
        char morada[50];
        devolverString("Nova morada", morada);

        empregados->listaEmpregados[index].codigo = codigo;
        strcpy(empregados->listaEmpregados[index].nome, nome);
        strcpy(empregados->listaEmpregados[index].morada, morada);

    }
    else
    {
        printf("\n!! Empregado selecionado nao existe.\n");
    }
    pausa();
}

Empregado devolveEmpregadoPorCodigo(int codigo, Empregados *empregados, int *index)
{
    Empregado empregadoVazio;
    empregadoVazio.codigo = -1;
    for (int i = 0; i < empregados->tamanho; i++)
    {
        if (empregados->listaEmpregados[i].codigo == codigo)
        {
            *index = i;
            return empregados->listaEmpregados[i];
        }
    }
    return empregadoVazio;
}
