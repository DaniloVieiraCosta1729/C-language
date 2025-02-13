#include <stdio.h>

// verify the value of the expression getchar() != EOF.

int main()
{
    int valor;

    valor = (getchar() != EOF);
    
    printf("%d", valor);

    return 0;
}

// Resultado: quando temos o sinal EOF, o resultado é 0, caso contrário é 1.