#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO 20

int string2int(char * texto);

int main(int argc, char const *argv[])
{
    if (argc > 1)
    {
        for (size_t i = 1; i < argc; i++)
        {
            printf("%s ",argv[i]);
        }
    }

    char texto[20];

    strcpy(texto, argv[1]);

    int t = string2int(texto);

    printf("\nO numero digitado + 1 = %d\n", (t + 1));

    char * nome;

    nome = (char *)malloc(sizeof(char) * TAMANHO);

    printf("Qual eh o seu nome? \n>>> ");
    
    fgets(nome, TAMANHO, stdin);
    strcspn(nome, "\n")[nome] = '\0';

    printf("Seu nome eh: %s\n", nome);

    free(nome);
    
    return 0;
}

int string2int(char * texto)
{
    register char c = texto[0];
    int aux = 0;
    int n = 0;
    int i = 0;
    register int base = 10;


    while (c != '\0')
    {
        n *= base;
        aux = (int)c;
        aux -= '0';
        n += aux;
        i++;
        c = texto[i];
    }

    return n;
}