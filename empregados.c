#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

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
    if (!empregados->listaEmpregados) exit(0);
    // Guardar o novo empregado, aumentar o contador de empregados guardados, e alocar espaço para um novo empregado.
    empregados->listaEmpregados[empregados->tamanho] = novoEmpregado;
    empregados->tamanho++;
    empregados->listaEmpregados = realloc(empregados->listaEmpregados, (2*empregados->tamanho * sizeof(Empregado) ));//+ sizeof(Empregado)));
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

        int codigo;
        // Pedir codigo (deve ser maior que 0)
        do
        {
            codigo = devolverNumero("Codigo");
            if (codigo <= 0)
            {
                printf("\n\t!! O codigo introduzido nao e valido.\n\n");
            }
            if (validarCodigoExistente(*empregados, codigo) == 1 && empregados->listaEmpregados[index].codigo != codigo)
            {
                codigo = -1;
                printf("\n\t!! O codigo introduzido esta ocupado por outro empregado.\n\n");
            }
        }
        while (codigo <= 0);

        empregados->listaEmpregados[index].codigo = codigo;

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
        mostrarEmpregado(empregadoAEliminar);

        char continuar;
        do
        {
            continuar = devolverCaracter("\nTem a certeza que deseja eliminar o empregado (S/N)");
            continuar = toupper(continuar);
            if (continuar != 'S' && continuar != 'N')
            {
                printf("\n\t## Opcao invalida.\n");
            }
        }
        while (continuar != 'S' && continuar != 'N');

        if (continuar == 'S')
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
                    pausa();
                }
            }
        }
    }
    else
    {
        printf("\n\t!! Empregado selecionado nao existe.\n\n");
        pausa();
    }
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

Empregado obterEmpregadoMaisNovo(Empregados empregados)
{
    int codigo = -1;
    int idade = INT_MAX;

    for (int i = 0; i < empregados.tamanho; i++)
    {
        if (calcularIdade(empregados.listaEmpregados[i].data_nascimento) < idade)
        {
            idade = calcularIdade(empregados.listaEmpregados[i].data_nascimento);
            codigo = empregados.listaEmpregados[i].codigo;
        }
    }

    int index;
    return devolveEmpregadoPorCodigo(codigo, &empregados, &index);
}

Empregado obterEmpregadoMaisVelho(Empregados empregados)
{
    int codigo = -1;
    int idade = 0;

    for (int i = 0; i < empregados.tamanho; i++)
    {
        if (calcularIdade(empregados.listaEmpregados[i].data_nascimento) > idade)
        {
            idade = calcularIdade(empregados.listaEmpregados[i].data_nascimento);
            codigo = empregados.listaEmpregados[i].codigo;
        }
    }

    int index;
    return devolveEmpregadoPorCodigo(codigo, &empregados, &index);
}

void ordenarEmpregadosAlfabeticamente(Empregados *empregados)
{
    Empregado temp;

    for (int i = 0; i < empregados->tamanho - 1; i++)
    {
        for (int j = i + 1; j < empregados->tamanho; j++)
        {
            if (strcmp(empregados->listaEmpregados[i].nome, empregados->listaEmpregados[j].nome) > 0)
            {
                temp = empregados->listaEmpregados[i];
                empregados->listaEmpregados[i] = empregados->listaEmpregados[j];
                empregados->listaEmpregados[j] = temp;
            }
        }
    }
}

