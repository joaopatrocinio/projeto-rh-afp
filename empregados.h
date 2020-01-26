#ifndef EMPREGADOS_H_INCLUDED
#define EMPREGADOS_H_INCLUDED

#include "comum.h"
#include "empregado.h"

typedef struct Empregados
{
    Empregado *listaEmpregados;
    int tamanho;
} Empregados;

void mostrarEmpregados(Empregados empregados);
void adicionarEmpregado(Empregados *empregados, Empregado novoEmpregado);
void atualizarEmpregado(Empregados *empregados);
Empregado devolveEmpregadoPorCodigo(int codigo, Empregados *empregados, int *index);
void eliminarEmpregados(Empregados *empregados);
void obterFichaDeEmpregadoPorCodigo(Empregados *empregados);
Empregado obterEmpregadoMaisNovo(Empregados empregados);
Empregado obterEmpregadoMaisVelho(Empregados empregados);
void ordenarEmpregadosAlfabeticamente(Empregados *empregados);
void conjuntoAtualFichasEmpregados(Empregados empregados);
void matrizNumeroEmpregados(Empregados empregados);
int importarEmpregados(char *sourceFile, Empregados *empregados);
void pedirImportarEmpregados(Empregados *empregados);
int exportarEmpregados(char *sourceFile, Empregados empregados);
void pedirExportarEmpregados(Empregados empregados);
int validarCodigoExistente(Empregados empregados, int codigo);
void empregadosDeFeriasNumaData(Empregados empregados, Data dataPesquisa);

#endif
