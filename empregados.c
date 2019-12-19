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
        printf("\n\t!! Nao existem empregados armazenados no programa.\n\n");
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
    int num = devolverNumero("\nInsira o codigo do empregado que quer atualizar");
    int index;
    Empregado empregadoParaAtualizar = devolveEmpregadoPorCodigo(num, empregados, &index);
    if (empregadoParaAtualizar.codigo != -1)
    {
        mostrarEmpregado(empregadoParaAtualizar);

        empregados->listaEmpregados[index].codigo = devolverNumero("Novo codigo");
        devolverString("Novo nome", empregados->listaEmpregados[index].nome);
        devolverString("Nova morada", empregados->listaEmpregados[index].morada);

    }
    else
    {
        printf("\n\t!! Empregado selecionado nao existe.\n\n");
    }
    pausa();
}

// Quando a função é executada deve ser feita uma validação ao código do empregado,
// se este for = -1, significa que não foi encontrado um empregado com o codigo facultado.
Empregado devolveEmpregadoPorCodigo(int codigo, Empregados *empregados, int *index)
{
    Empregado empregadoVazio;
    empregadoVazio.codigo = -1;
    for (int i = 0; i < empregados->tamanho; i++)
    {
        if (empregados->listaEmpregados[i].codigo == codigo)
        {
            *index = i; // Indice do empregado encontrado na lista de empregados
            return empregados->listaEmpregados[i];
        }
    }
    return empregadoVazio;
}

void eliminarEmpregados(Empregados *empregados)
{
    int codigo = devolverNumero("\nIntroduza o codigo do empregado que deseja eliminar");

    int index; // Indice do empregado a eliminar
    Empregado empregadoAEliminar = devolveEmpregadoPorCodigo(codigo, empregados, &index);

    if (empregadoAEliminar.codigo != -1)
    {
        for (int i = index; i < empregados->tamanho; i++)
        {
            if (i + 1 < empregados->tamanho)
                empregados->listaEmpregados[i] = empregados->listaEmpregados[i + 1];
            else
            {
                empregados->tamanho--;
                empregados->listaEmpregados = realloc(empregados->listaEmpregados, (empregados->tamanho * sizeof(Empregado) + sizeof(Empregado)));
                printf("\n-> Empregado eliminado com sucesso.\n\n");
            }
        }
    }
    else
    {
        printf("\n\t!! Empregado selecionado nao existe.\n\n");
    }
    pausa();
}
