#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int devolverNumero(char string[])
{
    int num;
    printf("%s: ", string);
    scanf("%d", &num);
    return num;
}

void devolverString(char *texto, char *str)
{
    char temp[200];
    fflush(stdin);
    printf("%s: ", texto);
    gets(temp);
    strcpy(str, temp);
}

char devolverCaracter(char string[])
{
    char res;
    fflush(stdin);
    printf("%s: ", string);
    scanf("%c", &res);
    return res;
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
