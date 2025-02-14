#include <stdio.h>

int main()
{
    int contador = 0;
    int holder;

    while ((holder = getchar()) != EOF)
    {
        if (holder == '\n')
        {
            printf("linha computada.\n");
            contador++;
        }
        
    }
    
    printf("Voce adicionou %ld linhas.", contador);

    return 0;
}