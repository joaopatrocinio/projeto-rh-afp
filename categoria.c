#include <stdio.h>
#include <stdlib.h>

char *devolveCategoria(char cat)
{
    switch (cat)
    {
    case 'M':
        return "Motorista";
        break;
    case 'F':
        return "Fabril";
        break;
    case 'A':
        return "Administrativo";
        break;
    default:
        return "N/A";
        break;
    }
}