void conjuntoAtualFichasEmpregados(Empregados empregados)
{
    char categoria;

    // Validar categoria
    do
    {
        categoria = devolverCaracter("\nFiltrar por categoria (T - Todas | F - Fabril | M - Motorista | A - Administrativo)");
        categoria = toupper(categoria);

        if (categoria != 'T' && categoria != 'F' && categoria != 'M' && categoria != 'A')
        {
            printf("\n\t!! Categoria introduzida nao e valida.\n");
        }
    }
    while (categoria != 'T' && categoria != 'F' && categoria != 'M' && categoria != 'A');

    // Validar genero
    char genero;

    do
    {
        genero = devolverCaracter("\nFiltrar por genero (T - Todos | M - Masculino | F - Feminino)");
        genero = toupper(genero);

        if (genero != 'T' && genero != 'M' && genero != 'F')
        {
            printf("\n\t!! Genero introduzido nao e valido.\n");
        }
    }
    while (genero != 'T' && genero != 'M' && genero != 'F');

    // Criar nova lista de empregados
    Empregados empregadosFiltrados;
    empregadosFiltrados.listaEmpregados = (Empregado*) malloc(1 * sizeof(Empregado));
    if (!empregados.listaEmpregados) exit(0);
    empregadosFiltrados.tamanho = 0;

    // Percorre a lista original de empregados e adiciona à nova lista aqueles que correspondem
    // ao filtro escolhido pelo utilizador
    for (int i = 0; i < empregados.tamanho; i++)
    {
        if (empregados.listaEmpregados[i].categoria == categoria || categoria == 'T')
        {
            if (empregados.listaEmpregados[i].genero == genero || genero == 'T')
            {
                adicionarEmpregado(&empregadosFiltrados, empregados.listaEmpregados[i]);
            }
        }
    }

    // Ordenar a lista filtrada por ordem alfabética, usando uma variável temporária para auxílio.
    ordenarEmpregadosAlfabeticamente(&empregadosFiltrados);
    mostrarEmpregados(empregadosFiltrados);
}

void matrizNumeroEmpregados(Empregados empregados)
{
    int feminino_motorista = 0;
    int feminino_fabril = 0;
    int feminino_administrativo = 0;
    int masculino_motorista = 0;
    int masculino_fabril = 0;
    int masculino_administrativo = 0;

    for (int i = 0; i < empregados.tamanho; i++)
    {
        Empregado empregado = empregados.listaEmpregados[i];
        if (empregado.genero == 'F')
        {
            if (empregado.categoria == 'M')
                feminino_motorista++;
            if (empregado.categoria == 'F')
                feminino_fabril++;
            if (empregado.categoria == 'A')
                feminino_administrativo++;
        }

        if (empregado.genero == 'M')
        {
            if (empregado.categoria == 'M')
                masculino_motorista++;
            if (empregado.categoria == 'F')
                masculino_fabril++;
            if (empregado.categoria == 'A')
                masculino_administrativo++;
        }
    }

    printf("%14s--------------------------------------------------*\n", "*");
    printf("%14s %-15s| %-15s| %-15s|\n", "|", "Fabril", "Motorista", "Administrativo");
    printf("*------------|--------------------------------------------------|\n");
    printf("| %-11s| %-15d| %-15d| %-15d|\n", "Feminino", feminino_fabril, feminino_motorista, feminino_administrativo);
    printf("| %-11s| %-15d| %-15d| %-15d|\n", "Masculino", masculino_fabril, masculino_motorista, masculino_administrativo);
    printf("*---------------------------------------------------------------*\n");

    pausa();
}

int importarEmpregados(char *sourceFile, Empregados *empregados)
{
    FILE *f;
    f = fopen(sourceFile, "r");
    if (f == NULL)
    {
        return 0;
    }

    Empregado novo;
    char categoria[20];
    char nome[51];
    char morada[151];
    float salario;

    while (fscanf(f, "%d;%[^;];%[^;];%c;%02d-%02d-%04d;%[^;];%f;%02d-%02d-%04d;%02d-%02d-%04d\n",
        &novo.codigo, nome, morada, &novo.genero,
        &novo.data_nascimento.dia, &novo.data_nascimento.mes, &novo.data_nascimento.ano,
        categoria, &salario,
        &novo.ferias_inicio.dia, &novo.ferias_inicio.mes, &novo.ferias_inicio.ano,
        &novo.ferias_fim.dia, &novo.ferias_fim.mes, &novo.ferias_fim.ano) != EOF)
    {
        if (strcmp(categoria, "fabril") == 0) novo.categoria = 'F';
        else if (strcmp(categoria, "motorista") == 0) novo.categoria = 'M';
        else if (strcmp(categoria, "administrativo") == 0) novo.categoria = 'A';
        strcpy(novo.nome, nome);
        strcpy(novo.morada, morada);
        novo.salario = salario;
        //mostrarEmpregado(novo);
        adicionarEmpregado(empregados, novo);
    }
    fclose(f);

    return 1;
}

