#include <stdio.h>
#include <stdlib.h>

char *categoriaDescricao(int categoria_id)
{
    switch (categoria_id)
    {
        case 1: return "Motorista";
        case 2: return "Fabril";
        case 3: return "Administrativo";
        default: return "N/A";
    }
}