#ifndef ESTATISTICAS_H_INCLUDED
#define ESTATISTICAS_H_INCLUDED

#include "empregados.h"

int numeroDeEmpregadosPorCategoria(Empregados empregados, char cat);
void mostrarNumeroDeEmpregadosPorCategoria(Empregados empregados);
float calcularSalariosAPagar(Empregados empregados, char categoria, char genero);
void totalSalariosAPagar(Empregados empregados);
void mediaSalariosAPagar(Empregados empregados);
void empregadoMaisNovo(Empregados empregados);
void empregadoMaisVelho(Empregados empregados);

#endif // ESTATISTICAS_H_INCLUDED