void pedirImportarEmpregados(Empregados *empregados)
{
    char string[20];
    devolverString("Ficheiro", string);
    if (importarEmpregados(string, empregados) == 1)
        printf("Importado com sucesso.\n");
    else
        printf("Erro ao importar empregados.\n");
    pausa();
}

int exportarEmpregados(char *sourceFile, Empregados empregados)
{
    FILE *f;
    f = fopen(sourceFile, "w");
    if (f == NULL)
    {
        return 0;
    }

    for (int i = 0; i < empregados.tamanho; i++)
    {
        fprintf(f, "%d;", empregados.listaEmpregados[i].codigo);
        fprintf(f, "%s;", empregados.listaEmpregados[i].nome);
        fprintf(f, "%s;", empregados.listaEmpregados[i].morada);
        fprintf(f, "%c;", empregados.listaEmpregados[i].genero);
        fprintf(f, "%d-%d-%d;", empregados.listaEmpregados[i].data_nascimento.dia, empregados.listaEmpregados[i].data_nascimento.mes, empregados.listaEmpregados[i].data_nascimento.ano);

        char categoria[20];
        if (empregados.listaEmpregados[i].categoria == 'F') strcpy(categoria, "fabril");
        else if (empregados.listaEmpregados[i].categoria == 'M') strcpy(categoria, "motorista");
        else if (empregados.listaEmpregados[i].categoria == 'A') strcpy(categoria, "administrativo");

        fprintf(f, "%s;", categoria);
        fprintf(f, "%.2f;", empregados.listaEmpregados[i].salario);
        fprintf(f, "%d-%d-%d;", empregados.listaEmpregados[i].ferias_inicio.dia, empregados.listaEmpregados[i].ferias_inicio.mes, empregados.listaEmpregados[i].ferias_inicio.ano);
        fprintf(f, "%d-%d-%d\n", empregados.listaEmpregados[i].ferias_fim.dia, empregados.listaEmpregados[i].ferias_fim.mes, empregados.listaEmpregados[i].ferias_fim.ano);
    }

    fclose(f);
    return 1;
}

void pedirExportarEmpregados(Empregados empregados)
{
    char string[20];
    devolverString("Ficheiro", string);
    if (exportarEmpregados(string, empregados) == 1)
        printf("Exportado com sucesso.\n");
    else
        printf("Erro ao exportar empregados.\n");
    pausa();
}

int validarCodigoExistente(Empregados empregados, int codigo)
{
    for (int i = 0; i < empregados.tamanho; i++)
    {
        if (codigo == empregados.listaEmpregados[i].codigo)
        {
            // existe
            return 1;
        }
    }
    // não existe
    return 0;
}

void empregadosDeFeriasNumaData(Empregados empregados, Data dataPesquisa)
{
    int contar = 0;
    for (int i = 0; i < empregados.tamanho; i++)
    {
        if ((dataPesquisa.ano <= empregados.listaEmpregados[i].ferias_fim.ano) && (dataPesquisa.ano  >= empregados.listaEmpregados[i].ferias_inicio.ano))
        {
            if((dataPesquisa.mes <= empregados.listaEmpregados[i].ferias_fim.mes) && (dataPesquisa.mes  >= empregados.listaEmpregados[i].ferias_inicio.mes))
            {
                if((dataPesquisa.dia <= empregados.listaEmpregados[i].ferias_fim.dia) || (dataPesquisa.dia  >= empregados.listaEmpregados[i].ferias_inicio.dia))
                {
                    contar++;
                    mostrarEmpregado(empregados.listaEmpregados[i]);
                }
            }
        }
    }
    if (contar == 0) printf("\n\t## Não vão estar empregados de férias na data inserida.\n\n");
    pausa();
}
