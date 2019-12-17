#include <stdio.h>
#include <stdlib.h>

int devolverNumero(char string[])
{
    int num;
    printf("%s: ", string);
    scanf("%d", &num);
    return num;
}

void limparEcra()
{
    system("cls || clear");
}

void pausa()
{
    #ifdef _WIN32
    system("pause");
    #endif
    #ifdef __APPLE__
    system("read -n 1 -s -p \"Prima qualquer tecla para continuar...\" || pause; echo");
    #endif
}