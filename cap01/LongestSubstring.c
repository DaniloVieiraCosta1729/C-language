#include <stdio.h>

#define MAXLENGTH 50001

int contador(char* s, int i)
{
    int contagem = 1;

    for (int k = i - 1; (k >= 0) && (s[k] != s[i]); k--)
    {
        contagem++;
    }

    return contagem;
}

int tamanhoMaiorSubstring(char* s)
{
    int resultado = 1;
    int c;

    for (int i = 1; (i < MAXLENGTH) && (s[i] == '\0'); i++)
    {
        c = contador(s, i);
        if (resultado < c)
        {
            resultado = c;
        }
    }
    return resultado;
}

int main()
{
    char* c = "abcffhgfgwemf";
    printf("%d", tamanhoMaiorSubstring(c));
    return 0;
}