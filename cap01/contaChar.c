#include <stdio.h>

int main()
{
    long contagem;

    int caracter;
    
    while ((caracter = getchar()) != EOF)
    {
        if (caracter == '\n')
        {
            continue;
        }

        printf("O caracter foi adicionado ao banco.\n");
        
        ++contagem;
    }
    
    /*
    for (contagem = 0; (caracter = getchar()) != EOF; contagem++)
    {
        if (caracter == '\n')
        {
            continue;
        }
        
        printf("O caracter foi adicionado ao banco.\n");

        // parece que o \n está sendo contado tbm...
    }
    */

    printf("Voce digitou %ld caracteres.", contagem);

    return 0;
}