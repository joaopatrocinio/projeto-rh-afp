#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    // Guardar o novo empregado, aumentar o contador de empregados guardados, e alocar espaço para um novo empregado.
    empregados->listaEmpregados[empregados->tamanho] = novoEmpregado;
    empregados->tamanho++;
    empregados->listaEmpregados = realloc(empregados->listaEmpregados, (empregados->tamanho * sizeof(Empregado) + sizeof(Empregado)));
    if (!empregados->listaEmpregados) exit(0);
}

void atualizarEmpregado(Empregados *empregados)
{
    int num = devolverNumero("\nInsira o codigo do empregado que quer atualizar");
    int index;
    Empregado empregadoParaAtualizar = devolveEmpregadoPorCodigo(num, empregados, &index);
    if (empregadoParaAtualizar.codigo != -1)
    {
        mostrarEmpregado(empregadoParaAtualizar);

        printf("\nIntroduza os novos detalhes do empregado:\n\n");

        // Pedir codigo (deve ser maior que 0)
        do
        {
            empregados->listaEmpregados[index].codigo = devolverNumero("Codigo");
            if (empregados->listaEmpregados[index].codigo <= 0)
            {
                printf("\n\t!! O codigo introduzido nao e valido.\n\n");
            }
        }
        while (empregados->listaEmpregados[index].codigo <= 0);

        // Nome e morada
        devolverString("Nome", empregados->listaEmpregados[index].nome);
        devolverString("Morada", empregados->listaEmpregados[index].morada);

        // Pedir genero (M ou F)
        do
        {
            empregados->listaEmpregados[index].genero = devolverCaracter("Genero (M/F)");
            empregados->listaEmpregados[index].genero = toupper(empregados->listaEmpregados[index].genero);
            if (empregados->listaEmpregados[index].genero != 'M' && empregados->listaEmpregados[index].genero != 'F')
            {
                printf("\n\t!! O genero introduzido nao e valido.\n\n");
            }
        }
        while (empregados->listaEmpregados[index].genero != 'M' && empregados->listaEmpregados[index].genero != 'F');

        // Pedir salario (deve ser maior que 0)
        do
        {
            empregados->listaEmpregados[index].salario = devolverFloat("Salario");
            if (empregados->listaEmpregados[index].salario <= 0)
            {
                printf("\n\t!! O salario introduzido nao e valido.\n\n");
            }
        }
        while (empregados->listaEmpregados[index].salario <= 0);

        // Categoria
        do
        {
            empregados->listaEmpregados[index].categoria = devolverCaracter("Categoria (M - Motorista / F - Fabril / A - Administrativo)");
            empregados->listaEmpregados[index].categoria = toupper(empregados->listaEmpregados[index].categoria);
            if (empregados->listaEmpregados[index].categoria != 'M' && empregados->listaEmpregados[index].categoria != 'F' && empregados->listaEmpregados[index].categoria != 'A')
            {
                printf("\n\t!! A categoria introduzida nao e valida.\n\n");
            }
        }
        while (empregados->listaEmpregados[index].categoria != 'M' && empregados->listaEmpregados[index].categoria != 'F' && empregados->listaEmpregados[index].categoria != 'A');

        // Datas
        printf("\n\tData de nascimento:\n\n");
        empregados->listaEmpregados[index].data_nascimento = lerData();
        printf("\n\tData de inicio de ferias:\n\n");
        empregados->listaEmpregados[index].ferias_inicio = lerData();
        printf("\n\tData de fim de ferias:\n\n");
        empregados->listaEmpregados[index].ferias_fim = lerData();
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
                if (!empregados->listaEmpregados) exit(0);
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

void obterFichaDeEmpregadoPorCodigo(Empregados *empregados)
{
    int num = devolverNumero("\nInsira o codigo do empregado que deseja visualizar");
    int index;
    Empregado empregado = devolveEmpregadoPorCodigo(num, empregados, &index);
    if (empregado.codigo != -1)
        mostrarEmpregado(empregado);
    else
        printf("\n\t!! Empregado selecionado nao existe.\n\n");
    pausa();
}
