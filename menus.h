#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include "empregados.h"

void desenharMenu();
void menuGerirEmpregados(Empregados *empregados);
void menuEstatisticas(Empregados empregados);
void importarEmpregadosDefault(Empregados *empregados);

#endif
